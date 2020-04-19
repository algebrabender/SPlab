#pragma once
#include "HashTable.h"
#include "ChainedScatterObject.h"

class ChainedScatterTable: public HashTable {
protected:
	ChainedScatterObject** arr;
	ChainedScatterObject** arrS; //prostor za sinonime
public:
	ChainedScatterTable(unsigned int length);
	~ChainedScatterTable();
	void insert(ChainedScatterObject* object);
	ChainedScatterObject* find(int key);
	void withdraw(int key);
};