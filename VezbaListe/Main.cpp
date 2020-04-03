#include "DoubleLinkedList.h"

int main()
{
	DoubleLinkedList* dll = new DoubleLinkedList;
	for (int i = 1; i < 11; i++)
		dll->addToHead(i);
	
	//dll->printAll();

	dll->addToHead(2);
	dll->addToTail(2);
	dll->addToHead(3);
	dll->addToHead(5);
	dll->addToTail(5);
	
	dll->printAll();

	dll->removeDuplicates();

	dll->printAll();

	return 0;
}