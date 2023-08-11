#include<iostream>

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
		top = NULL;
	}
	
	~StackLinkedList() {
		Node *p = top;
		while (top != NULL) {
			top = top->next;
			delete p;
			p = top;
		}
	}
	
	void push(int x) {
		Node *t = new Node;
		if (t == NULL)
			cout<<"Stack Overflow";
		else {
			t->data = x;
			t->next = top;
			top = t;
		}
	}
	
	int pop() {
		int x = -1;
		if (top == NULL)
			cout<<"Stack is Empty";
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
		for (int i = 0; p != NULL && i < pos - 1; i++)
			p = p->next;
			
		if (p != NULL)
			return p->data;
		else
			return -1;
	}
	
	int StackTop() {
		if (top)
			return top->data;
		return -1;
	}
	
	int isEmpty() {
		return top?0:1;
	}
	
	int isFull() {
		Node *t = new Node;
		int r = t?0:1;
		delete t;
		return r;
	}
	
	void Display() {
		Node *p;
		p = top;
		while (p != NULL) {
			cout<<p->data<<" ";
			p = p->next;
		}
		cout<<endl;
	}
};

int main() {
	// Sample: position starts with 1.
	StackLinkedList st;
	st.push(2);
	st.push(4);
	st.push(5);
	st.push(1);
	
	st.Display();
	
	cout<<"element at second position is "<<st.peek(2)<<endl;
	cout<<"top element is "<<st.StackTop()<<endl;
	cout<<"Deleted element is "<<st.pop()<<endl;
	st.Display();
	return 0;
}
