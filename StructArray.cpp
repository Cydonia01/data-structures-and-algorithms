#include <iostream>
#include <stdlib.h>

using namespace std;

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

	struct Array arr = { {6,7,8,9,11,12,15,16,17,18,19}, 11, 11 };

	multipleMissingElements(arr);

	return 0;
}
