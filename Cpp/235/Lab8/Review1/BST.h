//PancakeKing

#ifndef BST_H
#define BST_H
#include "BSTInterface.h"

using std::endl;
using std::stringstream;

/** A binary tree node with data, left and right child pointers */

template<typename T>
class BST {
	
private:
	struct Node{
		//data members
		T data;
		Node* left;
		Node* right;
		
		//constructor
		Node(){
			data = NULL;
			left = nullptr;
			right = nullptr;
		}
		Node(T mData){
			data = mData;
			left = nullptr;
			right = nullptr;
		}
		~Node(){
			;
		}
	};
	Node* root = nullptr;
	
public:
	
	Node* currentNode = root;
	
	BST(){
		this->root = nullptr;
	}
	
	BST(T value) {
		this->root = new Node(value);
	}
	
	~BST(void) {
		clearTree();
	}
	
	Node* getRoot(){
		return root;
	}
	
	bool insert(Node*& base, T value){
		if (base == NULL) {
			base =
			new Node(value);
			return true;
		} else {
			if (value < base->data)
				return insert(base->left, value);
			else if (base->data < value)
				return insert(base->right, value);
			else {
				return false;
			}
		}
	}
	
	/** Return true if node added to BST, else false */
	bool addNode(const T& value){
		return insert(this->root, value);
	}
	bool nodeExist(Node*& base, const T value){
		if(base == nullptr){
			return false;
		}
		
		if(base->value == value){
			return true;
		}
		if(base->value < value){
			if(base->right != nullptr){
				nodeExist(base->right, value);
			}
			else{
				return false;
			}
		}
		if(base->value > value){
			if(base->left != nullptr){
				nodeExist(base->left, value);
			}
			else{
				return false;
			}
		}
	}
	
	//only run this function if nodeExist == true
	Node*& findNode(Node*& base, const T value){
		if(base->value == value){
			return base;
		}
		if(base->value < value){
			findNode(base->right, value);
		}
		if(base->value > value){
			findNode(base->left, value);
		}
	}
	
	//returns node just greater than the one we want to remove
	Node*& replacingNodeGreaterThan(Node*& base, T value){
		if(base->left != nullptr)
			return replacingNodeGreaterThan(base->left, value);
		else{
			return base;
		}
	}
	
	//returns node just smaller than the one we want to remove
	Node*& replacingNodeLessThan(Node*& base, T value){
		if(base->right != nullptr){
			return replacingNodeLessThan(base->right, value);
		}
		else{
			return base;
		}
	}
	
	
	void replaceNode(Node*& baseRoot, Node*& localRoot){
		if (localRoot->right != NULL) {
			replaceNode(baseRoot, localRoot->right);
		} else {
			baseRoot->data = localRoot->data;
			baseRoot = localRoot;
			localRoot = localRoot->left;
		}
	}
	
	bool erase(Node*& base, T value){
		if (base == NULL) {
			return false;
		} else {
			if (value < base->data)
				return erase(base->left, value);
			else if (base->data < value)
				return erase(base->right, value);
			else { // Found item
				Node* old_root = base;
				if (base->left == NULL) {
					base = base->right;
				} else if (base->right == NULL) {
					base = base->left;
				} else {
					replaceNode(old_root, old_root->left); //find in order predesesor
				}
				delete old_root;
				return true;
			}
		}
	}
	
	bool removeNode(const T& value){
		 return erase(this->root, value);
	}
	
	
	
	/** Return true if BST cleared of all nodes, else false */
	bool clearTree(){
		while(root!= nullptr){
			removeNode(root->data);
		}
		return true;
	}
	
	
	
	/** Return a level order traversal of a BST as a string */
	bool outLevel(Node* root, int level, stringstream& out) const
	{
		if (root == NULL) return false;
		if (level == 0)
		{
			out << " " << root->data;
			if ((root->left != NULL) || (root->right != NULL)) return true;
			return false;
		}
		if ((level == 1) && !root->left && root->right) out << " _";
		bool left_ = outLevel(root->left, level - 1, out);
		bool right_ = outLevel(root->right, level - 1, out);
		if ((level == 1) && root->left && !root->right) out << " _";
		return left_ || right_;
	} // end outLevel()
	
	/** Return a level order traversal of a BST as a string */
	string toString() const
	{
		stringstream out;
		if (root == NULL) out << " Empty";
		else
		{
			int level = -1;
			do
			{
				out << endl << "  " << ++level << ":";
			} while (outLevel(root, level, out));
		}
		return out.str();
	} // end toString()
};
#endif	// BST_H
