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

// Copy constructor
CourseList::CourseList(const CourseList& otherCourseList)
{
	first = last = nullptr;
	count = 0;

	if (otherCourseList.count == 1)
	{
		first = last = new Node(otherCourseList.first->getCourse(), nullptr);
	}
	else if (otherCourseList.count > 1)
	{
		first = new Node(otherCourseList.first->getCourse(), nullptr);
		Node* current = first;
		Node* otherCurrent = otherCourseList.first->getNext();
		
		while (otherCurrent != nullptr)
		{
			current->setNext(new Node(otherCurrent->getCourse(), nullptr));
			if (otherCurrent == otherCourseList.last)
			{
				last = current->getNext(); 
			}
			otherCurrent = otherCurrent->getNext();
			current = current->getNext();
		} 
	}
	count = otherCourseList.count;
}

// Definition overloaded assignment operator
CourseList& CourseList::operator=(const CourseList& otherCourseList)
{
	if (this == &otherCourseList)
	{
		cerr << "Attempted assignment to itself." << endl;
	}
	else
	{
		if (otherCourseList.count == 0)
		{
			clearList();
		}
		else if(count == 0)
		{
			copyCallingObjIsEmpty(otherCourseList);
		}
		else if(count == otherCourseList.count)
		{
			copyObjectsSameLength(otherCourseList);
		}
		else if(count > otherCourseList.count)
		{
			copyCallingObjLonger(otherCourseList);
		}
		else
		{
			copyCallingObjShorter(otherCourseList);
		}
	}
	return *this;
}

// Definition function copyCallingObjIsEmpty
void CourseList::copyCallingObjIsEmpty(const CourseList& otherCourseList)
{
	if (otherCourseList.count == 1)
	{
		first = last = new Node(otherCourseList.first->getCourse(), nullptr);
	}
	else if (otherCourseList.count > 1)
	{
		first = new Node(otherCourseList.first->getCourse(), nullptr);
		Node* current = first;
		Node* otherCurrent = otherCourseList.first->getNext();
		
		while (otherCurrent != nullptr)
		{
			current->setNext(new Node(otherCurrent->getCourse(), nullptr));
			if (otherCurrent == otherCourseList.last)
			{
				last = current->getNext(); 
			}
			otherCurrent = otherCurrent->getNext();
			current = current->getNext();
		} 
	}
	count = otherCourseList.count;
}

// Definition function copyObjectsSameLength
void CourseList::copyObjectsSameLength(const CourseList& otherCourseList)
{
	Node* current = first;
	Node* otherCurrent = otherCourseList.first;
	while (otherCurrent != nullptr)
	{
		current->setCourse(otherCurrent->getCourse());
		current = current->getNext();
		otherCurrent = otherCurrent->getNext();
	}
}

// Definition function copyCallingObjLonger
void CourseList::copyCallingObjLonger(const CourseList& otherCourseList)
{

	Node* current = first;
	Node* otherCurrent = otherCourseList.first;
	Node* trailCurrent = current;
	while (otherCurrent != nullptr)
	{
		current->setCourse(otherCurrent->getCourse());
		trailCurrent = current;
		current = current->getNext();
		otherCurrent = otherCurrent->getNext();
	}
	last = trailCurrent;
	last->setNext(nullptr);

	Node* temp = current;

	if (temp != nullptr)
	{
		while (current != nullptr)
		{
			temp = current;
			current = current->getNext();
			delete temp;
			temp = nullptr;
		}
	}
	count = otherCourseList.count;
}

// Definition function copyCallingObjShorter
void CourseList::copyCallingObjShorter(const CourseList& otherCourseList)
{
	Node* current = first;
	Node* otherCurrent = otherCourseList.first;

	while (current != nullptr)
	{
		current->setCourse(otherCurrent->getCourse());
		current = current->getNext();
		otherCurrent = otherCurrent->getNext();
	}
	current = last;
	while (otherCurrent != nullptr)
	{
		current->setNext(new Node(otherCurrent->getCourse(), nullptr));
		current = current->getNext();
		otherCurrent = otherCurrent->getNext();
	}
	last = current;
	count = otherCourseList.count;
}

// Destructor
CourseList::~CourseList()
{
	if (count != 0) 
	{
		clearList();
	}
}