#include "MinHeap.h"

int main()
{
	MinHeap* heap = new MinHeap(8);
	heap->insert(5);
	heap->insert(12);
	heap->insert(6);
	heap->insert(9);
	heap->insert(3);
	heap->insert(7);
	heap->insert(17);
	heap->insert(2);
	cout << "Obilazak po sirini" << endl;
	heap->breadthFirst();
	cout << "\nObilazak po dubini (preorder rekurzivni)" << endl;
	heap->preorder();
	cout << "\nObilazak po dubini (preorder iterativni)" << endl;
	heap->iterativePreorder();
	cout << "\nKoren: "<< heap->deleteRoot() << endl;
	heap->breadthFirst();
	cout << endl;
	heap->toBST();
	delete heap;
	return 0;
}