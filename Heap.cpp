#include <iostream>

using namespace std;

class Node {
public:
	Node* lchild;
	int data;
	Node* rchild;
};

class Heap {
public:
	int *A;
	int length;
	int size;
	
	Heap() {
		
	}
	
	Heap(int size) {
		this->size = size + 1;
		A = new int[size + 1];
		length = 0;
	}

	Heap(int B[], int size) {
		this->size = size + 1;
		A = new int[size + 1];
		length = 0;
		
		for (int i = 1; i <= 7; i++) 
			Insert(B[i]);
	}
	
	void Insert(int x) {
		int i = length + 1;
	
		while (i > 1 && x > A[i/2]) {
			A[i] = A[i/2];
			i = i/2;
		}
		
		A[i] = x;
		length++;
	}
	
	int Delete() {
		int last, i, j, first, temp;
		last = A[length];
		first = A[1];
		
		A[1] = A[length];
		A[length] = first;
		
		i = 1; j = 2 * i;
		
		while (j < length - 1) {
			if (A[j + 1] > A[j])
				j = j + 1;
			if (A[i] < A[j]) {
				temp = A[i];
				A[i] = A[j];
				A[j] = temp;
				i = j;
				j = 2 * j;
			}
			else break;
		}
		
		length--;
		return first;
	}
	
	void Heapify() {
		int i, j, temp;
		i = (size - 1) / 2;
		j = 2 * i;
		for (i; i > 0; i++) {
			while (i != 0) {
				if (A[j + 1] > A[j])
					j = j + 1;
				if (A[i] < A[j]) {
					temp = A[i];
					A[i] = A[j];
					A[j] = temp;
					i
				}
			}
			
		}
	}
	
};

int main() {
	int A[] = {0, 10, 20, 30, 25, 5, 40, 35};
	Heap h(A, 7);
	
	for (int i = 1; i < h.size; i++)
		cout<<"Deleted element is "<<h.Delete()<<endl;
	
	cout<<"Sorted heap is ";

	for (int i = 1; i < h.size; i++)
		cout<<h.A[i]<<" ";

	return 0;
}
