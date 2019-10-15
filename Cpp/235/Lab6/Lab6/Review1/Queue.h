#ifndef QUEUE_H
#define QUEUE_H
#include <string>
#include "Deque.h"
using std::string;

template<typename T>
class Queue {
public:
	Queue() {}
	~Queue() {}

	//use delegation to implement functions
	void push(const T& value) {
		container.push_back(value);
	}
	void pop() {
		container.pop_front();
	}
	T& top() {
		return container.front();
	}
	size_t size() {
		return container.size();
	}
	T& at(size_t index) {
		return container.at(index);
	}
	string toString() const {
		return container.toString();
	}
	int find(T value) const {
		return container.find(value);
	}

private:
	Deque<T> container;
};
#endif
