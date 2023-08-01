#include<iostream>

using namespace std;

class QueueArray {
private:
	int size;
	int front;
	int rear;
	int *A;
public:
	QueueArray() {
		front = rear = 0;
		size = 10;
		A = new int[size];
	}
	
	QueueArray(int size) {
		this->size = size;
		front = rear = 0;
		A = new int[size];
	}
	
	void Display() {
		int i = front + 1;
		do {
			cout<<A[i]<<" ";
			i = (i + 1) % size;
		} while (i != (rear + 1) % size);
		cout<<endl;
	}
	
	void enqueue(int x) {
		if (isFull()) cout<<"Queue is full.";
		else {
			rear = (rear + 1) % size;
			A[rear] = x;
		}
	}
	
	int dequeue() {
		int x = -1;
		if (isEmpty()) cout<<"Queue is empty.\n";
		else {
			front = (front + 1) % size;
			x = A[front];
			
		}
		return x;
	}
	
	int isEmpty() {
		if (front == rear) return 1;
		return 0;
	}
	
	int isFull() {
		if ((rear + 1) % size == front) return 1;
		return 0;
	}
	
	int first() {
		return A[front + 1];
	}
	
	int last() {
		return A[rear];
	}
};

int main() {

	return 0;
}
