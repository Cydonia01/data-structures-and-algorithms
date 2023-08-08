#include<iostream>
#include "Node.h"
#ifndef LinkedList_h
#define LinkedList_h

using namespace std;

class LinkedList {
private:
	int length;
	Node *head = new Node();
	Node *tail = head;
public:
	LinkedList();
	LinkedList(int data);
	~LinkedList();
	
	void Display();
	void append(int x);
	void ReverseDisplay(Node *p);
	int getLength();
	Node* getHead();
	Node* getTail();
	int sum();
	int max();
	int RMax(Node *p);
	Node* search(int key);
	Node* ImprovedSearch(int key);
	void Insert(int x, int p);
	void InsertSorted(int x);
	int Delete(int index);
	int isSorted();
	void removeDuplicates();
	void reverseData();
	void reverseLinks();
	void RReverseLinks(Node *p, Node *q);
	void Concatenate(LinkedList ll2);
	void Merge(LinkedList ll2);
	int isLoop();
	void ReverseDisplay2();
};

LinkedList::LinkedList() {
	length = 0;
	head = 0;
	tail = 0;
}

LinkedList::LinkedList(int data) {
	length = 1;
	head->data = data;
	head->next = 0;
}

LinkedList::~LinkedList() {
	Node *p = head;
	while (head) {
		head = head->next;
		delete p;
		p = head;
	}
}

void LinkedList::append(int x) {
	Node *t = new Node();
	t->data = x;
	t->next = 0;
	if (head == 0) {
		head = tail = t;
	}
	else {
		tail->next = t;
		tail = t;	
	}
	length++;
}

void LinkedList::Display() {
	Node *p = head; 
	while(p != 0) {
		cout<<p->data<<" ";
		p = p->next;
	}
}

void LinkedList::ReverseDisplay(Node *p) {
	if (p != 0) {
		ReverseDisplay(p->next);
		cout<<p->data<<" ";
	}
}

int LinkedList::getLength() {
	return length;
}

Node* LinkedList::getHead() {
	
	return head;
}

Node* LinkedList::getTail() {
	return tail;
}

int LinkedList::sum() {
	Node *p = head; 
	int sum = 0;
	while(p != 0) {
		sum += p->data;
		p = p->next;
	}
	return sum;
}

int LinkedList::max() {
	Node *p = head;
	int max = INT_MIN;
	while(p != 0) {
		if (p->data > max) {
			max = p->data;
		}
		p = p->next;
	}
	return max;
}

int LinkedList::RMax(Node *p) {
	int x = 0;
	if (p == 0) return INT_MIN;
	x = RMax(p->next);
	if (x > p->data) return x;
	else return p->data;
}

Node* LinkedList::search(int key) {
	Node *p = head;
	while (p != 0) {
		if (key == p->data) return p;

		p = p->next;
	}
	return NULL;
}

Node* LinkedList::ImprovedSearch(int key) {
	Node *p = head;
	Node *q = NULL;
	while (p != 0) {
		if (key == p->data) {
			q->next = p->next;
			p->next = head;
			head = p;
		}
		q = p;
		p = p->next;
	}
	return NULL;
}

void LinkedList::Insert(int x, int index) {
	Node *t, *p;
	if (index < 0 || index > length) return;
	t = new Node;
	t->data = x;
	if (length == 0) {
		head = tail = t;
	}
	else if (index == 0) {
		t->next = head;
		head = t;
	}
	else {
		p = head;
		for (int i = 0; i < index - 1; i++)
			p = p->next;
		
		t->next = p->next;
		p->next = t;
	}
	length++;	
}

void LinkedList::InsertSorted(int x) {
	Node *t, *p, *q = 0;
	t = new Node;
	t->data = x;
	t->next = 0;
	p = head;
	
	if (head == 0) head = t;
	
	else {
		while (p && p->data < x) {
			q = p;
			p = p->next;
		}
		if (p == head) {
			t->next = head;
			head = t;
		}
		else {
			t->next = q->next;
			q->next = t;
		}
	}
	length++;
}

int LinkedList::Delete(int index) {
	Node *p, *q;
	p = head;
	if (index < 0 || index > length - 1) return -1;
	
	if (index == 0)
		head = head->next;
	else {
		for (int i = 0; i < index; i++) {
			q = p;
			p = p->next;
		}
		q->next = p->next;
	}
	int x = p->data;
	delete p;
	length--;
	return x;
}

int LinkedList::isSorted() {
	Node *p = head;
	while (p->next != 0) {
		if (p->data > p->next->data) {
			return false;
		}
		p = p->next;
	}
	return true;
}

void LinkedList::removeDuplicates() {
	Node *p = head;
	Node *q = head->next;
	
	while (q != 0) {
		if (p->data == q->data) {
			p->next = q->next;
			delete q;
			q = p->next;
			length--;
		}
		else {
			p = q;
			q = q->next;
		}
	}
}

void LinkedList::reverseData() {
	Node *p = head;
	int A[length];
	int i;
	for (i = 0; i < length; i++) {
		A[i] = p->data;
		p = p->next;
	}
	p = head;
	for (i = length - 1; i >= 0; i--) {
		p->data = A[i];
		p = p->next;
	}
}

void LinkedList::reverseLinks() {
	Node *p, *r, *q;
	p = head; q = 0; r = 0;
	
	while (p != 0) {
		r = q;
		q = p;
		p = p->next;
		q->next = r;
	}
	head = q;
}

void LinkedList::RReverseLinks(Node *p, Node *q) {
	if (p != 0) {
		RReverseLinks(p->next, p);
		p->next = q;
	}
	else
		head = q;
}

void LinkedList::Concatenate(LinkedList ll2) {
	tail->next = ll2.getHead();
	length += ll2.getLength();
}

void LinkedList::Merge(LinkedList ll2) {
	Node *first, *second, *third, *last;
	first = head;
	second = ll2.head;
	third = 0;
	last = 0;
	if (first->data < second->data) {
		third = last = first;
		first = first->next;
		last->next = 0;
	} else {
		third = last = second;
		second = second->next;
		last->next = 0;
	}
	while (first != 0 && second != 0) {
		if (first->data < second->data) {
			last->next = first;
			last = first;
			first = first->next;
			last->next = 0;
		} else {
			last->next = second;
			last = second;
			second = second->next;
			last->next = 0;
		}
		
	}
	if (first != 0) last->next = first;
	else last->next = second;
	head = third;
	length += ll2.getLength();
}

int LinkedList::isLoop()  {
	Node *p, *q;
	p = q = head;
	while (p && q) {
		q = q->next;
		p = p->next->next;
		if (p == q)
			return 1;
	}
	return 0;
}

void LinkedList::ReverseDisplay2() {
	Node *q;
	for (int i = 0; i < length; i++) {
		q = head;
		for (int j = 0; j < length - i - 1; j++) {
			q = q->next;
		}
		cout<<q->data<<" ";
	}
}

int getMiddle(LinkedList list) {
	Node *p = list.getHead();
	int length = list.getLength();
	for (int i = 0; i < length / 2; i++) {
		p = p->next;
	}
	return p->data;
}

int getMiddleV2(LinkedList list) {
	Node *p, *q;
	p = q = list.getHead();
	
	while (q) {
		q= q->next;
		if (q) q = q->next;
		if (q) p = p->next;
	}
	return p->data;
}

#endif
