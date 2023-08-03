#include <iostream>

using namespace std;

class LinearProbing {
private:
	int *HT;
	int size;
public:
	LinearProbing() {
		size = 10;
		HT = new int[size];
		
		for (int i = 0; i < size; i++)
			HT[i] = 0;
	}
	
	LinearProbing(int size) {
		this->size = size;
		HT = new int[size];
		
		for (int i = 0; i < size; i++)
			HT[i] = 0;
	}
	
	~LinearProbing() {
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
		return (key + i) % 10;
	}
	
	void Insert(int key) {
		int i, index;
		i = 0;
		index = hashing(key, i);
		
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
	LinearProbing lp;
	int x;
	lp.Insert(26);
	lp.Insert(30);
	lp.Insert(45);
	lp.Insert(23);
	lp.Insert(43);
	lp.Insert(75);
	lp.Insert(85);
	
	lp.Display();
	cout<<"What number do you seek? ";
	cin>>x;
	if(lp.Search(x))
		cout<<x<<" is found.";
	else
		cout<<x<<" is not found.";

	return 0;
}
