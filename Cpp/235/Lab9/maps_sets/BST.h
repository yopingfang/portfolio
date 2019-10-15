#ifndef BST_H
#define BST_H
//#include "BSTInterface.h"

template <typename T>
class BST //: public BSTInterface<T>
{
public:
	BST(void) /** CONSTRUCTOR */
	{
		this->root = NULL;
	}
	~BST(void) /** DESTRUCTOR */
	{
		deleteTree(root);
	}

	/** WRAPPER: Return true if node added to BST, else false */
	bool addNode(const T& data)
	{
		return addNode(root, data);
	}

	/** WRAPPER: Return true if node removed from BST, else false */
	bool removeNode(const T& data)
	{
		return removeNode(root, data);
	}

	/** WRAPPER: Return true if BST cleared of all nodes, else false */
	bool clearTree()
	{
		return clearTree(root);
	}

	/** WRAPPER: Returns the size of the tree */
	size_t size() const
	{
		return size(root);
	}

	/** Return a level order traversal of a BST as a string */
	string toString() const
	{
		std::stringstream toString;
		if (root == NULL)
		{
			toString << " Empty";
		}
		else
		{
			int level = -1;
			do
			{
				toString << endl << "  " << ++level << ":";
			} while (outLevel(root, level, toString));
		}
		return toString.str();
	}

	/* WRAPPER: Returns true if the data can be found in the binary search tree */
	bool find(const T& data) const
	{
		return find(root, data);
	}

	/* WRAPPPER: Prints out tree in order */
	string printInorder() const
	{
		if (root == NULL)
		{
			return "";
		}
		std::stringstream inOrderString;
		return printInorder(root, inOrderString);
	}
//private:
	struct Node
	{
		T data;
		Node* left;
		Node* right;
		Node(T d) : data(d), left(NULL), right(NULL) { }
	};
	Node* root;

	/** Return true if node added to BST, else false */
	bool addNode(Node*& nodePtr, const T& data)
	{
		if (nodePtr == NULL)
		{
			nodePtr = new Node(data); //insert new Node
			return true;
		}
		else if (data == nodePtr->data)
		{
			return false;
		}
		else if (data < nodePtr->data)
		{
			return addNode(nodePtr->left, data);
		}
		else if (data > nodePtr->data)
		{
			return addNode(nodePtr->right, data);
		}
	}

	/** Return true if node removed from BST, else false */
	bool removeNode(Node*& nodePtr, const T& data)
	{
		if (nodePtr == NULL)
		{
			return false;
		}
		else
		{
			if (data < nodePtr->data)
			{
				return removeNode(nodePtr->left, data);
			}
			if (data > nodePtr->data)
			{
				return removeNode(nodePtr->right, data);
			}
			else //found item
			{
				Node* oldPtr = nodePtr;
				if (nodePtr->left == NULL)
				{
					nodePtr = nodePtr->right;
				}
				else if (nodePtr->right == NULL)
				{
					nodePtr = nodePtr->left;
				}
				else
				{
					replaceParent(oldPtr, oldPtr->left);
				}
				delete oldPtr;
				return true;
			}
		}
	}

	/* Replcaes the parent old root with local root */
	void replaceParent(Node*& oldRoot, Node*& localRoot)
	{
		if (localRoot->right != NULL)
		{
			replaceParent(oldRoot, localRoot->right);
		}
		else
		{
			oldRoot->data = localRoot->data;
			oldRoot = localRoot;
			localRoot = localRoot->left;
		}
	}

	/* Return true if BST cleared of all nodes, else false */
	bool clearTree(Node*& localRoot)
	{
		if (localRoot != NULL)
		{
			clearTree(localRoot->left);
			clearTree(localRoot->right);
			delete localRoot;
			localRoot = NULL;
		}
		return true;
	}

	/** Output nodes at a given level */
	bool outLevel(Node* root, int level, std::stringstream& out) const
	{
		if (root == NULL) return false;
		if (level == 0)
		{
			out << " " << root->data;
			if ((root->left != NULL) || (root->right != NULL)) return true;
			return false;
		}
		if ((level == 1) && !root->left && root->right)
		{
			out << " _";
		}
		bool left = outLevel(root->left, level - 1, out);
		bool right = outLevel(root->right, level - 1, out);
		if ((level == 1) && root->left && !root->right)
		{
			out << " _";
		}
		return left || right;
	}

	/* Returns true if the data can be found in the binary search tree */
	bool find(Node* localRoot, const T& data) const
	{
		if (localRoot == NULL)
		{
			return false;
		}
		else
		{
			if (data < localRoot->data)
			{
				return find(localRoot->left, data);
			}
			if (data > localRoot->data)
			{
				return find(localRoot->right, data);
			}
			else //found item
			{
				return true;
			}
		}
	}

	/* Given a binary tree, print its nodes in inorder*/
	string printInorder(Node* localRoot, std::stringstream& inOrderString) const
	{
		if (localRoot == NULL)
		{
			return inOrderString.str();
		}
		else
		{
			/* first recur on left child */
			printInorder(localRoot->left, inOrderString);

			/* then print the data of node */
			inOrderString << localRoot->data << " ";

			/* now recur on right child */
			printInorder(localRoot->right, inOrderString);
		}
		return inOrderString.str();
	}

	bool deleteTree()
	{
		return deleteTree(root);
	}
	bool deleteTree(Node*& localRoot)
	{
		if (localRoot != NULL)
		{
			deleteTree(localRoot->left);
			deleteTree(localRoot->right);
			delete localRoot;
			localRoot = NULL;
		}
		return true;
	}
};

#endif