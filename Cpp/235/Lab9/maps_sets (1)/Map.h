/* Map template class
Contains MapNode class, definitions of operator[](), erase(), 
clear(), size(), max_size(), toString()
*/

#ifndef MAP_H
#define MAP_H
#include"MapInterface.h"
#include"Set.h"
#include <string>

template <typename K, typename V>
class Map :
	public MapInterface< K, V>
{
	struct MapNode
	{
		MapNode() : key(K()), value(V()), next(NULL) {}
		MapNode(K keyData, V valueData, MapNode* theNext): key(keyData), value(valueData), next(theNext) {}
		K getKey() { return key; }
		V& getValue() { return value; }
		MapNode* next = nullptr;

	private:
		K key;
		V value = V();
	};
	MapNode** hashTable;
	size_t numOfPairs;

public:
	static const int HashTableSize = 31;
	static const int BonusHashTableSize = 7;

	Map() : hashTable(new MapNode*[HashTableSize]) {}
	~Map() 
	{
		clear();
		delete[] hashTable;
	}

	/** Read/write index access operator.
	If the key is not found, an entry is made for it.
	@return: Read and write access to the value mapped to the provided key. */
	V& operator[](const K& key)
	{
		int location = hashAlg(key);
		MapNode* theChosenOne = hashTable[location];

		while (theChosenOne != NULL)
		{
			if (theChosenOne->getKey() == key)
			{
				return theChosenOne->getValue();
			}
			theChosenOne = theChosenOne->next;
		}

		MapNode* theNewOne = new MapNode(key, V(), NULL);
		if (theChosenOne == NULL)
		{
			theChosenOne->next = theNewOne;
		}
		return theNewOne->getValue();
	}

	/** @return: the hash position of the key*/
	int hashAlg(K key)
	{
		int code = 0;
		int mult = 1;
		for (size_t i = 0; i < key.length(); i++)
		{
			code += mult * key[i];
		}
		return code % HashTableSize;
	}

	/** @return: the number of elements removed from the Map. */
	size_t erase(const K& key)
	{
		int location = hashAlg(key);
		MapNode* beforeChosen = NULL;
		MapNode* theChosenOne = hashTable[location];

		if (theChosenOne == NULL)
		{
			return 0;
		}
		while (theChosenOne != NULL && theChosenOne->getKey() != key)
		{
			beforeChosen = theChosenOne;
			theChosenOne = theChosenOne->next;
		}
		if (theChosenOne == NULL)
		{
			return 0;
		}
		else
		{
			if (beforeChosen == NULL)
			{
				hashTable[location] = theChosenOne->next;
			}
			else
			{
				beforeChosen->next = theChosenOne->next;
			}

			delete theChosenOne;
			numOfPairs--;
			return 1;
		}
	}

	/** Removes all items from the Map. */
	void clear()
	{
		for (int i = 0; i < HashTableSize; i++)
		{
			MapNode* theChosenOne = hashTable[i];
			if (theChosenOne == NULL)
			{
				return;
			}
			while (theChosenOne != NULL)
			{
				MapNode* chosenBefore = theChosenOne;
				theChosenOne = theChosenOne->next;
				delete chosenBefore;
			}
			hashTable[i] = NULL;
			numOfPairs = 0;
		}
	}


	/** @return: number of Key-Value pairs stored in the Map. */
	size_t size() const
	{
		return numOfPairs;
	}

	/** @return: maximum number of Key-Value pairs that the Map can hold. */
	size_t max_size() const
	{
		return 1000;	//benefit of chaining!
	}

	/** @return: string representation of Key-Value pairs in Map. */
	std::string toString() const
	{
		std::stringstream outStr;
		for (int i = 0; i < HashTableSize; i++)
		{
			MapNode* theChosenOne = hashTable[i];
			while (theChosenOne != NULL)
			{
				outStr << theChosenOne->getKey() << "\n";
				theChosenOne = theChosenOne->next;
			}
		}
		return outStr.str();
	}
};

#endif // MAP_H

