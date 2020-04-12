#include "OpenScatterTable.h"

OpenScatterTable::OpenScatterTable(unsigned int length)
{
	if (length > 0)
	{
		this->length = length;
		this->count = 0;
		arr = new ScatterObject * [length];
	}
	else
		throw exception("Nevalidna duzina");
}

OpenScatterTable::~OpenScatterTable()
{
	if (arr != nullptr)
	{
		delete[] arr;
		arr = nullptr;
	}
}

unsigned int OpenScatterTable::findUnoccupied(ScatterObject* object)
{
	unsigned int hash = h3(object);
	unsigned int temp = hash;
	if (arr[temp]->status < 2) //slobodno ili obrisano mesto
		return temp;
	else
	{
		int i = 0;
		do
		{
			temp = (hash + c1(i, 5)) % length;
			if (arr[temp]->status < 2)
				return temp;
			++i;
		} while (temp != hash && i < length);
		throw exception("Tablica je puna");
	}
}

int OpenScatterTable::findMatch(int key)
{
	unsigned int temp = f(key) % length;
	for (int i = 0; i < length; i++)
	{
		int synonim = temp + c2(i, 5);
		if (arr[synonim]->status == 0)
			return -1; //slobodno mesto, svaki sledece mesto za synonim je isto slobodno
		if (arr[synonim]->isEqualKey(key))
			return temp; //nadjen match
	}
	return -1; //nije nadjen match
}

void OpenScatterTable::insert(ScatterObject* object)
{
	if (this->count == this->length)
		throw exception("Tablica je puna"); //mozda bolje sa loadfactor
	else
	{
		unsigned int temp = this->findUnoccupied(object);
		arr[temp] = object;
		arr[temp]->status = 2; //zauzeto mesto
		++count;
	}
}

ScatterObject* OpenScatterTable::find(int key)
{
	int temp = findMatch(key);
	if (temp > -1)
		return arr[temp];
	else
		throw exception("Nije nadjen element");
}

void OpenScatterTable::withdraw(int key)
{
	if (count > 0)
	{
		int temp = findMatch(key);
		if (temp > -1)
		{
			arr[temp]->deleteRecord();
			arr[temp]->status = 1; //obrisan element
		}
		else
			 throw exception("Nije nadjen element");
	}
	else
		throw exception("Prazna tablica");
}

unsigned int OpenScatterTable::c1(unsigned int i, unsigned int alfa)
{
	return (i * alfa) % length;
}

unsigned int OpenScatterTable::c2(unsigned int i, unsigned int alfa)
{
	return (i * i * alfa) % length;
}

unsigned int OpenScatterTable::c3(unsigned int i, HashObject* object)
{
	return i * hPrim(object);
}

unsigned int OpenScatterTable::hPrim(HashObject* object)
{

}