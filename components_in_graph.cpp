#include <iostream>
#include <string>

using namespace std;

struct Edge {
	int src, dest;
};

struct Graph {
	int V,E;
	Edge * edges;
};

int find(int parent[], int i) {
	if (parent[i] == -1)
		return i;
	return find(parent, parent[i]);
}

void Union(int parent[], int x, int y) {
	parent[find(parent,x)] = find(parent,y);
}

void componentsInGraph(Graph *graph) {
	int *representatives = new int[graph->V];
	for (int i=0; i<graph->V; ++i)
		representatives[i] = -1;
	for (int i=0; i<graph->E; ++i)
		Union(representatives,graph->edges[i].src,graph->edges[i].dest);
	int *CCs = new int[graph->V]();
	for (int i=0; i<graph->V; ++i)
		++CCs[find(representatives,i)];
	int maxCC(0),minCC(0);
	for (int i=0; i<graph->V; ++i) {
		maxCC = (CCs[i] > maxCC) ? CCs[i] : maxCC;
		minCC = (CCs[i] < minCC || minCC==0) ? CCs[i] : minCC;
	}
	printf("%d %d\n",minCC,maxCC);
}

int main() {
	Graph *graph = new Graph{10,5,new Edge[5]};

	graph->edges[0].src = 1;
	graph->edges[0].dest = 6;

	graph->edges[1].src = 2;
	graph->edges[1].dest = 7;

	graph->edges[2].src = 3;
	graph->edges[2].dest = 8;

	graph->edges[3].src = 4;
	graph->edges[3].dest = 9;

	graph->edges[4].src = 2;
	graph->edges[4].dest = 6;

	componentsInGraph(graph);

	return 0;
}

