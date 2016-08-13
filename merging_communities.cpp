#include <iostream>
#include <vector>
#include <utility>
#include <tuple>
#include <set>
#include <string>
#include <climits>

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

int main() {
	int N,Q;std::cin>>N>>Q;
	 DisjSets sets(N+1);
	 for (int q(0); q<Q; ++q) {
	 	std::string query;std::cin>>query;
		if (query == "Q") {
			int u;std::cin>>u;
			int x(sets.find(u));
			std::cout<<sets.getSetSize(x)<<std::endl;
		}
		if (query == "M") {
			int u,v;std::cin>>u>>v;
			int x(sets.find(u)),y(sets.find(v));
			if (x != y)
				sets.unionSets(x,y);
		}
	}

	return 0;
}
