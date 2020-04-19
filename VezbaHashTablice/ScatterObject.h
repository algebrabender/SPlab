#pragma once
#include "HashObject.h"

class ScatterObject: public HashObject { 
public:
	int status; //0-slobodan, 1-obrisan, 2-zauzet

	ScatterObject() :HashObject(), status(0) {};
	ScatterObject(Preduzece* object) :HashObject(object), status(0) {};
};