#ifndef AVL_H
#define AVL_H

#include"AVLInterface.h"
#include"Node.h"

template<typename T>

class AVL : public AVLInterface<T> {
private:
	Node<T> *root_;
public:
	AVL() : root_(NULL) {}
	~AVL() { if (root_ != NULL) clearTree(root_); }
	/*
	* Returns the root node for this tree
	*
	* @return the root node for this tree.
	*/
	NodeInterface<T> * getRootNode() const { return root_; }

	/*
	* Attempts to add the given T to the AVL tree
	* Rebalances the tree if data is successfully added
	*
	* @return true if added
	* @return false if unsuccessful (i.e. the T is already in tree)
	*/
	bool add(T data) {

		if (root_ == NULL) {
			root_ = new Node<T>(data);
			return true;
		}
		else if (findNode(root_, data)) return false;
		else {
			add(root_, data);
			Node<T>* addNode = getNode(root_, data);
			Node<T>* testptr = nullptr;
			while (addNode != root_) {
				testptr = findImbalance(findParent(addNode, root_));
				if (testptr != NULL) {
					if (getBalance(testptr) > 1) {
						rotate_l(testptr);
					}
					if (getBalance(testptr) < -1) {
						rotate_r(testptr);
					}
				}
				if (addNode != root_) addNode = findParent(addNode, root_);
			}
			testptr = findImbalance(root_);
			if (testptr != NULL) {
				if (getBalance(testptr) > 1) {
					rotate_l(testptr);
				}
				if (getBalance(testptr) < -1) {
					rotate_r(testptr);
				}
			}
			return true;
			/*if (data < root_->data_) {
				add(root_->left_, data);
				if (getBalance(root_);
			}
			if (data > root_->data_) {
				int b_height = 0;
				if (root_->right_ != NULL) {
					b_height = root_->right_->getHeight();
				}
				add(root_->right_, data);
				if (root_->right_->getHeight() > b_height) balance_++;
			}
			if (balance_ < -1) rotate_r(root_);
			if (balance_ > 1) rotate_l(root_);
			return true;*/
		}
	}

	/*Recursive portion of above*/
	void add(Node<T>*& node_, T data) {

		if (node_ == NULL) {
			node_ = new Node<T>(data);
			return;
		}
		if (data > node_->data_) {
			add(node_->right_, data);
			return;
		}
		else {
			add(node_->left_, data);
			return;
		}

	}

	/*
	* Attempts to remove the given T from the AVL tree
	* Rebalances the tree if data is successfully removed
	*
	* @return true if successfully removed
	* @return false if remove is unsuccessful(i.e. the T is not in the tree)
	*/
	bool remove(T data) {

		if (root_ == NULL) return false;
		if (findNode(root_, data)) {
			Node<T>* addNode = getNode(root_, data);
			if (addNode != root_) addNode = findParent(addNode, root_);
			//else if (addNode->left_ != NULL) addNode = addNode->left_;
			//else addNode = addNode->right_;
			removeNode(data, root_);
			if (root_ != NULL) {
				if (findNode(root_, addNode->data_) == false) addNode = root_;
				if (addNode == root_) {
					if (addNode->left_ != NULL) {
						addNode = addNode->left_;
					}
					else if (addNode->right_ != NULL) addNode = addNode->right_;
					else addNode = root_;
				}

				Node<T>* testptr = nullptr;
				while (addNode != root_) {
					testptr = findImbalance(findParent(addNode, root_));
					if (testptr != NULL) {
						if (getBalance(testptr) > 1) {
							rotate_l(testptr);
						}
						if (getBalance(testptr) < -1) {
							rotate_r(testptr);
						}
					}
					if (addNode != root_) addNode = findParent(addNode, root_);
				}
				testptr = findImbalance(root_);
				if (testptr != NULL) {
					if (getBalance(testptr) > 1) {
						rotate_l(testptr);
					}
					if (getBalance(testptr) < -1) {
						rotate_r(testptr);
					}
				}
			}
			return true;
			/*Node<T>* testptr = nullptr;
			testptr = findImbalance(root_);
			while (testptr != NULL) {
				if (getBalance(testptr) > 1) {
					rotate_l(testptr);
				}
				if (getBalance(testptr) < -1) {
					rotate_r(testptr);
				}
				testptr = findImbalance(root_);
			}
			return true;*/
			/*if (data < root_->data_) {
				int b_height = 0;
				if (root_->left_ != NULL) b_height = root_->left_->getHeight();
				removeNode(data, root_);
				if (root_->left_->getHeight() > b_height) balance_--;
			}
			if (data > root_->data_) {
				int b_height = 0;
				if (root_->right_ != NULL) b_height = root_->right_->getHeight();
				removeNode(data, root_);
				if (root_->right_->getHeight() > b_height) balance_++;
			}
			if (balance_ < -1) rotate_r(root_);
			if (balance_ > 1) rotate_l(root_);*/
			return true;
		}
		else return false;
	}

