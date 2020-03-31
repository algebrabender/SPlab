#pragma once
#include "Node.h"

class LancanaLista {
protected:
	Node* head;
public:
	LancanaLista() : head(nullptr) {};
	~LancanaLista();
	void addToHead(int E);
	void addToTail(int E);
	int deleteFromHead();
	int deleteFromTail();
	void printAll();
	bool isEmpty() { return head == nullptr; };
};