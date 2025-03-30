// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// czehner

#include <string>

class Student
{
	public:
		// Constructors and Destructor
		Student();
		Student(std::string i, int g, int h, double gpa, char lg);
		~Student();
		
		// Getters
		std::string getID();
		int getGradePoints();
		int getCreditHours();
		double getGPA();
		char getLetterGrade();
		
	private:
		// Private Variables
		std::string id_;
		int gradePoints_, creditHours_;
		double gpa_;
		char letterGrade_;
		
};