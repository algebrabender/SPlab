#pragma once
#include "LinkedNode.h"

class LinkedNode;

class Edge {
public:
	LinkedNode* dest; //odredisni cvor
	Edge* link; //sl u listi
	//int weight;
	Edge() : dest(nullptr), link(nullptr) {};
	Edge(LinkedNode* dest, Edge* link) :dest(dest), link(link) {};
};
