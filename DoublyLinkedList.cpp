#include<iostream>
#include<stdlib.h>

using namespace std;

class Node {
public:
	Node* prev;
	int data;
	Node* next;	
};

class DoublyLinkedList {
private:
	int length;
	Node* head;
	Node* tail;
public:
	DoublyLinkedList() {
		length = 0;
		head = 0;
		tail = 0;	
	}
	
	DoublyLinkedList(int x) {
		head = new Node;
		tail = head;
		head->prev = 0;
		head->next = 0;
		head->data = x;
		length = 1;
	}
	
	~DoublyLinkedList() {
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
		while (p) {
			cout<<p->data<<" ";
			p = p->next;
		}
		cout<<endl;
	}
	
	void Insert(int x, int index) {
		if (index < 0 || index > length)
			return;
			
		Node *t, *p;
		
		t = new Node;
		t->data = x;
		t->next = t->prev = 0;
		
		if (index == 0) {
			if (head == 0) 
				head = tail = t;
			else {
				t->prev = 0;
				t->next = head;
				head->prev = t;
				head = t;
			}
		} 
		else if (index == length) {
			tail->next = t;
			t->prev = tail;
			tail = t;
		}
		else {
			p = head;
			for (int i = 0; i < index - 1; i++)
				p = p->next;

			t->next = p->next;
			t->prev = p;
			
			if (p->next)
				p->next->prev = t;
				
			p->next = t;
		}
		length++;
	}
	
	int Delete(int index) {
		if (index < 0 || index > length - 1)
			return -1;
			
		int x;
		Node *p;
		
		if (index == 0) {
			p = head;
			head = head->next;
			x = p->data;
			delete p;
			
			if (head)
				head->prev = 0;
		} else {
			p = head;
			for (int i = 0; i < index; i++)
				p = p->next;

			p->prev->next = p->next;
			
			if (p->next)
				p->next->prev = p->prev;
				
			x = p->data;
			delete p;
		}
		length--;
		return x;
	}
	
	void Reverse() {
		Node *p, *temp;
		p = head;
		tail = head;
		while (p) {
			temp = p->next;
			p->next = p->prev;
			p->prev = temp;
			p = p->prev;
			if (p != 0 && p->next == 0)
				head = p;
		}
	}
};

int main() {
	// Sample:
	DoublyLinkedList dll;
	dll.Insert(3, 0);
	dll.Insert(6, 0);
	dll.Insert(2, 1);
	dll.Insert(8, 2);
	dll.Insert(11, 3);
	dll.Insert(5, 1);
	
	dll.Display();

	dll.Delete(2);
	dll.Delete(0);
	
	dll.Display();
	
	dll.Reverse();
	
	dll.Display();
	return 0;
}
