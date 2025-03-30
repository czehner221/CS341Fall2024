// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// czehner

#include "Student.h"
#include <string>

// Default Constructor
Student::Student()
{
	
}

// Parameterized Constructor
Student::Student(std::string i, int g, int h, double gpa, char lg)
{
	id_ = i;
	gradePoints_ = g;
	creditHours_ = h;
	gpa_ = gpa;
	letterGrade_ = lg;
}

// Destructor
Student::~Student()
{
	
}

// Accessor Methods
std::string Student::getID()
{
	return id_;
}

int Student::getGradePoints()
{
	return gradePoints_;
}

int Student::getCreditHours()
{
	return creditHours_;
}

double Student::getGPA()
{
	return gpa_;
}

char Student::getLetterGrade()
{
	return letterGrade_;
}
