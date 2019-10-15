#ifndef VECTOR_H
#define VECTOR_H
#include <string>
#include "Deque.h"
using std::string;

template<typename T>
class Vector {
public:
	Vector() {}
	~Vector() {}

	//use delegation to implement functions
	void push_back(const T& value) {
		container.push_back(value);
	}
	void pop_back() {
		container.pop_back();
	}
	T& back() {
		return container.back();
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
