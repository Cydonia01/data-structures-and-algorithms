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
		if (isFull())
			cout<<"Queue is full.";
		else {
			rear = (rear + 1) % size;
			A[rear] = x;
		}
	}
	
	int dequeue() {
		int x = -1;
		if (isEmpty())
			cout<<"Queue is empty.\n";
		else {
			front = (front + 1) % size;
			x = A[front];
		}
		return x;
	}
	
	int isEmpty() {
		if (front == rear)
			return 1;
		return 0;
	}
	
	int isFull() {
		if ((rear + 1) % size == front)
			return 1;
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
	// Sample: Since this is circular queue. The actual size of queue is given size minus 1.
	
	QueueArray q(5); // actual size is 4.
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	
	q.Display();
	
	q.dequeue();
	q.dequeue();
	
	q.Display();
	
	q.enqueue(5);
	q.enqueue(6);
	
	q.Display();
	
	cout<<"front element is "<<q.first()<<endl;
	cout<<"rear element is "<<q.last()<<endl;
	
	if (q.isFull())
		cout<<"Queue is full.";
	
	return 0;
}
