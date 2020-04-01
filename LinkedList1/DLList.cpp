#include "DLList.h"
#include <iostream>
using namespace std;

DLList::DLList()
{
	head = tail = nullptr;
}
DLList::~DLList()
{
	while (!isEmpty()) {
		int temp = deleteFromHead();
	}
}
void DLList::addToHead(int element)
{
	if (isEmpty())
		head = tail = new DLLNode(element);
	else
	{
		DLLNode* temp = new DLLNode(nullptr, element, head);
		head->prev = temp;
		head = temp;
		//proveri
	}
}
void DLList::addToTail(int element)
{
	if (!isEmpty())
	{
		DLLNode* temp = new DLLNode(tail, element, nullptr);
		tail->next = temp;
		tail = temp;
	}
	else
	{
		head = tail = new DLLNode(element);
	}
}
void DLList::deleteElement(int element)
{
	if (isEmpty())
		throw exception ("The list is empty.");
	if (head == tail && head->info == element)
	{
		delete head;
		head = tail = nullptr;
	}
	else if (head->info == element)
	{
		DLLNode* temp = head;
		head = head->next;
		head->prev = nullptr;
		delete temp;
	}
	else
	{
		DLLNode* temp = head->next;
		while (temp != nullptr && temp->info != element)
			temp = temp->next;
		if (temp!=nullptr)
		{
			temp->prev->next = temp->next;
			if (temp->next != nullptr)
			{
				temp->next->prev = temp->prev;
			}
			if (temp == tail)
				tail = temp->prev;
			delete  temp;
		}

	}
}
void DLList::printAll()
{
	if (isEmpty())
		throw exception("The list is empty.");
	DLLNode* temp = head;
	while (temp != nullptr)
	{
		cout << temp->print() << " ";
		temp = temp->next;
	}
	cout << endl;
}
int DLList::deleteFromHead()
{
	if (isEmpty())
		throw exception("The list is empty.");
	else
	{
		int element = head->info;
		DLLNode* temp = head;
		if (head == tail)
			head = tail = nullptr;
		else
			head = head->next;
		delete temp;
		return element;
	}

}