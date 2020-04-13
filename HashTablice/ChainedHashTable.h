#pragma once
#include "HashTable.h"
#include "SLL.h"

class ChainedHashTable : public HashTable {
protected:
	SLL<HashObject*>* arr;
public:
	ChainedHashTable(unsigned int length);
	~ChainedHashTable();
	void insert(HashObject* object);
	HashObject* find(int key);
	void withdraw(int key);
	void withdraw(HashObject* object);
};