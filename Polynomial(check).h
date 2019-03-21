#pragma once

class Polynomial
{
public:
	Polynomial(); //Constructor
	Polynomial(const Polynomial& poly); //Copy-constructor
	~Polynomial(); //Destructor

	Polynomial& operator=(const Polynomial& poly); //operator=
	Polynomial operator+(const Polynomial& poly);  //operator+
	Polynomial operator*(const Polynomial& poly); //operator*
	Polynomial derivative(); //derivative

private:
	void setPower(int power);
	void setCoef(int power, double coef);
	int getPower() const;
	double getCoef(int index) const;
	void makeCopy(const Polynomial& poly);

	int power;
	double * coefs;
};
