#include<iostream>
#ifndef TreeQueue_h
#define TreeQueue_h

/* This file is Queue data structure adapted to the trees. Node class contains left and right pointers
instead of just next. Also, main array contains Node pointers instead of int. */

using namespace std;

class Node {
public:
	Node *left;
	int data;
	Node *right;
};

class TreeQueue {
private:
	int size;
	int front;
	int rear;
	Node **A;
public:
	TreeQueue() {
		front = rear = 0;
		size = 10;
		A = new Node*[size];
	}
	
	TreeQueue(int size) {
		this->size = size;
		front = rear = 0;
		A = new Node*[size];
	}

	void enqueue(Node* p) {
		if (isFull())
			cout<<"Queue is full.";
		else {
			rear = (rear + 1) % size;
			A[rear] = p;
		}
	}
	
	Node* dequeue() {
		Node* p = NULL;
		if (isEmpty())
			cout<<"Queue is empty.\n";
		else {
			front = (front + 1) % size;
			p = A[front];
		}
		return p;
	}
	
	int isEmpty() {
		return front == rear;
	}
	
	int isFull() {
		return (rear + 1) % size == front;
	}
};

#endif

