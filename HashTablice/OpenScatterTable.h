#pragma once
#include "HashTable.h"
#include "ScatterObject.h"

class OpenScatterTable : public HashTable {
protected:
	ScatterObject** arr;
public:
	OpenScatterTable(unsigned int length);
	~OpenScatterTable();
	unsigned int findUnoccupied(ScatterObject* object);
	int findMatch(int key); //int da bi moglo da se vrati -1
	void insert(ScatterObject* object);
	ScatterObject* find(int key);
	void withdraw(int key);

	unsigned int c1(unsigned int i, unsigned int alfa); //linearno trazenje
	unsigned int c2(unsigned int i, unsigned int alfa); //kvadratno trazenje
	unsigned int c3(unsigned int i, HashObject* object); //trasf sa sek. hash funkcijom
	unsigned int hPrim(HashObject* object); //sek. hash funkcija
};