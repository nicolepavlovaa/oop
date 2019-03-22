
#ifndef __PLAYER_H
#define __PLAYER_H
class Student
{
	char * name;
	int fn;
	int course;

public:
	Student(const char * name = "Anonymous", int fn = 0, int course = 0);
	Student(Student& other);
	Student& operator=(Student& other);
	bool operator!=(Student & other);
	bool operator==(Student & other);
	friend std::istream& operator>>(std::istream &is, Student &other);
	friend std::ostream& operator<<(std::ostream &os, const Student &other);
	~Student();

	void setName(const char * n);
	void setFn(int fn);
	void setCourse(int course);

	char * getName() const;
	int getFn() const;
	int getCourse() const;

	void print();
};
#endif
