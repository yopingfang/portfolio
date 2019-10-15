#ifndef SET_H
#define SET_H

#include "SetInterface.h"
#include "BST.h"

template<typename T>
class Set:
	public SetInterface<T>
{
private:
	BST<T>* theSet;

public:
	Set(): theSet(new BST<T>()) {}
	~Set() 
	{
		delete theSet;
	}

	/** Inserts item into the set, if the container doesn't
	already contain an element with an equivalent value.
	@return: pair.first = pointer to item
	pair.second = true if successfully inserted, else false. */
	//virtual Pair<T*, bool> insert(const T& item) = 0;
	bool insert(const T& item)
	{
		return theSet->addNode(item);
	}

	/** @return: the number of elements removed from the Set. */
	size_t erase(const T& item)
	{
		if (theSet->removeNode(item) == true)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	/** Removes all items from the set. */
	void clear()
	{
		theSet->clearTree();
	}

	/** @return: the number of elements contained by the Set. */
	size_t size() const
	{
		return theSet->theSize();
	}

	/** @return: return 1 if contains element equivalent to item, else 0. */
	size_t count(const T& item) const
	{
		//PLEASE WRITE A REAL ONE SOON
		if (theSet->removeNode(item) == true)
		{
			theSet->addNode(item);
			return 1;
		}
		else
		{
			return 0;
		}
	}

	/** @return: string representation of items in Set. */
	std::string toString() const
	{
		return theSet->toBSTString();
	}
};
#endif // SET_INTERFACE_H

