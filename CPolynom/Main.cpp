#include "CPolynom.h"
#include <iostream>
#include <exception>

using namespace std;

int main()
{
	try
	{
		CPolynom* p1 = new CPolynom(2);
		CPolynom* p2 = new CPolynom(3);
		CPolynom* p3 = new CPolynom(0);

		p1->Coef(0, 10.02);
		p1->Coef(2, 19.94);
		p2->Coef(0, 1.08);
		p2->Coef(1, 20.14);
		p2->Coef(3, 15.03);

		p1->print();
		p2->print();

		p3->Add(p1, p2);
		p3->print();

		p3 = p3->Mul(p1, p2);
		p3->print();

		delete p1;
		delete p2;
		delete p3;
	}
	catch (exception exc)
	{
		cout << exc.what() << endl;
	}
	catch (...)
	{
		cout << "Nepoznata greska" << endl;
	}
	return 0;
}
