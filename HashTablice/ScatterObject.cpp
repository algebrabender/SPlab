#include "ScatterObject.h"

ScatterObject::ScatterObject()
	:HashObject()
{
	status = 0;
}

ScatterObject::ScatterObject(int key)
	:HashObject(key)
{
	status = 0;
}

ScatterObject::ScatterObject(int key, char* record)
	: HashObject(key, record)
{
	status = 0;
}
