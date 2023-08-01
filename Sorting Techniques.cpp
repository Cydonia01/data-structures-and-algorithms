#include <iostream>

using namespace std;

void swap(int *x, int *y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

void Bubble(int A[], int n) {
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

void Insertion(int A[], int n) {
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

void Selection(int A[], int n) {
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

void Quick(int A[], int l, int h) {
	int j;
	
	if (l < h) {
		j = Partition(A, l, h);
		Quick(A, l, j);
		Quick(A, j + 1, h);
	}
}

int main() {
	int A[] = {6,2,3,7,14,5,12,4,11,INT_MAX};

	Quick(A, 0, sizeof(A)/4 - 1);
	for (int i = 0; i < sizeof(A)/4 - 1; i++) cout<<A[i]<<" ";
	return 0;
}
