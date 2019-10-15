//created by pp
#ifndef STACK_H
#define STACK_H

#include"Deque.h"
#include<string>
using namespace std;

template<typename T>

class Stack {
private:
	Deque<unsigned int> container_;
public:
	Stack() {}
	~Stack() {}
	void push(const T& toPush) {
		container_.push_back(toPush);
		return;
	}
	void pop() {
		container_.pop_back();
		return;
	}
	T& top() {
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
	void delStack() {
		container_.delDeck();
		return;
	}
};

#endif
