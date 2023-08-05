#include <iostream>

using namespace std;
class DoubleHashing {
private:
	int *HT;
	int size;
	int maxPrime;
public:
	DoubleHashing() {
		size = 10;
		HT = new int[size];
		maxPrime = findMaxPrime();
		for (int i = 0; i < size; i++)
			HT[i] = 0;
	}
	
	DoubleHashing(int size) {
		this->size = size;
		HT = new int[size];
		maxPrime = findMaxPrime();
		
		for (int i = 0; i < size; i++)
			HT[i] = 0;
	}
	
	~DoubleHashing() {
		delete HT;
	}
	
	void Display() {
		for (int i = 0; i < size; i++) {
			if (isFull(i))
				cout<<HT[i]<<" ";
			else
				cout<<0;
			cout<<endl;
		}
	}
	
	int hashing(int key, int i) {
		return (hash1(key) + i * hash2(key)) % size;
	}
	
	int hash1(int key) {
		return key % size;
	}
	
	int hash2(int key) {
		return maxPrime - (key % maxPrime);
	}
	
	int findMaxPrime() {
		bool check = true;
		int i = size - 1;
		int j;
		while (i > 0) {
			check = true;
			for (j = 2; j < i / 2; j++) {
				if (i % j == 0) {
					check = false;
					break;
				}
			}
			if (check) return i;
			i--;
		}
	}
	
	void Insert(int key) {
		int i, index;
		i = 0;
		index = hash1(key);
		
		while (isFull(index))
			index = hashing(key, ++i);
		
		HT[index] = key;
	}
	
	int Search(int key) {
		int index = hashing(key, 0);
		while(isFull(index)) {
			if (key == HT[index++])
				return 1;
		}
		return 0;
	}
	
	int isFull(int index) {
		if (HT[index])
			return 1;
		return 0;
	}
};

int main() {
	// Sample 1:
	DoubleHashing dh;
	int x;
	dh.Insert(5);
	dh.Insert(25);
	dh.Insert(15);
	dh.Insert(35);
	dh.Insert(95);
	
	dh.Display();
	cout<<"What number do you seek? ";
	cin>>x;
	cout<<x;
	dh.Search(x) ? cout<<" is found.":cout<<" is not found.";
	cout<<endl<<endl;
	
	// Sample 2:
	DoubleHashing dh2(20);
	dh2.Insert(17);
	dh2.Insert(57);
	dh2.Insert(37);
	dh2.Insert(77);
	dh2.Insert(13);
	dh2.Insert(33);
	dh2.Insert(53);
	dh2.Insert(73);
	dh2.Display();
	cout<<"What number do you seek? ";
	cin>>x;
	cout<<x;
	dh2.Search(x) ? cout<<" is found.":cout<<" is not found.";
}
