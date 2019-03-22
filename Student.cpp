#include <iostream>
#include "Header.h"
using namespace std;
#include <cstring>

char * Student::getName()
{
	return name;
}
int Student::getFn()
{
	return fn;
}
int Student::getCourse()
{
	return course;
}

void Student::setName(char * n) 
{
	delete[] name;
	int nameLength = strlen(n);
	name = new char[nameLength + 1];
	strcpy_s(name,strlen(n)+1, n);
}
void Student::setFn(int facNum)
{
	fn = facNum;
}
void Student::setCourse(int c)
{
	course = c;
}
Student::Student()
{
	name = nullptr;
	fn = 0;
	course = 0;
}
Student::Student(char * n, int facNum, int c) : name(nullptr), fn(facNum), course(c)
{
	setName(n);
}
Student::~Student()
{
	delete[] name;
}
Student::Student(Student& other) : name(nullptr), fn(other.fn), course(other.course)
{
	setName(other.getName());
}

Student & Student::operator=(Student & other)
{
	if (this == &other)
	{
		return *this;
	}
	delete[] name;
	this->fn = other.getFn();
	this->course = other.getCourse();
	this->name = new char[strlen(other.getName())+1];
	strcpy_s(this->name,strlen(other.getName()) + 1,other.getName());
	return *this;
}

bool Student::operator==(Student & other)
{
	if (fn==other.getFn()&& course==other.getCourse() && strcmp(name, other.getName())==0)
	{
		return true;
	}
	return false;
}

bool Student::operator!=(Student & other)
{
	if (fn == other.getFn() || course == other.getCourse() || strcmp(name, other.getName()) == 0)
	{
		return false;
	}
	return true;

}

void Student::print()
{
	cout << "Student: " << name << " fn: " << fn << " course " << course << endl;
}
int main()
{
	system("pause");
	return 0;
}
