#include <iostream>

using namespace std;

class Node {
public:
	int data;
	Node* next;
};

class Chaining {
private:
	Node **HT;
public:
	Chaining() {
		HT = new Node*[10];
		
		for (int i = 0; i < 10; i++)
			HT[i] = NULL;
	}
	
	Chaining(int A[], int size) {
		HT = new Node*[10];
		
		for (int i = 0; i < 10; i++)
			HT[i] = NULL;
		
		for (int i = 0; i < size; i++) 
			InsertSorted(A[i]);
	}
	
	~Chaining() {
		delete HT;
	}
	
	void Display() {
		Node *p;
		int i;
		cout<<"Hash Table: "<<endl;
		for (i = 0; i < 10; i++) {
			if (HT[i] != NULL) {
				p = HT[i];
				cout<<p->data;
				while (p->next != NULL) {
					p = p->next;
					cout<<" "<<p->data;
				}
			}
			cout<<endl;
		}
	}
	
	int hashing(int key) {
		return key % 10;
	}
	
	void InsertSorted(int key) {
		Node *t, *q, *f;
		int index = hashing(key);
		
		t = new Node;
		t->data = key;
		t->next = NULL;
		
		if (HT[index] == NULL)
			HT[index] = t;
			
		else {
			q = NULL;
			f = HT[index];
			
			while (f != NULL && key > f->data) {
				q = f;
				f = f->next;
			}
			
			if (f == HT[index]) 
				HT[index] = t;
				
			else
				q->next = t;
				
			t->next = f;
		}
	}
	
	int Search(int key) {
		Node *p = HT[hashing(key)];
		if (p == NULL) return 0;
		while (p != NULL) {
			if (p->data == key)
				return 1;
			p = p->next;
		}
		return 0;
	}
};

int main() {
	// Sample 1:
	Chaining ch;
	int x;
	ch.InsertSorted(10);ch.InsertSorted(32);ch.InsertSorted(23);ch.InsertSorted(54);ch.InsertSorted(85);ch.InsertSorted(96);ch.InsertSorted(36);ch.InsertSorted(17);
	ch.InsertSorted(38);ch.InsertSorted(59);ch.InsertSorted(41);ch.InsertSorted(7);ch.InsertSorted(3);ch.InsertSorted(2);ch.InsertSorted(28);ch.InsertSorted(35);
	
	ch.Display();
	
	cout<<"which number do you seek? ";
	cin>>x;
	if (ch.Search(x)) 
		cout<<x<<" is found.";
	else
		cout<<x<<" is not found.";
	
	cout<<endl<<endl;
	
	// Sample 2:
	int A[] = {16, 12, 25, 39, 6, 122, 5, 68, 75};
	
	Chaining ch1(A, sizeof(A) / sizeof(int));
	
	ch1.Display();
	
	cout<<"which number do you seek? ";
	cin>>x;
	if (ch1.Search(x)) 
		cout<<x<<" is found.";
	else
		cout<<x<<" is not found.";

	return 0;
}
