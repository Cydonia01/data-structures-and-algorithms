#include<iostream>
#include<stdlib.h>

using namespace std;

class Node {
public:
	int data;
	Node* next;
};

class StackLinkedList {
public:
	Node *top;
	
	StackLinkedList(){
		top = NULL
	}
	
	~StackLinkedList() {
		Node *p = top;
		while (top) {
			top = top->next;
			delete p;
			p = head;
		}
	}
	
	void push(int x) {
		Node *t = new Node;
		if (t == NULL) cout<<"Stack Overflow";
		else {
			t->data = x;
			t->next = top;
			top = t;
		}
	}
	
	int pop() {
		int x = -1;
		if (top == NULL) cout<<"Stack is Empty ";
		else {
			Node *p = top;
			top = top->next;
			x = p->data;
			delete p;
		}
		return x;
	}
	
	int peek(int pos) {
		Node *p = top;
		for (int i = 0; p != NULL && i < pos - 1; i++) {
			p = p->next;
		}
		if (p != NULL) return p->data;
		else return -1;
	}
	
	int StackTop() {
		if (top) return top->data;
		return -1;
	}
	
	int isEmpty() {
		return top?0:1;
	}
	
	int isFull() {
		Node *t = new Node;
		int r = t?0:1;
		free(t);
		return r;
	}
	
	void Display() {
		Node *p;
		p = top;
		while (p != NULL) {
			cout<<p->data<<" ";
			p = p->next;
		}
	}
	
};

int main() {
	
	return 0;
}
