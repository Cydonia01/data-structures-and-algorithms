#include<iostream>

using namespace std;

class LTMatrix {
private:
	int *A;
	int n;
public:
	LTMatrix() {
		n = 2;
		A = new int[2 * (2 + 1) / 2];
	}
	
	LTMatrix(int n) {
		this->n = n;
		A = new int[n * (n + 1) / 2];
	}
	
	~LTMatrix() {
		delete []A;
	}
	
	void create();
	void Set(int i, int j, int x);
	int Get(int i, int j);
	void Display();
	int GetDimension(){return n;}
};

void LTMatrix::create() {
	int x;
	cout<<"Enter All Elements:"<<endl;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin>>x;
			Set(i, j, x);
		}
	}
}

void LTMatrix::Set(int i, int j, int x) {
	int index = i * (i - 1) / 2 + j - 1;
	if (i >= j) A[index] = x;
}

int LTMatrix::Get(int i, int j) {
	int index = i * (i - 1) / 2 + j - 1;
	if (i >= j) return A[index];
	else return 0;
}

void LTMatrix::Display() {
	int index, i, j;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			index = i * (i - 1) / 2 + j - 1;
			if (i >= j) cout<<A[index]<<" ";
			else cout<<"0 ";
		}
		cout<<endl;
	}
}

int main() {
	// indexes start with 1.
	
	LTMatrix lm(4);
	lm.create();
	lm.Display();
	
	return 0;
}
