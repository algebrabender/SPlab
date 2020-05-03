#include "BST.h"

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
	cout << "\nBroj cvorova koji imaju samo desno dete: " << tree->brojCvorova() << endl;
	tree->insert(3);
	tree->insert(21);
	cout << "\nBroj cvorova koji imaju samo desno dete: " << tree->brojCvorova() << endl;
	delete tree;
	return 0;
}