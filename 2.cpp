#include <iostream>
#include <cstring>
#include <Untitled3.h>

using namespace std;

ImaginaryNumber::(int a, int b)
{
    this->a=a;
    this->b=b;
};

int ImaginaryNumber::getA()
{
    return this->a;

}
int ImaginaryNumber::getB()
{
    return this->b;

}
int ImaginaryNumber::setA(int a)
{
    this->a=a;
}
int ImaginaryNumber::setB(int b)
{
    this->b=b;
}
void ImaginaryNumber::print()
{
    cout<<a<<"+i*"<<b<<endl;
}

void ImaginaryNumber::add(ImaginaryNumber number2)
{
    this->setA(this->a + number2.getA);
    this->setB(this->b + number2.getB);
}
void ImaginaryNumber::multiply(ImaginaryNumber number2)
{
    //ac-bd ad+bc
    this->setA(this->a*number2.getA- this->b*number2.getB);
    this->setB(this->a*number2.getB- this->a*number2.getA);
}
//(a,b)*(c,-d)/(c,d)*(c,-d)
void ImaginaryNumber::divide(ImaginaryNumber number2)
{
    ImaginaryNumber copyNumber2=number2;
    number2.setB= -1*number2.getB;
    ImaginaryNumber nominator= this->multiply(number2); 
    ImaginaryNumber denominator= copyNumber2.multiply(number2); //real
    this->setA(nominator.getA/ denominator);
    this->setB(nominator.getB);
}
