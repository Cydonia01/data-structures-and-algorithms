#include<iostream>
#include<stdlib.h>

using namespace std;

class Node {
public:
	Node* prev;
	int data;
	Node* next;	
};

class CircularDoublyLinkedList {
private:
	int length;
	Node* head;
	Node* tail;
public:
	CircularDoublyLinkedList() {
		length = 0;
		head = 0;
		tail = 0;	
	}
	
	CircularDoublyLinkedList(int x) {
		length = 1;
		head = new Node;
		tail = head;
		head->prev = tail;
		head->next = head;
		head->data = x;
	}
	
	~CircularDoublyLinkedList() {
		Node *p = head;
		while (head) {
			head = head->next;
			delete p;
			p = head;
		}
	}
	
	Node* getHead() {
		return head;
	}
	
	Node* getTail() {
		return tail;
	}
	
	int getLength() {
		return length;
	}
	
	void Display() {
		Node *p = head;
		do {
			cout<<p->data<<" ";
			p = p->next;
		} while (p != head);
	}
	
	void Insert(int x, int index) {
		if (index < 0 || index > length) return;
		Node *t = new Node;
		Node *p;
		t->data = x;
		if (index == 0) {
			if (head == 0) {
				head = tail = t;
				head->next = t;
				head->prev = t;
			} else {
				t->prev = tail;
				t->next = head;
				tail->next = t;
				head->prev = t;
				head = t;
			}
		} 
		else if (index == length) {
			tail->next = t;
			t->prev = tail;
			t->next = head;
			head->prev = t;
			tail = t;
		}
		else {
			p = head;
			for (int i = 0; i < index - 1; i++) {
				p = p->next;
			}
			t->next = p->next;
			t->prev = p;
			if (p->next) p->next->prev = t;
			p->next = t;
		}
		length++;
	}
	
	int Delete(int index) {
		if (index < 0 || index > length - 1) return -1;
		int x;
		Node *p;
		if (index == 0) {
			p = head;
			head = head->next;
			head->prev = tail;
			tail->next = head;
			x = p->data;
			delete p;
		} else {
			p = head;
			for (int i = 0; i < index; i++) {
				p = p->next;
			}
			p->prev->next = p->next;
			if (p->next) p->next->prev = p->prev;
			x = p->data;
			delete p;
		}
		length--;
		return x;
	}
};

int main() {
	CircularDoublyLinkedList cll;

	return 0;
}
