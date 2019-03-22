#pragma once
#include <iostream>
class Student
{
	char * name;
	int fn;
	int course; 

public:
	Student();
	Student(char * name, int fn, int course);
	Student(Student& other);
	Student& operator=(Student& other);
	bool operator!=(Student & other);
	bool operator==(Student & other);
	~Student();

	void setName(char * n);
	void setFn(int fn);
	void setCourse(int course);
	char * getName();
	int getFn();
	int getCourse();

	void print();
};
