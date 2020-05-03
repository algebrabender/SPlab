#pragma once
#include <iostream>
#include "BSTNode.h"

using namespace std;

class MinHeap {
protected:
	BSTNode** heap;
	int length;
	int numOfEl;
public:
	MinHeap(int length);
	virtual ~MinHeap();
	bool isEmpty() { return numOfEl == 0; };
	void insert(BSTNode* node);
	BSTNode* deleteRoot();
	void breadthFirst(); //obilazak po sirini
	void preorder() { preorder(1); }; //rekurzivni metod
	void preorder(int index); //rekurzivni metod
	void iterativePreorder(); //iterativni metod
	void toBST(); //dinamicka reprezentacija
};