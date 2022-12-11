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

// Definition function insertInOrder
// Assume there are no duplicates.
void CourseList::insertInOrder(Node* courseNode)
{
	if (count == 0)
	{
		first = last = courseNode;
	}
	else if (count == 1)
	{	
		if (first->getCourse().getCourseNumber() >= courseNode->getCourse().getCourseNumber())
		{
			courseNode->setNext(first);
			last = first;
			first = courseNode;
		}
		else 
		{
			first->setNext(courseNode);
			last = courseNode;
		}
	}
	else if (first->getCourse().getCourseNumber() >= courseNode->getCourse().getCourseNumber()) 
	{
		courseNode->setNext(first);
		last = first;
		first = courseNode;
	}
	else 
	{
		Node* current = first->getNext();
		Node* trail = first; 
		bool isFound = false;
		while(current != nullptr && !isFound)
		{
			if (current->getCourse().getCourseNumber() >= courseNode->getCourse().getCourseNumber())
			{
				trail->setNext(courseNode);
				trail->getNext()->setNext(current);
				isFound = true;
			}
			else
			{
				trail = current; 
				current = current->getNext();
			}
		}
		if (!isFound)
		{
			trail->setNext(courseNode);
			last = courseNode;
		}
	}
	++count;
}