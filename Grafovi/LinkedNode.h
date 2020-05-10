#pragma once
#include "Edge.h"
#include <iostream>

using namespace std;

class Edge;

class LinkedNode {
public:
	int info; //i guess sta daju u zadataku
	Edge* adj; //za listu potega
	LinkedNode* next; //za listu cvorova
	int status; //0-nista, 1-nacekanju, 2-u redu/na stacku, 3-obradjen
	LinkedNode();
	LinkedNode(int info);
	LinkedNode(int info, Edge* ajd, LinkedNode* next, int status);
	void visit();
};