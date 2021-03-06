#pragma once
#include "Queue.h"
class QueueAsArray : public Queue {
protected:
	LinkedNode** queue;
	int head;
	int tail;
	int size;
	int numOfElements;
public:
	QueueAsArray(int size);
	virtual ~QueueAsArray();
	void enqueue(LinkedNode* node);
	LinkedNode* dequeue();
	LinkedNode* getHead();
	bool isEmpty() { return this->numOfElements == 0; };
	int numberOfElements() { return this->numOfElements; };
};