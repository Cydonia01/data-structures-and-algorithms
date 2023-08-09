#include <iostream>
#include "Queue.h"
#include "LinkedList.h"

using namespace std;

// Global visited array for DFS and DFSAL methods.
int visited[7] = {0};


// Breadth-first search and Depth-first search methods for adjacency matrices.
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
	if (visited[start] == 0) {
		cout<<start<<" ";
		visited[start] = 1;
		for (int j = 1; j < n; j++) {
			if (G[start][j] == 1 && visited[j] == 0)
				DFS(G, j, n);
		}
	}
}

// Breadth-first search and Depth-first search methods for adjacency lists.
void BFSAL(LinkedList *GL, int n) {
	Node* p;
	int visited[6] = {0};
	for (int i = 1; i < n; i++) {
		if (visited[i] == 0) {
			cout<<i<<" ";
			visited[i] = 1;
		}
		p = GL[i].getHead();
		while (p != NULL && visited[p->data] == 0) {
			cout<<p->data<<" ";
			visited[p->data] = 1;
			if (p->next)
				p = p->next;
		}
	}
}

void DFSAL(LinkedList *GL, int start) {
	Node *p = GL[start].getHead();
	if (visited[start] == 0) {
		cout<<start<<" ";
		visited[start] = 1;
		while (p != NULL) {
			if (visited[p->data] == 0)
				DFSAL(GL, p->data);
			else p = p->next;
		}
	}
}

int main() {
	//index starts with '1' in all programs. Node class header file is in LinkedList and Queue header files.
	
	// Undirected graph BFS and DFS sample.
	// using adjacency matrix.
	cout<<"Undirected graph adjacency matrix:"<<endl;
	
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
	cout<<endl<<endl;
	
	// using adjacency list.
	cout<<"Undirected Graph adjacency list: "<<endl;
	
	LinkedList *GL = new LinkedList[6];
	GL[1].append(2);GL[1].append(3);GL[1].append(4);
	GL[2].append(1);GL[2].append(3);
	GL[3].append(1);GL[3].append(2);GL[3].append(4);GL[3].append(5);
	GL[4].append(1);GL[4].append(3);GL[4].append(5);
	GL[5].append(3);GL[5].append(4);
	
	BFSAL(GL, 6);
	cout<<endl;
	
	// resetting global visited array for DFSAL.
	for (int i = 0; i < 7; i++)
		visited[i] = 0;
	
	DFSAL(GL, 2);
	cout<<endl<<endl;
	
	
	// Directed graph BFS and DFS example.
	// using adjacency matrix.
	cout<<"Directed Graph adjacency matrix: "<<endl;
		
	int DG[7][7] = {{0,0,0,0,0,0,0},
					{0,0,1,1,0,0,0},
					{0,0,0,0,1,0,0},
					{0,0,1,0,1,1,0},
					{0,0,0,0,0,1,1},
					{0,0,0,0,0,0,1},
					{0,0,0,0,0,0,0}};
					
	BFS(DG, 1, 7);
	cout<<endl;
	
	// resetting global visited array for DFS.
	for (int i = 0; i < 7; i++)
		visited[i] = 0;
	
	DFS(DG, 1, 7);
	cout<<endl<<endl;
	
	// using adjacency list.
	cout<<"Directed Graph adjacency list: "<<endl;

	LinkedList *DGL = new LinkedList[6];
	DGL[1].append(2);DGL[1].append(3);
	DGL[2].append(5);
	DGL[3].append(4);
	DGL[4].append(2);
	
	BFSAL(DGL, 6);
	cout<<endl;
		
	// resetting global visited array for DFSAL.
	for (int i = 0; i < 7; i++)
		visited[i] = 0;
		
	DFSAL(DGL, 1);
	
	return 0;
}
