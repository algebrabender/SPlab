#pragma once
#include "HashObject.h"
#include <exception>

class HashTable {
protected:
	unsigned int length; //velicina tablice
	unsigned int count; //broj elemenata u tablici

	unsigned int h(HashObject* object); //hash f-ja
	unsigned int f(int iKey); //int->unsigned, Fibonacijev metod
	unsigned int f(double dKey); //double->unsigned
	unsigned int f(char* sKey); //string->unsigned
	unsigned int g(unsigned int key); //sek. f-ja
public:
	unsigned int getLength() { return this->length; };
	double getLoadFactor();

private:
	int getPower(unsigned int num); //za fib
};