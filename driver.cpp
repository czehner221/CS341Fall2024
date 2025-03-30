// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// czehner

#include "Student.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

// Function declarations.
double calculateGPA(int gradePts, int creditHrs);
char calculateLetterGrade(double gpa);
void sortStudents(Student students[]);

int main()
{
	// Variables
	std::string id;
	int gradePoints = 0;
	int creditHours = 0;
	double gpa = 0;
	char letterGrade;
	
	// Index for while loop
	int studentNumber = 0;
	
	// Array of students. Size of 30
	Student students[30];

	// Input Stream
	std::ifstream inputFile;
	inputFile.open("students.txt");
	
	// Format the decimal of the GPA
	std::cout << std::setprecision(2) << std::fixed;
	
	// Greeting message
	std::cout << "\n****\tWelcome to Charlie's GPA Calculator Program!\t****\n" << std::endl;
	
	// If the file is open, a loop will fill in information for the student.
	if(inputFile.is_open())
	{
		// Loops for the length of the file.
		while(!inputFile.eof())
		{
			
			// Read values from file and stores into variables.
			inputFile >> id >> gradePoints >> creditHours;
			
			// Calculates GPA with calculateGPA function
			gpa = calculateGPA(gradePoints, creditHours);
			
			// Determines letter grade with function
			letterGrade = calculateLetterGrade(gpa);
			
			// New student is created for each iteration of loop until it reaches the end of the file.
			Student student(id, gradePoints, creditHours, gpa, letterGrade);
			students[studentNumber] = student;
			
			// Increment to get the next student info
			studentNumber++;
		}
		// Close file.
		inputFile.close();
	}
	else
	{
		// File is unable to open.
		std::cout << "Cannot open file." << std::endl;
	}
	
	// Call function to sort students.
	sortStudents(students);
	
	// Display each student once sorted.
	for(int j = 0; j < 30; j++)
	{
		std::cout << students[j].getID() << ": " << students[j].getGPA() << "\t " << students[j].getLetterGrade() << std::endl;
	}
	
	// Farewell message
	std::cout << "\nThank you for using my GPA calculator program - goodbye!\n" << std::endl;

	return 0;
}

// Calculates the GPA
double calculateGPA(int gradePts, int creditHrs)
{
	return (double)gradePts / creditHrs;
}

// Calculates the Letter Grade
char calculateLetterGrade(double gpa)
{
	// Determines letter grade based on GPA.
	if(gpa >= 3.7)
	{
		return 'A';
	}
	else if(gpa >= 2.7)
	{
		return 'B';
	}
	else if(gpa >= 1.7)
	{
		return 'C';
	}
	else if(gpa >= 0.7)
	{
		return 'D';
	}
	else
	{
		return 'F';
	}	
}

// Sorts the students by GPA from highest to lowest.
void sortStudents(Student students[])
{
	// Outer loops through entire array of students
	for(int i = 0; i < 30 - 1; i++)
	{
		// Inner loops through array contents that have not been compared yet
		for(int j = 0; j < 30 - i - 1; j++)
		{
			// Swap student position in array based on GPA
			if(students[j].getGPA() < students[j+1].getGPA())
			{
				Student temp = students[j];
				students[j] = students[j+1];
				students[j+1] = temp;
			}
		}
	}
}

