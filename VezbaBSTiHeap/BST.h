#pragma once
#include "BSTNode.h"
#include <exception>

class BST {
protected:
	BSTNode* root;
	int numOfEl;
public:
	BST() : root(nullptr), numOfEl(0) {}
	virtual ~BST();
	void deleteTree(BSTNode* node);
	bool isEmpty() { return this->root == nullptr; };
	void insert(int key);
	BSTNode* search(int key) { return search(this->root, key); }; //trazenje u celom stablu
	BSTNode* search(BSTNode* node, int key); //trazenje od node
	void breadthFirst(); //obilazak po sirini
	void inorder() { inorder(this->root); }; //rekurzivni metod, celo stablo
	void inorder(BSTNode* node); //rekurzivni metod, od node
	void iterativeInorder(); //iterativni metod
	int brojCvorova() { return brojCvorova(this->root); }
	int brojCvorova(BSTNode* node);
};