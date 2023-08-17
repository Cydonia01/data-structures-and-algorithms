#include<iostream>
#include "AVLQueue.h"

using namespace std;

/* Node class in in AVLQueue.h header file. */

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

	// Helper methods for Rotations.
	int NodeHeight(Node *p) {
		int hl, hr;
		
		if (p == NULL)
			return 0;
		
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
	
	// Inorder predecessor of a node.
	Node* InPre(Node *p) {
		while (p && p->rchild)
			p = p->rchild;
		return p;
	}
	
	// Inorder successor of a node.
	Node* InSucc(Node *p) {
		while (p && p->lchild)
			p = p->lchild;
		return p;
	}
	
	void Levelorder() {Levelorder(root);}
	
	void Levelorder(Node *p) {
		AVLQueue q(20);
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
	
	// This function recursively inserts an item and makes necessary rotations.
	Node *RInsert(Node *p, int key) {
		Node *t = NULL;
		
		if (p == NULL) {
			t = new Node;
			t->data = key;
			t->height = 1;
			t->lchild = t->rchild = NULL;
			return t;
		}
		
		if (key < p->data)
			p->lchild = RInsert(p->lchild, key);
			
		else if (key > p->data)
			p->rchild = RInsert(p->rchild, key);
		
		p->height = NodeHeight(p);
		
		int balance = BalanceFactor(p);
		
		if (balance == 2 && BalanceFactor(p->lchild) == 1)
			return LLRotation(p);
			
		if (balance == 2 && BalanceFactor(p->lchild) == -1)
			return LRRotation(p);
			
		if (balance == -2 && BalanceFactor(p->rchild) == -1)
			return RRRotation(p);
			
		if (balance == -2 && BalanceFactor(p->rchild) == 1)
			return RLRotation(p);
		
		return p;
	}
	
	Node *Delete(int key) {return Delete(root, key);}
	
	// This functions deletes an item and makes necessary rotations.
	Node *Delete(Node *p, int key) {
		Node* q;
		
		if (p == NULL)
			return NULL;
			
		if (p->lchild == NULL && p->rchild == NULL) {
			if (p == root)
				root = NULL;
			delete p;
			return NULL;
		}
		
		if (key < p->data)
			p->lchild = Delete(p->lchild, key);
			
		else if (key > p->data)
			p->rchild = Delete(p->rchild, key);
			
		else {
			if (NodeHeight(p->lchild) > NodeHeight(p->rchild)) {
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
		
		p->height = NodeHeight(p);
		
		int balance = BalanceFactor(p);
		
		if (balance == 2 && BalanceFactor(p->lchild) >= 0)
			return LLRotation(p);
		
		if (balance == 2 && BalanceFactor(p->lchild) < 0)
			return LRRotation(p);
		
		if (balance == -2 && BalanceFactor(p->rchild) <= 0)
			return RRRotation(p);
		
		if (balance == -2 && BalanceFactor(p->rchild) > 0)
			return RLRotation(p);
			
		return p;
	}
};

int main() {
	// to make it simple, height of the root is 1.
	AVLTree avlt;
	
	avlt.root = avlt.RInsert(30);
	avlt.RInsert(40);
	avlt.RInsert(10);
	avlt.RInsert(20);
	avlt.RInsert(5);
	avlt.RInsert(35);
	avlt.RInsert(2);
	
	cout<<"First Tree:"<<endl;
	avlt.Levelorder();
	
	avlt.Delete(20);
	cout<<endl<<endl<<"After Deleting 20:"<<endl;
	avlt.Levelorder();
	
	avlt.Delete(35);
	cout<<endl<<endl<<"After Deleting 35:"<<endl;
	avlt.Levelorder();
	
	avlt.Delete(40);
	cout<<endl<<endl<<"After Deleting 40:"<<endl;
	avlt.Levelorder();
	return 0;
}
