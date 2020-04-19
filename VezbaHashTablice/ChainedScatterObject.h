#pragma once
#include "ScatterObject.h"

class ChainedScatterObject: public ScatterObject {
public:
	int next;

	ChainedScatterObject() :ScatterObject(), next(-1) {};
	ChainedScatterObject(Preduzece* record) :ScatterObject(record), next(-1) {};
	ChainedScatterObject(Preduzece* record, unsigned int next) :ScatterObject(record), next(next) {};
};