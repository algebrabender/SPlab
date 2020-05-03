#pragma once
#include <iostream>

using namespace std;

class BSTNode {
public:
	int key;
	BSTNode* left, * right;

	BSTNode() : key(0), left(nullptr), right(nullptr) {};
	BSTNode(int element);
	BSTNode(int element, BSTNode* left, BSTNode* right);
	bool isLower(int element) { return this->key < element; };
	bool isGreater(int element) { return this->key > element; };
	bool isEqual(int element) { return this->key == element; };
	void setKey(int element) { this->key = element; };
	int getKey() { return this->key; };
	void visit();
};