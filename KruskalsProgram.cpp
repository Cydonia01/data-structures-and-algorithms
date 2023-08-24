#include <iostream>
#define I INT_MAX

using namespace std;

/* There are 7 vertices and 9 edges. Size of set array is 8 because 0th index is not used.
It is just to mark the seven vertices which are 1, 2, 3, 4, 5, 6, 7. Then we need 6 edges
to link these vertices. Therefore the size of t array is 2 by 6. Size of the 'included' array
is determined by the size of edges. It allows us to mark the vertices that is visited. */

// edges of the graph.
int edges[3][9] = {{1, 1, 2, 2, 3, 4, 4, 5, 5},
				   {2, 6, 3, 7, 4, 5, 7, 6, 7},
				   {25, 5, 12, 10, 8, 16, 14, 20, 18}};

// initializing set for union and find operations.
int set[8] = {-1, -1, -1, -1, -1, -1, -1, -1};

// checking if any edge visited or not.
int included[9] = {0};

int t[2][6];

int Union(int u, int v) {
	if (set[u] < set[v]) {
		set[u] += set[v];
		set[v] = u;
	}
	else {
		set[v] += set[u];
		set[u] = v;
	}
}

int find(int u) {
	int x = u, v = 0;
	
	while (set[x] > 0) 
		x = set[x];
	
	while (u != x) {
		v = set[u];
		set[u] = x;
		u = v;
	}
	
	return x;
}

int main() {
	// e is number of edges. n is number of vertices.
	int i, j, k, n = 7, e = 9, u, v, min;
	i = 0;
	while (i < n - 1) {
		min = I;
		for (j = 0; j < e; j++) {
			if (edges[2][j] < min && included[j] == 0) {
				min = edges[2][j];
				k = j;
				u = edges[0][j];
				v = edges[1][j];
			}
		}
		
		if (find(u) != find(v)) {
			t[0][i] = u;
			t[1][i] = v;
			Union(find(u), find(v));
			i++;
		}
		
		included[k] = 1;
	}
	
	cout<<"Edges of spanning tree: "<<endl;
	
	for (i = 0; i < n - 1; i++)
		cout<<t[0][i]<<" "<<t[1][i]<<endl;
	
	return 0;
}
