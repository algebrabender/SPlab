#pragma once
#include "BSTNode.h"

class Queue {
	virtual void enqueue(BSTNode* node) = 0;
	virtual BSTNode* dequeue() = 0;
	virtual BSTNode* getHead() = 0;
	virtual bool isEmpty() = 0;
	virtual int numberOfElements() = 0;
};