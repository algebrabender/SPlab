#pragma once
#include "Stack.h"

class StackAsArray : public Stack {
protected:
	LinkedNode** stack;
	int top;
	int size;
public:
	StackAsArray(int size);
	virtual ~StackAsArray();
	void push(LinkedNode* node);
	LinkedNode* pop();
	LinkedNode* getTop();
	bool isEmpty() { return this->top == -1; };
	int numberOfElements() { return this->top + 1; };
};