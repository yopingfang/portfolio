#ifndef MAP_H
#define MAP_H
#include "MapInterface.h"
#include "Map.h"
#include <string>
#include <cmath>
#include <typeinfo>

// Generic template for map<key,value>
template<typename K, typename V>
class Map : public MapInterface<K,V>
{
private:
	size_t const DEFAULT_CAPACITY = 31;
	int numKeys = 0;

	struct HashNode
	{
	public:
		K key;
		V value;
		HashNode(K k) 
		{
			this->key = k;
		}
		HashNode()
		{
			this->key = "";
			this->value = "";
		}
	};
	HashNode** hashTable;
	
public:
	Map()
	{
		hashTable = new HashNode*[DEFAULT_CAPACITY];
		for (int i = 0; i < DEFAULT_CAPACITY; i++)
		{
			hashTable[i] = NULL;
		}
	}
	~Map()
	{
		for (int i = 0; i < DEFAULT_CAPACITY; i++)
		{
			delete hashTable[i];
		}
		delete[] hashTable;
	}

	/** Read/write index access operator.
	If the key is not found, an entry is made for it.
	@return: Read and write access to the value mapped to the provided key. */
	virtual V& operator[](const K& key)
	{
		int hashedKey = hashFnc(key); 
		
		for (int i = hashedKey; i < DEFAULT_CAPACITY; i++)
		{
			if (hashTable[i] == NULL)
			{
				hashTable[i] = new HashNode(key);
				numKeys++;
				return hashTable[i]->value;
			}
			else if (i == DEFAULT_CAPACITY)
			{
				i = 0;
			}
			else if (hashTable[i]->key == key)
			{
				return hashTable[i]->value;
			}
		}
		
	}

	/* HASH FUNCTION */
	virtual int  hashFnc(std::string key)
	{
		//hash the key value
		int hash = 0;
		for (int i = 0; i < key.length(); ++i)
		{
			hash = hash + (key.at(i) * pow(DEFAULT_CAPACITY, key.length() - 1)); //from book "s0x31^(n-1) + s1x31^(n-2)...
		}
		hash = hash % 31;
		if (hash < 0)
		{
			hash = hash * -1;
		}
		return hash;
	}

	/** @return: the number of elements removed from the Map. */
	virtual size_t erase(const K& key)
	{
		int hashedKey = hashFnc(key);

		for (int i = hashedKey; i < DEFAULT_CAPACITY; i++)
		{
			if (hashTable[i]->key == key)
			{
				//delete hashTable[i];
				hashTable[i] = NULL;
				numKeys--;
				return 1;
			}
			if (i == DEFAULT_CAPACITY)
			{
				i = 0;
			}
			if (i == hashedKey - 1) //if the key is never found
			{
				return 0;
			}
		}
		
	}

	/** Removes all items from the Map. */
	virtual void clear()
	{
		for (int i = 0; i < DEFAULT_CAPACITY; i++)
		{
			if (hashTable[i] != NULL)
			{
				delete hashTable[i];
			}
		}
		delete[] hashTable;
		numKeys = 0;
	}

	/** @return: number of Key-Value pairs stored in the Map. */
	virtual size_t size() const
	{
		return numKeys;
	}

	/** @return: maximum number of Key-Value pairs that the Map can hold. */
	virtual size_t max_size() const
	{
		return DEFAULT_CAPACITY;
	}

	/** @return: string representation of Key-Value pairs in Map. */
	virtual std::string toString() const
	{
		std::stringstream toString;
			for (int i = 0; i < DEFAULT_CAPACITY; i++)
			{
				if (hashTable[i] != NULL)
				{
					toString << hashTable[i]->key << " " << hashTable[i]->value << endl;
				}
			}
			return toString.str();
	}

};

#endif
