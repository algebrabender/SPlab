#pragma once
#include "ScatterObject.h"

class ChainedScatterObject : public ScatterObject {
public:
	long next;

	ChainedScatterObject();
	ChainedScatterObject(int key);
	ChainedScatterObject(int key, char* record);
	ChainedScatterObject(int key, char* record, unsigned int next);
};