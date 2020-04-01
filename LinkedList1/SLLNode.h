#pragma once

template <class T>
class SLLNode {
public:
	T info;
	SLLNode<T>* next;

	SLLNode() { next = nullptr; };
	SLLNode(T info) {
		this->info = info;
		next = nullptr;
	};
	SLLNode(T info, SLLNode<T>* next) {
		this->info = info;
		this->next = next;
	};
	~SLLNode() {};
	T print() { return info; };
	bool isEqual(T el) { return el == info };
};
