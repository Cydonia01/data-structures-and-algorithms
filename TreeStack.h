#include<iostream>
#include "TreeQueue.h"
#ifndef TreeStack_h
#define TreeStack_h

/* This file is Stack data structure adapted to the trees. For example, stack contains Node pointers
instead of int. Node class is in TreeQueue.h header file. */

using namespace std;

class TreeStack {
public:
	int size;
	Node **A;
	int top;
	
	TreeStack(int size) {
		this->size = size;
		A = new Node*[size];
		top = -1;
	}
	
	~TreeStack() {
		delete []A;
	}
	
	void push(Node* x) {
		if (isFull())
			cout<<"Stack Overflow";
		else A[++top] = x;
	}
	
	Node* pop() {
		Node *x = NULL;
		if (isEmpty()) {
			cout<<"Stack Underflow ";
			return x;
		}
		else {
			x = A[top];
			A[top--] = 0;
			return x;
		}
	}
	
	Node* peek(int pos) {
		int index = top - pos + 1;
		
		if (index < 0 || index > top) {
			cout<<"Invalid Position ";
			return NULL;
		}
		else return A[index];
	}
	
	Node* StackTop() {
		if (top == -1)
			return NULL;
		return A[top];
	}
	
	int isEmpty() {
		return (top == -1);
	}
	
	int isFull() {
		return (top == size - 1);
	}
	
	void Display() {
		for (int i = 0; i < top + 1; i++)
			cout<<A[i]<<" ";
	}
};

#endif
