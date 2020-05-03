#include "QueueAsArray.h"

QueueAsArray::QueueAsArray(int size)
{
	if (size > 0)
	{
		this->size = size;
		this->head = this->tail = -1;
		this->queue = new BSTNode * [size];
		this->numOfElements = 0;
	}
	else
		throw exception("Nevalidna velicina");
}

QueueAsArray::~QueueAsArray()
{
	if (this->queue != nullptr)
	{
		delete[] queue;
		queue = nullptr;
	}
}

void QueueAsArray::enqueue(BSTNode* node)
{
	if (this->numOfElements >= this->size)
		throw exception("Queue je pun");
	else
	{
		if (++this->tail == this->size) //ako tail prelazi kraj niza
			this->tail = 0;
		this->queue[this->tail] = node;
		if (this->numOfElements == 0) //ako je ovo prvi element
			this->head = this->tail;
		++this->numOfElements;
	}
}

BSTNode* QueueAsArray::dequeue()
{
	BSTNode* temp = nullptr;
	if (isEmpty())
		throw exception("Queue je prazan");
	else
	{
		BSTNode* temp = this->queue[this->head];
		if (++this->head == this->size) //ako head prelazi kraj niza
			this->head = 0;
		--this->numOfElements;
		if (this->numOfElements == 0)
			head = tail = -1; //nema na sta da ukazuju
		return temp;
	}

}

BSTNode* QueueAsArray::getHead()
{
	if (isEmpty())
		throw exception("Queue je prazan");
	else
		return this->queue[this->head];
}