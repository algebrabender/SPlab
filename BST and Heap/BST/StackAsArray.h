#pragma once
#include "Stack.h"

class StackAsArray : public Stack {
protected:
	BSTNode** stack;
	int top;
	int size;
public:
	StackAsArray(int size);
	virtual ~StackAsArray();
	void push(BSTNode* node);
	BSTNode* pop();
	BSTNode* getTop();
	bool isEmpty() { return this->top == -1; };
	int numberOfElements() { return this->top + 1; };
};