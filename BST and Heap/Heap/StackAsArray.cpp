#include "StackAsArray.h"

StackAsArray::StackAsArray(int size)
{
	if (size > 0)
	{
		this->size = size;
		this->top = -1;
		this->stack = new int[size];
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

void StackAsArray::push(int element)
{
	if (this->top >= this->size)
		throw exception("Stack je pun");
	else
		this->stack[++this->top] = element;
}

int StackAsArray::pop()
{
	if (isEmpty())
		throw exception("Stack je prazan");
	else
	{
		int temp = this->stack[this->top--];
		return temp;
	}
}

int StackAsArray::getTop()
{
	if (isEmpty())
		throw exception("Stack je prazan");
	else
		return this->stack[this->top];
}