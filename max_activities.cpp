#include <iostream>
using namespace std;

void printMaxActivities(int s[], int f[], int n) {
	int i(0),j(1);
	cout<<i<<endl;
	for (;j<n;++j)
		if (s[j] >= f[i]) {
			cout<<j<<endl;
			i=j;
		}
}

int main() {
	int s[6] = {1,3,0,5,8,5};
	int f[6] = {2,4,6,7,8,9};
	printMaxActivities(s,f,6);
	return 0;
}
