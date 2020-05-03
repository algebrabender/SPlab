#include "BST.h"
#include "MinHeap.h"

int main()
{
	cout << "BST" << endl;
	BST* tree = new BST();
	tree->insert(5);
	tree->insert(9);
	tree->insert(12);
	tree->insert(2);
	tree->insert(1);
	tree->insert(7);
	tree->insert(8);
	tree->insert(4);
	tree->insert(17);
	cout << "Obilazak po sirini" << endl;
	tree->breadthFirst();
	cout << "\nObilazak po dubini (inorder rekurzivni)" << endl;
	tree->inorder();
	cout << "\nObilazak po dubini (inorder iterativni)" << endl;
	tree->iterativeInorder();
	cout << "Broj cvorova koji imaju samo desno dete: " << tree->brojCvorova() << endl;
	//dodati jos cvorova
	cout << "\n---------------------------------------" << endl;
	cout << "HEAP" << endl;
	MinHeap* heap = new MinHeap(5);
	heap->insert(new BSTNode(5));
	heap->insert(new BSTNode(12));
	heap->insert(new BSTNode(6));
	heap->insert(new BSTNode(9));
	heap->insert(new BSTNode(3));
	cout << "Obilazak po sirini" << endl;
	heap->breadthFirst();
	cout << "\nObilazak po dubini (preorder rekurzivni)" << endl;
	heap->preorder();
	cout << "\nObilazak po dubini (preorder iterativni)" << endl;
	heap->iterativePreorder();
	BSTNode* koren = heap->deleteRoot();
	cout << "\nKoren: ";
	koren->visit();
	cout << endl;
	heap->breadthFirst();
	delete tree;
	delete heap;
	return 0;
}