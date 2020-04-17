#include "ChainedScatterObject.h"

ChainedScatterObject::ChainedScatterObject()
	:ScatterObject()
{
	this->next = -1;
}

ChainedScatterObject::ChainedScatterObject(int key)
	:ScatterObject(key)
{
	this->next = -1;
}

ChainedScatterObject::ChainedScatterObject(int key, char* record)
	: ScatterObject(key, record)
{
	this->next = -1;
}

ChainedScatterObject::ChainedScatterObject(int key, char* record, unsigned int next)
	: ScatterObject(key, record)
{
	this->next = next;
}
