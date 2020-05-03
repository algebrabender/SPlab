#pragma once

class Stack {
public:
	virtual void push(int element) = 0;
	virtual int pop() = 0;
	virtual int getTop() = 0;
	virtual bool isEmpty() = 0;
	virtual int numberOfElements() = 0;
};