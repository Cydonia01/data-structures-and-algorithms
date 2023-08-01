#include<iostream>
#include<stdlib.h>
#include<math.h>

using namespace std;

class Term {
public:
	int cf;
	int exp;
};

class Polynomial {
private:
	int num;
	Term *terms;
public:
	Polynomial(int num) {
		this->num = num;
		terms = new Term[num];
	}
	
	~Polynomial() {
		delete [] terms;
	}
	
	friend istream & operator>>(istream &is, Polynomial &p);
	friend ostream & operator<<(ostream &os, Polynomial &p);
	Polynomial operator+(Polynomial &p);
	int eval(int x);
};

istream & operator>>(istream &is, Polynomial &p) {
	cout<<"Enter coefficient and exponentials: ";
	int i;
	for (i = 0; i < p.num; i++) {
		cin>>p.terms[i].cf>>p.terms[i].exp;
	}
	return is;
}

ostream & operator<<(ostream &os, Polynomial &p) {
	int i;
	for (i = 0; i < p.num; i++) {
		if (p.terms[i].cf != 1)
			cout<<p.terms[i].cf;
		if (p.terms[i].exp != 0)
			cout<<"x";
		if (p.terms[i].exp > 1)
			cout<<"^"<<p.terms[i].exp;
		if (i != p.num - 1)
			cout<<" + ";
	}
	return os;
}

Polynomial Polynomial::operator+(Polynomial &p) {
	Polynomial *sum = new Polynomial(num + p.num);
	int i, j, k;
	i=j=k=0;
	
	while(i < num && j < p.num) {
		if (terms[i].exp > p.terms[j].exp)
			sum->terms[k++] = terms[i++]; 
		else if (terms[i].exp < p.terms[j].exp)
			sum->terms[k++] = p.terms[j++];
		else {
			sum->terms[k] = terms[i++];
			sum->terms[k++].cf += p.terms[j++].cf;
		}
	}
	
	for(; i < num; i++) sum->terms[k++] = terms[i];
	for(; j < p.num; j++) sum->terms[k++] = p.terms[j];
	
	sum->num = k;
	return *sum;
}

int Polynomial::eval(int x) {
	int i, sum = 0;
	for (i = 0; i < num; i++)
		sum += pow(x, terms[i].exp) * terms[i].cf;
	return sum;
}

int main() {
	Polynomial p1(3);
	Polynomial p2(3);
	cin>>p1;
	cin>>p2;
	
	cout<<"First polynomial: "<<p1<<endl;
	cout<<"Second polynomial: "<<p2<<endl;
	
	Polynomial p3 = p1+p2;
	cout<<"Sum Polynomial: "<<p3;
	return 0;
}


