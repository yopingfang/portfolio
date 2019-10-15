#ifndef STACK_H
#define STACK_H
#include <string>
#include "Deque.h"
using std::string;

template<typename T>
class Stack {
public:
	Stack() {}
	~Stack() {}

	//use delegation to implement functions
	void push(const T& value) {
		container.push_front(value);
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
	/*In this find function, I had to add a little extra math beacuse I used push_front to add to my stack and it looks like the key used push_back, which would flip the indices.
	I solved this by getting the highest index (size - 1) and subtracting the find index from that value*/
	int find(T value) const {
		if (container.find(value) != -1) {
			return ((container.size() - 1) - container.find(value));
		}
		return container.find(value);
	}

private:
	Deque<T> container;
};
#endif