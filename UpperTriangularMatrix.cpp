#include<iostream>

using namespace std;

class UTMatrix {
private:
	int *A;
	int n;
public:
	UTMatrix() {
		n = 2;
		A = new int[2 * (2 + 1) / 2];
	}
	
	UTMatrix(int n) {
		this->n = n;
		A = new int[n * (n + 1) / 2];
	}
	
	~UTMatrix() {
		delete []A;
	}
	
	void create();
	void Set(int i, int j, int x);
	int Get(int i, int j);
	void Display();
	int GetDimension(){return n;}
};

void UTMatrix::create() {
	int x;
	cout<<"Enter All Elements:"<<endl;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			cin>>x;
			Set(i, j, x);
		}
	}
}

void UTMatrix::Set(int i, int j, int x) {
	int index = (i - 1) * n - (i - 2) * (i - 1) / 2 + j - i;
	if (i <= j) A[index] = x;
}

int UTMatrix::Get(int i, int j) {
	int index = (i - 1) * n - (i - 2) * (i - 1) / 2 + j - i;
	if (i <= j) return A[index];
	else return 0;
}

void UTMatrix::Display() {
	int index,i,j;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			index = (i - 1) * n - (i - 2) * (i - 1) / 2 + j - i;
			if (i <= j) cout<<A[index]<<" ";
			else cout<<"0 ";
		}
		cout<<endl;
	}
}

int main() {
	// indexes start with 1.
	UTMatrix um(4);
	um.create();
	um.Display();
	
	return 0;
}
