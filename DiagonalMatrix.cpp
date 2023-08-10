#include<iostream>

using namespace std;

class Diagonal {
private:
	int *A;
	int n;
public:
	Diagonal() {
		n = 2;
		A = new int[2];
	}
	
	Diagonal(int n) {
		this->n = n;
		A = new int[n];
	}
	
	~Diagonal() {
		delete []A;
	}
	
	void create();
	void Set(int i, int x);
	int Get(int i, int j);
	void Display();
};

void Diagonal::create() {
	int x;
	cout<<"Enter diagonal values:"<<endl;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; 
		j <= n; j++) {
			if (i == j) {
				cin>>x;
				Set(i, x);
			}
		}
	}
}

void Diagonal::Set(int i, int x) {
	A[i - 1] = x;
}

int Diagonal::Get(int i, int j) {
	if (i == j) return A[i - 1];
	else return 0;
}

void Diagonal::Display() {
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (i == j) cout<<A[i]<<" ";
			else cout<<"0 ";
		}
		cout<<endl;
	}
}

int main() {
	//indexes start with 1.
	
	Diagonal d(4);
	d.create();
	d.Display();
	
	return 0;
}
