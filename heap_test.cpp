#include <iostream>
#include <vector>
#include <cassert>
#include "BinaryHeap.h"

using namespace std;

void test0() {
	BinaryHeap<float> h {3,2,1};
	assert(h.findMax() == 3);
}

void test1() {
	BinaryHeap<float> h {3,2,1};
	assert(h.findMax() != 1);
}

void test2() {
	BinaryHeap<float> h {3,2,1};
	assert(h.size() == 3);
}

void test3() {
	BinaryHeap<float> h {3.4234,555.23,1.45,355.2};
	assert(h.size() == 4);
	assert(h.findMax() == 555.23f);
}

void test4() {
	vector<int> vec {4,66,7,2425,7,1,4,6,2,5,3,7245,1,3145,6,1,3,5,7,98,88,2345};
	BinaryHeap<int> h (vec);
	assert(h.findMax() == 7245);
}

void test5() {
	vector<int> vec {4,66,7,2425,7,1,4,6,2,5,3,7245,1,3145,6,1,3,5,7,98,88,2345};
	BinaryHeap<int> h (vec);
	assert(h.extractMax() == 7245);
	assert(h.extractMax() == 3145);
	assert(h.extractMax() == 2425);
}

void test6() {
	vector<int> vec {4,66,7,2425,7,1,4,6,2,5,3,7245,1,3145,6,1,3,5,7,98,88,2345};
	BinaryHeap<int> h (vec);
	h.insert(7246);
	assert(h.size() == vec.size()+1);
	assert(h.findMax() == 7246);
}

void test7() {
	vector<int> vec {4,66,7,2425,7,1,4,6,2,5,3,7245,1,3145,6,1,3,5,7,98,88,2345};
	BinaryHeap<int> h1 (vec);
	BinaryHeap<int> h2 (h1);
	assert(h1.findMax() == h2.findMax());
	h1.deleteMax();
	h2.deleteMax();
	assert(h1.findMax() == h2.findMax());
}

void test8() {
	vector<int> vec {4,66,7,2425,7,1,4,6,2,5,3,7245,1,3145,6,1,3,5,7,98,88,2345};
	BinaryHeap<int> h1 (vec);
	h1.replaceRoot(9000);
	assert(h1.findMax() == 9000);
	h1.deleteMax();
	assert(h1.findMax() == 3145);
}

int main() {
	test0();
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();
	test8();

	return 0;
}
