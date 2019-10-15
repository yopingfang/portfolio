#ifndef QUICKSORT_H
#define QUICKSORT_H

#include"QSInterface.h"
#include<sstream>

template<typename T>
class QuickSort : public QSInterface<T> {
private:
	T* array_;
	int capacity_;
	int size_;
	const int INITIAL_CAPACITY = 7;
public:
	QuickSort() {
		array_ = nullptr;
		capacity_ = INITIAL_CAPACITY;
	}
	~QuickSort() { delete array_; }

	/** Dynamically allocate an initial array to the QuickSort class. */
	bool createArray(size_t capacity) {
		clear();
		array_ = new T[capacity];
		capacity_ = capacity;
		return true;
	}

	/** Add an element to the QuickSort array. Dynamically grow array as needed. */
	bool addElement(T element) {
		if (size_ == capacity_) {
			capacity_ *= 2;
			T* n_array = new T[capacity_];
			for (unsigned int i = 0; i < size_; i++) {
				n_array[i] = array_[i];
			}
			delete array_;
			array_ = n_array;
		}
		array_[size_] = element;
		size_++;
		return true;
	}

	/** Sort the elements of a QuickSort subarray using median and partition functions. */
	bool sort(size_t left, size_t right) {
		if (left + 1 == right) return true;
		if (right - left == 2 && array_[left] < array_[right - 1]) return true;
		int pivotIndex = medianOfThree(left, right);
		pivotIndex = partition(left, right, pivotIndex);
		sort(left, pivotIndex);
		sort(pivotIndex, right);
		return true;
	}

	/** Sort all elements of the QuickSort array using median and partition functions. */
	bool sortAll() {
		int pivotIndex = medianOfThree(0, size_);
		pivotIndex = partition(0, size_, pivotIndex);
		sort(0, pivotIndex);
		sort(pivotIndex, size_);
		return true;
	}

	/** Removes all items from the QuickSort array. */
	bool clear() {
		if (array_ != NULL) {
			delete array_;
			array_ = NULL;
			size_ = 0;
			array_ = new T[capacity_];
			return true;
		}
		else return false;
	}

	/** Return size of the QuickSort array. */
	size_t capacity() const { return capacity_; }

	/** Return number of elements in the QuickSort array. */
	size_t size() const { return size_; }

	/** The median of three pivot selection has two parts:
	1) Calculates the middle index by averaging the given left and right indices:
	middle = (left + right)/2
	2) Then bubble-sorts the values at the left, middle, and right indices.

	After this method is called, data[left] <= data[middle] <= data[right].

	@param left - the left boundary for the subarray from which to find a pivot
	@param right - the right + 1 boundary for the subarray from which to find a pivot
	@return the index of the pivot (middle index).
	Return -1 if	1) the array is empty,
	2) if either of the given integers is out of bounds,
	3) or if the left index is not less than the right index.
	*/
	int medianOfThree(size_t left, size_t right) { 
		if (size_ == 0 || left < 0 || right > size_ || left >= right) return -1;
		int middle_i = (left + right) / 2;
		right = right - 1;
		while (array_[left] > array_[right] || array_[middle_i] > array_[right] || array_[left] > array_[middle_i]) {
			if (array_[left] > array_[middle_i]) {
				T temp = array_[left];
				array_[left] = array_[middle_i];
				array_[middle_i] = temp;
			}
			if (array_[middle_i] > array_[right]) {
				T temp = array_[middle_i];
				array_[middle_i] = array_[right];
				array_[right] = temp;
			}
		}
		return middle_i;
	}

	/** Partitions a subarray around a pivot value selected according
	to median-of-three pivot selection. Because there are multiple ways
	to partition a list, follow the algorithm on page 611.

	The values which are smaller than the pivot should be placed to the left of the pivot;
	the values which are larger than the pivot should be placed to the right of the pivot.

	@param left - left index for the subarray to partition.
	@param right - right index + 1 for the subarray to partition.
	@param pivotIndex - index of the pivot in the subarray.
	@return the pivot's ending index after the partition completes:
	Return -1 if	1) the array is empty,
	2) if any of the given indexes are out of bounds,
	3) if the left index is not less than the right index.
	*/
	int partition(size_t left, size_t right, size_t pivotIndex) { 
		if (size_ == 0 || left < 0 || right > size_ || left >= right || pivotIndex >= right) return -1;
		T temp = array_[pivotIndex];
		array_[pivotIndex] = array_[left];
		array_[left] = temp;
		int up_i = left + 1;
		int down_i = right- 1;
		do {
			while (array_[up_i] <= array_[left] && up_i != (right - 1)) {
				up_i++;
			}
			while (array_[down_i] > array_[left] && down_i != (left + 1)) {
				down_i--;
			}
			if (up_i > down_i || up_i == down_i) break;
			if (array_[up_i] > array_[down_i]) {
				temp = array_[down_i];
				array_[down_i] = array_[up_i];
				array_[up_i] = temp;
			}
		} while (up_i < down_i);
		temp = array_[left];
		array_[left] = array_[down_i];
		array_[down_i] = temp;
		return down_i;
	}

	/** @return: comma delimited string representation of the array. */
	std::string toString() const {
		if (size_ == 0) return "Empty";

		ostringstream oSS;

		for (int i = 0; i < size_ - 1; i++) {
			oSS << array_[i] << ",";
		}
		oSS << array_[size_ - 1];
		string toR = oSS.str();
		return toR;
	}
};

#endif
