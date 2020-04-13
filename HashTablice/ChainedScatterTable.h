#pragma once
#include "HashTable.h"
#include "ChainedScatterObject.h"

class ChainedScatterTable : public HashTable {
protected: 
	ChainedScatterObject** arr;
public:
	ChainedScatterTable(unsigned int length);
	~ChainedScatterTable();
	void insert(ChainedScatterObject* object);
	ChainedScatterObject* find(int key);
	void withdraw(int key);

private:
	unsigned int g(unsigned int key);
};