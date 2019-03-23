#include <iostream>
#include "Student.h"
#include "Faculty.h"
using namespace std;

Student Faculty::getStudent(int index)
{
	return students[index];
}
Faculty::Faculty()
{
	Student * students = new Student[1];
}
Faculty::Faculty(Faculty& other)
{
	int size = sizeof(other);
	for (int i = 0; i < size; i++)
	{
		this->students[i] = other.students[i];
	}
}
Faculty& Faculty::operator=(Faculty& other)
{
	if (this != &other)
	{
		int size = sizeof(other);
		delete[] students;
		Student * students = new Student[size];
		for (int i = 0; i < size; i++)
		{
			this->students[i] = other.students[i];
		}
	}
	return *this;
}
Faculty& Faculty::operator+=(Student& other)
{
	int size=sizeof(this->students);
	if (students[0].getName() != "Anonymous") 
	{
		size = sizeof(this->students) + 1;
	}
	Student * temp = new Student[size];
	for (int i = 0; i < size-1; i++)
	{
		temp[i] = students[i];
	}
	temp[size - 1] = other;
	delete[] students;
	students = temp;
	return *this;
}
Faculty& Faculty::operator-=(Student& other)
{
	bool found = false;
	int removedIndex;
	for (int i = 0; i < sizeof(this->students); i++)
	{
		if (students[i] == other)
		{
			found = true;
			removedIndex = i;
		}
	}
	if (found == true)
	{
		int size = sizeof(students) - 1;
		Student * temp = new Student[size];
		for (int i = 0; i < removedIndex; i++)
		{
			temp[i] = students[i];
		}
		for (int i = removedIndex+1; i < size; i++)
		{
			temp[i-1] = students[i];
		}
		delete[] students;
		students = temp;
	}
	return *this;
}

Student & Faculty::operator[](int index)
{
	return this->students[index];
}

Faculty::~Faculty()
{
	delete[] students;
}
