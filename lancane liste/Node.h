#pragma once

class Node {
public:
	int info;
	Node* next;
	Node() { next = nullptr; };
	Node(int info) 
	{ 
		this->info = info; 
		next = nullptr; 
	};
	Node(int info, Node* next)
	{
		this->info = info;
		this->next = next;
	};
	~Node() {};
	int print() { return info; };
};