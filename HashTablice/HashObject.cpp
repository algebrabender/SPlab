#include "HashObject.h"

HashObject* HashObject::operator=(const HashObject* object)
{
	this->key = object->key;
	this->deleteRecord();
	this->record = object->record;
	return this;
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
	std::cout << this->key << " (" << this->record << ") \n";
}