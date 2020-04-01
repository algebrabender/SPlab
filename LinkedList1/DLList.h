#pragma once
#include "DLLNode.h"
class DLList {
protected:
	DLLNode* head;
	DLLNode* tail;
public:
	DLList();
	~DLList();

	bool isEmpty() { return head == nullptr; }
	void printAll();

	void addToHead(int element);
	void addToTail(int element);

	void deleteElement(int element);
	int deleteFromHead();
	//int deleteFromTail();




};