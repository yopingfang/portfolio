//created by pp
#ifndef QUEUE_H
#define QUEUE_H

#include"Deque.h"
#include<string>
using namespace std;

template<typename T>
class Queue {
private:
	Deque<unsigned int> container_;
public:
	Queue() {}
	~Queue() {}
	void push(const T& input) {
		container_.push_back(input);
		return;
	}
	void pop() {
		container_.pop_front();
		return;
	}
	T& top() {
		return container_.front();
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
	void delQ() {
		container_.delDeck();
		return;
	}
};

#endif