#pragma once
#pragma once
#include "LinkedNode.h"

class Stack {
public:
	virtual void push(LinkedNode* node) = 0;
	virtual LinkedNode* pop() = 0;
	virtual LinkedNode* getTop() = 0;
	virtual bool isEmpty() = 0;
	virtual int numberOfElements() = 0;
};