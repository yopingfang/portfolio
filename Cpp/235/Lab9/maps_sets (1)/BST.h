/* BST template
contains root and node structure
defines addNode, addToTree, removeNode, removeFromTree, replaceParent, clear, toString and outLevel functions
*/

#include<sstream>

template <typename T>
class BST 
{
private:
	struct Node
	{
		T data;
		Node* right;
		Node* left;
	};
	Node* root;
	size_t numOfElem;

public:
	BST() : root(nullptr) {};
	~BST() 
	{
		clearTree();
	};


	/** Return true if node added to BST, else false */
	bool addNode(const T& data)
	{
		return addToTree(root, data);
	}

	/**recursively finds open leaf to add the new data if it is unique. Returns true if added, else false*/
	bool addToTree(Node*& currRoot, const T& newData)
	{
		if (currRoot == nullptr)
		{
			currRoot = new Node();
			currRoot->data = newData;
			numOfElem++;
			return true;
		}
		else
		{	
			if (currRoot->data > newData)
			{
				return addToTree(currRoot->left, newData);
			}
			else if (currRoot->data < newData)
			{
				return addToTree(currRoot->right, newData);
			}
			else
			{
				return false;
			}
		}

	}

	/** Return true if node removed from BST, else false */
	bool removeNode(const T& data) 
	{
		return removeFromTree(root, data);
	}

	/**Recursively finds the node to delete and calls replaceParent to situate the tree*/
	bool removeFromTree(Node*& currRoot, const T& newData)
	{
		if (currRoot == nullptr)
		{
			return false;
		}
		else
		{
			if (currRoot->data < newData)
			{
				return removeFromTree(currRoot->right, newData);
			}
			else if (currRoot->data > newData)
			{
				return removeFromTree(currRoot->left, newData);
			}
			else
			{
				Node* oldRoot = currRoot;
				if (currRoot->left == nullptr)
				{
					currRoot = currRoot->right;
				}
				else if (currRoot->right == nullptr)
				{
					currRoot = currRoot->left;
				}
				else
				{
					replaceParent(oldRoot, oldRoot->left);
				}
				delete oldRoot;
				numOfElem--;
				return true;
			}
		}
	}

	/**replaces parent nodes with inorder predecessor*/
	void replaceParent(Node*& parentRoot, Node*& chillunNode)
	{
		if (chillunNode->right != nullptr)
		{
			replaceParent(chillunNode, chillunNode->right);
		}
		else
		{
			parentRoot->data = chillunNode->data;
			parentRoot = chillunNode;
			chillunNode = chillunNode->left;
		}
	}

	/** Return true if BST cleared of all nodes, else false */
	bool clearTree() 
	{
		while (root != nullptr)
		{
			removeNode(root->data);
		}
		return true;
	}

	/** Return a level order traversal of a BST as a string */
	std::string toBSTString() 
	{
		std::stringstream out;
		if (root == NULL) out << " Empty";
		else
		{
			int level = -1;
			do
			{
				level++;
			} while (outLevel(root, level, out));
		}
		return out.str();
	}
	/**returns values level by level*/
	bool outLevel(Node* root, int level, std::stringstream& out) const
	{
		if (root == NULL)
		{
			return false;
		}
		if (level == 0)
		{
			out << " " << root->data;
			if ((root->left != NULL) || (root->right != NULL)) return true;
			return false;
		}
//		if ((level == 1) && !root->left && root->right) out << " _";
		bool left = outLevel(root->left, level - 1, out);
		bool right = outLevel(root->right, level - 1, out);
//		if ((level == 1) && root->left && !root->right) out << " _";
		return left || right;
	}

	size_t theSize()
	{
		return numOfElem;
	}

/*	bool find(T item) const
	{

	}*/
};

