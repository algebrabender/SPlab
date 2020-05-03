#include "BSTNode.h"

BSTNode::BSTNode(int element)
{
	this->key = element;
	this->left = this->right = nullptr;
}

BSTNode::BSTNode(int element, BSTNode* left, BSTNode* right)
{
	this->key = element;
	this->left = left;
	this->right = right;
}

void BSTNode::visit()
{
	cout << this->key << " ";
}

BSTNode* BSTNode::operator=(const BSTNode* object)
{
	if (this != object)
	{
		this->key = object->key;
		this->left = object->left;
		this->right = object->right;
	}
	return this;
}