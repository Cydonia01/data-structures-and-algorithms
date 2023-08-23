#include <iostream>

using namespace std;

// Node class for bucket sort and radix sort.
class Node {
public:
	int data;
	Node *next;
};

void Display(int A[], int size) {
	for (int i = 0; i < size; i++)
		cout<<A[i]<<" ";
	cout<<endl<<endl;
}

// helper method for some sorting methods.
void swap(int *x, int *y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}


void BubbleSort(int A[], int size) {
	int flag;
	for (int i = 0; i < size - 1; i++) {
		flag = 0;
		for (int j = 0; j < size - 1 - i; j++) {
			if (A[j] > A[j + 1]) {
				swap(&A[j], &A[j + 1]);
				flag = 1;
			}
		}
		if (flag == 0) break;
	}
}


void InsertionSort(int A[], int size) {
	int temp;
	int i, j, x;
	
	for (i = 1; i < size; i++) {
		j = i - 1;
		x = A[i];
		while (j >= 0 && A[j] > x) {
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = x;
	}
}


void SelectionSort(int A[], int size) {
	int i, j, k;
	for (i = 0; i < size - 1; i++) {
		k = i;
		for (j = i + 1; j < size; j++) {
			if (A[j] < A[k])
				k = j;
		}
		swap(&A[i], &A[k]);
	}
}

// helper method for quick sort. 'l' is for 'low'; h is for 'high'.
int Partition(int A[], int l, int h) {
	int pivot = A[l];
	int i = l, j = h;
	
	do {
		do {i++;} while (A[i] <= pivot);
		do {j--;} while (A[j] > pivot);
		
		if (i < j) swap(&A[i], &A[j]);
	} while (i < j);
	
	swap(&A[l], &A[j]);
	return j;
}


void QuickSort(int A[], int l, int h) {
	int j;
	
	if (l < h) {
		j = Partition(A, l, h);
		QuickSort(A, l, j);
		QuickSort(A, j + 1, h);
	}
}

// helper method for merge sort.
void Merge(int A[], int l, int mid, int h) {
	int B[h + 1];
	int i, j, k;
	
	i = l;
	j = mid + 1;
	k = l;
	
	while (i <= mid && j <= h) {
		if (A[i] < A[j])
			B[k++] = A[i++];
		else
			B[k++] = A[j++];
	}
	
	for (; i <= mid; i++)
		B[k++] = A[i];
	
	for (; j <= h; j++)
		B[k++] = A[j];
	
	for (i = l; i <= h; i++)
		A[i] = B[i];
}

// iterative merge sort.
void IMergeSort(int A[], int size) {
	int p, i, l, mid, h;
	
	for (p = 2; p <= size; p = p * 2) {
		for (i = 0; i + p - 1 < size; i = i + p) {
			l = i;
			h = i + p - 1;
			mid = (l + h) / 2;
			Merge(A, l, mid, h);
		}
	}
	if (p / 2 < size)
		Merge(A, 0, p / 2 - 1, size - 1); 
}

// recursive merge sort.
void RMergeSort(int A[], int l, int h) {
	int mid;
	if (l < h) {
		mid = (l + h) / 2;
		RMergeSort(A, l, mid);
		RMergeSort(A, mid + 1, h);
		Merge(A, l, mid, h);
	}
}

// helper method for some sorting methods.
int findMax(int A[], int size) {
	int max = INT_MIN;
	int i;
	for (i = 0; i < size; i++) {
		if (A[i] > max)
			max = A[i];
	}
	return max;
}


void CountSort(int A[], int size) {
	int max, i, j, *C;
	max = findMax(A, size);
	
	C = new int[max + 1];
	
	for (i = 0; i < max + 1; i++)
		C[i] = 0;
	
	for (i = 0; i < size; i++)
		C[A[i]]++;
	
	i = j = 0;
	
	while (i < max + 1) {
		if (C[i] > 0) {
			A[j++] = i;
			C[i]--;
		}
		else
			i++;
	}
}

// helper method bucket sort and radix sort.
void Insert(Node* &p, int x) {
	Node *t, *q;
	t = new Node;
	t->data = x;
	t->next = NULL;
	
	if (p == NULL)
		p = t;
		
	else {
		q = p;
		while (q->next)
			q = q->next;
			
		q->next = t;
	}
}

// helper method bucket sort and radix sort.
int Delete(Node* &p) {
	Node *q;
	int x;
	
	q = p;
	x = p->data;
	p = p->next;
	delete q;
	return x;
}


void BucketSort(int A[], int size) {
	int max, i, j;
	Node* *Bins;
	max = findMax(A, size);
	Bins = new Node*[max + 1];
	
	for (i = 0; i < max + 1; i++)
		Bins[i] = NULL;
		
	for (i = 0; i < size; i++)
		Insert(Bins[A[i]], A[i]);
	
	i = 0; j = 0;
	
	while (i < max + 1) {
		while (Bins[i] != NULL)
			A[j++] = Delete(Bins[i]);
		i++;
	}
}


void RadixSort(int A[], int size) {
	int max, i, j, div, index;
	Node* *Bins;
	max = findMax(A, size);
	
	Bins = new Node*[10];
	
	for (i = 0; i < 10; i++)
		Bins[i] = NULL;
	
	div = 1;
	
	while (div <= max) {
		j = 0;
		
		for (i = 0; i < size; i++) {
			index = (A[i] / div) % 10;
			Insert(Bins[index], A[i]);
		}
	
		i = 0; j = 0;
		
		while (i < 10) {
			while (Bins[i] != NULL)
				A[j++] = Delete(Bins[i]);
			i++;
		}
		div = div * 10;
	}
}


void ShellSort(int A[], int size) {
	int gap, i, j, temp;
	for (gap = size / 2; gap >= 1; gap /= 2) {
		for (i = gap; i < size; i++) {
			temp = A[i];
			j = i - gap;
			while (j >= 0 && A[j] > temp) {
				A[j + gap] = A[j];
				j = j - gap;
			}
			A[j + gap] = temp;
		}
	}
}

int main() { 
	int A[] = {1, 4, 2, 5, 3, 7, 11, 8, 12, 4};
	BubbleSort(A, sizeof(A) / sizeof(int));
	cout<<"Bubble Sort: ";
	Display(A, sizeof(A) / sizeof(int));
	
	int B[] = {13, 3, 11, 5, 4, 7, 12, 1, 2, 5};
	InsertionSort(B, sizeof(B) / sizeof(int));
	cout<<"Insertion Sort: ";
	Display(B, sizeof(B) / sizeof(int));
	
	int C[] = {5, 1, 6, 11, 7, 2, 12, 4, 15, 7};
	SelectionSort(C, sizeof(C) / sizeof(int));
	cout<<"Selection Sort: ";
	Display(C, sizeof(C) / sizeof(int));
	
	int D[] = {3, 7, 4, 2, 8, 13, 11, 8, 12, 8, INT_MAX};
	QuickSort(D, 0, sizeof(D) / sizeof(int) - 1);
	cout<<"Quick Sort: ";
	Display(D, sizeof(D) / sizeof(int) - 1);
	
	int E[] = {6, 14, 22, 2, 8, 3, 11, 13, 12, 11};
	IMergeSort(E, sizeof(E) / sizeof(int));
	cout<<"Iterative Merge Sort: ";
	Display(E, sizeof(E) / sizeof(int));
	
	int F[] = {3, 1, 6, 11, 8, 13, 7, 15, 9, 13};
	RMergeSort(F, 0, sizeof(F) / sizeof(int) - 1);
	cout<<"Recursive Merge Sort: ";
	Display(F, sizeof(F) / sizeof(int));
	
	int G[] = {5, 3, 1, 7, 5, 9, 12, 4, 13, 17};
	CountSort(G, sizeof(G) / sizeof(int));
	cout<<"Count Sort: ";
	Display(G, sizeof(G) / sizeof(int));
	
	int H[] = {7, 1, 4, 4, 5, 8, 4, 6, 13, 11};
	BucketSort(H, sizeof(H) / sizeof(int));
	cout<<"Bucket Sort: ";
	Display(H, sizeof(H) / sizeof(int));
	
	int I[] = {169, 324, 246, 14, 42, 313, 117, 426, 234};
	RadixSort(I, sizeof(I) / sizeof(int));
	cout<<"Radix Sort: ";
	Display(I, sizeof(I) / sizeof(int));
	
	int J[] = {14, 4, 22, 15, 33, 47, 21, 13, 7};
	ShellSort(J, sizeof(J) / sizeof(int));
	cout<<"Shell Sort: ";
	Display(J, sizeof(J) / sizeof(int));
	
	return 0;
}
