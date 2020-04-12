#pragma once
#include "HashObject.h"

class ScatterObject : public HashObject {
public:
	int status; //0-slobodan, 1-obrisan, 2-zauzet

	ScatterObject();
	ScatterObject(int key);
	ScatterObject(int key, char* record);
};