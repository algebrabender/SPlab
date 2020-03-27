#include "CPolynom.h"
#include <iostream>
#include <exception>

using namespace std;

CPolynom::CPolynom(int order)
{
	if (order >= 0)
	{
		red = order;
		polinom = new double[order+1]; //polinom treceg reda bi imao stepene [0,3]
		for (int i = 0; i <= order; i++)
			polinom[i] = 0;
	}
	else
		throw exception("Nevazeci red"); 
}


void CPolynom::Coef(int exp, double coef)
{
	if (exp > this->red)
	{
		double* temp = new double[exp + 1];
		for (int i = 0; i <= this->red; i++)
			temp[i] = this->polinom[i];
		for (int i = this->red + 1; i < exp; i++)
			temp[i] = 0;
		temp[exp] = coef;
		this->red = exp;
		delete[] this->polinom;
		polinom = temp;
		delete[] temp;
	}
	else if (exp >= 0)
		polinom[exp] = coef;
	else
		throw exception("Nevazeci exp");
}

void CPolynom::Add(CPolynom* poly1, CPolynom* poly2)
{
	delete[] this->polinom; //novo polje bice duze
	if (poly1->red < poly2->red)
	{
		this->red = poly2->red;
		this->polinom = new double[poly2->red + 1];
		for (int i = 0; i <= poly2->red; i++)
			this->polinom[i] = 0;
		for (int i = 0; i <= poly1->red; i++)
			this->polinom[i] = poly1->polinom[i] + poly2->polinom[i];
		for (int i = poly1->red + 1; i <= poly2->red; i++)
			this->polinom[i] = poly2->polinom[i];
	}
	else if (poly1->red > poly2->red)
	{
		
		this->red = poly1->red;
		this->polinom = new double[poly2->red + 1];
		for (int i = 0; i <= poly1->red; i++)
			this->polinom[i] = 0;
		for (int i = 0; i <= poly2->red; i++)
			this->polinom[i] = poly1->polinom[i] + poly2->polinom[i];
		for (int i = poly2->red + 1; i <= poly1->red; i++)
			this->polinom[i] = poly1->polinom[i];
	}
	else
	{
		this->red = poly2->red;
		this->polinom = new double[poly2->red + 1];
		for (int i = 0; i <= poly2->red; i++)
			this->polinom[i] = 0;
		for (int i = 0; i <= poly1->red; i++)
			this->polinom[i] = poly1->polinom[i] + poly2->polinom[i];
	}
}

CPolynom* CPolynom::Mul(CPolynom* poly1, CPolynom* poly2) //moze isto preko void i this
{
	CPolynom* temp = new CPolynom(poly1->red + poly2->red);
	for (int i = 0; i <= poly1->red; i++)
		for (int j = 0; j <= poly2->red; j++)
		{	
			if (poly1->polinom[i] == 0)
				temp->polinom[i + j] = poly2->polinom[j];
			else if (poly2->polinom[j] == 0)
				temp->polinom[i + j] = poly1->polinom[i];
			else
				temp->polinom[i + j] += poly1->polinom[i] * poly2->polinom[j]; //mnozenje svaki sa svaki i sabiranje istih stepena
		}
	return temp;
}

void CPolynom::print()
{
	for (int i = 0; i < this->red; i++)
		cout << polinom[i] << "*x^" << i << " + ";
	cout << polinom[this->red] << "*x^" << this->red << endl;
}
