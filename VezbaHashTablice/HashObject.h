#pragma once
#include "Preduzece.h"

class HashObject {
protected:
	int key; //bice PIB
	Preduzece* record; //podatak u tablici
public:
	HashObject() :key(0), record(nullptr) {};
	HashObject(Preduzece* record);
	virtual ~HashObject();
	HashObject* operator= (const HashObject* object);
	bool operator == (const HashObject* object) { return this->record == object->record; };
	void deleteRecord();
	int getKey() { return this->key; };
	Preduzece* getRecord() { return this->record; };
	bool isEqualKey(int key) { return this->key == key; };
	void print();
};