#include "HashTable.h"

unsigned int HashTable::h(HashObject* object)
{
	return (f(object->getKey()) % this->length);
}

unsigned int HashTable::f(int iKey)
{
	unsigned int squaredKey = iKey * iKey;
	unsigned int p = getPower(this->length);
	if (p != -1)
		return squaredKey >> (32 - p);
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

double HashTable::getLoadFactor()
{
	return (double)this->count / (double)this->length;
}

int HashTable::getPower(unsigned int num)
{
	if (num % 2 == 0)
	{
		int count = 0;
		while (num != 1)
		{
			num /= 2;
			++count;
		}
		return count;
	}
	else
		return -1;
}
