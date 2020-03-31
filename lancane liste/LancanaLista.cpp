#include "LancanaLista.h"
#include <iostream>
#include <exception>

LancanaLista::~LancanaLista()
{
	while (!isEmpty())
	{
		int temp = deleteFromHead();
	}
}

void LancanaLista::addToHead(int E)
{
	Node* temp = new Node();
	temp->info = E;
	temp->next = head;
	head = temp;
}

void LancanaLista::addToTail(int E)
{
	if (isEmpty()) //head==nullptr
		head = new Node(E);
	else
	{
		Node* temp = head;
		while (temp->next != nullptr)
			temp = temp->next;
		temp->next = new Node();
		temp->next->info = E;
		temp->next->next = nullptr;
	}
}

int LancanaLista::deleteFromHead()
{
	if (isEmpty())
		throw std::exception("Lista je prazna");
	int E = head->info;
	Node* temp = head;
	delete temp;
	return E;
}

int LancanaLista::deleteFromTail()
{
	if (isEmpty())
		throw std::exception("Lista je prazna");
	int E;
	if (head->next == nullptr)
	{
		E = head->info;
		delete head;
		head = nullptr;
	}
	else
	{
		Node* temp = head->next; //optimizacija?
		while (temp->next != nullptr)
			temp = temp->next;
		E = temp->next->info;
		delete temp->next;
		temp->next = nullptr;
		return E;
	}
}

void LancanaLista::printAll()
{
	Node* temp = head;
	while (temp != nullptr)
	{
		std::cout << temp->print() << " ";
		temp = temp->next;
	}
}