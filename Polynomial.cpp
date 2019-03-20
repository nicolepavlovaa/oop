#include "Header.h"
#include <iostream>
using namespace std;

Polynomial::Polynomial()
{
	this->power = 0;
	this->coefs = new double[1];
}
Polynomial::Polynomial(const Polynomial& poly) 
{
	this->power = poly.power;
	for (int i = 0; i <= power; i++)
	{
		this->coefs[i] = poly.coefs[i];
	}
}
Polynomial & Polynomial::operator=(const Polynomial & poly)
{
	if (this==&poly)
	{
		return *this;
	}
	else
	{
		delete[] coefs;
		this->power = poly.power;
		for (int i = 0; i <= power; i++)
		{
			this->coefs[i] = poly.coefs[i];
		}
	}
}
Polynomial Polynomial::operator+(const Polynomial & poly)
{
	int maxPower, minPower;
	Polynomial result;
	if (this->power <= poly.power)
	{
		maxPower = poly.power;
		minPower = this->power;
	}
	else
	{
		minPower = poly.power;
		maxPower = this->power;
	}
	//result.power = maxPower;
	for (int i = 0; i <= minPower; i++)
	{
		result.setCoef(this->coefs[i]+poly.coefs[i], i);
	}
	for (int i = minPower+1; i <= maxPower; i++)
	{
		if (poly.power == maxPower) {
			result.setCoef(poly.coefs[i], i);
		}
		else result.setCoef(this->coefs[i], i);
	}
}

void Polynomial::setCoef(double coef, int power)
{
	if (power > this->power)
	{
		double * newArr = new double[power+1];
		for (int i = 0; i <= this->power; i++)
		{
			newArr[i] = coefs[i];
		}
		for (int i = this->power+1; i <= power; i++)
		{
			newArr[i] = 0;
		}
		this->power = power;
		delete[] coefs;
		coefs = newArr;
	}
	coefs[power] = coef;
}

Polynomial::~Polynomial()
{
	delete[] this->coefs;
}
