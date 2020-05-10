#pragma once
#include "Edge.h"
#include "LinkedNode.h"

class GraphAsLists {
protected:
	LinkedNode* start; //pointer na prvi cvor
	int numberOfNodes;
public:
	GraphAsLists() :start(nullptr), numberOfNodes(0) {};
	virtual ~GraphAsLists();
	LinkedNode* findNode(int info);
	Edge* findEdge(int a, int b);
	bool insertNode(int info);
	bool deleteNode(int info);
	bool insertEdge(int a, int b);
	bool deleteEdge(int a, int b);
	int breadthTrav(int a); //obilazak po sirini
	int depthTrav(int a); //obilazak po dubini
	int topologicalOrderTrav(); //topoloski obilazak
	void print();
protected:
	void deleteEdgeToNode(LinkedNode* node);
};