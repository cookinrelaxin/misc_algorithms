#include <iostream>
#include <vector>
#include <utility>
#include <tuple>
#include <set>
#include <string>
#include <climits>

//using namespace std;

class DisjSets {
	public:
		explicit DisjSets(int numElements);

		int find(int x);
		void unionSets(int root1, int root2);
		int getSetSize(int x);

	private:
		std::vector<int> s;
};

DisjSets::DisjSets(int numElements) : s(numElements,-1){};

//union by size
//return the root index and size of the larger set
void DisjSets::unionSets(int root1, int root2) {
	if (s[root2] < s[root1]) {
		s[root2] += s[root1];
		s[root1] = root2;
	}
	else {
		s[root1] += s[root2];
		s[root2] = root1;
	}
}

int DisjSets::find(int x) {
	if (s[x] < 0)
		return x;
	else {
		int root(find(s[x]));
		s[x] = root;
		return root;
	}
}

int DisjSets::getSetSize(int x) {
	return -s[x];
}

struct Edge {
	int from;
	int to;
	int weight;
};

struct EdgeComp {
	bool operator()(const Edge *e1, const Edge *e2) const {
		return e1->weight <= e2->weight;
	}
};

int main() {
	int N,M;std::cin>>N>>M;
	std::set<Edge*,EdgeComp> graph;
	for (int m(0); m<M; ++m) {
		int x,y,r;std::cin>>x>>y>>r;
		graph.insert(new Edge{x,y,r});
	}
	//int S;cin>>S;
	DisjSets sets(N+1);
	int sum(0);
	for (Edge *e : graph) {
		int x(sets.find(e->from));
		int y(sets.find(e->to));
		//printf("consider edge (%d, %d)\n", e->from, e->to);
		if (x != y) {
			//printf("add edge (%d, %d)\n", e->from, e->to);
			sets.unionSets(x,y);
			sum += e->weight;
		}
	}
	std::cout<<sum<<std::endl;

	return 0;
}
