#include<iostream>
#include "TreeQueue.h"
#include "Stack.h"

using namespace std;

class Tree {
private:
	Node *root;
public:
	Tree() {root = NULL;}
	void CreateTree();
	void ItPreorder();
	void Preorder(){Preorder(root);}
	void Preorder(Node *p);
	void ItPostorder();
	void Postorder() {Postorder(root);}
	void Postorder(Node *p);
	void ItInorder();
	void Inorder(){Inorder(root);}
	void Inorder(Node *p);
	void Levelorder(){Levelorder(root);}
	void Levelorder(Node *p);
	int Height(){return Height(root);}
	int Height(Node *root);
	int Count(){return Count(root)};
	int Count(Node *p);
	int CountV2(){return CountV2(root)};
	int CountV2(Node *p);
	int sum(){return sum(root)};
	int sum(Node *p);
};

void Tree::CreateTree() {
	Node *p, *t;
	int x;
	TreeQueue q(100);
	
	cout<<"Enter root value: ";
	cin>>x;
	
	root = new Node;
	root->data = x;
	root->left = root->right = NULL;
	
	q.enqueue(root);
	while (!q.isEmpty()) {
		p = q.dequeue();
		cout<<"Enter left child of "<<p->data<<": ";
		cin>>x;
		
		if (x != -1) {
			t = new Node;
			t->data = x;
			t->left = t->right = NULL;
			p->left = t;
			q.enqueue(t);
		}
		
		cout<<"Enter right child of "<<p->data<<": ";
		cin>>x;
		
		if (x != -1) {
			t = new Node;
			t->data = x;
			t->left = t->right = NULL;
			p->right = t;
			q.enqueue(t);
		}
	}
}

void Tree::ItPreorder() {
	Node *t = root;
	TreeStack st(10);
	while (t != NULL || !st.isEmpty()) {
		if (t != NULL) {
			cout<<t->data<<" ";
			st.push(t);
			t = t->left;
		}
		else {
			t = st.pop();
			t = t->right;
		}
	}
}

void Tree::Preorder(Node *p) {
	if (p) {
		cout<<p->data<<" ";
		Preorder(p->left);
		Preorder(p->right);
	}
}

void Tree::ItInorder() {
	Node *t = root;
	TreeStack st(10);
	while (t != NULL || !st.isEmpty()) {
		if (t != NULL) {
			st.push(t);
			t = t->left;
		}
		else {
			t = st.pop();
			cout<<t->data<<" ";
			t = t->right;
		}
	}
}

void Tree::Inorder(Node *p) {
	if (p) {
		Inorder(p->left);
		cout<<p->data<<" ";
		Inorder(p->right);
	}
}

void Tree::ItPostorder() {
	Node *t = root;
	TreeStack st(10);
	while (t != NULL || !st.isEmpty()) {
		if (t != NULL) {
			st.push(t);
			t = t->left;
		}
		else {
			t = st.pop();
			cout<<t->data<<" ";
			t = t->right;
		}
	}
}

void Tree::Postorder(Node *p) {
	if (p) {
		Postorder(p->left);
		Postorder(p->right);
		cout<<p->data<<" ";
	}
}

void Tree::Levelorder(Node *p) {
	TreeQueue q(100);
	cout<<p->data<<" ";
	q.enqueue(p);
	
	while (!q.isEmpty()) {
		p = q.dequeue();
		if (p->left) {
			cout<<p->left->data<<" ";
			q.enqueue(p->left);
		}
		if (p->right) {
			cout<<p->right->data<<" ";
			q.enqueue(p->right);
		}
	}
}

int Tree::Height(Node *p) {
	int x = 0, y = 0;
	if (p == 0 || (p->left == 0 && p->right == 0)) return 0;
	
	x = Height(p->left);
	y = Height(p->right);
	if (x > y) return x + 1;
	else return y + 1;
}

int Tree::Count(Node *p) {
	int x, y;
	if (p != NULL) {
		x = Count(p->left);
		y = Count(p->right);
		return x + y + 1;
	}
	return 0;
}

int Tree::CountV2(Node *p) {
	int x, y;
	if (p != NULL) {
		x = CountV2(p->left);
		y = CountV2(p->right);
		if (p->left && p->right)
			return x + y + 1;
		else
			return x + y;
	}
	return 0;
}

int Tree::sum(Node *p) {
	int x, y;
	if (p != NULL) {
		x = sum(p->left);
		y = sum(p->right);
		return x + y + p->data;
	}
	return 0;
}

int main() {
	
	return 0;
}
