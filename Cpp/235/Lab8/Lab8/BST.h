#ifndef BST_H
#define BST_H

#include"BSTInterface.h"
#include<sstream>
using namespace std;

template<typename T>
class BST : public BSTInterface<int> {
private:
	struct Node {
		T data_;
		Node *right_;
		Node *left_;
		Node(T d) : data_(d), right_(NULL), left_(NULL) {}
		~Node() {}
	};
	Node *root_;
public:
	BST() { this->root_ = NULL; }
	~BST() { clearTree(); delete root_; }
	/*class Iterator {
	private:
		mutable int index_;
		Node* root_i;
	public:
		Iterator(int index, Node* root) : index_(index), root_i(root) {}
		~Iterator() {}
		virtual bool operator!=(const Iterator& rhs) const {
			if (rhs->index_ == index_) return true;
			else return false;
		}
		virtual Iterator operator++(T) {
			Node* node = root_;
			index_++;
			while (node->data_ !=)
			if (root_i->right_ != NULL) {

				while (root_i->right_ != NULL) {
					root_i == root_i->right_;
				}
			}

			return *this;
		}
		virtual T operator*() const {
			return index_;
		}
	};
	virtual Iterator begin() {
		Node *node;

		Iterator newIter(0, root_);
		return newIter;
	}
	virtual Iterator end() { ... }
	virtual Iterator find(T& value) { ... }*/

	/** Return true if node added to BST, else false (wrapper function)*/
	bool addNode(const T& data) {
		return addNode(data, root_);
	}
	/** Recursive portion of above*/
	bool addNode(const T& data, Node*& node) {
		if (node == NULL) {
			node = new Node(data);
			return true;
		}
		if (data == node->data_) {
			return false;
		}
		if (data < node->data_) {
			return addNode(data, node->left_);
		}
		if (data > node->data_) {
			return addNode(data, node->right_);
		}
	}

	/** Return true if node removed from BST, else false */
	bool removeNode(const T& data) {
		return removeNode(data, root_);
	}
	bool removeNode(const T& data, Node*& node) {
		if (node == NULL) return false;
		if (data < node->data_) return removeNode(data, node->left_);
		if (data > node->data_) return removeNode(data, node->right_);
		Node *deleteNode = node;
		if (node->left_ == NULL) {
			node = node->right_;
		}
		else if (node->right_ == NULL) {
			node = node->left_;
		}
		else {
			replaceParent(deleteNode, deleteNode->left_);
		}
		delete deleteNode;
		return true;
	}
	/** switches a removed parent node with its inorder predecessor */
	void replaceParent(Node*& deleteNode, Node*& replaceNode) {
		if (replaceNode->right_ != NULL) {
			replaceParent(deleteNode, replaceNode->right_);
		}
		else {
			deleteNode->data_ = replaceNode->data_;
			deleteNode = replaceNode;
			replaceNode = replaceNode->left_;
		}
		return;
	}

	/** Return true if BST cleared of all nodes, else false */
	bool clearTree() {
		bool isClear = clearTree(root_);
		root_ = NULL;
		return isClear;
	}
	bool clearTree(Node*& node) {
		if (root_ == NULL) {
			return true;
		}
		if (node->left_ != NULL) {
			clearTree(node->left_);
		}
		if (node->right_ != NULL) {
			clearTree(node->right_);
		}
		delete node;
		return true;
	}

	/** Return a level order traversal of a BST as a string */
	string toString() const {
		
		stringstream out;
		if (root_ == NULL) {
			return " Empty";
		}
		
		else {
			int level = -1;
			do
			{
				out << endl << "  " << ++level << ":";
			} while (outLevel(root_, level, out));
		}
		return out.str();
	}
	/** Output nodes at a given level */
	bool outLevel(Node* root, int level, stringstream& out) const {
		if (root == NULL) return false;
		if (level == 0)
		{
			out << " " << root->data_;
			if ((root->left_ != NULL) || (root->right_ != NULL)) return true;
			return false;
		}
		if ((level == 1) && !root->left_ && root->right_) out << " _";
		bool left = outLevel(root->left_, level - 1, out);
		bool right = outLevel(root->right_, level - 1, out);
		if ((level == 1) && root->left_ && !root->right_) out << " _";
		return left || right;
	}
};

#endif