#ifndef SET_H
#define SET_H

#include"SetInterface.h"
#include<sstream>
using namespace std;

template<typename T>
class Set : public SetInterface<T> {
private:
	struct Node {
		T data_;
		Node *right_;
		Node *left_;
		Node(T d) : data_(d), right_(NULL), left_(NULL) {}
		~Node() {}
	};
	Node *root_;
	int numItems;
public:
	Set() { root_ = NULL; numItems = 0; }
	~Set() { clear(); }
	/** Inserts item into the set, if the container doesn't
	already contain an element with an equivalent value.
	@return: pair.first = pointer to item
	pair.second = true if successfully inserted, else false. */
	//virtual Pair<T*, bool> insert(const T& item) = 0;
	bool insert(const T& item) {
		bool isAdded = addNode(item, root_);
		if (isAdded) numItems++;
		return isAdded;
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

	/** @return: the number of elements removed from the Set. */
	size_t erase(const T& item) {
		bool isErased = removeNode(item, root_);
		return 1;
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

	/** Removes all items from the set. */
	void clear() {
		clearTree(root_);
		root_ = NULL;
		return;
	}
	void clearTree(Node*& node) {
		if (root_ == NULL) {
			return;
		}
		if (node->left_ != NULL) {
			clearTree(node->left_);
		}
		if (node->right_ != NULL) {
			clearTree(node->right_);
		}
		delete node;
		return;
	}

	/** @return: the number of elements contained by the Set. */
	size_t size() const { return numItems; }

	/** @return: return 1 if contains element equivalent to item, else 0. */
	size_t count(const T& item) const {
		bool isFound = findItem(item, root_);
		if (isFound) return 1;
		else return 0;
	}
	bool findItem(const T& item, Node* node) const {
		if (node == NULL) return false;
		if (node->data_ == item) {
			return true;
		}
		if (node->data_ > item) {
			return findItem(item, node->left_);
		}
		if (node->data_ < item) {
			return findItem(item, node->right_);
		}
	}

	/** @return: string representation of items in Set. */
	std::string toString() const {
		stringstream out;
		if (root_ == NULL) {
			return " Empty";
		}
		outLevel(root_, out);
		return out.str();
	}
	/** Output nodes at a given level */
	void outLevel(Node* node, stringstream& out) const {
		if (node == NULL) return;
		if (node != NULL) out << node->data_ << " ";
		outLevel(node->left_, out);
		outLevel(node->right_, out);
		return;
	}

};

#endif
