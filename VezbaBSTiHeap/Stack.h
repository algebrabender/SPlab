#pragma once
#include "BSTNode.h"

class Stack {
public:
	virtual void push(BSTNode* node) = 0;
	virtual BSTNode* pop() = 0;
	virtual BSTNode* getTop() = 0;
	virtual bool isEmpty() = 0;
	virtual int numberOfElements() = 0;
};