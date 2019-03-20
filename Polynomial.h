#pragma once
class Polynomial {
	double * coefs;
	int power;

public:
	void setCoef(double coef, int power);
	
	Polynomial();
	Polynomial(const Polynomial& poly);
	Polynomial& operator=(const Polynomial& poly);
	Polynomial operator+(const Polynomial& poly);
	Polynomial operator*(const Polynomial& poly);
	~Polynomial();
};