	/*Recursive portion of above*/
	bool removeNode(const T& data, Node<T>*& node) {
		if (node == NULL) return false;
		if (data < node->data_) return removeNode(data, node->left_);
		if (data > node->data_) return removeNode(data, node->right_);
		Node<T> *deleteNode = node;
		if (node->left_ == NULL) {
			node = node->right_;
			/*Node<T> *parent = findParent(deleteNode, root_);
			if (parent->right_ == deleteNode) parent->right_ = node;
			else parent->left_ = node;*/
		}
		else if (node->right_ == NULL) {
			node = node->left_;
			/*Node<T> *parent = findParent(deleteNode, root_);
			if (parent->right_ == deleteNode) parent->right_ = node;
			else parent->left_ = node;*/
		}
		else {
			replaceParent(deleteNode, deleteNode->left_);
		}
		//Node<T> *parent = findParent(deleteNode, root_);
		delete deleteNode;
		return true;
	}
	/** switches a removed parent node with its inorder predecessor */
	void replaceParent(Node<T>*& deleteNode, Node<T>*& replaceNode) {
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

	/*
	* Removes all nodes from the tree, resulting in an empty tree.
	*/
	void clear() {
		clearTree(root_);
		root_ = NULL;
		return;
	}

	/*Recursive portion of above*/
	bool clearTree(Node<T>*& node) {
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

	/*Returns true if value is in tree, false if not*/
	bool findNode(Node<T>*& node_, T data)  {
		if (node_ == NULL) return false;
		if (node_->data_ == data) return true;
		if (findNode(node_->left_, data)) return true;
		if (findNode(node_->right_, data)) return true;
		return false;
	}

	/*Rotates tree left*/
	void rotate_l(Node<T>*& node_) {
		Node<T>* tempNode = nullptr;
		if (getBalance(node_->right_) < 0) {
			tempNode = node_->right_;
			node_->right_ = tempNode->left_;
			tempNode->left_ = node_->right_->right_;
			node_->right_->right_ = tempNode;
		}
		tempNode = node_;
		node_ = tempNode->right_;
		tempNode->right_ = node_->left_;
		node_->left_ = tempNode;
		if (tempNode == root_) root_ = node_;
		else {
			Node<T>* parent = findParent(tempNode, root_);
			if (parent->left_ == tempNode) parent->left_ = node_;
			if (parent->right_ == tempNode) parent->right_ = node_;
		}
		return;
	}

	/*Rotates tree right*/
	void rotate_r(Node<T>*& node_) {
		Node<T>* tempNode = nullptr;
		if (getBalance(node_->left_) > 0) {
			tempNode = node_->left_;
			node_->left_ = tempNode->right_;
			tempNode->right_ = node_->left_->left_;
			node_->left_->left_ = tempNode;
		}
		tempNode = node_;
		node_ = tempNode->left_;
		tempNode->left_ = node_->right_;
		node_->right_ = tempNode;
		if (tempNode == root_) root_ = node_;
		else {
			Node<T>* parent = findParent(tempNode, root_);
			if (parent->left_ == tempNode) parent->left_ = node_;
			if (parent->right_ == tempNode) parent->right_ = node_;
		}
		return;
	}
	int getBalance(Node<T>*& node_) {
		if (node_->left_ == NULL && node_->right_ == NULL) return 0;
		if (node_->left_ == NULL) return node_->right_->getHeight();
		if (node_->right_ == NULL) {
			int toReturn = node_->left_->getHeight();
			toReturn *= -1;
			return toReturn;
		}
		int test = node_->right_->getHeight();
		test = node_->left_->getHeight();
		return (node_->right_->getHeight() - node_->left_->getHeight());
	}
	Node<T>* findImbalance(Node<T>* node_) {

		Node<T>* ptr = nullptr;
		if (node_ == NULL) return NULL;
		if (node_->left_ == NULL && node_->right_ == NULL) {
			return NULL;
		}
		if (node_->left_ == NULL) {
			if (node_->right_->getHeight() > 1) return node_;
			else return NULL;
		}
		if (node_->right_ == NULL) {
			if (node_->left_->getHeight() > 1) return node_;
			else return NULL;
		}

		if (getBalance(node_) > 1 || getBalance(node_) < -1) {
			return node_;
		}
		ptr = findImbalance(node_->left_);
		if (ptr == NULL) ptr = findImbalance(node_->right_);
		return ptr;
	}
	Node<T>* findParent(Node<T>*& toFind, Node<T>*& toSearch) {

		if (toSearch == NULL) return NULL;
		if (toSearch->left_ == NULL && toSearch->right_ == NULL) return NULL;
		if (toSearch->left_ == toFind || toSearch->right_ == toFind) return toSearch;
		Node<T>* ptr = nullptr;
		ptr = findParent(toFind, toSearch->left_);
		if (ptr == NULL) ptr = findParent(toFind, toSearch->right_);
		return ptr;
	}
	Node<T>* getNode(Node<T>* node_, T data) {
		if (node_ == NULL) return NULL;
		if (node_->data_ == data) return node_;
		if (getNode(node_->left_, data) != NULL) return getNode(node_->left_, data);
		if (getNode(node_->right_, data) != NULL) return getNode(node_->right_, data);
		return NULL;
	}
};

#endif
