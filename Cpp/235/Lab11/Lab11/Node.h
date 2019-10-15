#ifndef NODE_H
#define NODE_H

#include"NodeInterface.h"

template<typename T>

class Node : public NodeInterface<T> {

public:
	T data_;
	Node<T> *left_;
	Node<T> *right_;
	Node() : left_(NULL), right_(NULL) {}
	Node(T data) : data_(data), left_(NULL), right_(NULL) {}
	~Node() {}
	/*
	* Returns the data stored in this node
	*
	* @return the data stored in this node.
	*/
	T getData() const { return data_; }

	/*
	* Returns the left child of this node or null if empty left child.
	*
	* @return the left child of this node or null if empty left child.
	*/
	NodeInterface<T> * getLeftChild() const { return left_; }

	/*
	* Returns the right child of this node or null if empty right child.
	*
	* @return the right child of this node or null if empty right child.
	*/
	NodeInterface<T> * getRightChild() const { return right_; }

	/*
	* Returns the height of this node. The height is the number of nodes
	* along the longest path from this node to a leaf.  While a conventional
	* interface only gives information on the functionality of a class and does
	* not comment on how a class should be implemented, this function has been
	* provided to point you in the right direction for your solution.  For an
	* example on height, see page 448 of the text book.
	*
	* @return the height of this tree with this node as the local root.
	*/
	unsigned getHeight() const {

		if (left_ == NULL && right_ == NULL) {
			return 1;
		}
		else {
			unsigned height_ = getHeight(this, 0);
			return height_;
		}

	}
	/* Recursive portion of above*/
	unsigned getHeight(const Node<T>* node_, unsigned height) const {

		height++;
		if (node_->left_ == NULL && node_->right_ == NULL) {
			return height;
		}
		else if (node_->left_ == NULL && node_->right_ != NULL) return getHeight(node_->right_, height);
		else if (node_->left_ != NULL && node_->right_ == NULL) return getHeight(node_->left_, height);
		else {
			if (getHeight(node_->left_, height) >= getHeight(node_->right_, height)) return getHeight(node_->left_, height);
			else return getHeight(node_->right_, height);
		}

	}

};


#endif
