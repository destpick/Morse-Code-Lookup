#pragma once
#include <iostream>
#include <string>


using std::endl;
using std::cin;
using std::cout;

using std::ifstream;
using std::ofstream;
using std::fstream;
using std::string;

template <class T >

class BSTNode {

private:
	T data;
	BSTNode *leftChild;
	BSTNode *rightChild;
	
public:

	BSTNode( T newData);
//	~BSTNode();
	T getData();
	void setData(T data);
	BSTNode<T> *& getLeftChild();
	BSTNode<T> *& getRightChild();
	void setLeftChild(BSTNode<T> *leftChild);
	void setRightChild(BSTNode<T> *rightChild);
	void printNode() const;
};
//template<class T>
//BSTNode<T>::~BSTNode{
//	return;
//}

template <class T>
BSTNode<T>::BSTNode(T newData) {
	this->data = newData;
	 leftChild = nullptr;
	 rightChild = nullptr;
}

//template <class T>
//BSTNode<T>::~BSTNode{
//}

template <class T>
T BSTNode <T>::getData() {
	return this->data;
}

template <class T>
void BSTNode<T>::setData(T newData) {
	data = newData;
}

template <class T>
BSTNode<T> *& BSTNode<T>::getLeftChild() {
	return this->leftChild;
}

template<class T>
BSTNode<T> *& BSTNode<T>::getRightChild() {
	return this->rightChild;
}

template <class T>
void BSTNode<T>::printNode() const {
	cout << this->getData();
}

template<class T>
void BSTNode<T>::setLeftChild(BSTNode<T> *leftChild) {
	this->leftChild = leftChild;
}

template<class T>
void BSTNode<T>::setRightChild(BSTNode<T> *rightChild) {
	this->rightChild = rightChild;
}
