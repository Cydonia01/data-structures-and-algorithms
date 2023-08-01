#include<iostream>
#include "TreeStack.h"

using namespace std;

class BinarySearchTree {
public:
	Node* root;
	
	BinarySearchTree() {root = NULL;}

	BinarySearchTree(int x) {
		root = new Node;
		root->data = x;
		root->right = root->left = NULL;
	}
	
	Node* Search(int x) {
		Node *t = root;
		while (t) {
			if (x < t->data) t = t->left;
			else if (x > t->data) t = t->right;
			else return t;
		}
		return NULL;
	}
	
	Node* RSearch(int x) {return RSearch(root, x);}
	
	Node* RSearch (Node *t, int x) {
		if (t == NULL)
			return NULL;
		if (x == t->data)
			return t;
		else if (x < t->data)
			return RSearch(t->left, x);
		else 
			return RSearch(t->right, x);
	}
	
	void Insert(int x) {
		Node *r = NULL;
		Node *t = root;
		Node *p;
		if (root == NULL) {
			p = new Node;
			p->data = x;
			p->left = p->right = NULL;
			root = p;
			return;
		}
		while (t != NULL) {
			r = t;
			if (x == t->data)
				return;
			else if (x < t->data)
				t = t->left;
			else
				t = t->right;
		}
		p = new Node;
		p->data = x;
		p->left = p->right = NULL;
		if (p->data < r->data) r->left = p;
		else r->right = p;
	}
	
	void myInsert(int x) {
		Node *t = root;
		Node *p;
		if (root == NULL) {
			p = new Node;
			p->data = x;
			p->left = p->right = NULL;
			root = p;
			return;
		}
		while(t != NULL) {
			if (x < t->data && t->left)
				t = t->left;
			else if (x > t->data && t->right)
				t = t->right;
			else if (x == t->data) return;
			else break;
		}
		p = new Node;
		p->data = x;
		p->left = p->right = NULL;
		if (p->data < t->data) t->left = p;
		else t->right = p;
	}
	
	Node* RInsert(int x) {return RInsert(root, x);}
	
	Node* RInsert(Node *p, int x) {
		Node *t;
		if (!p) {
			t = new Node;
			t->data = x;
			t->left = t->right = NULL;
			return t;
		}
		if (x < p->data)
			p->left = RInsert(p->left, x);
		else if (x > p->data)
			p->right = RInsert(p->right, x);
		return p;
	}
	
	void Inorder(){return Inorder(root);}
	
	void Inorder(Node *p) {
		if (p) {
			Inorder(p->left);
			cout<<p->data<<" ";
			Inorder(p->right);
		}
	}
	
	int Height(){return Height(root);}
	
	int Height(Node *p) {
		int x, y;
		if (p == NULL) return 0;
		x = Height(p->left);
		y = Height(p->right);
		return x > y ? x + 1: y + 1;
	}
	
	Node* InPre(Node *p) {
		while (p && p->right != NULL)
			p = p->right;
		return p;
	}
	
	Node* InSucc(Node *p) {
		while (p && p->left != NULL)
			p = p->left;
		return p;
	}
	
	Node* Delete(int x){return Delete(root, x);}
	
	Node* Delete(Node*p, int x) {
		Node* q;
		
		if (p == NULL)
			return NULL;
			
		if (p->left == NULL && p->right == NULL) {
			if (p == root)
				root = NULL;
			delete p;
			return NULL;
		}
		
		if (x < p->data)
			p->left = Delete(p->left, x);
		else if (x > p->data)
			p->right = Delete(p->right, x);
		else {
			if (Height(p->left) > Height(p->right)) {
				q = InPre(p->left);
				p->data = q->data;
				p->left = Delete(p->left, q->data);
			}
			else {
				q = InSucc(p->right);
				p->data = q->data;
				p->right = Delete(p->right, q->data);
			}
			
		}
		return p;
	}
};

BinarySearchTree CreatePre(int pre[], int n) {
		TreeStack st(10);
		BinarySearchTree bst2(pre[0]);
		Node* t;
		int a, i = 1;
		Node *p = bst2.root;
		while (i < n) {
			if (pre[i] < p->data) {
				t = new Node;
				t->data = pre[i++];
				t->right = t->left = NULL;
				p->left = t;
				st.push(p);
				p = t;
			}
			else {
				a = st.StackTop() ? st.StackTop()->data:INT_MAX;
				
				if (pre[i] > p->data && pre[i] < a) {
					t = new Node;
					t->data = pre[i++];
					t->right = t->left = NULL;
					p->right = t;
					p = t;
				}
				else p = st.pop();
			}
		}
		return bst2;
	}

int main() {
	
	return 0;
}
