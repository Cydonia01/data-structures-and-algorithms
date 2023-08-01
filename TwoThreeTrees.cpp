#include <iostream>

using namespace std;

class Node {
public:
	Node* lchild;
	int left;
	Node* mchild;
	int right;
	Node* rchild;
};

class TwoThreeTree {
public:
	Node* root;
	
	TwoThreeTree() {
		root = NULL;
	}
	
	
	TwoThreeTree(int data) {
		root = new Node;
		root->left = data;
	}
	
	Node* RInsert(Node *p, int data) {
		Node* h;
		Node* q;
		Node* t;
		
		if (p == NULL) {
			h = new Node;
			h->left = data;
			h->lchild = h->rchild = h->mchild = NULL;
			return h;
		}
		
		if (data < p->left && p->lchild) p->lchild = RInsert(p->lchild, data);
		else if (data > p->left && p->mchild) p->mchild = RInsert(p->mchild, data);
		else if (data > p->right && p->rchild) p->rchild = RInsert(p->rchild, data);
		else {
			if (p->left && p->right) {
				q = new Node;
				t = new Node;
				p->lchild = q;
				p->mchild = t;
				if (data > p->left && data < p->right) {
					q->left = p->left;
					t->left = p->right;
					p->left = data;
				}
				
				else if (data > p->right) {
					q->left = p->left;
					t->left = data;
					p->left = p->right;
				}
				
				else if (data < p->right) {
					q->left = data;
					t->left = p->right;
				}
				p->right = 0;
			}
			else {
				if (data < p->left) {
					p->right = p->left;
					p->left = data;
				}
				else if (data > p->left) 
					p->right = data;
				
				else return p;
			}
		}
		return p;
	}
};

int main() {
	TwoThreeTree ttt;
	ttt.root = ttt.RInsert(ttt.root, 20);
	cout<<ttt.root->left<<endl;
	ttt.RInsert(ttt.root, 30);
	cout<<ttt.root->left<<" "<<ttt.root->right<<endl;
	ttt.RInsert(ttt.root, 40);
	cout<<ttt.root->left<<endl<<ttt.root->lchild->left<<" "<<ttt.root->mchild->left;
	ttt.RInsert(ttt.root, 50);
	cout<<" "<<ttt.root->mchild->right;
	ttt.RInsert(ttt.root, 60);
	cout<<" "<<ttt.root->rchild->left;
}
