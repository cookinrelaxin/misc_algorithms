#include <iostream>

template <typename T>
T findMax(const vector<T> H);

template <typename T>
T extractMax(vector<T> H);

template <typename T>
T deleteMax(vector<T> H);

template <typename T>
void insert(const T x, vector<T> H);

template <typename T>
void replaceRoot(const T x, vector<T> H);

template <typename T>
void heapify(vector<T> H);

template <typename T>
void siftDown(vector<T> H, int start, int end);

template <typename T>
void siftUp(vector<T> H, int start, int end);

inline int leftChildIndex(int i) {
	return 2*i + 1;
}

inline int rightChildIndex(int i) {
	return 2*i + 2;
}

inline int greaterChildIndex(int i) {
	int left(leftChildIndex(i));
	int right(rightChildIndex(i));
	return (heap[left] > heap[right]) ? left : right;
}

inline int parentIndex(int i) {
	return floor((i-1)/2);
}

template <typename T>
T findMax(const vector<T> H) {
	return H[0];
};

template <typename T>
T extractMax(vector<T> H) {
	T x(findMax(H));
	deleteMax(H);
	return x;
};

template <typename T>
void replaceRoot(const T x, vector<T> H) {
	H[0] = x;
	siftDown(H);
};

template <typename T>
void deleteMax(vector<T> H) {
	std::swap(H[start],H[end]);
	H.pop_back();
	siftDown(H);
};

template <typename T>
void heapify(vector<T> H) {
	int end(H.size()-1);
	for (int start(parentIndex(end)); start>=0; --start) {
		siftDown(start,end);
	}
}

template <typename T>
void siftDown(vector<T> H, index start, index end) {
	if (start < end) {
		int child(greaterChildIndex(start));
		if (child < end && H.at(start) < H.at(child)) {
			std::swap(H.at(start), H.at(child));
			siftDown(H,child,end);
		}
	}
}

template <typename T>
void siftUp(vector<T> H, index start, index end) {
	int child(end);
	while (child > start) {
		int parent(parentIndex(child));
		if (H[parent] < H[child]) {
			std::swap(H[parent],H[child]);
			child = parent;
		}
		else return;
	}
}

template <typename T>
void insert(const T x, vector<T> H) {
	H.push_back(x);
	siftUp(H,0,end+1);
}

int main() {
	return 0;
}

#endif
