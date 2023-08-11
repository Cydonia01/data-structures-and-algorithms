#include<iostream>
#include "TreeQueue.h"
#include "TreeStack.h"

using namespace std;

class Tree {
private:
	Node *root;
	
	// helper function for recursive destruction.
	void destroy(Node* p) {
		if (p) {
			destroy(p->left);
			destroy(p->right);
			delete p;
		}
	}
	
public:
	Tree();
	~Tree();
	void CreateTree();
	void ItPreorder();
	void Preorder(){Preorder(root);}
	void Preorder(Node *p);
	void ItPostorder(); // 'It' means iterative.
	void Postorder() {Postorder(root);}
	void Postorder(Node *p);
	void ItInorder();
	void Inorder(){Inorder(root);}
	void Inorder(Node *p);
	void Levelorder(){Levelorder(root);}
	void Levelorder(Node *p);
	int Height(){return Height(root);}
	int Height(Node *root);
	int Count(){return Count(root);};
	int Count(Node *p);
	int CountDeg1() {return CountDeg1(root);}
	int CountDeg1(Node *p);
	int CountDeg2() {return CountDeg2(root);}
	int CountDeg2(Node *p);
	int CountInternal(){return CountInternal(root);};
	int CountInternal(Node *p);
	int CountLeaf(){return CountLeaf(root);};
	int CountLeaf(Node *p);
	int sum(){return sum(root);};
	int sum(Node *p);
};

Tree::Tree() {
	root = NULL;
}

Tree::~Tree() {
	destroy(root);
}

void Tree::CreateTree() {
	Node *p, *t;
	int x;
	TreeQueue q(20);
	
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
	TreeStack st(20);
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
	TreeQueue q(20);
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
	if (p == 0 || (p->left == 0 && p->right == 0))
		return 0;
	
	x = Height(p->left);
	y = Height(p->right);
	if (x > y)
		return x + 1;
	else
		return y + 1;
}

// This method counts all nodes.
int Tree::Count(Node *p) {
	if (p == NULL)
		return 0;
	return Count(p->left) + Count(p->right) + 1;
}

// This method counts degree 1 nodes. In other words, nodes which has 1 children.
int Tree::CountDeg1(Node *p) {
	if (p == NULL)
		return 0;
	if (p->left != NULL ^ p->right != NULL)
		return CountDeg1(p->left) + CountDeg1(p->right) + 1;
	return CountDeg1(p->left) + CountDeg1(p->right);
}

// This method counts degree 2 nodes. In other words, nodes which has 2 children.
int Tree::CountDeg2(Node *p) {
	if (p == NULL)
		return 0;
	if (p->left && p->right)
		return CountDeg2(p->left) + CountDeg2(p->right) + 1;
	return CountDeg2(p->left) + CountDeg2(p->right);
}

// This method counts internal nodes.
int Tree::CountInternal(Node *p) {
	if (p == NULL)
		return 0;
	if (p->left || p->right)
		return CountInternal(p->left) + CountInternal(p->right) + 1;
	return CountInternal(p->left) + CountInternal(p->right);
}

// This method counts leaf nodes.
int Tree::CountLeaf(Node *p) {
	if (p == NULL)
		return 0;
	if (!p->left && !p->right)
		return CountLeaf(p->left) + CountLeaf(p->right) + 1;
	return CountLeaf(p->left) + CountLeaf(p->right);
}

// This method evaluates the sum of data in all nodes.
int Tree::sum(Node *p) {
	if (p == NULL)
		return 0;
	return sum(p->left) + sum(p->right) + p->data;
}

int main() {
	// Sample: enter -1 to not add a child.
	// Example input: 8 3 5 12 -1 10 6 -1 4 -1 -1 2 -1 9 7 -1 -1 -1 -1 -1 -1
	Tree t;
	t.CreateTree();
	cout<<endl;
	cout<<endl<<"Preorder travelsal of tree: ";
	t.Preorder();
	
	cout<<endl<<"Inorder travelsal of tree: ";
	t.Inorder();
	
	cout<<endl<<"Postorder travelsal of tree: ";
	t.Postorder();
	
	cout<<endl<<"Levelorder travelsal of tree: ";
	t.Levelorder();
	
	cout<<endl<<"Height of tree is "<<t.Height();
	cout<<endl<<"Total nodes of tree is "<<t.Count();
	cout<<endl<<"Degree 1 nodes of tree is "<<t.CountDeg1();
	cout<<endl<<"Degree 2 nodes of tree is "<<t.CountDeg2();
	cout<<endl<<"Internal nodes of tree is "<<t.CountInternal();
	cout<<endl<<"Leaf nodes of tree is "<<t.CountLeaf();
	cout<<endl<<"Sum of tree is "<<t.sum();
	return 0;
}
