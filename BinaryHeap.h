#ifndef BINARYHEAP_COOKIN
#define BINARYHEAP_COOKIN

#include "Heap.h"

template <typename T>
class BinaryHeap : public Heap<T> {
	public:
		BinaryHeap() = default;
		BinaryHeap(const std::initializer_list<T> ls);
		BinaryHeap(const std::vector<T> ls);
		//BinaryHeap(const BinaryHeap<T> H);
		//BinaryHeap(const BinaryHeap<T> A, const BinaryHeap<T> B);

		T findMax() const override;

		T extractMax() override;
		void deleteMax() override;
		void insert(const T x) override;
		void replaceRoot(const T x) override;
		int size() const override;
		bool isEmpty() const;
	protected:
		using index = int;
		T findMax(index start, index end) const override;
		T extractMax(index start, index end) override;
		void deleteMax(index start, index end) override;
		void insert(const T x, index start, index end) override;
		void replaceRoot(const T x, index start, index end) override;
		void heapify(index end) override;
		void siftDown(index start, index end) override;
		void siftUp(index start, index end) override;
};

template <typename T>
BinaryHeap<T>::BinaryHeap(const std::initializer_list<T> ls) {
	this->heap = ls;
	this->heapify(this->heap.size()-1);
};

template <typename T>
BinaryHeap<T>::BinaryHeap(const std::vector<T> ls) {
	this->heap = ls;
	this->heapify(this->size()-1);
};

template <typename T>
T BinaryHeap<T>::findMax() const {
	return this->findMax(0,this->size()-1);
};

template <typename T>
T BinaryHeap<T>::findMax(index start, index end) const {
	return this->heap[start];
};

template <typename T>
T BinaryHeap<T>::extractMax() {
	return this->extractMax(0,this->size()-1);
};

template <typename T>
T BinaryHeap<T>::extractMax(index start, index end) {
	T x(this->findMax(start,end));
	this->deleteMax(start, end);
	return x;
};

template <typename T>
void BinaryHeap<T>::replaceRoot(const T x) {
	this->replaceRoot(x,0,this->size()-1);
};

template <typename T>
void BinaryHeap<T>::replaceRoot(const T x, index start, index end) {
	this->heap[start] = x;
	this->siftDown(start,end);
};

template <typename T>
void BinaryHeap<T>::deleteMax() {
	this->deleteMax(0,this->heap.size()-1);
};

template <typename T>
void BinaryHeap<T>::deleteMax(index start, index end) {
	std::swap(this->heap[start],this->heap[end]);
	this->heap.pop_back();
	this->siftDown(start,end-1);
};

template <typename T>
void BinaryHeap<T>::heapify(index end) {
	for (index start(this->parentIndex(end)); start>=0; --start) {
		this->siftDown(start,end);
	}
}

template <typename T>
void BinaryHeap<T>::siftDown(index start, index end) {
	if (start < end) {
		index child(this->greaterChildIndex(start));
		if (child < end && this->heap.at(start) < this->heap.at(child)) {
			std::swap(this->heap.at(start), this->heap.at(child));
			this->siftDown(child,end);
		}
	}
}

template <typename T>
void BinaryHeap<T>::siftUp(index start, index end) {
	index child(end);
	while (child > start) {
		index parent(this->parentIndex(child));
		if (this->heap[parent] < this->heap[child]) {
			std::swap(this->heap[parent],this->heap[child]);
			child = parent;
		}
		else 
			return;
	}
}

template <typename T>
void BinaryHeap<T>::insert(const T x) {
	this->insert(x,0,this->size()-1);
}

template <typename T>
void BinaryHeap<T>::insert(const T x, index start, index end) {
	this->heap.push_back(x);
	this->siftUp(0,end+1);
}

template <typename T>
int BinaryHeap<T>::size() const {
	return this->heap.size();
};

template <typename T>
bool BinaryHeap<T>::isEmpty() const {
	return this->heap.size() > 0;
};

#endif
