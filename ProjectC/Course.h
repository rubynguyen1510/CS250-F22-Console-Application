/*
	JMJN

	Ho, Jerry
	Nguyen, Minh
	Pham, Jordan
	Nguyen, Ngoc

	Fall 2022
	CS A250 - C++ 2
	Project: CS Courses  
*/
#ifndef COURSE_H
#define COURSE_H
#include <string>
#include <set>

class Course
{
public:
	// Constructors
	Course() : courseNumber(0), courseName("N/A"), courseUnits(0) {};
	Course(int inputCourseNumber, const std::string& inputCourseName, int inputCourseUnits, const std::set<int>& inputPrereqs);

	// Accessor functions
	const std::string& getCourseName() const;
	int getCourseNumber() const;
	int getCourseUnits() const;
	const std::set<int>& getCoursePrereqs() const;
	const Course& getCourse() const;
	static std::string getPrefix();

	// Mutator functions
	void setCourseName(const std::string& newName);
	void setCourseNumber(int newNumber);
	void setCourseUnits(int newUnits);
	void setPrereqs(const int newPrereqsArray[], int length);

	// Destructor
	~Course() {};

private:
	int courseNumber;
	std::string courseName;
	int courseUnits;
	std::set<int> prereqs;
	static const std::string PREFIX;
};
#endif