#include <iostream>
#include <climits>

using namespace std;

#define V 5

int minKey(int key[], bool mstSet[], int V) {
	int min(INT_MAX), min_index;
	for (int v(0); v<V; ++v)
		if (mstSet[v] == false && key[v] < min)
			min = key[v], min_index = v;
	return min_index;
}

void printMST(int parent[], int *graph, int V) {
	printf("Edge	Weight");
	for (int i(1); i<V; ++i)
		printf("%d - %d		%d \n", parent[i], i, graph[i][parent[i]]);}

void primMST(int *graph, int V, int S) {
	int parent[V];
	int key[V];
	bool mstSet[V];
	for (int i(0); i<V; ++i)
		key[i] = INT_MAX, mstSet[i] = false;
	key[S] = 0;
	parent[S] -1;
	for (int count(0); count < V-1; ++count) {
		int u(minKey(key, mstSet));
		mstSet[u] = true;
		for (int v(0); v<V; ++v)
			if (graph[u][v] &&
				mstSet[v] == false &&
				graph[u][v] < key[v])
				parent[v] = u, key[v] = graph[u][v];
	}
	printMST(parent, graph, V);
}

int main() {
	return 0;
}
