#pragma once

class CPolynom {
private:
	double* polinom;
	int red;
public:
	CPolynom(int order);
	void Coef(int exp, double coef);
	void Add(CPolynom* poly1, CPolynom* poly2);
	CPolynom* Mul(CPolynom* poly1, CPolynom* poly2);
	void print();
};

