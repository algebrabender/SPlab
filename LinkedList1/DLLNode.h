#pragma once
class DLLNode {
public:
	DLLNode* prev;
	int info;
	DLLNode* next;
	
	DLLNode() { prev = next = nullptr; };
	DLLNode(int info) { this->info = info; };
	DLLNode( DLLNode* left, int info, DLLNode* right)
	{
		this->prev = left;
		this->info = info;
		this->next = right;
	};
	~DLLNode() {};
	int print() { return info; }
	bool isEqual(int element) { return info == element; };
};