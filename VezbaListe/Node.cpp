#include "Node.h"

Node::Node(int element)
{
	info = element;
	next = prev = nullptr;
}

Node::Node(int element, Node* next, Node* prev)
{
	info = element;
	this->next = next;
	this->prev = prev;
}