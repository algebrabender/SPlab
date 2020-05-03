#pragma once
#include <iostream> 

using namespace std;

class BSTNode {
public:
public:
	int key;
	BSTNode* left, * right;

	BSTNode() : key(0), left(nullptr), right(nullptr) {};
	BSTNode(int element);
	BSTNode(int element, BSTNode* left, BSTNode* right);
	void visit();
	void addLeft(BSTNode* left) { this->left = left; };
	void addRight(BSTNode* right) { this->right = right; };
};