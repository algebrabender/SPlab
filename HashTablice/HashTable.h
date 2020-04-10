#pragma once
#include "HashObject.h"
#include <exception>

class HashTable {
protected:
	unsigned int length; //velicina tablice
	unsigned int count; //broj elemenata u tablici
	
	unsigned int h1(HashObject* object); //hash funkcija, metod deljenja
	unsigned int h2(HashObject* object); //hash f-ja, metod sredina kvadrata
	unsigned int h3(HashObject* object); //hash f-ja, Fibonacijev metod
	unsigned int f(int iKey); //int->unsigned
	unsigned int f(double dKey); //double->unsigned
	unsigned int f(char* sKey); //string->unsigned
	///ovo ce vrv da ide u klasu za otvoreno adresiranje
	unsigned int c1(unsigned int i, unsigned int alfa); //linearno trazenje
	unsigned int c2(unsigned int i, unsigned int alfa); //kvadratno trazenje
	unsigned int c3(unsigned int i, HashObject* object); //trasf sa sek. hash funkcijom
	unsigned int hPrim(HashObject* object); //sek. hash funkcija
	///
public:
	unsigned int getLength() { return this->length; };
	double getLoadFactor();

private:
	int getPower(unsigned int num);
};