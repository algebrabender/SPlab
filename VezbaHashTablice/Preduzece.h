#pragma once
#include <iostream>
#include <string>

using namespace std;

class Preduzece {
private:
	string naziv;
	int PIB; //bice key, int dovoljan za osam cifara
	int brRadnika;
	double godPrihod;
public:
	Preduzece(string naziv, int pib, int brRadnika, double godPrihoda);
	virtual ~Preduzece() {};
	void print();
	bool operator== (const Preduzece* object) { return this->naziv == object->naziv; };
	int getPIB() { return this->PIB; };
	Preduzece* operator= (const Preduzece* object);
};