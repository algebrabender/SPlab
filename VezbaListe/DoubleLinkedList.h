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
	Node* findNodePtr(int element);
	Node* getHead() { return head; }; //i da je lista prazna vratice nullptr
	Node* getNext(Node* ptr);
	int getHeadElement();
	int getNextElement(int element);
};
