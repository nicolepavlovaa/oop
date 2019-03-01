#include <iostream>
#include <cstring>
#include <Untitled3.h>

using namespace std;

Square::Square(int a)
{
    this->a=a;
};

int Square::getA()
{
    return this->a;
}
int Square::setA(int a)
{
    this->a=a;
}
int Square::getParameter()
{
    return 4*a;
}
