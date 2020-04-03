#include "DoubleLinkedList.h"

DoubleLinkedList::~DoubleLinkedList()
{
	while (!isEmpty()) //dok imamo cvorove
	{
		int temp = deleteFromHead();
	}
}

void DoubleLinkedList::addToHead(int element)
{
	if (!isEmpty()) //ako lista nije prazna
	{
		Node* temp = new Node(element, head, nullptr); //ukazuje na sta je ukazivao head
		head->prev = temp; //treba da ukazuje na prethodni element
		head = temp;
	}
	else
		head = tail = new Node(element);
}

void DoubleLinkedList::addToTail(int element)
{
	if (!isEmpty())
	{
		Node* temp = new Node(element, nullptr, tail); //ukazuje na cvor na koji je ukazivao tail
		tail->next = temp; //cvor na koji je ukazivao tail treba da ukazje na novi el
		tail = temp;
	}
	else
		head = tail = new Node(element);
}

int DoubleLinkedList::deleteFromHead()
{
	if (!isEmpty())
	{
		int toReturn = head->info;
		Node* temp = head;
		if (head == tail) //onda oba treba da budu nullptr
			head = tail = nullptr;
		else
			head = head->next;
		delete temp;
		return toReturn;
	}
	else
		throw exception("Lista je prazna");
}

int DoubleLinkedList::deleteFromTail()
{
	int toReturn = tail->info;
	Node* temp = tail;
	if (head == tail) //oba na nullptr
		head = tail = nullptr;
	else
		tail = tail->prev;
	delete temp;
	return toReturn;
}

void DoubleLinkedList::printAll()
{
	if (!isEmpty())
	{
		Node* temp = head;
		while (temp != nullptr)
		{
			cout << temp->print() << " ";
			temp = temp->next;
		}
		cout << endl;
	}
	else
		throw exception("Prazna lista");
}

void DoubleLinkedList::deleteElement(int element)
{
	if (!isEmpty())
	{
		if (head == tail && head->isEqual(element)) //ako je jedini cvor sa elementom koji trazimo
		{
			delete head;
			head = tail = nullptr;
		}
		else if (head->info == element) //prvi cvor sa elementom koji trazimo ali nije jedini
		{
			Node* temp = head;
			head = head->next;
			head->prev = nullptr;
			delete temp;
		}
		else
		{
			Node* temp = head->next; //vec proveren head;
			while (temp != nullptr && !temp->isEqual(element)) //dok ne ukazuje na tail tj da je poslednji cvor ili dok nije cvor sa time elementom
				temp = temp->next;
			if (temp != nullptr) //izaslo je iz petlje jer doslo do cvora sa elementom
			{
				temp->prev->next = temp->next; //sledeci cvor prethodnog cvor ukazuje na sledeci (u odnosu na trenunti)
				if (temp->next != nullptr) //nije poslednji cvor u listi
					temp->next->prev = temp->prev; //prethdonik sledeceg cvora ukazuje na prethodni (u odnosu na trenutni)
				if (temp == tail) //ako je poslednji cvor 
					tail = temp->prev; //tail treba da ukazuje na prethoni trenutnog
				delete temp;
			}
		}
	}
	else
		throw exception("Lista je prazna");
}

bool DoubleLinkedList::isInList(int element)
{
	if (!isEmpty())
	{
		if (head == tail)
			return head->isEqual(element); //ako je jedini cvor u listi
		else if (head->info == element)
			return true;
		else
		{
			Node* temp = head->next;
			while (temp != nullptr && !temp->isEqual(element))
				temp = temp->next;
			if (temp != nullptr) //izaslo je iz while jer je naslo element
				return true;
			else 
				return false;
		}
	}
	else
		throw exception("Lista je prazna");
}

void DoubleLinkedList::removeDuplicates() //mozda treba optimizovati
{
	Node* temp;
	Node* temp2; //temp i temp2 da bi bila "for" petlja kao kod polja
	Node* temp3; //temp3 za delete
	temp = head;
	while (temp != nullptr && temp->next != nullptr) //prva "for" petlja
	{
		temp2 = temp; //za drugu "for" petlju
		while (temp2->next != nullptr) //druga "for" petlja
		{
			if (temp2->next->isEqual(temp->info)) //ako je duplikat
			{
				temp3 = temp2->next; //temp2->next je za brisanje
				temp2->next = temp2->next->next;
				delete temp3; //brisanje duplikata
			}
			else //ako nije preci na sledeci element
				temp2 = temp2->next;
		}
		temp = temp->next; //pomeranje na sledeci element
	}
}