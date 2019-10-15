#ifndef DEQUE_H
#define DEQUE_H
#include <string>
#include <sstream>
#include "DequeInterface.h"
using std::string;

template<typename T>
class Deque : public DequeInterface<T> {
public:

	Deque(void) :
		capacity(DEFAULT_CAPACITY),
		numItems(0),
		frontIndex(0),
		rearIndex(DEFAULT_CAPACITY - 1),
		theData(new T[DEFAULT_CAPACITY]) {}
	~Deque(void) {
		delete[] theData;
	}

	/** Insert item at front of deque */
	void push_front(const T& value) {
		//double size of array if needed
		if (numItems == capacity) {
			reallocate();
		}
		numItems++;
		frontIndex = (frontIndex - 1) % capacity;
		theData[frontIndex] = value;
	}

	/** Insert item at rear of deque */
	void push_back(const T& value) {
		//double size of array if needed
		if (numItems == capacity) {
			reallocate();
		}
		numItems++;
		rearIndex = (rearIndex + 1) % capacity;
		theData[rearIndex] = value;
	}

	/** Remove the front item of the deque */
	void pop_front(void) {
		frontIndex = (frontIndex + 1) % capacity;
		numItems--;
	}

	/** Remove the rear item of the deque */
	void pop_back(void) {
		rearIndex = (rearIndex - 1) % capacity;
		numItems--;
	}

	/** Return the front item of the deque (Do not remove) */
	T& front(void) {
		return(theData[frontIndex]);
	}

	/** Return the rear item of the deque (Do not remove) */
	T& back(void) {
		return(theData[(rearIndex - 1) % capacity]);
	}

	/** Return the number of items in the deque */
	size_t size(void) const {
		return numItems;
	}

	/** Return true if deque is empty */
	bool empty(void) const {
		if (numItems == 0) {
			return true;
		}
		return false;
	}

	/** Return item in deque at index (0 based) */
	T& at(size_t index) {
		return(theData[index]);
	}

	/** Return the deque items */
	string toString() const {
		std::stringstream ss;
		//iterate through array and put items in stringstream
		for (size_t i = 0; i < numItems - 1; i++) {
			int index = (i + frontIndex) % capacity;
			ss << theData[index] << " ";
		}
		ss << theData[rearIndex];
		return ss.str();
	}

	//iterate through container numItems -1 times and compare search value to value at index (starting at front index)
	int find(T value) const {
		for (size_t k = 0; k < numItems; k++) {
			int index = (k + frontIndex) % capacity;
			if (theData[index] == value) {
				return k;
			}
		}
		return -1;
	}

private:
	static const size_t DEFAULT_CAPACITY = 4;
	size_t capacity;
	size_t numItems;
	size_t frontIndex;
	size_t rearIndex;
	T* theData;
	//reallocate function doubles the size of the current array
	void reallocate() {
		size_t newCapacity = 2 * capacity;
		T* newData = new T[newCapacity];
		size_t j = frontIndex;
		for (size_t i = 0; i < numItems; i++) {
			newData[i] = theData[j];
			j = (j + 1) % capacity;
		}
		frontIndex = 0;
		rearIndex = numItems - 1;
		capacity = newCapacity;
		std::swap(theData, newData);
		delete[] newData;
	}
};
#endif // DEQUE_H
