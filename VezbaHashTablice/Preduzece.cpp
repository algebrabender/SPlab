#include "Preduzece.h"

Preduzece::Preduzece(string naziv, int pib, int brRadnika, double godPrihod)
{
	this->naziv = naziv;
	this->PIB = pib;
	this->brRadnika = brRadnika;
	this->godPrihod = godPrihod;
}

void Preduzece::print()
{
	cout << "PIB: " << this->PIB << " Preduzece: " << this->naziv
		<<  "Broj radnika: " << this->brRadnika
		<< " Godisnji prihod: " << this->godPrihod << endl;
}

Preduzece* Preduzece::operator=(const Preduzece* object)
{
	if (this != object)
	{
		this->naziv = object->naziv;
		this->PIB = object->PIB;
		this->brRadnika = object->brRadnika;
		this->godPrihod = object->godPrihod;
		return this;
	}
}