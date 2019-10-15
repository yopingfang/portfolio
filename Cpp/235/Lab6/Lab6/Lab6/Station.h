//created by pp
#ifndef STATION_H
#define STATION_H

#include"Vector.h"
#include"Queue.h"
#include"Stack.h"
#include<string>
using namespace std;

template<typename T>
class Station {
private:
	Vector<T> train_;
	Stack<T> stack_;
	Queue<T> queue_;
	T turnTableCar;
	bool empty_;
public:
	Station() : turnTableCar(NULL) {};
	~Station() {};
	string addCar(const T& car) {
		if (turnTableCar == NULL) {
			turnTableCar = car;
			return "OK";
		}
		else return "Turntable occupied!";
	}
	string removeCar() {
		if (turnTableCar == NULL) {
			return "Turntable empty!";
		}
		train_.push_back(turnTableCar);
		turnTableCar = NULL;
		return "OK";
	}
	string topCar() {
		if (turnTableCar == NULL) {
			return "Turntable empty!";
		}
		ostringstream oSS;
		oSS << turnTableCar;
		return oSS.str();
	}
	string addStack() {
		if (turnTableCar == NULL) {
			return "Turntable empty!";
		}
		stack_.push(turnTableCar);
		turnTableCar = NULL;
		return "OK";
	}
	string removeStack() {
		if (turnTableCar == NULL) {
			turnTableCar = stack_.top();
			if (turnTableCar == NULL) {
				return "Stack empty!";
			}
			stack_.pop();
			return "OK";
		}
		else return "Turntable occupied!";
	}
	string topStack() {
		ostringstream oSS;
		if (stack_.top() == NULL) {
			return "Stack empty!";
		}
		oSS << stack_.top();
		return oSS.str();
	}
	string sizeStack() {
		ostringstream oSS;
		oSS << stack_.size();
		return oSS.str();
	}
	string addQueue() {
		if (turnTableCar == NULL) {
			return "Turntable empty!";
		}
		queue_.push(turnTableCar);
		turnTableCar = NULL;
		return "OK";
	}
	string removeQueue() {
		if (turnTableCar == NULL) {
			turnTableCar = queue_.top();
			if (turnTableCar == NULL) {
				return "Queue empty!";
			}
			queue_.pop();
			return "OK";
		}
		else return "Turntable occupied!";
	}
	string topQueue() {
		ostringstream oSS;
		if (queue_.top() == NULL) {
			return "Queue empty!";
		}
		oSS << queue_.top();
		return oSS.str();
	}
	string sizeQueue() {
		ostringstream oSS;
		oSS << queue_.size();
		return oSS.str();
	}
	string toString() {
		return train_.toString();
	}
	string find(T input) {
		ostringstream oSS;
		for (int i = 0; i < stack_.size(); i++) {
			if (input == stack_.at(i)) {
				oSS << "Stack[" << i << "]";
				return oSS.str();
			}
		}
		for (int i = 0; i < queue_.size(); i++) {
			if (input == queue_.at(i)) {
				oSS << "Queue[" << i << "]";
				return oSS.str();
			}
		}
		for (int i = 0; i < train_.size(); i++) {
			if (input == train_.at(i)) {
				oSS << "Train[" << i << "]";
				return oSS.str();
			}
		}
		if (input == turnTableCar) {
			return "Turntable";
		}
		else return "Not Found!";
	}
	void delAll() {
		stack_.delStack();
		queue_.delQ();
		train_.delTrain();
		return;
	}
};

#endif
