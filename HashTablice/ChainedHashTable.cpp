#include "ChainedHashTable.h"

ChainedHashTable::ChainedHashTable(unsigned int length)
{
	if (length > 0)
	{
		this->length = length;
		this->count = 0;
		arr = new SLL<HashObject*> [length];
	}
	else
		throw exception("Nevalidna duzina");
}

ChainedHashTable::~ChainedHashTable()
{
	HashObject* temp;
	for (unsigned int i = 0; i < this->length; ++i)
	{
		try 
		{
			temp = arr[i].getHeadEl();
			while (true) //izacice preko catch
			{
				temp->deleteRecord();
				temp = arr[i].getNextEl(temp);
			}
		}
		catch (exception exc) {}
	}
	delete[] arr;
}

void ChainedHashTable::insert(HashObject* object)
{
	arr[h1(object)].addToHead(object);
	++count;
}

HashObject* ChainedHashTable::find(int key)
{
	unsigned int k = f(key) % length;
	HashObject* temp = arr[k].getHeadEl();
	while (!temp->isEqualKey(key))
	{
		try 
		{
			temp = arr[k].getNextEl(temp);
		}
		catch (exception exc)
		{
			return nullptr; //ako bude exception znaci da nije nadjen sl elepent
		}
	}
	return temp; 
}

void ChainedHashTable::withdraw(int key)
{
	HashObject* temp = find(key);
	withdraw(temp);
}

void ChainedHashTable::withdraw(HashObject* object)
{
	arr[h1(object)].deleteEl(object);
	--count;
}