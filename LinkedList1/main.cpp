#include "DLList.h"
#include <iostream>
using namespace std;

int main()
{
	DLList* list = new DLList();


	list->addToHead(5);
	list->addToHead(3);
	list->addToHead(21);

	list->addToHead(11);
	list->addToHead(10);

	list->printAll();

	list->deleteFromHead();
	list->printAll();

	list->deleteElement(5);
	list->printAll();

	list->addToTail(9);
	list->printAll();

	list->addToTail(18);
	list->deleteElement(15);
	list->printAll();


	delete list;







	return 0;
}