#ifndef STATION_H
#define STATION_H
#include "Vector.h"
#include "Stack.h"
#include "Queue.h"
#include <string>
#include <sstream>
using std::string;

template<typename T>
class Station {

public:
	Station() {
		turntable = NULL;
	}
	~Station() {}

	//if turntable is empty, put new value on turntable
	string addCar(const T& value) {
		if (turntable == NULL) {
			turntable = value;
			return "OK";
		}
		else {
			return "Turntable occupied!";
		}
	}

	//if turntable is occupied, put value on vector
	string removeCar() {
		if (turntable == NULL) {
			return "Turntable empty!";
		}
		vector.push_back(turntable);
		turntable = NULL;
		return "OK";
	}

	//if turntable is occupied, put value on stack
	string addStack() {
		if (turntable == NULL) {
			return "Turntable empty!";
		}
		stack.push(turntable);
		turntable = NULL;
		return "OK";
	}

	//if turntable is empty and stack is not empty, put top value of stack value on turntable
	string removeStack() {
		if (turntable != NULL) {
			return "Turntable occupied!";
		}
		if (stack.size() == 0) {
			return "Stack empty!";
		}
		turntable = stack.top();
		stack.pop();
		return "OK";
	}

	//return top value of stack
	string topStack() {
		std::stringstream ss;
		ss << stack.top();
		return ss.str();
	}

	//return size of stack
	string sizeStack() {
		std::stringstream ss;
		ss << stack.size();
		return ss.str();
	}

	//if turntable is occupied, put value on queue
	string addQueue() {
		if (turntable == NULL) {
			return "Turntable empty!";
		}
		queue.push(turntable);
		turntable = NULL;
		return "OK";
	}

	//if turntable is empty and queue is not empty, put top value of queue on turntable
	string removeQueue() {
		if (turntable != NULL) {
			return "Turntable occupied!";
		}
		if (queue.size() == 0) {
			return "Queue empty!";
		}
		turntable = queue.top();
		queue.pop();
		return "OK";
	}

	//return top value of queue
	string topQueue() {
		std::stringstream ss;
		ss << queue.top();
		return ss.str();
	}

	//return size of queue
	string sizeQueue() {
		std::stringstream ss;
		ss << queue.size();
		return ss.str();
	}

	//BONUS: check each container for value; if value is found, return string referring to location and index
	string find(T value) {
		std::stringstream ss;
		if (queue.find(value) != -1) {
			ss << "Queue[" << queue.find(value) << "]";
			return ss.str();
		}
		else if (stack.find(value) != -1) {
			ss << "Stack[" << stack.find(value) << "]";
			return ss.str();
		}
		else if (vector.find(value) != -1) {
			ss << "Train[" << vector.find(value) << "]";
			return ss.str();
		}
		else if (value == turntable) {
			return "Turntable";
		}
		return "Not Found!";
	}

	//return vector values in a " " separated string
	string toString() const {
		return vector.toString();
	}
private:
	Vector<T> vector;
	Stack<T> stack;
	Queue<T> queue;
	T turntable;
	bool empty;
};
#endif