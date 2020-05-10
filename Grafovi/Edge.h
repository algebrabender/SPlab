#pragma once
#include "LinkedNode.h"

class LinkedNode;

class Edge {
public:
	LinkedNode* dest; //odredisni cvor
	Edge* link; //sl u listi
	//int weight; //idk sta za tezinum ovamo je W drugacije od T za info
	Edge() : dest(nullptr), link(nullptr) {};
	Edge(LinkedNode* dest, Edge* link) :dest(dest), link(link) {};
};