#include<iostream>

using namespace std;

class Node {
public:
	Node *lchild;
	int data;
	int height;
	Node *rchild;
};

class AVLTree {
public:
	Node* root;
	
	AVLTree() {
		root = NULL;	
	}
	
	AVLTree(int x) {
		root = new Node;
		root->data = x;
		root->height = 1;
		root->lchild = root->rchild = NULL;
	}
	
	int NodeHeight(Node *p) {
		int hl, hr;
		hl = p && p->lchild?p->lchild->height:0;
		hr = p && p->rchild?p->rchild->height:0;
		
		return hl > hr ? hl + 1:hr + 1;
	}
	
	int BalanceFactor(Node *p) {
		int hl, hr;
		hl = p && p->lchild?p->lchild->height:0;
		hr = p && p->rchild?p->rchild->height:0;
		
		return hl - hr;
	}
	
	Node *LLRotation(Node *p) {
		Node *pl = p->lchild;
		Node *plr = pl->rchild;
		
		pl->rchild = p;
		p->lchild = plr;
		p->height = NodeHeight(p);
		pl->height = NodeHeight(pl);
		
		if (root == p)
			root = pl;
			
		return pl;
	}

	Node *LRRotation(Node *p) {
		Node *pl = p->lchild;
		Node *plr = pl->rchild;
		
		pl->rchild = plr->lchild;
		p->lchild = plr->rchild;
		
		plr->lchild = pl;
		plr->rchild = p;
		pl->height = NodeHeight(pl);
		p->height = NodeHeight(p);
		plr->height = NodeHeight(plr);
		
		if (root == p)
			root = plr;
		
		return plr;
	}
	
	Node *RRRotation(Node *p) {
		Node *pr = p->rchild;
		Node *prl = pr->lchild;
		
		pr->lchild = p;
		p->rchild = prl;
		p->height = NodeHeight(p);
		pr->height = NodeHeight(pr);
		
		if (root == p)
			root = pr;
			
		return pr;
	}
	
	Node *RLRotation(Node *p) {
		Node *pr = p->rchild;
		Node *prl = pr->lchild;
		
		pr->lchild = prl->rchild;
		p->rchild = prl->lchild;
		
		prl->lchild = p;
		prl->rchild = pr;
		pr->height = NodeHeight(pr);
		p->height = NodeHeight(p);
		prl->height = NodeHeight(prl);
		
		if (root == p)
			root = prl;
		
		return prl;
	}
	
	Node *RInsert(int key) {return RInsert(root, key);}
	
	Node *RInsert(Node *p, int key) {
		Node *t = NULL;
		
		if (p == NULL) {
			t = new Node;
			t->data = key;
			t->height = 1;
			t->lchild = t->rchild = NULL;
			return t;
		}
		
		if (key < p->data) p->lchild = RInsert(p->lchild, key);
		else if (key > p->data) p->rchild = RInsert(p->rchild, key);
		p->height = NodeHeight(p);
		
		if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1)
			return LLRotation(p);
		else if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1)
			return LRRotation(p);
		else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == -1)
			return RRRotation(p);
		else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 1)
			return RLRotation(p);
		
		return p;
	}

	Node *Delete(Node *p, int x) {
		Node* q;
		p->height = NodeHeight(p);
		
		if (p == NULL)
			return NULL;
			
		if (p->lchild == NULL && p->rchild == NULL) {
			if (p == root)
				root = NULL;
			delete p;
			return NULL;
		}
		
		if (x < p->data)
			Delete(p->lchild, x);
		else if (x > p->data)
			Delete(p->rchild, x);
			
		if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1)
			return LLRotation(p);
		else if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1)
			return LRRotation(p);
		else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == -1)
			return RRRotation(p);
		else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 1)
			return RLRotation(p);
		else if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 0)
			return LLRotation(p);
		else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 0)
			return RRRotation(p);
	}
};

int main() {
	AVLTree avlt;
	
	avlt.root = avlt.RInsert(30);
	avlt.RInsert(40);
	avlt.RInsert(10);
	avlt.RInsert(5);
	avlt.RInsert(20);
	cout<<avlt.Delete(avlt.root, 40)->data;
	return 0;
	
}
