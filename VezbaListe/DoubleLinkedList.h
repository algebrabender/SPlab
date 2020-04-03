#pragma once
#include "Node.h"
#include <iostream>
#include <exception>

using namespace std;

class DoubleLinkedList
{
protected:
	Node* head;
	Node* tail;
public:
	DoubleLinkedList() : head(nullptr), tail(nullptr) {};
	~DoubleLinkedList();
	void addToHead(int element);
	void addToTail(int element);
	int deleteFromHead();
	int deleteFromTail();
	void printAll();
	bool isEmpty() { return head == nullptr; };
	void deleteElement(int element);
	bool isInList(int element);
	void removeDuplicates();
};