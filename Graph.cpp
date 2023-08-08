#include <iostream>
#include "Queue.h"

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

void DFS() {
	
}

int main() {
	int G[7][7] = {{0,0,0,0,0,0,0},
	               {0,0,1,1,0,0,0},
				   {0,1,0,0,1,0,0},
				   {0,1,0,0,1,0,0},
				   {0,0,1,1,0,1,1},
	               {0,0,0,0,1,0,0},
	               {0,0,0,0,1,0,0}};
	
	BFS(G, 1, 7);
	return 0;
}
