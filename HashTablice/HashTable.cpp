#include "HashTable.h"

unsigned int HashTable::h1(HashObject* object)
{
	return (f(object->getKey()) % this->length);
}

unsigned int HashTable::h2(HashObject* object)
{
	unsigned int squaredKey = object->getKey() * object->getKey();
	unsigned int p = getPower(this->length);
	if (p != -1)
		return squaredKey >> (32 - p);
	else
		return -1;
		//throw std::exception ("Nemoguce koristiti ovu funkciju")
}

unsigned int HashTable::h3(HashObject* object)
{
	unsigned const int a = 2654435769;
	unsigned int ak = a * object->getKey();
	unsigned int p = getPower(this->length);
	if (p != -1)
		return ak >> (32 - p);
	else
		return -1;
}

unsigned int HashTable::f(int iKey)
{
	return abs(iKey);
}

unsigned int HashTable::f(double dKey)
{
	if (dKey != 0)
	{
		int exp;
		double m = frexp(dKey, &exp);
		unsigned int key = (unsigned int)((2 * fabs(m) - 1) * ~0U);
		return key;
	}
	else
		return 0;
}

unsigned int HashTable::f(char* sKey)
{
	unsigned int key = 0;
	unsigned int a = 7; //za pomeranje
	for (int i = 0; sKey[i] != 0; ++i)
		key = key >> a ^ sKey[i];
	return key;
}

unsigned int HashTable::c1(unsigned int i, unsigned int alfa)
{
	return i * alfa;
}

unsigned int HashTable::c2(unsigned int i, unsigned int alfa)
{
	return i*i * alfa;
}

unsigned int HashTable::c3(unsigned int i, HashObject* object)
{
	return i * hPrim(object);
}

unsigned int HashTable::hPrim(HashObject* object)
{

}

double HashTable::getLoadFactor()
{
	return (double)this->count / (double)this->length;
}

int HashTable::getPower(unsigned int num)
{
	if (num % 2 == 0)
	{
		int count = 1;
		while (num != 0)
		{
			num /= 2;
			++count;
		}
		return count;
	}
	else
		return -1;
}