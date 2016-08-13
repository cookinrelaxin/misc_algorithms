#ifndef HEAP_COOKIN
#define HEAP_COOKIN

#include <iostream>
#include <cmath>
#include <vector>

template <typename T>
class Heap {
	public:
		virtual T findMax() const = 0;
		virtual T extractMax() = 0;
		virtual void deleteMax() = 0;
		virtual void insert(const T x) = 0;
		virtual void replaceRoot(const T x) = 0;
		virtual int size() const = 0;
		virtual bool isEmpty() const = 0;
	protected:
		using index = int;
		std::vector<T> heap;
		virtual T findMax(index start, index end) const = 0;
		virtual T extractMax(index start, index end) = 0;
		virtual void deleteMax(index start, index end) = 0;
		virtual void insert(const T x, index start, index end) = 0;
		virtual void replaceRoot(const T x, index start, index end) = 0;
		virtual void heapify(index end) = 0;
		virtual void siftDown(index start, index end) = 0;
		virtual void siftUp(index start, index end) = 0;
		index leftChildIndex(index i) {
			return 2*i + 1;
		}
		index rightChildIndex(index i) {
			return 2*i + 2;
		}
		index greaterChildIndex(index i) {
			index left(leftChildIndex(i));
			index right(rightChildIndex(i));
			return (heap[left] > heap[right]) ? left : right;
		}
		index parentIndex(index i) {
			return floor((i-1)/2);
		}
};
#endif
