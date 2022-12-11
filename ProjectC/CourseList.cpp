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

#include "CourseList.h"

#include <iostream>
using namespace std;

// Definition function addCourse
void CourseList::addCourse(const Course& paramCourse)
{
	insertInOrder(new Node(paramCourse, nullptr));
}

// Definition function addCourse
void CourseList::addCourse(int courseNumber, const string& courseName,
	int courseUnits, const set<int>& prereqs)
{
	insertInOrder(new Node(
		Course(courseNumber, courseName, courseUnits, prereqs), nullptr));
}

// Definition function getPrefix
string CourseList::getPrefix()
{
	return Course::getPrefix();
}

// Definition function getNumberOfCourses
int CourseList::getNumberOfCourses() const
{
	return count;
}

// Definition function isEmpty
bool CourseList::isEmpty() const
{
	return count == 0;
}

// Definition function searchCourse (courseNumber)
// Assume list is non-empty.
bool CourseList::searchCourse(int courseNumber) const
{
	return (getCourseLocation(courseNumber) != nullptr);
}

// Definition function searchCourse (courseNumber, courseName)
// Assume list is non-empty.
bool CourseList::searchCourse(int courseNumber, string& courseName) const
{
	if (getCourseLocation(courseNumber) == nullptr) return false;
	courseName = getCourseLocation(courseNumber)->getCourse().getCourseName();
	return (getCourseLocation(courseNumber) != nullptr);
}

// Definition function searchCourse(courseNumber, course) 
// Assume list is non-empty.
bool CourseList::searchCourse(int courseNumber, Course& otherCourse) const
{
	if (getCourseLocation(courseNumber) == nullptr) return false;
	otherCourse = getCourseLocation(courseNumber)->getCourse();
	return (getCourseLocation(courseNumber) != nullptr);
}

int CourseList::getTotalUnits() const
{
	int totalUnits = 0;
	Node* current = first;
	while (current != nullptr)
	{
		Course temp = current->getCourse();
		totalUnits += temp.getCourseUnits();
		current = current->getNext();
	}
	return totalUnits;
}
// Definitiion deleteCourse
// Assume list is non-empty.
// Assume course is in the list.
void CourseList::deleteCourse(int courseNumber)
{
	Node* current = first;
	if (current->getCourse().getCourseNumber() == courseNumber)
	{
		first = first->getNext();
		delete current;
		current = nullptr;
	}
	else 
	{
		Node* trail = nullptr;
		bool isFound = false;
		while (!isFound)
		{
			if (current->getCourse().getCourseNumber() == courseNumber)
			{
				isFound = true;
				trail->setNext(current->getNext());
				delete current;
				current = nullptr;
			}
			else
			{
				trail = current;
				current = current->getNext();
			}
		}
	}
	--count;
}

// Definition retrieveAllCourses
// Assume list is non-empty.
void CourseList::retrieveAllCourses(string& retrievedCourses) const
{
	// CS A150 - C++ 1
	retrievedCourses = "";
	Node* current = first;
	while (current != nullptr)
	{
		Course temp = current->getCourse();
		string courseFormat = getPrefix() 
			+ to_string(temp.getCourseNumber())
			+ " - " + temp.getCourseName()
			+ " " + to_string(temp.getCourseUnits()) + '\n';
		retrievedCourses += courseFormat;
		current = current->getNext();
	}
}

// Definition clearList
void CourseList::clearList()
{
	Node* current = first;
	while (count > 0)
	{
		first = first->getNext();
		delete current;
		current = nullptr;
		current = first;
		--count;
	}
}

// Definition function getCourseLocation
Node* CourseList::getCourseLocation(int courseNumber) const
{
	Node* current = first;
	while (current != nullptr)
	{
		if (current->getCourse().getCourseNumber() == courseNumber)
			return current;
		else
			current = current->getNext();
	}
	return nullptr;
}
