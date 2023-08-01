#include <iostream>

using namespace std;

class Node {
public:
	Node* lchild;
	int data;
	Node* rchild;
	int color;
};

class TreeQueue {
private:
	int size;
	int front;
	int rear;
	Node **A;
public:
	TreeQueue() {
		front = rear = 0;
		size = 10;
		A = new Node*[size];
	}
	
	TreeQueue(int size) {
		this->size = size;
		front = rear = 0;
		A = new Node*[size];
	}

	void enqueue(Node* p) {
		if (isFull()) cout<<"Queue is full.";
		else {
			rear = (rear + 1) % size;
			A[rear] = p;
		}
	}
	
	Node* dequeue() {
		Node* p = NULL;
		if (isEmpty()) cout<<"Queue is empty.\n";
		else {
			front = (front + 1) % size;
			p = A[front];
			
		}
		return p;
	}
	
	int isEmpty() {
		return front == rear;
	}
	
	int isFull() {
		return (rear + 1) % size == front;
		
	}
};

class RedBlackTree {
public:
	Node* root;
	
	RedBlackTree() {root = NULL;}
	
	RedBlackTree(int data) {
		root = new Node;
		root->data = data;
		root->lchild = root->rchild = NULL;
		root->color = 0;
	}
	
	void Inorder(){Inorder(root);}
	
	void Inorder(Node *p) {
		if (p) {
			Inorder(p->lchild);
			cout<<p->data<<" "<<p->color<<"  ";
			Inorder(p->rchild);
		}
	}
	
	void Levelorder(Node *p) {
		TreeQueue q(100);
		cout<<p->data<<" ";
		q.enqueue(p);
		
		while (!q.isEmpty()) {
			p = q.dequeue();
			if (p->lchild) {
				cout<<p->lchild->data<<" ";
				q.enqueue(p->lchild);
			}
			if (p->rchild) {
				cout<<p->rchild->data<<" ";
				q.enqueue(p->rchild);
			}
		}
	}
	
	void Recoloring(Node* p) {
		p->lchild->color = 0;
		p->rchild->color = 0;
		p->color = 1;
	}
	
	Node *LLRotation(Node *G) {
		Node *P = G->lchild;
		Node *N = P->rchild;
		
		P->rchild = G;
		G->lchild = N;
		
		P->color = 0;
		G->color = 1;
		
		if (root == G)
			root = P;
			
		return P;
	}
	
	Node *LRRotation(Node *G) {
		Node *P = G->lchild;
		Node *N = P->rchild;
		
		P->rchild = N->lchild;
		G->lchild = N->rchild;
		
		N->lchild = P;
		N->rchild = G;
		
		N->color = 0;
		G->color = 1;
		
		if (root == G)
			root = N;
		
		return N;
	}
	
	Node *RRRotation(Node *G) {
		Node *P = G->rchild;
		Node *N = P->lchild;
		
		P->lchild = G;
		G->rchild = N;
		
		P->color = 0;
		G->color = 1;
		
		if (root == G)
			root = P;
			
		return P;
	}
	
	Node *RLRotation(Node *G) {
		Node *P = G->rchild;
		Node *N = P->lchild;
		
		P->lchild = N->rchild;
		G->rchild = N->lchild;
		
		N->lchild = G;
		N->rchild = P;
		
		N->color = 0;
		G->color = 1;
		
		if (root == G)
			root = N;
		
		return N;
	}
	
	Node *RInsert(int key) {RInsert(root, key);}
	
	Node *RInsert(Node *p, int key) {
		Node *t = NULL;
		
		if (p == NULL) {
			t = new Node;
			t->data = key;
			t->lchild = t->rchild = NULL;
			t->color = 1;
			return t;
		}
		
		if (key < p->data) p->lchild = RInsert(p->lchild, key);
		else if (key > p->data) p->rchild = RInsert(p->rchild, key);
		
		if (p->lchild && p->lchild->color == 1 && p->lchild->lchild) {
			if (p->rchild == NULL || p->rchild->color == 0 && p->lchild->lchild->color == 1)
				return LLRotation(p);
			else if (p->lchild->lchild->color == 1)
				Recoloring(p);
		}
			
		else if (p->lchild && p->lchild->color == 1 && p->lchild->rchild) {
			if (p->rchild == NULL || p->rchild->color == 0 && p->lchild->rchild->color == 1)
				return LRRotation(p);
			else if (p->lchild->rchild->color == 1)
				Recoloring(p);
		}
			
		else if (p->rchild && p->lchild->color && p->rchild->rchild) {
			if (p->rchild->color == 1 && p->rchild->rchild->color == 1) {
				if (p->lchild == NULL || p->lchild->color == 0)
					return RRRotation(p);
				else if (p->lchild->color == 1)
					Recoloring(p);
			}
		}
			
		else if (p->rchild && p->rchild->color == 1 && p->rchild->lchild) {
			if (p->lchild == NULL || p->lchild->color == 0 && p->rchild->lchild->color == 1)
				return RLRotation(p);
			else if (p->rchild->lchild->color == 1)
				Recoloring(p);
		}
		
		root->color = 0;
		return p;
	}
	
	int Height(){return Height(root);}
	
	int Height(Node *p) {
		int x, y;
		if (p == NULL) return 0;
		x = Height(p->lchild);
		y = Height(p->rchild);
		return x > y ? x + 1: y + 1;
	}
	
	Node* InPre(Node *p) {
		while (p && p->rchild != NULL)
			p = p->rchild;
		return p;
	}
	
	Node* InSucc(Node *p) {
		while (p && p->lchild != NULL)
			p = p->lchild;
		return p;
	}
	
	Node* Delete(int x){return Delete(root, x);}
	
	Node* Delete(Node*p, int x) {
		Node* q;
		
		if (p == NULL)
			return NULL;
			
		if (p->lchild == NULL && p->rchild == NULL) {
			if (p == root)
				root = NULL;
			delete p;
			return NULL;
		}
		
		if (x < p->data)
			p->lchild = Delete(p->lchild, x);
		else if (x > p->data)
			p->rchild = Delete(p->rchild, x);
		else {
			if (Height(p->lchild) > Height(p->rchild)) {
				q = InPre(p->lchild);
				p->data = q->data;
				p->lchild = Delete(p->lchild, q->data);
			}
			else {
				q = InSucc(p->rchild);
				p->data = q->data;
				p->rchild = Delete(p->rchild, q->data);
			}
		}
	}
};

int main() {
	RedBlackTree a;
	a.root = a.RInsert(10);
	a.RInsert(20);
	a.RInsert(30);
	a.RInsert(40);
	a.RInsert(50);
	a.RInsert(60);
	a.RInsert(70);
	a.RInsert(80);
	a.RInsert(90);
	a.RInsert(100);
	a.Inorder();
	cout<<endl;
	a.Levelorder(a.root);
}
