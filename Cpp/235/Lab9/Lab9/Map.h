#ifndef MAP_H
#define MAP_H

#include <string>
#include"SetInterface.h"
#include"MapInterface.h"
using namespace std;

template<typename K, typename V>
class Map : public MapInterface<K, V> {};

template<typename K>
class Map<K, string> : public MapInterface<K, string> {
private:
	static const int HashTableSize = 31; //autograder wouldnt compile without this here
	static const int BonusHashTableSize = 7;
	struct M_node {
		M_node(K left, string right) : key_(left), value_(right) {}
		M_node(K left) : key_(left) {}
		K key_;
		string value_;
	};
	M_node **dex_;
	int size_;
public:
	Map() {
		dex_ = new M_node*[BonusHashTableSize];
		for (unsigned int i = 0; i < BonusHashTableSize; i++) {
			dex_[i] = NULL;
		}
		size_ = BonusHashTableSize;
	}
	~Map() { clear(); delete[] dex_; }
	/** Read/write index access operator.
	If the key is not found, an entry is made for it.
	@return: Read and write access to the value mapped to the provided key. */
	std::string& operator[](const K& key) {

		int index = hashFunct(key);

		//collisions
		while (dex_[index] != NULL) {
			if (dex_[index]->key_ == key) {
				return dex_[index]->value_;
			}
			else index++;
			if (index >= size_) {
				index = 0;
			}
		}
		
		bool hasSpace = validSize();
		if (!hasSpace) resize();
		dex_[index] = new M_node(key);

		return dex_[index]->value_;
	}

	/** @return: the number of elements removed from the Map. */
	size_t erase(const K& key) {
		
		int index = hashFunct(key);
		
		dex_[index]->key_ = "TEMP";

		return 1;
	}

	/** Removes all items from the Map. */
	void clear() {

		for (unsigned int i = 0; i < size_; i++) {
			delete dex_[i];
		}

		return;
	}

	/** @return: number of Key-Value pairs stored in the Map. */
	size_t size() const {

		int numItems = 0;
		for (unsigned int i = 0; i < HashTableSize; i++) {
			if (dex_[i] != NULL && dex_[i]->key_ != "TEMP") {
				numItems++;
			}
		}

		return numItems;
	}

	/** @return: maximum number of Key-Value pairs that the Map can hold. */
	size_t max_size() const {
		return size_;
	}

	/** @return: string representation of Key-Value pairs in Map. */
	std::string toString() const {
		
		ostringstream oSS;

		for (unsigned int i = 0; i < size_; i++) {
			if (dex_[i] != NULL && dex_[i]->key_ != "TEMP") {
				oSS << dex_[i]->key_ << ": " << dex_[i]->value_ << endl;
			}
		}

		return oSS.str();
	}

	/**Hashes and returns index*/
	int hashFunct(K key) const {
		int toHash = 0;
		for (unsigned int i = 0; i < key.size(); i++) {
			toHash += key[i];
		}

		int index = toHash % size_;
		return index;
	}
	/**Resizes array*/
	void resize() {

		size_ *= 2;
		M_node** newDex_ = new M_node*[size_];
		for (unsigned int i = 0; i < size_; i++) {
			newDex_[i] = NULL;
		}
		
		for (unsigned int i = 0; i < (size_ / 2); i++) {
			if (dex_[i] != NULL && dex_[i]->key_ != "TEMP") {
				int newIndex = hashFunct(dex_[i]->key_);
				while (newDex_[newIndex] != NULL) {
					newIndex++;
					if (newIndex >= size_) {
						newIndex = 0;
					}
				}
				newDex_[newIndex] = new M_node(dex_[i]->key_);
				newDex_[newIndex]->value_ = dex_[i]->value_;
			}
		}
		for (unsigned int i = 0; i < (size_ / 2); i++) {
			delete dex_[i];
		}
		delete[] dex_;
		dex_ = newDex_;
		return;
	}
	/**Checks if array needs to be resized*/
	bool validSize() {
		int currentFill = 0;
		for (unsigned int i = 0; i < size_; i++) {
			if (dex_[i] != NULL && dex_[i]->key_ != "TEMP") {
				currentFill++;
			}
		}
		if (static_cast<double>(currentFill) / static_cast<double>(size_) > 0.75) {
			return false;
		}
		else return true;
	}
};

