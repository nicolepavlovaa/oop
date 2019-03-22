#include <iostream>
#include "Student.h"
using namespace std;
#include <cstring>

void Student::setName(const char * n)
{
	delete[] name;
	const int length = strlen(n);
	name = new char[length + 1];
	strcpy_s(name, strlen(n) + 1, n);
}
void Student::setFn(int facNum)
{
	this->fn = facNum;
}
void Student::setCourse(int c)
{
	this->course = c;
}
char * Student::getName() const
{
	return name;
}
int Student::getFn() const
{
	return fn;
}
int Student::getCourse() const
{
	return course;
}
void Student::print()
{
	cout << "name: " << name << " fn: " << fn << " course: " << course << endl;
}
Student::Student(const char * n, int facNum, int c)
{
	fn = facNum;
	course = c;
	setName(n);
}
Student::Student(Student& other) :name(nullptr), fn(other.fn), course(other.course)
{
	setName(other.name);
}
Student& Student::operator=(Student& other) 
{
	if (this != &other)
	{
		fn = other.fn;
		course = other.course;
		delete[] name;
		name = new char[strlen(other.name) + 1];
		strcpy_s(name, strlen(other.name) + 1, other.name);
	}
	return *this;
}
bool Student::operator==(Student& other)
{
	if (fn == other.fn && course == other.course && strcmp(this->name, other.name) == 0)
	{
		return true;
	}
	return false;
}
istream & operator>>(std::istream & is, Student & other)
{
	is.getline(other.name, 200);
	is >> other.fn >> other.course;
	return is;
}
ostream & operator<<(std::ostream & os, const Student & other)
{
	os << "name: " << other.name << endl << "fn: " << other.fn << endl << "course: " << other.course;
	return os;
}

bool Student::operator!=(Student& other)
{
	if (fn != other.fn || course != other.course || strcmp(this->name, other.name) != 0)
	{
		return true;
	}
	return false;
}
Student::~Student()
{
	delete[] name;
}
