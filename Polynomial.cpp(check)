#include <iostream>
#include "Header.h"
#include <algorithm>
using namespace std;

Polynomial::Polynomial()
{
	this->power = 0;
	this->coefs = new double[1];
	coefs[0] = 0;
}
Polynomial::Polynomial(const Polynomial& poly)
{
	makeCopy(poly);
}
int Polynomial::getPower() const
{
	return this->power;
}
Polynomial & Polynomial::operator=(const Polynomial& poly)
{
	if (this == &poly)
	{
		return *this;
	}
	delete[] coefs;
	makeCopy(poly);
}
Polynomial Polynomial::operator+(const Polynomial& poly)
{
	Polynomial result;
	result.setPower(max(this->getPower, poly.getPower));
	for (int i = 0; i <= min(this->getPower, poly.getPower); i++)
	{
		result.setCoef(i, this->getCoef(i) + poly.getCoef(i));
	}
	for (int i = min(this->getPower, poly.getPower)+1; i <= result.getPower; i++)
	{
		if (this->getPower >= poly.getPower)
		{
			result.setCoef(i, this->getCoef(i));
		}
		else result.setCoef(i, poly.getCoef(i));
	}
}
Polynomial Polynomial::operator*(const Polynomial& poly)
{
	Polynomial result;
	double maxPower=this->getPower*poly.getPower;
	double minPower = min(this->getPower, poly.getPower);
	result.setPower(maxPower);
	for (int i = 0; i <= maxPower; i++)
	{
		for (int j = 0; j <= minPower; j++)
		{
			if (poly.getPower <= this->getPower)
			{
				result.setCoef(i*j, poly.getCoef(j)*this->getCoef(i));
			}
			else
			{
				result.setCoef(i*j, poly.getCoef(i)*this->getCoef(j));
			}
		}
	}
}
Polynomial Polynomial::derivative()
{
	Polynomial result;
	result.setPower(this->getPower - 1);
	for (int i = 0; i <= this->getPower; i++)
	{
		result.setCoef(i, this->getCoef(i + 1)*(i + 1));
	}
}

double Polynomial::getCoef(int index) const
{
	if (index > this->power)
	{
		return 0;
	}
	return this->coefs[index];
}
void Polynomial::setPower(int power)
{
	this->power = power;
}
void Polynomial::setCoef(int power, double coef)
{
	int minPower, maxPower;
	minPower = min(this->power, power);
	maxPower = max(this->power, power);
	if (this->power < power)
	{
		double * tempCoefs = new double[maxPower + 1];
		for (int i = 0; i <= minPower; i++)
		{
			tempCoefs[i] = coefs[i];
		}
		for (int i = minPower+1; i <= maxPower; i++)
		{
			tempCoefs[i] = 0;
		}
		this->power = power;
		delete[] coefs;
		coefs = tempCoefs;
	}
	coefs[power] = coef;
}
void Polynomial::makeCopy(const Polynomial& poly)
{
	this->power = poly.getPower;
	this->coefs = new double[this->power];
	for (int i = 0; i <= this->power; i++)
	{
		this->coefs[i] = poly.coefs[i];
	}
}
Polynomial::~Polynomial()
{
	delete[] coefs;
}