template<typename K> //special template for effectivites and ineffectivites (almost identical to above)
class Map<K, Set<string>> : public MapInterface<K, Set<string>> {
private:
	static const int HashTableSize = 31; //autograder wouldnt compile without this here
	static const int BonusHashTableSize = 7;
	struct M_node {
		M_node(K left, Set<string> right) : key_(left), value_(right) {}
		M_node(K left) : key_(left) {}
		K key_;
		Set<string> value_;
	};
	M_node **dex_;
	int size_;
public:
	Map() {
		dex_ = new M_node*[BonusHashTableSize];
		for (unsigned int i = 0; i < BonusHashTableSize; i++) {
			dex_[i] = NULL;
		}
		size_ = BonusHashTableSize;
	}
	~Map() { clear(); delete[] dex_; }
	/** Read/write index access operator.
	If the key is not found, an entry is made for it.
	@return: Read and write access to the value mapped to the provided key. */
	Set<string>& operator[](const K& key) {

		bool hasSpace = validSize();
		if (!hasSpace) resize();
		int index = hashFunct(key);

		//collisions
		while (dex_[index] != NULL) {
			if (dex_[index]->key_ == key) {
				return dex_[index]->value_;
			}
			else index++;
			if (index >= size_) {
				index = 0;
			}
		}

		dex_[index] = new M_node(key);

		return dex_[index]->value_;
	}

	/** @return: the number of elements removed from the Map. */
	size_t erase(const K& key) {

		int index = hashFunct(key);

		dex_[index]->key_ = "TEMP";

		return 1;
	}

	/** Removes all items from the Map. */
	void clear() {

		for (unsigned int i = 0; i < size_; i++) {
			delete dex_[i];
		}

		return;
	}

	/** @return: number of Key-Value pairs stored in the Map. */
	size_t size() const {

		int numItems = 0;
		for (unsigned int i = 0; i < HashTableSize; i++) {
			if (dex_[i] != NULL && dex_[i]->key_ != "TEMP") {
				numItems++;
			}
		}

		return numItems;
	}

	/** @return: maximum number of Key-Value pairs that the Map can hold. */
	size_t max_size() const {
		return size_;
	}
	/** @return: string representation of Key-Value pairs in Map. */
	std::string toString() const {

		ostringstream oSS;

		for (unsigned int i = 0; i < size_; i++) {
			if (dex_[i] != NULL && dex_[i]->key_ != "TEMP") {
				oSS << dex_[i]->key_ << ": " << dex_[i]->value_.toString() << endl;
			}
		}

		return oSS.str();
	}

	/**Hashes and returns index*/
	int hashFunct(K key) const {
		int toHash = 0;
		for (unsigned int i = 0; i < key.size(); i++) {
			toHash += key[i];
		}

		int index = toHash % size_;
		return index;
	}
	/**Resizes array*/
	void resize() {

		size_ *= 2;
		M_node** newDex_ = new M_node*[size_];
		for (unsigned int i = 0; i < size_; i++) {
			newDex_[i] = NULL;
		}

		for (unsigned int i = 0; i < (size_ / 2); i++) {
			if (dex_[i] != NULL && dex_[i]->key_ != "TEMP") {
				int newIndex = hashFunct(dex_[i]->key_);
				while (newDex_[newIndex] != NULL) {
					newIndex++;
					if (newIndex >= size_) {
						newIndex = 0;
					}
				}
				newDex_[newIndex] = new M_node(dex_[i]->key_);
				newDex_[newIndex]->value_ = dex_[i]->value_;
			}
		}
		for (unsigned int i = 0; i < (size_ / 2); i++) {
			delete dex_[i];
		}
		delete[] dex_;
		dex_ = newDex_;
		return;
	}
	/**Checks if array needs to be resized*/
	bool validSize() {
		int currentFill = 0;
		for (unsigned int i = 0; i < size_; i++) {
			if (dex_[i] != NULL && dex_[i]->key_ != "TEMP") {
				currentFill++;
			}
		}
		if (static_cast<double>(currentFill) / static_cast<double>(size_) > 0.75) {
			return false;
		}
		else return true;
	}
};


#endif
