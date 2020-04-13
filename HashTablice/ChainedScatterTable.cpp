#include "ChainedScatterTable.h"

ChainedScatterTable::ChainedScatterTable(unsigned int length)
{
	if (length > 0)
	{
		this->length = length;
		this->count = 0;
		arr = new ChainedScatterObject * [length];
	}
	else
		throw exception("Nevalidna duzina");
}

ChainedScatterTable::~ChainedScatterTable()
{
	if (arr != nullptr)
	{
		delete[] arr;
		arr = nullptr;
	}
}

void ChainedScatterTable::insert(ChainedScatterObject* object)
{
	if (this->count == this->length)
		throw exception("Tablica je puna");
	else
	{
		unsigned int temp = h2(object);
		if (arr[temp]->status == 2) //ako zauzeto mesto
		{
			while (arr[temp]->next != -1)
				temp = arr[temp]->next; //trazi se kraj sinonima
			unsigned int tail = temp;
			temp = g(temp);
			while (arr[temp]->status == 2 && temp!=tail) //ako zauzeto mesto i nismo se vratili na pocetak 
				temp = g(temp);
			if (temp != tail)
				arr[tail]->next = temp; //poslednji treba da ukazuje na novi sinonim
			else
				throw exception("Losa sekundarna transforamcija");
		}
		//i da nije zauzeto i da je zauzeto temp je indeks gde treba staviti object
		arr[temp] = object;
		arr[temp]->status = 2;
		arr[temp]->next = -1;
		++count;
	}
}

ChainedScatterObject* ChainedScatterTable::find(int key)
{
	unsigned int temp = f(key) % length;
	while (temp != -1) //ako je -1 nema sl element u prvom prolazu je svako razlico
	{
		if (!arr[temp]->isEqualKey(key))
			temp = arr[temp]->next; //prelazi se na sledeci sinonim
		else
			return arr[temp]; //nadjen je element sa istim kljucem
	}
	throw exception("Element nije nadjen");
}

void ChainedScatterTable::withdraw(int key)
{
	if (count > 0)
	{
		unsigned int temp = f(key) % length;
		int prev = -1; //prethodnik
		while (temp != -1 && !arr[temp]->isEqualKey(key))
		{
			prev = temp; //sadasnji je prethodni
			temp = arr[temp]->next; //prelazak na sl
		}
		if (temp == -1)
			throw exception("Element nije nadjen");
		if (prev != -1) //izaslo se zbog isEqualKey tj nadjen odgovarajuci sinonim
		{
			arr[prev]->next = arr[temp]->next; //prelancavanje
			arr[temp]->deleteRecord();
			arr[temp]->status = 1;
		}
		else //nije se ni proslo kroz while petlju, tj temp odgovaraj key
		{
			if (arr[temp]->next == -1) //nema sinonima
			{
				arr[temp]->deleteRecord();
				arr[temp]->status = 1;
			}
			else //ima sinonima na dalje
			{
				unsigned int nextEl = arr[temp]->next; 
				arr[temp]->deleteRecord();
				arr[temp] = arr[nextEl]; //prebacivanje posto je temp prvi u listi sinonima
				arr[temp]->next = arr[nextEl]->next; //prelancavanje
				arr[nextEl] = new ChainedScatterObject(); //novi "prazni" objekat
				arr[nextEl]->next = 1; //obrisano
			}
		}
	}
	else
		throw exception("Prazna tablica");
}

unsigned int ChainedScatterTable::g(unsigned int key)
{
	return (key + 1) % length;
}