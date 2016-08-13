#include <iostream>
#include <vector>
#include <utility>
#include <tuple>
#include <set>
#include <climits>

class DisjSets {
	public:
		explicit DisjSets(int numElements);

		int find(int x);
		std::pair<int,int> unionSets(int root1, int root2);

		std::vector<int> s;
};

DisjSets::DisjSets(int numElements) : s(numElements,-1){};

//union by size
//return the root index and size of the larger set
std::pair<int,int> DisjSets::unionSets(int root1, int root2) {
	if (s[root2] < s[root1]) {
		s[root2] += s[root1];
		s[root1] = root2;
		return {root2, -s[root2]};
	}
	else {
		s[root1] += s[root2];
		s[root2] = root1;
		return {root1, -s[root1]};
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

int main() {
	int N,u,v;
	std::cin>>N;
	DisjSets sets(2*N+1);
	std::set<int> S;
	for (int n(0);n<N;++n) {
		std::cin>>u>>v;
		int x(sets.find(u)),y(sets.find(v));
		S.insert(x);
		S.insert(y);
		if (x != y)
			sets.unionSets(x,y);
	}
	int minCC(INT_MAX), maxCC(0);
	for (const int &e : S) {
		int x(sets.find(e));
		int componentSize(-sets.s[x]);
		if (componentSize < minCC)
			minCC = componentSize;
		if (componentSize > maxCC)
			maxCC = componentSize;
	}
	printf("%d %d\n",minCC,maxCC);

	return 0;
}
