//Created by pp
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include"LinkedListInterface.h"
#include<sstream>
#include<string>
#include<iostream>

template<typename T>

class LinkedList : public LinkedListInterface<T> {
private:
	struct Node {
		Node(const T& i) : info(i), next(NULL) {}
		Node(const T& i, Node* n) : info(i), next(n) {}
		T info;
		Node *next;
		int index;
	};
	Node *head;
	int lSize;
public:
	LinkedList() { head = NULL; lSize = 0; }
	~LinkedList() { clear(); }

	virtual bool insertHead(T value) {
		bool isValid = checkDoubles(value);

		if (isValid) {
			Node *newPtr = new Node(value, head);
			head = newPtr;
			Node *ptr = head;
			lSize++;
			for (int i = 0; i < lSize; i++) {
				ptr->index = i;
				ptr = ptr->next;
			}
			return true;
		}
		else return false;
	}

	virtual bool insertTail(T value) {
		bool isValid = checkDoubles(value);
		Node *ptr = head;

		if (lSize != 0) {
			while (ptr->next != NULL) {
				ptr = ptr->next;
			}
		}

		if (isValid) {
			Node *newPtr = new Node(value);
			if (lSize == 0) {
				head = newPtr;
				head->index = 0;
			}
			else {
				ptr->next = newPtr;
				newPtr->index = lSize;
			}
			lSize++;
			return true;
		}
		else return false;
	}

	virtual bool insertAfter(T matchNode, T node) {
		bool isNotIn = checkDoubles(matchNode);

		if (!isNotIn) {
			Node *checkPtr = head;
			while (checkPtr->info != matchNode) {
				checkPtr = checkPtr->next;
			}
			if (checkPtr->index != (lSize - 1)) {
				if (checkPtr->next->info == node) {
					return false;
				}
			}
			Node *ptr = head;
			while (ptr->info != matchNode) {
				ptr = ptr->next;
			}
			Node *newPtr = new Node(node);
			newPtr->next = ptr->next;
			ptr->next = newPtr;
			lSize++;
			int newIndex = ptr->index;
			ptr = ptr->next;
			for (int i = newIndex + 1; i < lSize; i++) {
				ptr->index = i;
				ptr = ptr->next;
			}
			return true;
		}
		else return false;
	}

	virtual bool remove(T value) {
		bool isNotIn = checkDoubles(value);

		if (!isNotIn) {
			Node *ptr = head;
			if (head->info != value) {
				while (ptr->next->info != value) {
					ptr = ptr->next;
				}
				Node *delPtr = ptr->next;
				ptr->next = delPtr->next;
				delete delPtr;
			}
			else {
				if (lSize != 1) {
					Node *delPtr = head;
					head = head->next;
					delete delPtr;
					head->index = 0;
					ptr = head;
				}
				else {
					Node *delPtr = head;
					head = NULL;
					delete delPtr;
					lSize = 0;
					return true;
				}
			}
			lSize--;
			int newIndex = ptr->index;
			ptr = ptr->next;
			for (int i = newIndex + 1; i < lSize; i++) {
				ptr->index = i;
				ptr = ptr->next;
			}
			return true;
		}
		else return false;
	}

	virtual bool clear() {
		Node *ptr = head;
		Node *nextPtr = nullptr;
		for (int i = 0; i < lSize; i++) {
			nextPtr = ptr->next;
			delete ptr;
			ptr = nextPtr;
		}
		lSize = 0;
		head = nullptr;
		return true;
	}

	virtual T at(int index) {
		Node *ptr = head;
		while (ptr->index != index) {
			ptr = ptr->next;
		}
		return ptr->info;
	}

	virtual int size() const { return lSize; }

	std::string print() {
		std::ostringstream oss;

		if (lSize > 0) {
			Node *ptr = head;
			for (int i = 0; i < lSize; i++) {
				oss << ptr->info << " ";
				ptr = ptr->next;
			}
			return (oss.str());
		}
		else return "Empty";
	}
private:
	bool checkDoubles(T value) const {
		Node *ptr = head;
		for (int i = 0; i < lSize; i++) {
			if (ptr->info == value) return false;
			ptr = ptr->next;
		}
		return true;
	}
};

#endif
