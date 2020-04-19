#include "ChainedScatterTable.h"

ChainedScatterTable::ChainedScatterTable(unsigned int length)
{
	if (length > 0)
	{
		this->length = length;
		this->count = 0;
		arr = new ChainedScatterObject * [length];
		arrS = new ChainedScatterObject * [length];
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
	if (arrS != nullptr)
	{
		delete[] arrS;
		arrS = nullptr;
	}
}

void ChainedScatterTable::insert(ChainedScatterObject* object)
{
	if (this->count == this->length)
		throw exception("Tablica je puna");
	else
	{
		unsigned int temp = h(object);
		if (arr[temp]->status == 2) //ako zauzeto mesto
		{
			unsigned int temp2 = arr[temp]->next; //indeks u arrS
			while (temp2 != -1) //traziti u arrS
				temp2 = arrS[temp2]->next; //trazi se kraj sinonima
			unsigned int tail = temp2;
			temp2 = g(temp2); //pomeraj, ako je -1 g ce da vrati nulu
			unsigned int prev = temp2; //da mi mogli da ulancamo sinonime
			while (arrS[temp2]->status == 2 && temp2 != tail) //ako zauzeto mesto i nismo se vratili na pocetak 
			{
				prev = temp2;
				temp2 = g(temp2); //jos pomeranja
			}
			//ako se izaslo jer je mesto slobodno
			if (temp2 != tail) //tj nije se izaslo jer smo prosli sve
			{
				arrS[prev]->next = temp2; //poslednji sinonim treba da ukazuje na novi sinonim
				arrS[temp2] = object; //smestamo
				arrS[temp2]->status = 2;
				arrS[temp2]->next = -1;
				++count;
			}
			else
				throw exception("Losa sekundarna transforamcija");
		}
		else //ako nije zauzeto smestamo object
		{
			arr[temp] = object;
			arr[temp]->status = 2;
			arr[temp]->next = -1;
			++count;
		}
	}
}

ChainedScatterObject* ChainedScatterTable::find(int key)
{
	unsigned int temp = f(key) % length;
	if (temp != -1)
	{
		if (arr[temp]->isEqualKey(key))
			return arr[temp];
		else if (arr[temp]->next != -1) //ako ima sinonimee
		{
			unsigned int temp2 = arr[temp]->next;
			while (temp2 != -1) //trazenje u prostoru za sinonime
			{
				if (!arrS[temp2]->isEqualKey(key))
					temp2 = arrS[temp2]->next;
				else //nadjen element
					return arrS[temp2];
			}
		}
	}
	//ako nisto od uslova nije ispunjeno element nije nadjen
	throw exception("Element nije nadjen");
}

void ChainedScatterTable::withdraw(int key) //verovatno neoptimizovano
{
	if (count > 0) //ako ima elemenata
	{
		unsigned int temp = f(key) % length;
		if (temp != -1)
		{
			if (arr[temp]->isEqualKey(key)) //ako je to taj element
			{
				if (arr[temp]->next == -1) //nema sinonima
				{
					arr[temp]->deleteRecord(); //brise se object sa key
					arr[temp]->status = 1; //obrisano
				}
				else //ima sinonima
				{
					unsigned int temp2 = arr[temp]->next;
					arr[temp]->deleteRecord();
					arr[temp] = arrS[temp2]; //prebacivanje prvog sinonima iz prostora za sinonime
					arr[temp]->next = arrS[temp2]->next; //prelancavanje
					arrS[temp2] = new ChainedScatterObject(); //"popuniti mesto"
					arrS[temp2]->next = 1; //obrisano, to mesto slobodno za sledeci insert
				}
			}
			else if (arr[temp]->next != -1) //ako nije taj kljuc i ima sinonime, traziti po njima
			{
				unsigned int temp2 = arr[temp]->next;
				int prev = -1;
				while (temp2 != -1)
				{
					if (!arrS[temp2]->isEqualKey(key))
					{
						prev = temp2;
						temp2 = arrS[temp2]->next;
					}
					else //nadjen kljuc
					{
						if (prev != -1)
						{
							arrS[prev]->next = arrS[temp2]->next; //prelancavanje
							arrS[temp2]->deleteRecord();
							arrS[temp2]->status = 1; //obrisano
						}
						else //ako prvi sinonim
						{
							if (arrS[temp]->next == -1) //ako nema jos sinonima
							{
								arr[temp]->next = -1; //nece imati sinonim vise
								arrS[temp2]->deleteRecord();
								arrS[temp2]->status = 1; //obrisano
							}
							else //ima jos sinonima 
							{
								arr[temp]->next = arrS[temp2]->next; //prelancavanje
								arrS[temp2]->deleteRecord();
								arrS[temp2]->status = 1; //obrisano
							}
						}
					}
				}
			}
		}
		//ako nista od unutrasnjih ifova ili prvi if
		throw exception("Element nije nadjen");
	}
	else
		throw exception("Prazna tablica");
}