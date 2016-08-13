#include <iostream>
#include <vector>
#include <queue>
//#include <set>
#include <climits>
#include <cassert>

using namespace std;

#define MAX_DISTANCE 10000

struct Node;
struct NodeComp;
struct PartialEdge;
struct Graph;

struct Node {
	int id;
	int distance;
	Node *parent;
	vector<PartialEdge*> *adjacent;
};

struct NodeComp {
	bool operator() (const Node* u, const Node* v) {
		return u->distance < v->distance;
	}
};

struct PartialEdge {
	int weight;
	Node *to;
};

struct Graph {
	vector<Node*> *V;
};

void Dijkstra(Graph *G, Node *V) {
	//multiset<Node*, NodeComp> Q;
	priority_queue<NodeComp,vector<Node*>> Q;
	V->distance = 0;
	Q.push(V);
	for (Node *n : *(G->V))
		if (n != V) {
			n->distance = MAX_DISTANCE;
			n->parent = nullptr;
			Q.push(n);
		}
	while (!Q.empty()) {
		Node *current = *(Q.begin());
		assert(Q.find(current) != Q.end());
		Q.erase(current); 
		assert(Q.find(current) == Q.end());
		//printf("current->id: %d\n", current->id);
		printf("Q.size(): %lu\n", Q.size());
		//assert(current->id == 17 or current->id == 1);
		for (PartialEdge *e : *(current->adjacent)) {
			int alt(current->distance + e->weight);
			//printf("Q contains Node %d: %s\n",e->to->id,(Q.find(e->to) != Q.end()) ? "true" : "false");
			if ((Q.find(e->to) != Q.end()) && alt < e->to->distance) {
				printf("current->id: %d\n", current->id);
				printf("e->to->id: %d\n", e->to->id);
				printf("Q.size() 1: %lu\n", Q.size());
				assert(Q.find(e->to) != Q.end());
				Q.erase(e->to);
				assert(Q.find(e->to) == Q.end());
				e->to->distance = alt;
				e->to->parent = current;
				Q.insert(e->to);
				assert(Q.find(e->to) != Q.end());
				printf("Q.size() 2: %lu\n", Q.size());
			}
			else if (alt < e->to->distance) {
				e->to->distance = alt;
				e->to->parent = current;
			}
			//return;
		}
	}
}

void cleanup(Graph *G) {
	for (vector<Node*>::iterator v_it = G->V->begin(); v_it != G->V->end(); ++v_it) {
		for (vector<PartialEdge*>::iterator e_it = (*v_it)->adjacent->begin(); e_it != (*v_it)->adjacent->end(); ++e_it) {
			delete (*e_it);
		}
		delete (*v_it)->adjacent;
		delete *v_it;
	}
	delete G->V;
	delete G;
}

int main() {
	int T,N,M;
	cin>>T>>N>>M;
	//for (int t(0); t<T; ++t) {
	for (int t(0); t==0; ++t) {
		Graph *G = new Graph{new vector<Node*>};
		for (int n(0); n<N; ++n) {
			G->V->push_back(new Node{n+1,0,nullptr,new vector<PartialEdge*>});
		}
		for (int m(0); m<M; ++m) {
			int x,y,r;cin>>x>>y>>r;
			G->V->at(x-1)->adjacent->push_back(new PartialEdge{r,G->V->at(y-1)});
			G->V->at(y-1)->adjacent->push_back(new PartialEdge{r,G->V->at(x-1)});
		}
		int S;cin>>S;
		Dijkstra(G,G->V->at(S-1));
		for (int i(0); i<N; ++i) {
			if (i != S-1) {
				Node *n = G->V->at(i);
				if (n->distance == MAX_DISTANCE)
					printf("%d ", -1);
				else
					printf("%d ",n->distance);
			}
		}
		printf("\n");
		cleanup(G);
	}
	return 0;
}
