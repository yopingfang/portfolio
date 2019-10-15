//created by pp
#ifndef VECTOR_H
#define VECTOR_H

#include"Deque.h"
using namespace std;

template<typename T>

class Vector {
private:
	Deque<unsigned int> container_;
public:
	Vector() {};
	~Vector() {};
	void push_back(const T& toPush) {
		container_.push_back(toPush);
		return;
	}
	void pop_back() {
		container_.pop_back();
		return;
	}
	T& back() {
		return container_.back();
	}
	size_t size() {
		return container_.size();
	}
	T& at(size_t index) {
		return container_.at(index);
	}
	string toString() {
		return container_.toString();
	}
	void delTrain() {
		container_.delDeck();
		return;
	}
};

#endif
