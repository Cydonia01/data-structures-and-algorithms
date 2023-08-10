#include <iostream>

using namespace std;

/* This program implements some algorithms using arrays and C structs. */

struct Array {
	int A[11];
	int size;
	int length;
};

int missingElement(struct Array arr) {
	int n = arr.length + 1;
	int realSum = (n * (n + 1))/2;
	int sum = 0;

	for (int i = 0; i < arr.length; i++) {
		sum += arr.A[i];
	}
	return realSum - sum;
}

int missingElement2(struct Array arr) {
	int l = arr.A[0];
	int diff = l;
	for (int i = 0; i < arr.length; i++) {
		if (arr.A[i] - i != diff) {
			cout << i + diff;
			break;
		}
	}
}

int multipleMissingElements(struct Array arr) {
	int l = arr.A[0];
	int diff = l;
	for (int i = 0; i < arr.length; i++) {
		if (arr.A[i] - i != diff) {
			while (diff < arr.A[i] - i) {
				cout << i + diff << endl;
				diff++;
			}
		}
	}
}

int main() {
	
	struct Array arr = {{1,2,3,4,5,6,7,8,10,11,12}, 11, 11};
	cout<<"Missing element is "<<missingElement(arr)<<endl<<endl;
	
	struct Array arr2 = { {6,7,8,9,11,12,15,16,17,18,19}, 11, 11 };
	cout<<"Missing elements are "<<endl;
	multipleMissingElements(arr2);
	
	return 0;
}
