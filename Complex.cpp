#include<iostream>

using namespace std;

/* this file is an exercise of 'operator' keyword. */

class Complex {
private:
	int real;
	int img;
public:
	Complex() {}
	
	Complex operator+(Complex &c);
	friend istream & operator>>(istream &is, Complex &c);
	friend ostream & operator<<(ostream &os, Complex &c);
};

istream & operator>>(istream &is, Complex &c) {
	cout<<"Enter real and imaginary number: ";
	cin>>c.real>>c.img;
	return is;
}	

ostream & operator<<(ostream &os, Complex &c) {
	cout<<c.real<<" + "<<c.img<<"i"<<endl;
	return os;
}

Complex Complex::operator+(Complex &c) {
	Complex *c3 = new Complex();
	c3->real = real + c.real;
	c3->img = img + c.img;
	return *c3;
}

int main() {
	Complex c1,c2,c3;
	cin>>c1>>c2;
	c3 = c1 + c2;
	cout<<c1<<c2<<c3;
	return 0;
}
