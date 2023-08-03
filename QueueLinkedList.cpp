#include<iostream>

using namespace std;

class Node {
public:
	int data;
	Node *next;
};

class QueueLinkedList {
private:
	int length;
	Node *f, *r;
public:
	QueueLinkedList() {
		length = 0;
		f = r = NULL;
	}
	
	~QueueLinkedList() {
		Node *p = f;
		while (f) {
			f = f->next;
			delete p;
			p = f;
		}
	}

	void Display() {
		Node *p = f;
		while (p) {
			cout<<p->data<<" ";
			p = p->next;
		}
		cout<<endl;
	}
	
	void enqueue(int x) {
		Node *t = new Node;
		if (t == NULL) cout<<"Queue is Full.\n";
		else {
			t->data = x;
			t->next = NULL;
			if (f == NULL) f = r = t;
			else {
				r->next = t;
				r = t;
			}
		}
	}
	
	int dequeue() {
		int x = -1;
		Node *p;
		if (f == NULL) cout<<"Queue is empty.\n";
		else {
			p = f;
			f = f->next;
			x = p->data;
			delete p;
		}
		return x;
	}
	
	int isEmpty() {
		return (f == NULL);
	}
	
	int isFull() {
		Node *t = new Node;
		return (t == NULL);
	}
	
	int first() {
		return f->data;
	}
	
	int last() {
		return r->data;
	}
};

int main() {
	
	return 0;
}
