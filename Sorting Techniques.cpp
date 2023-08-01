#include <iostream>

using namespace std;

class Node {
public:
	int data;
	Node *next;
};

void swap(int *x, int *y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

void BubbleSort(int A[], int n) {
	int flag;
	for (int i = 0; i < n - 1; i++) {
		flag = 0;
		for (int j = 0; j < n - 1 - i; j++) {
			if (A[j] > A[j + 1]) {
				swap(&A[j], &A[j + 1]);
				flag = 1;
			}
		}
		if (flag == 0) break;
	}
}

void InsertionSort(int A[], int n) {
	int temp;
	int i, j, x;
	
	for (i = 1; i < n; i++) {
		j = i - 1;
		x = A[i];
		while (j >= 0 && A[j] > x) {
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = x;
	}
}

void SelectionSort(int A[], int n) {
	int i, j, k;
	for (i = 0; i < n - 1; i++) {
		k = i;
		for (j = i + 1; j < n; j++) {
			if (A[j] < A[k])
				k = j;
		}
		swap(&A[i], &A[k]);
	}
}

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

int* Merge(int A[], int l, int mid, int h) {
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

void IMergeSort(int A[], int n) {
	int p, i, l, mid, h;
	
	for (p = 2; p <= n; p = p * 2) {
		for (i = 0; i + p - 1 < n; i = i + p) {
			l = i;
			h = i + p - 1;
			mid = (l + h) / 2;
			Merge(A, l, mid, h);
		}
	}
	if (p / 2 < n)
		Merge(A, 0, p / 2 - 1, n - 1); 
}

void RMergeSort(int A[], int l, int h) {
	int mid;
	if (l < h) {
		mid = (l + h) / 2;
		RMergeSort(A, l, mid);
		RMergeSort(A, mid + 1, h);
		Merge(A, l, mid, h);
	}
}

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

/*void BucketSort(int A[], int size) {
	int max, i, j;
	Node* *Bins;
	max = findMax(A, size);
	Bins = new Node*[max + 1];
	
	for (i = 0; i < max + 1; i++)
		Bins[i] = NULL;
		
	for (i = 0; i < size; i++)
		Insert(Bins[A[i]], A[i]);
	
	i = 0; j = 0;
	
	cout<<Bins[3]->data;
	
	while (i < max + 1) {
		while (Bins[i] != NULL)
			A[j++] = Delete(Bins[i]);
		i++;
	}
	
}*/

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
	int A[] = {6,2,3,7,14,5,12,4,1,13};
	ShellSort(A, 10);
	for (int i = 0; i < sizeof(A) / sizeof(int); i++) cout<<A[i]<<" ";
	return 0;
}
