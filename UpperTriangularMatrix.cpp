#include<iostream>
#include<stdlib.h>

using namespace std;

class UTMatrix {
private:
	int *A;
	int n;
public:
	UTMatrix() {
		n = 2;
		A = new int[2*(2+1)/2];
	}
	
	UTMatrix(int n) {
		this->n = n;
		A = new int[n*(n+1)/2];
	}
	
	~UTMatrix() {
		delete []A;
	}
	
	void Set(int i, int j, int x);
	int Get(int i, int j);
	void Display();
	int GetDimension(){return n;}
};

void UTMatrix::Set(int i, int j, int x) {
	int index = i * (i - 1)/2 + j - 1;
	if (i <= j) A[index] = x;
}

int UTMatrix::Get(int i, int j) {
	int index = i * (i - 1)/2 + j - 1;
	if (i <= j) return A[index];
	else return 0;
}

void UTMatrix::Display() {
	int index,i,j;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			index = i * (i - 1)/2 + j - 1;
			if (i <= j) cout<<A[index]<<" ";
			else cout<<"0 ";
		}
		cout<<endl;
	}
}

int main() {
	int d;
	cout<<"Enter Dimensions"<<endl;
	cin>>d;
	UTMatrix lm(d);
	int x;
	cout<<"Enter All Elements"<<endl;
	
	for (int i = 1; i <= d; i++) {
		for (int j = 1; j <= d; j++) {
			cin>>x;
			lm.Set(i, j, x);
		}
	}
	lm.Display();
	
	return 0;
}
