#pragma once
#include <iostream>

//int key, char* record

class HashObject {
protected:
	int key;
	char* record;
public:
	HashObject() :key(0), record(nullptr) {};
	HashObject(int key) :key(key), record(nullptr) {};
	HashObject(int key, char* record) :key(key), record(record) {};
	~HashObject() { this->deleteRecord(); };
	HashObject* operator = (const HashObject* object);
	bool operator == (const HashObject* object) { return this->record == object->record; };
	void deleteRecord();
	int getKey() { return this->key; };
	char* getRecord() { return this->record; };
	bool isEqualKey(int key) { return this->key == key; };
	void print();
};