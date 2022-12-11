/*
	Team name: JMJN

	Ho, Jerry
	Nguyen, Minh
	Pham, Jordan
	Nguyen, Ngoc

	Fall 2022
	CS A250 - C++ 2
	Project: CS Courses
*/

#include "Course.h"

#include <iostream>
#include <iomanip>
using namespace std;

const string Course::PREFIX = "CS A";

// Definition overloaded constructor
Course::Course(int inputCourseNumber, const string& inputCourseName,
	int inputCourseUnits, const set<int>& inputPrereqs)
{
	courseNumber = inputCourseNumber;
	courseName = inputCourseName;
	courseUnits = inputCourseUnits;
	prereqs = inputPrereqs;
}

// Definition function getCourseName
const string& Course::getCourseName() const
{
	return courseName;
}

// Definition function getCourseNumber
int Course::getCourseNumber() const
{
	return courseNumber;
}

// Definition function getCourseUnits
int Course::getCourseUnits() const
{
	return courseUnits;
}

// Definition function getPrereqs
const set<int>& Course::getCoursePrereqs() const
{
	return prereqs;
}

// Definition function getCourse
const Course& Course::getCourse() const
{
	return *this;
}

// Definition function getPrefix
string Course::getPrefix()
{
	return PREFIX;
}

// Definition function setCourseName
void Course::setCourseName(const string& newName)
{
	courseName = newName;
}

// Definition function setCourseNumber
void Course::setCourseNumber(int newCourseNumber)
{
	courseNumber = newCourseNumber;
}

// Definition function setCourseUnits
void Course::setCourseUnits(int newUnits)
{
	courseUnits = newUnits;
}

// Definition function setPrereqs
void Course::setPrereqs(const int newPrereqsArray[], int length)
{
	prereqs.clear();
	for (int i = 0; i < length; ++i)
	{
		prereqs.insert(newPrereqsArray[i]);
	}
}