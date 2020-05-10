#include "StackAsArray.h"

StackAsArray::StackAsArray(int size)
{
	if (size > 0)
	{
		this->size = size;
		this->top = -1;
		this->stack = new LinkedNode * [size];
	}
	else
		throw exception("Nevalidna velicina");
}

StackAsArray::~StackAsArray()
{
	if (this->stack != nullptr)
	{
		delete[] stack;
		stack = nullptr;
	}
}

void StackAsArray::push(LinkedNode* node)
{
	if (this->top >= this->size)
		throw exception("Stack je pun");
	else
		this->stack[++this->top] = node;
}

LinkedNode* StackAsArray::pop()
{
	if (isEmpty())
		throw exception("Stack je prazan");
	else
	{
		LinkedNode* temp = this->stack[this->top--];
		return temp;
	}
}

LinkedNode* StackAsArray::getTop()
{
	if (isEmpty())
		throw exception("Stack je prazan");
	else
		return this->stack[this->top];
}