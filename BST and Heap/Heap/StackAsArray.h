#pragma once
#include "Stack.h"
#include <exception>

using namespace std;
class StackAsArray : public Stack {
protected:
	int* stack;
	int top;
	int size;
public:
	StackAsArray(int size);
	virtual ~StackAsArray();
	void push(int element);
	int pop();
	int getTop();
	bool isEmpty() { return this->top == -1; };
	int numberOfElements() { return this->top + 1; };
};