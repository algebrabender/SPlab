#pragma once
class Node
{
public:
	int info;
	Node* next; //dlink
	Node* prev; //llink
public:
	Node() :info(0), next(nullptr), prev(nullptr) {};
	Node(int element);
	Node(int element, Node* next, Node* prev);
	~Node() {};
	int print() { return this->info; };
	bool isEqual(int element) { return element == info; };
};

