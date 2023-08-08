#include <iostream>
#include "Queue.h"
#include "LinkedList.h"

using namespace std;

int visited[] = {0};

void BFS(int G[][7], int start, int n) {
	int i = start;
	Queue q;
	int visited[7] = {0};
	
	cout<<i<<" ";
	visited[i] = 1;
	q.enqueue(i);
	
	while (!q.isEmpty()) {
		i = q.dequeue();
		for (int j = 1; j < n; j++) {
			if (G[i][j] == 1 && visited[j] == 0) {
				cout<<j<<" ";
				visited[j] = 1;
				q.enqueue(j);
			}
		}
	}
}

void DFS(int G[][7], int start, int n) {
	static int visited[7] = {0};
	if (visited[start] == 0) {
		cout<<start<<" ";
		visited[start] = 1;
		for (int j = 1; j < n; j++) {
			if (G[start][j] == 1 && visited[j] == 0)
				DFS(G, j, n);
		}
	}
}

void BFSAL(LinkedList *GL, int start) {
	Node* p;
	Queue q;
	p = GL[start].getHead();
	int visited[6] = {0};
	while (p != NULL) {
		cout<<p->data<<" ";
		visited[p->data] = 1;
		q.enqueue(p->data);
		if (p->next)
			p = p->next;
		else
			p = GL[p->data].getHead();
	}
}

void DFSAL(LinkedList *GL, Node *p) {
	static int visited[6] = {0};
	if (visited[p->data] == 0) {
		while (p != NULL && visited[p->data] == 0) {
			cout<<p->data<<" ";
			visited[p->data] = 1;
			if (p->next)
				p = p->next;
			else
				DFSAL(GL, GL[p->data].getHead());
		}
	}
}

int main() {
	//index starts with '1' in all programs. Node class header file is in LinkedList and Queue header files.
	
	// Undirected graph BFS and DFS sample.
	
	// using adjacency matrix.

	int G[7][7] = {{0,0,0,0,0,0,0},
	               {0,0,1,1,0,0,0},
				   {0,1,0,0,1,0,0},
				   {0,1,0,0,1,0,0},
				   {0,0,1,1,0,1,1},
	               {0,0,0,0,1,0,0},
	               {0,0,0,0,1,0,0}};
	
	BFS(G, 1, 7);
	cout<<endl;
	
	DFS(G, 1, 7);
	cout<<endl;
	
	// using adjacency list.

	LinkedList *GL = new LinkedList[6];
	GL[1].append(2);GL[1].append(3);GL[1].append(4);
	GL[2].append(1);GL[2].append(3);
	GL[3].append(1);GL[3].append(2);GL[3].append(4);GL[3].append(5);
	GL[4].append(1);GL[4].append(3);GL[4].append(5);
	GL[5].append(3);GL[5].append(4);
	
	BFSAL(GL, 1);
	cout<<endl;
	
	DFSAL(GL, GL[1].getHead());
	cout<<endl;
	return 0;
}
