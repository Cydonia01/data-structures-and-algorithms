#include<iostream>

/* This program is Queue using linked list. */

using namespace std;

class Node {
public:
	int data;
	Node *next;
};

// 'f' and 'r' are 'front' and 'rear'.
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
		
		if (t == NULL)
			cout<<"Queue is Full.\n";
			
		else {
			t->data = x;
			t->next = NULL;
			
			if (f == NULL) 
				f = t;
				
			else
				r->next = t;
			
			r = t;
		}
	}
	
	int dequeue() {
		Node *p;
		int x = -1;
		
		if (isEmpty())
			cout<<"Queue is empty.\n";
			
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
	
	int front() {
		return f->data;
	}
	
	int rear() {
		return r->data;
	}
};

int main() {
	// Sample:
	QueueLinkedList q;
	q.enqueue(3);
	q.enqueue(6);
	q.enqueue(2);
	q.enqueue(5);
	
	q.Display();
	
	cout<<"Deleted element is "<<q.dequeue()<<endl;
	
	q.Display();
	
	cout<<"Front element is "<<q.front()<<endl;
	cout<<"Rear element is "<<q.rear()<<endl;
	return 0;
}
