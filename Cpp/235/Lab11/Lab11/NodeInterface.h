//YOU MAY NOT MODIFY THIS DOCUMENT
#ifndef NODEINTERFACE_H_
#define NODEINTERFACE_H_

#include <iostream>
using namespace std;

template<class T>
class NodeInterface {

public:
	NodeInterface() {}
	virtual ~NodeInterface() {}

	/*
	* Returns the data stored in this node
	*
	* @return the data stored in this node.
	*/
	virtual T getData() const = 0;

	/*
	* Returns the left child of this node or null if empty left child.
	*
	* @return the left child of this node or null if empty left child.
	*/
	virtual NodeInterface<T> * getLeftChild() const = 0;

	/*
	* Returns the right child of this node or null if empty right child.
	*
	* @return the right child of this node or null if empty right child.
	*/
	virtual NodeInterface<T> * getRightChild() const = 0;

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
	virtual unsigned getHeight() const = 0;
};

#endif /* NODEINTERFACE_H_ */
