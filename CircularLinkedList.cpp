#include<iostream>

using namespace std;

class Node {
public:
	int data;
	Node *next;
};

class CircularLinkedList {
private:
	int length;
	Node *head;
	Node *tail;
public:
	CircularLinkedList() {
		length = 0;
		head = 0;
		tail = 0;
	}

	CircularLinkedList(int data) {
		length = 1;
		head = new Node;
		tail = head;
		head->data = data;
		tail->next = head;
	}
	
	~CircularLinkedList() {
		Node *p = head;
		while (head) {
			head = head->next;
			delete p;
			p = head;
		}
	}
	
	void Display() {
		Node *p = head;
		do {
			cout<<p->data<<" ";
			p = p->next;
		} while (p != head);
	}

	void RDisplay(Node *p) {
		static int flag = 0;
		if (p != head || flag == 0) {
			flag = 1;
			cout<<p->data<<" ";
			RDisplay(p->next);
		}
		flag = 0;
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
	
	void Insert(int x, int index) {
		if (index < 0 || index > length) return;
		Node *t = new Node;
		t->data = x;
		Node *p;
		if (index == 0) {
			if (head == 0) {
				head = t;
				tail = t;
				tail->next = head;
			} else {
				tail->next = t;
				t->next = head;
				head = t;
			}
		}
		else if (index == length) {
			tail->next = t;
			t->next = head;
			tail = t;
		}
		else {
			p = head;
			for (int i = 0; i < index - 1; i++) {
				p = p->next;
			}
			t->next = p->next;
			p->next = t;
		}
		length++;
	}
	
	int Delete(int index) {
		if (index < 0 || index > length - 1) return -1;
		int x;
		Node *p;
		Node *q;
		if (index == 0) {
			x = head->data;
			if (length == 1) {
				delete head;
				head = 0;
			} else {
				tail->next = head->next;
				delete head;
				head = tail->next;
			}
		} else {
			p = head;
			for (int i = 0; i < index - 1; i++) {
				p = p->next;
			}
			q = p->next;
			p->next = q->next;
			x = q->data;
			delete q;
		}
		length--;
		return x;
	}
};

int main() {
	CircularLinkedList cll(4);

	return 0;
}
