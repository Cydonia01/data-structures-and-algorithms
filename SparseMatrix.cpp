#include<iostream>

using namespace std;

/* This program implement sparse matrices and sum of matrices. It also uses 'operator' keyword. */

class Element {
public:
	int i;
	int j;
	int x;
};

class Sparse {
private:
	int m;
	int n;
	int num;
	Element *e;
public:
	Sparse(int m, int n, int num) {
		this->m=m;
		this->n=n;
		this->num=num;
		e = new Element[this->num];
	}
	
	~Sparse() {
		delete []e;
	}
	
	friend istream & operator>>(istream &is, Sparse &s);
	friend ostream & operator<<(ostream &os, Sparse &s);
	Sparse operator+(Sparse &s);
	int getNum() {
		return num;
	}
};

istream & operator>>(istream &is, Sparse &s) {
	cout<<"Enter col, row, and data of non-zero elements:\n";
	for(int h = 0; h < s.getNum(); h++) {
		cin>>s.e[h].i;
		cin>>s.e[h].j;
		cin>>s.e[h].x;
	}
		
	cout<<endl;
	return is;
}
	
ostream & operator<<(ostream &os, Sparse &s) {
	int i, j, k;
	int found;
	for (i = 0; i < s.m; i++) {
		for (j = 0; j < s.n; j++) {
			found = 0; k = 0;
			for (k = 0; k < s.getNum(); k++) {
				if (i == s.e[k].i && j == s.e[k].j) {
					found = 1;
					break;
				}	
			}
			
			if (found)
				cout<<s.e[k].x<<" ";
			else
				cout<<"0 ";
		}
		cout<<endl;
	}
	return os;
}

Sparse Sparse::operator+(Sparse &s) {
	int i,j,k;
	
	Sparse *sum = new Sparse(m, n, num + s.num);
	
	if (m != s.m || n != s.n)
		return *sum;
	
	i=j=k=0;
	
	while (i < num && j < s.num) {
		if (e[i].i < s.e[j].i)
			sum->e[k++] = e[i++];
			
		else if (e[i].i > s.e[j].i)
			sum->e[k++] = s.e[j++];
			
		else {
			if (e[i].j < s.e[j].j)
				sum->e[k++] = e[i++];
				
			else if (e[i].j > s.e[j].j)
				sum->e[k++] = s.e[j++];
				
			else {
				sum->e[k] = e[i];
				sum->e[k++].x = e[i++].x + s.e[j++].x;
			}
		}
	}
	for(; i < num; i++)
		sum->e[k++] = e[i];
	
	for(; j < s.num; j++)
		sum->e[k++] = s.e[j];

	sum->num = k;
	
	return *sum;
}

int main() {
	Sparse s1(4,4,4);
	Sparse s2(4,4,4);
	cin>>s1;
	cin>>s2;
	
	Sparse sum = s1 + s2;
	
	cout<<"First Matrix: "<<endl<<s1<<endl;
	cout<<"Second Matrix: "<<endl<<s2<<endl;
	cout<<"Sum Matrix: "<<endl<<sum;
	return 0;
}
