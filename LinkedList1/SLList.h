#pragma once
#include "SLLNode.h"

template <class T>
class SLList
{
protected:
	SLLNode <T>* head;
	SLLNode <T>* tail;
public:
	SLList() { head = tail = nullptr; };
	~SLList();
	bool isEmpty() { return head == nullptr; };
	void addToHead(T element);
	void addToTail(T element);
	T deleteFromHead();
	T deleteFromTail();
	void printAll();
	void deleteEl(T element);

	//za sledece f-je nema def na prezentaciji

	

	SLLNode <T>* findNodePtr(T element);
	SLLNode <T>* getHead() { return head; }
	SLLNode<T>* getNext(SLLNode<T>* ptr);
	T getHeadEl();
	T getNextEl(T element);
	bool isInList(T el);
};

template <class T>
SLList<T>::~SLList()
{
	while (!isEmpty)
		T tmp = deleteFromHead();
	
}
template <class T>
void SLList<T>::addToHead(T element)
{
	SLLNode<T>* temp = new SLLNode<T>();
	temp->info = element;
	temp->next = head;
	head = temp;
	if (this->tail == nullptr)
		tail = head;
	
}
template <class T>
void SLList<T>::addToTail(T element)
{
	if (!isEmpty())
	{
		tail->next = new SLLNode<T>(element);//next ce biti nullptr jer je poslednji element
		tail = tail->next;
	}
	else
		head = tail = new SLLNode<T>(element)
}
template <class T>
T SLList<T>::deleteFromHead()
{
	if (isEmpty())
		throw exception("List is empty.");
	T element = head->info;
	SLLNode<T>* temp = head;
	if (head == tail)
		head = tail = nullptr;
	else
		head = head->next;
	delete temp;
	return element;
}
template <class T>
T SLList<T>::deleteFromTail()
{
	if (isEmpty())
		throw exception("List is empty.");
	T element = tail->info;
	SLLNode<T>* temp = tail;
	if (head == tail) //samo jedan element
		head = tail = nullptr;
	else
	{
		SLLNode<T> *temp1;
		temp1 = head;
		while (temp1->next != tail)
			temp1 = temp1->next;
		tail = temp1;
		tail->next = nullptr;
	}
	delete temp;
	return el;

}
template <class T>
void SLList<T>::deleteEl(T element)
{
	if (isEmpty())
		throw exception("List is empty.");
	if (head == tail && head->info.isEqual(element))
	{
		delete head;
		head = tail = nullptr;
	}
	else if (element == head->info)
	{
		SLLNode<T>* temp = head;
		head = head->next;
		delete temp;
	}
	else
	{
		SLLNode<T>* spok, * npok;
		spok = head;
		npok = head->next;
		while (npok != nullptr && !(npok->info.isEqual(element)))
		{
			spok = npok; //proveri
			npok = npok->next;
		}
		if (npok != nullptr)
		{
			spok->next = npok->next;
			if (npok == tail)
				tail = spok;
			delete npok;
			delete spok; // valjda
		}

	}
}
template <class T>
void SLList<T>::printAll() {
	SLLNode<T>* temp = head;
	while (temp != nullptr)
	{
		
		cout << temp->print() << " ";
		temp = temp->next
	}
}
template<class T>
 SLLNode<T>* SLList<T>::findNodePtr(T element)
{
	 SLLNode<T>* temp = head;
	 while (temp != nullptr && !(temp->isEqual(element)))
		 temp = temp->next;
	 if (temp == nullptr)
		 throw exception("Element not found.");
	 else return temp;

}
 template<class T>
 SLLNode<T>* SLList<T>::getNext(SLLNode<T>* ptr)
 {
	 if (ptr)
		 return ptr->next;
	 else throw exception("Nullpointer exception.");

 }
 template<class T>
 T SLList<T>::getHeadEl()
 {
	 if (head == nullptr)
		 throw exception("The list is empty.");
	 else
		 return head->info;
 }
 template<class T>
 T SLList<T>::getNextEl(T element)
 {
	 SLLNode<T>* temp = findNodePtr(element);
	 if (temp->next == nullptr)
		 throw exception("There is no next element.");
	 else
		 return (temp->next->info);
 }
 template<class T>
 bool SLList<T>::isInList(T el)
 {
	 SLLNode<T>* temp = head;
	 while (temp != nullptr && !(temp->info.isEqual(el)))
		 temp = temp->next;
	 return temp != nullptr;
 }
