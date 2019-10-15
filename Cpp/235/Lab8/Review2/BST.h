#ifndef BST_H
#define BST_H

#include "BSTInterface.h"
#include <sstream>
#include <stack>

using std::string;

template<typename T>
class BST : public BSTInterface<T>
{
	friend class Iterator;
private:
	//Nested node struct to be used in the binary search tree
	struct Node
	{
		T value;
		Node* left;
		Node* right;

		Node(T input) : value(input), left(nullptr), right(nullptr) {}
	};

	Node* root;

public:
	//Constructor and destructor:
	BST(void) { root = nullptr; }
	~BST(void) { clearTree(); }

	//Iterator class is nested in BST:
	class Iterator
	{
		friend class BST<T>;
	private:
		typename BST<T>::Node* itRoot;
		size_t numItems;
		//Choose an array size of 15 for this application since it's very unlikely we'll use a binary tree with
		//enough levels to need a bigger one
		Node* path[15];

	public:

		Iterator(Node* root) : itRoot(root),
			numItems(0) {}
		~Iterator() {}
		
		/*Overloads the asterisk operator so that in the main function we can use it to reference the data in the Node the iterator points to*/
		T operator*() const
		{
			if (itRoot != nullptr)
				return itRoot->value;
			else
				return T();
		}

		/*Overloads the ++ operator so that it can be used to move the iterator to the next Node*/
		Iterator& operator++()
		{
			//If the node has right children, go right, then go left as long as we can--that is
			//the next inorder value
			if (itRoot->right != nullptr)
			{
				itRoot = itRoot->right;
				Node* temp;
				while (itRoot->left != nullptr)
				{
					temp = itRoot;
					itRoot = itRoot->left;
					numItems++;
					path[numItems - 1] = temp;
				}
			}
			else
			{
				//If the node has no right children, we need to go back
				//In the array we've been keeping track of the roots we've passed but not output
				//Set the node to the root at the end of the array and decrement numItems to remove
				//it from the array
				if (numItems > 0)
				{
					itRoot = path[numItems - 1];
					numItems--;
				}
				else
					itRoot = nullptr;
			}

			return *this;
		}

		/*Overloads the != operator so it can be used to compare two nodes and see if they are different*/
		bool operator!=(const Iterator& compIterator)
		{
			if (itRoot != compIterator.itRoot)
				return true;
			else
				return false;
		}

		void findStart()
		{
			//Go left until we can't go left any longer--that is the first item in the BST
			Node* temp;
			while (itRoot->left != nullptr)
			{
				temp = itRoot;
				itRoot = itRoot->left;
				numItems++;
				path[numItems - 1] = temp;
			}
		}
	};

	/*Returns an iterator object that points to the beginning of the list*/
	Iterator begin()
	{
		//Initialize it with the root node of the BST and then use findStart()
		//to set it to the smallest item in the tree
		Iterator myIterator(BST::root);
		if(BST::root != nullptr)
			myIterator.findStart();
		return myIterator;
	}

	Iterator end()
	{
		//Initialize the end iterator with NULL
		Iterator myIterator(nullptr);
		return myIterator;
	}

	/** Return true if node added to BST, else false 
	*This function is a wrapper for the addNode function that takes arguments of
	*node and data. The wrapper function passes in the root as the starting node*/
	bool addNode(const T& data)
	{
		return addNode(root, data);
	}

	/*Takes arguments Node and data
	*Returns true if node added; false if the node is found to be already in the BST
	*/
	bool addNode(Node*& node, const T& data)
	{
		if (node == nullptr)
		{
			node = new Node(data);
			return true;
		}
		else if (node->value == data)
			return false;
		//Checks to see how the data compares to the current node. If it is less, we need to move left;
		//if it is more, we need to move right. Then calls the addNode function recursively to repeat 
		//the process with the left or right child of the current node.
		else if (data < node->value)
			return addNode((node->left), data);
		else
			return addNode((node->right), data);
	}

	/** Return true if node removed from BST, else false
	*Wrapper function for removeNode; passes in the root node as the starting point
	*/
	bool removeNode(const T& data)
	{
		return removeNode(root, data);
	}

	bool removeNode(Node*& node, const T& data)
	{
		if (node == nullptr)
			return false;
		//Recursively calls removeNode again with either the left or right child of the current node, depending
		//on whether the data is less or greater than that in the current node
		else if (data < node->value)
			return removeNode(node->left, data);
		else if (data > node->value)
			return removeNode(node->right, data);
		else
		//We have found the node we want to remove!
		{
			//temp will be a placeholder for the node we want to delete
			Node* temp = node;
			//If the node only has one child, we can change our reference to the current node to 
			//reference its child, erasing the current node
			if (node->left == nullptr)
				node = node->right;
			else if (node->right == nullptr)
				node = node->left;
			//If it has more than one child, we need to find the inordr predecessor using the
			//switchParent function
			else
				switchParent(temp, temp->left);
			delete temp;
			return true;
		}
	}

	void switchParent(Node*& oldRoot, Node*& current)
	{
		//Keep moving right down the tree until we find the rightmost node
		//in the right subtree of the left child of the node we want to delete
		//(current is the left child of the node to delete)
		if (current->right != nullptr)
			switchParent(oldRoot, current->right);
		else
		{
			oldRoot->value = current->value;
			oldRoot = current;
			current = current->left;
		}
	}

	/** Return true if BST cleared of all nodes, else false */
	bool clearTree()
	{
		if (root == nullptr)
			return true;
		//Delete all nodes to the left of the root
		while (root->left != nullptr)
		{
			removeNode(root->left->value);
		}
		//Delete all nodes to the right of the rooot
		while (root->right != nullptr)
		{
			removeNode(root->right->value);
		}
		//Delete the root
		removeNode(root->value);
		
		return true;
	}

	bool outLevel(Node* root, int level, std::stringstream& output) const
	{
		if (root == nullptr)
			return false;
		else if (level == 0)
		{
			output << " " << root->value;
			//If the root has no children, return false; otherwise true
			if ((root->left != nullptr) || (root->right != nullptr))
				return true;
			else
				return false;
		}
		//Output _ if there is no left child
		if ((level == 1) && (root->left == nullptr) && (root->right != nullptr))
			output << " " << "_";
		//Call outLevel again with the left subtree of the root
		bool left = outLevel(root->left, level - 1, output);
		//Call outLevel again with the right subtree of the root
		bool right = outLevel(root->right, level - 1, output);
		//Output _ if there is no right child
		if ((level == 1) && (root->right == nullptr) && (root->left != nullptr))
			output << " " << "_";
		return left || right;
	}

	/** Return a level order traversal of a BST as a string */
	string toString() const
	{
		int counter = 0;
		int level = -1;
		std::stringstream output;
		//Increment level and keep outputting each level of the tree until outLevel returns false
		//(there are no more nodes to output)
		do
		{
			output << "\n  " << ++level << ":";
			counter++;
		} while (outLevel(root, level, output));

		if (output.str() == "\n  0:")
			return " Empty";

		string printedList = output.str();
		return printedList;
	}

	/** Override insertion operator to insert BST string */
	friend std::ostream& operator<<(std::ostream& os, const BST<T>& bst)
	{
		os << bst.toString();
		return os;
	}

};


#endif //BST_H


