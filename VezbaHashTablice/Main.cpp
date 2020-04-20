#include "ChainedScatterTable.h"

int main()
{
	Preduzece* p1 = new Preduzece("Preduzece 1", 1002, 50, 199402.10);
	Preduzece* p2 = new Preduzece("Preduzece 2", 309, 100, 199609.3);
	Preduzece* p3 = new Preduzece("Preduzece 3", 503, 150, 199903.5);
	Preduzece* p4 = new Preduzece("Preduzece 4", 2903, 100, 199103.29);
	Preduzece* p5 = new Preduzece("Preduzece 5", 2102, 50, 199402.21);
	Preduzece* p6 = new Preduzece("Preduzece 6", 1002, 100, 199002.10);
	Preduzece* p7 = new Preduzece("Preduzece 7", 1002, 50, 199402.10);

	ChainedScatterObject* obj1 = new ChainedScatterObject(p1);
	ChainedScatterObject* obj2 = new ChainedScatterObject(p2);
	ChainedScatterObject* obj3 = new ChainedScatterObject(p3);
	ChainedScatterObject* obj4 = new ChainedScatterObject(p4);
	ChainedScatterObject* obj5 = new ChainedScatterObject(p5);
	ChainedScatterObject* obj6 = new ChainedScatterObject(p6);
	ChainedScatterObject* obj7 = new ChainedScatterObject(p7);
	ChainedScatterObject* obj8;

	try {
		ChainedScatterTable* tablica = new ChainedScatterTable(8192); //2^13 zbog fib
		tablica->insert(obj1);
		tablica->insert(obj2);
		tablica->insert(obj3);
		tablica->insert(obj4);
		tablica->insert(obj5);
		tablica->insert(obj6);
		tablica->insert(obj7);
		tablica->print();
		cout << "--------------------------------------------------------------------------------" << endl;
		tablica->withdraw(503);
		tablica->withdraw(obj1->getKey());
		tablica->print();
		cout << "--------------------------------------------------------------------------------" << endl;
		obj8 = tablica->find(2903);
		obj8->print();
		delete tablica;
	}
	catch (exception exc)
	{
		cout << exc.what() << endl;
	}
	catch (...)
	{
		cout << "Nepoznata greska" << endl;
	}
	delete obj1;
	delete obj2;
	delete obj3;
	delete obj4;
	delete obj5;
	delete obj6;
	delete obj7;
	return 0;
}