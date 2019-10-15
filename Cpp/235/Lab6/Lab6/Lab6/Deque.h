//created by pp
#ifndef DEQUE_H
#define DEQUE_H

#include"DequeInterface.h"
#include<sstream>
using namespace std;

template<typename T>
class Deque : public DequeInterface<unsigned int> {
private:
	T *d_data;
	size_t capacity;
	size_t numItems;
	size_t frontIndex;
	size_t rearIndex;
	void reallocate() {
		capacity *= 2;
		T* n_array = new T[capacity];
		for (int i = 0; i < capacity/2; i++) {
			n_array[i] = d_data[i];
		}
		delete d_data;
		d_data = n_array;
		return;
	}
public:
	Deque() :
		capacity(DequeInterface::DEFAULT_CAPACITY),
		numItems(0),
		frontIndex(0),
		rearIndex(0),
		d_data(new T[DEFAULT_CAPACITY]) {}

	~Deque(void) { delete d_data; }
	/** Insert item at front of deque */
	void push_front(const T& value) {

		numItems++;
		if (numItems > capacity) {
			reallocate();
		}
		T* n_array = new T[capacity];
		n_array[0] = value;
		for (int i = 0; i <= rearIndex; i++) {
			n_array[i + 1] = d_data[i];
		}
		rearIndex++;
		delete d_data;
		d_data = n_array;
		return;
	}

	/** Insert item at rear of deque */
	void push_back(const T& value) {

		numItems++;
		if (numItems > capacity) {
			reallocate();
		}
		if (numItems == 1) {
			d_data[0] = value;
		}
		else {
			rearIndex++;
			d_data[rearIndex] = value;
		}
	}

	/** Remove the front item of the deque */
	void pop_front(void) {
		if (numItems == 0) {
			return;
		}

		if (numItems > 1) {
			T *n_array = new T[capacity];
			for (int i = 1; i <= rearIndex; i++) {
				n_array[i - 1] = d_data[i];
			}
			delete d_data;
			d_data = n_array;
			rearIndex--;
		}
		else {
			d_data[0] = NULL;
		}
		numItems--;
		return;
	}

	/** Remove the rear item of the deque */
	void pop_back(void) {
		if (numItems == 0) {
			return;
		}

		if (numItems > 1) rearIndex--;
		else {
			d_data[0] = NULL;
		}
		numItems--;
		return;
	}

	/** Return the front item of the deque (Do not remove) */
	T& front(void) { return d_data[0]; }

	/** Return the rear item of the deque (Do not remove) */
	T& back(void) { return d_data[rearIndex]; }

	/** Return the number of items in the deque */
	size_t size(void) const { return numItems; }

	/** Return true if deque is empty */
	bool empty(void) const {
		if (numItems == 0) return true;
		else return false;
	}

	/** Return item in deque at index (0 based) */
	T& at(size_t index) { return d_data[index]; }

	/** Return the deque items */
	virtual string toString() const {
		ostringstream oSS;

		for (int i = 0; i <= rearIndex; i++) {
			oSS << d_data[i] << " ";
		}
		string rtnString = oSS.str();
		return rtnString;
	}
	void delDeck() {
		delete d_data;
		return;
	}

};

#endif