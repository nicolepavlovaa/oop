#ifndef __FACULTY_H
#define __FACULTY_H
#include <iostream>
#include "Student.h"

class Faculty
{
	Student * students;

public:
	Faculty();
	Faculty(Faculty& other);
	Faculty& operator=(Faculty& other);
	Faculty& operator+=(Student& other);
	Faculty& operator-=(Student& other);
	Student& operator[](int index);
	~Faculty();

	Student getStudent(int index);
};

#endif 
