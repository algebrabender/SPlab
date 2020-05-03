#pragma once
#include "Queue.h"
class QueueAsArray : public Queue {
protected:
	BSTNode** queue;
	int head;
	int tail;
	int size;
	int numOfElements;
public:
	QueueAsArray(int size);
	virtual ~QueueAsArray();
	void enqueue(BSTNode* node);
	BSTNode* dequeue();
	BSTNode* getHead();
	bool isEmpty() { return this->numOfElements == 0; };
	int numberOfElements() { return this->numOfElements; };
}; 