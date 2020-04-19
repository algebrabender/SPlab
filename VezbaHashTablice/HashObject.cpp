#include "HashObject.h"

HashObject::HashObject(Preduzece* object)
{
	this->record = object;
	this->key = object->getPIB();
}

HashObject::~HashObject() //proveriti da li se ovim izbegava delete u mainu
{
	if (record != nullptr)
		delete record;
}

HashObject* HashObject::operator=(const HashObject* object)
{
	if (this != object)
	{
		this->key = object->key;
		this->record = object->record;
		return this;
	}
}

void HashObject::deleteRecord()
{
	if (record != nullptr)
	{
		delete record;
		record = nullptr;
	}
}

void HashObject::print()
{
	this->record->print(); //PIB koji je kljuc ce biti prvi stampan
}