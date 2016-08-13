#include <iostream>
#include <cmath>

template <typename T>
void HeapSort(T A[], int n);

template <typename T>
void Heapify(T A[], int n);

template <typename T>
void SiftDown(T A[], int start, int end);

int iLeftChild(int root);
int iRightChild(int root);
int iParent(int child);

template <typename T>
void HeapSort(T A[], int n) {
	Heapify(A,n);
	int end(n-1);
	while (end > 0) {
		std::swap(A[end],A[0]);
		--end;
		SiftDown(A,0,end);
	}
}

template <typename T>
void Heapify(T A[], int n) {
	for (int start(iParent(n-1)); start >= 0; --start)
		SiftDown(A,start,n-1);
}

template <typename T>
void SiftDown(T A[], int start, int end) {
	int root(start);
	while (iLeftChild(root) <= end) {
		int child(iLeftChild(root));
		int to_swap(root);
		if (A[to_swap] < A[child]) to_swap = child;
		if ((child+1) <= end and (A[to_swap] < A[child+1])) to_swap = child + 1;
		if (to_swap == root) return;
		else {
			std::swap(A[root],A[to_swap]);
			root = to_swap;
		}
	}
}

int iLeftChild(int root) {return 2*root + 1;}
int iRightChild(int root) {return 2*root + 2;}
int iParent(int child) {return floor((child-1)/2);}

template <typename T>
int printArray(T A[], int n) {
	for (int i(0); i<n; ++i)
		std::cout<<A[i]<<" ";
	std::cout<<std::endl;
}

int randomArray(int A[], int n) {
	for (int i(0); i<n; ++i)
		A[i] = rand()%(n+1);
}

int main() {
	constexpr int N(10);
	//int test[N];
	//randomArray(test,N);
	float test[N] {6.6,.3,5.523,7.444,2.62441,3.111,78.0,2,3.1,1.1779};
	printArray(test,N);
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	HeapSort(test,N);
	printArray(test,N);

	return 0;
}
