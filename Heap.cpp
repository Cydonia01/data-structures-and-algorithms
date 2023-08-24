#include <iostream>

using namespace std;

class Heap {
public:
	int *A;
	int length;
	int size;
	
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
};

void Heapify(int A[], int size) {
	int i, j, temp;
	for (i = size / 2; i > 0; i--) {
		j = i;
		while (j <= size / 2) {
			if (A[2 * j] > A[2 * j + 1] && A[2 * j] > A[j]) {
				temp = A[i];
				A[j] = A[2 * j];
				A[2 * j] = temp;
				j = 2 * j;
			}
			
			else if (A[2 * j + 1] > A[j]){
				temp = A[j];
				A[j] = A[2 * j + 1];
				A[2 * j + 1] = temp;
				j = 2 * j + 1;
			}
		}
	}
}

int main() {
	// index starts from 1. 0th index is placeholder. All of them is max heap and same array.
	
	int A[] = {0, 10, 20, 15, 12, 40, 25, 18};
	int size = 7, i;
	
	// Sample 1: Insertion manually.
	Heap h1(size);
	
	h1.Insert(10);h1.Insert(20);h1.Insert(15);h1.Insert(12);
	h1.Insert(40);h1.Insert(25);h1.Insert(18);
	
	cout<<"Max Heap: ";
	
	for (i = 1; i < h1.size; i++)
		cout<<h1.A[i]<<" ";
	
	cout<<endl<<endl<<endl;
	
	// Sample 2: Insertion Automatically, Deletion & Heap Sort.
	Heap h2(A, size);
	
	for (i = 1; i < h2.size; i++)
		cout<<"Deleted element: "<<h2.Delete()<<endl;
	
	cout<<endl<<"Sorted heap: ";
	
	for (i = 1; i < h1.size; i++)
		cout<<h2.A[i]<<" ";
	
	cout<<endl<<endl;
	
	// Sample 3: Heapify.
	Heapify(A, size);
	
	cout<<"Heap created via Heapify: ";
	
	for (i = 1; i < size + 1; i++)
		cout<<A[i]<<" ";
	
	cout<<endl;
	
	return 0;
}
