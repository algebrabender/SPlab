#include "LinkedNode.h"

LinkedNode::LinkedNode()
{
	this->info = 0;
	this->adj = nullptr;
	this->next = nullptr;
	this->status = 0;
}

LinkedNode::LinkedNode(int info)
{
	this->info = info;
	this->adj = nullptr;
	this->next = nullptr;
	this->status = 0;
}

LinkedNode::LinkedNode(int info, Edge* adj, LinkedNode* next, int status)
{
	this->info = info;
	this->adj = adj;
	this->next = next;
	this->status = status;
}

void LinkedNode::visit()
{
	cout << this->info << endl;
}