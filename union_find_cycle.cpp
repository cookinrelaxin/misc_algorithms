#include <iostream>
#include <string>

using namespace std;

struct Edge {
	int src, dest;
};

struct Graph {
	int V,E;
	Edge * edge;
};

int find(int parent[], int i) {
	if (parent[i] == -1)
		return i;
	return find(parent, parent[i]);
}

void Union(int parent[], int x, int y) {
	parent[find(parent,x)] = find(parent,y);
}

int isCycle(Graph *graph) {
	int *parent = new int[graph->V];
	for (int i=0; i<graph->V; ++i)
		parent[i] = -1;
	for (int i=0; i<graph->E; ++i) {
		int x = find(parent, graph->edge[i].src);
		int y = find(parent, graph->edge[i].dest);
		if (x == y)
			return 1;
		Union(parent,x,y);
	}
	return 0;
}

int main() {
	Graph *graph = new Graph{3,3,new Edge[3]};

	graph->edge[0].src = 0;
	graph->edge[0].dest = 1;

	graph->edge[1].src = 1;
	graph->edge[1].dest = 2;

	graph->edge[2].src = 0;
	graph->edge[2].dest = 2;

	if (isCycle(graph))
		cout<<"graph contains cycle"<<endl;
	else
		cout<<"graph doesn't contain cycle"<<endl;

	return 0;
}
