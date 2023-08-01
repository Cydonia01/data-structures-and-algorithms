#include <iostream>
#include <stdlib.h>
using namespace std;

int length(char A[]) {
	int i;
	for (i = 0; A[i] != '\0'; i++) {}
	return i;
}

void reverse(char A[], char B[]) {
	int i = length(A);
	int j;
	for (j = 0; j < length(A); j++) {
		B[j] = A[--i];
	}
	B[j] = '\0';
}

int compare(char A[], char B[]) {
	int i, j;
	for (i = 0, j = 0; A[i] != '\0' && B[j] != '\0'; i++, j++) {
		if (A[i] != B[j]) break;
	}
	if (A[i] == B[j]) return 1;
	else if (A[i] < B[j]) return 0;
	else return 0;
}

void palindrome(char A[], char B[]) {
	reverse(A, B);
	if (compare(A, B)) {
		cout<<"This word is palindrome.";
	}
	else {
		cout<<"This word is not palindrome.";
	}
}

void palindrome2(char A[], char B[]) {
	int i;
	int j;
	for (i = length(A), j = 0; i >= 0 && j < length(A); j++) {
		B[j] = A[--i];
	}
	B[length(B)] = '\0';
	if (compare(A, B)) {
		cout<<"This word is palindrome.";
	}
	else {
		cout<<"This word is not palindrome.";
	}
}

void findDuplicates(char A[]) {
	int temp[26] = {};
	int i;
	for (i = 0; i < A[i] != '\0'; i++) {
		temp[A[i] - 97] += 1;
	}
	for (i = 0; i < 26; i++) {
		if (temp[i] > 1) {
			printf("%c is duplicate for %d times\n", i + 97, temp[i]);
		}
	}
}

void bitwiseDuplicates(char A[]) {
	int H = 0;
	int x = 0;
	for (int i = 0; A[i] != '\0'; i++) {
		x = 1;
		x = x<<(A[i] - 97);
		if ((x & H) > 0) {
			printf("%c is duplicate\n", A[i]);
		}
		else {
			H = x|H;
		}
	}
}

void anagram(char A[], char B[]) {
	int temp[26] = {};
	int i;
	for (i = 0; A[i] != '\0'; i++) {
		temp[A[i] - 97] += 1;
	}
	
	for (i = 0; B[i] != '\0'; i++) {
		temp[B[i] - 97] -= 1;
	}
	for (i = 0; i < 26; i++) {
		if (temp[i] != 0) {
			printf("It's not Anagram");
			break;
		}
	}
	
	if (B[i] == '\0') printf("It's Anagram");
} 

void permutation(char S[], int k) {
	static int A[10] = {};
	static char Res[10] = {};
	int i;
	if (S[k] == '\0') {
		Res[k] = '\0';
		cout<<Res<<endl;
	}
	
	else {
		for(i = 0; S[i] != '\0'; i++) {
			if (A[i] == 0) {
				Res[k] = S[i];
				A[i] = 1;
				permutation(S, k + 1);
				A[i] = 0;
			}
		}
	}
	
}

void perm2(char S[], int l, int h) {
	int i;
	if (l == h) printf(S);
	else {
		for (i=l; i <= h; i++) {
			swap(S[l], S[i]);
			perm2(S, l+1, h);
			swap(S[l], S[i]);
		} 
	}
}

int main() {
	char A[] = "ABC";
	char B[] = "decimel";
	perm2(A, 0, 3);
	return 0;
}
