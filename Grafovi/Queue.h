#pragma once
#include "LinkedNode.h"

class Queue {
	virtual void enqueue(LinkedNode* node) = 0;
	virtual LinkedNode* dequeue() = 0;
	virtual LinkedNode* getHead() = 0;
	virtual bool isEmpty() = 0;
	virtual int numberOfElements() = 0;
};