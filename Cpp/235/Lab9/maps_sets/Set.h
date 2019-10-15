#ifndef SET_H
#define SET_H
#include <iostream>
#include "SetInterface.h"
#include "BST.h"
using namespace std;

template<typename T>
class Set : public SetInterface<T>
{
public:
//private:
	BST<T> treeSet;
	size_t setSize;
//
	Set() {}
	~Set()
	{
		treeSet.clearTree();
		treeSet.deleteTree();
	}

	/** Inserts item into the set, if the container doesn't
	already contain an element with an equivalent value.
	@return: pair.first = pointer to item
	pair.second = true if successfully inserted, else false. */
	//virtual Pair<T*, bool> insert(const T& item) = 0;
	bool insert(const T& item)
	{
		setSize++;
		return treeSet.addNode(item);
	}

	/** @return: the number of elements removed from the Set. */
	size_t erase(const T& item)
	{
		if (treeSet.removeNode(item))
		{
			setSize--;
			return 1; //???
		}
		else return 0;
	}

	/** Removes all items from the set. */
	void clear()
	{
		treeSet.clearTree();
		setSize = 0;
	}

	/** @return: the number of elements contained by the Set. */
	size_t size() const
	{
		return setSize;
	}

	/** @return: return 1 if contains element equivalent to item, else 0. */
	size_t count(const T& item) const
	{
		if (treeSet.find(item))
		{
			return 1;
		}
		else return 0;
	}

	/** @return: string representation of items in Set. */
	std::string toString() const
	{
		return treeSet.printInorder();
	}

	friend ostream& operator<<(ostream& out,const Set& mySet)
	{
		out << mySet.toString();
		return out;
	}

	

	void deleteSet()
	{
		treeSet.deleteTree();
		setSize = 0;
	}

};

#endif
