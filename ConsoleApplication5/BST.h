#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "Morse.h"
#include "BSTNode.h"

using std::endl;
using std::cin;
using std::cout;
using std::fstream;
using std::string;

template <class T>
class BST {
public:
	BST(fstream &input);
	~BST();
	bool isEmpty();
	void insert(T &newData);
	void displayTree() const;
	T search(T lookup) const;


private:
	BSTNode<T> *root;
	void insert(T &newData, BSTNode<T> *& root);
	void destroyTree(BSTNode<T> *& root);
	void printTree(BSTNode<T> * tree)const;
};

template<class T>
BST<T>::BST(fstream &input) {
	root = nullptr;
	while (!input.eof()) {
		T newData;
		input >> newData;
		insert(newData);
	}
}

template<class T>
BST<T>::~BST() {
	destroyTree(root);
}

template<class T>
void BST<T>::destroyTree(BSTNode<T> *& tree) {
	if (tree != nullptr) {
		destroyTree(tree->getLeftChild());
		destroyTree(tree->getRightChild());
		//cout << "About to delete: " << tree->getData() << endl;
		delete tree;
	}
}

template<class T>
bool BST<T>::isEmpty() {
	bool conclusion = false;
	if (root == nullptr) {
		conclusion = true;
	}
	return conclusiion;
}

template<class T>
void BST<T>::insert(T &newData) {
	insert(newData, root);
}

template<class T>
void BST<T>::insert(T &newData, BSTNode<T> *& root) {
	if (root == nullptr) {
		root = new BSTNode<T>(newData);
	}
	else if (newData < root->getData()) {
		insert(newData, root->getLeftChild());
	}
	else {
		insert(newData, root->getRightChild());
	}
}

template<class T>
void BST<T>::displayTree()const {
	printTree(this->root);
}

template<class T>
void BST<T>::printTree(BSTNode<T> *tree)const {
	if (tree != nullptr) {
		printTree(tree->getLeftChild());
		cout << tree->getData();
		printTree(tree->getRightChild());
	}
}
template<class T>
T BST<T>::search(T find) const {
	BSTNode<T> *lookup = root;
	while (lookup->getData() != find) {
		if (find < lookup->getData()) {
			lookup = lookup->getLeftChild();
		}
		else {
			lookup = lookup->getRightChild();
		}
	}
	return lookup->getData();
}


/*
template <class E>
void BST<E>::inOrderPrint(BSTNode<E> *root) {
	if (this->root == nullptr) {
		cout << "Nothing left in the tree" << endl;
	}
	if (root != nullptr) {
		inOrderPrint(root->getLeftChild());
		cout << root->data << endl;
		inOrderPrint(root->getRightChild());
	}
}

template <class E>
void BST<E>::preOrderPrint(BSTNode<E> *root) {
	if (this->root == nullptr) {
		cout << "Nothing left in the tree" << endl;
	}
	if (this->root != nullptr) {
		cout << root->data << endl;
		preOrderPrint(root->getLeftChild());
		preOrderPrint(root->getRightChild());
	}
}

template <class E>
void BST<E>::postOrder(BSTNode<E> *root) {
	if (this->root == nullptr) {
		cout << "Nothing Left in the tree" << endl;
	}
	if (this->root != nullptr) {
		postOrder(root->getLeftChild());
		postOrder(root->getRightChild());
		cout << root->data << endl;
	}
}

*/