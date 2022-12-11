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

#include "CourseList.h";

#include <iostream>
using namespace std; 

void testCopyConstructor()
{	
	/***************************************************
	* TEST COPY CONSTRUCTOR: PARAMETER OBJECT IS EMPTY
	****************************************************/

	// To print, create a variable of type string and use it
	// as an argument to call the function retrieveAllCourses().
	string myString1, myString2;

	// Create an object of the class CourseList named 
	// courseList1 using the default constructor.
	CourseList courseList1;

	// Create an object of the class CourseList named 
	// courseList2 using the copy constructor with 
	// parameter courseList1.
	// CALL: CourseList courseList1(courseList2)
	CourseList courseList2(courseList1);

	// Print courseList1 (should be empty)
	courseList1.retrieveAllCourse(myString1);
	cout << myString1 << "\n";
	//cout << "Should be empty" << endl;
	
	// Print courseList2 (should be empty)
	courseList2.retrieveAllCourse(myString2);
	cout << myString2 << "\n";
	//
	/*****************************************************
	* TEST COPY CONSTRUCTOR: PARAMETER OBJECT HAS COURSES
	******************************************************/	

	// Add 131 and 272 to courseList1
	set<int> a;
	Course cs131(131, "cs131", 4, a);
	Course cs272(272, "cs272", 4, a);
	courseList1.addCourse(cs131);
	courseList1.addCourse(cs272);

	// Create an object of the class CourseList named 
	// courseList3 using the copy constructor with 
	// parameter courseList1.
	// CALL: CourseList courseList3(courseList1)
	CourseList courseList3(courseList1);

	// Print courseList1 (should show 131 and 272)
	courseList1.retrieveAllCourse(myString1);
	cout << myString1 << endl;

	// Print courseList3 (should show 131 and 272)
	string myString3;
	courseList3.retrieveAllCourse(myString3);
	cout << myString3 << endl;

	// CLEAR courseList1
	courseList1.clearList();

	// Print courseList1 (should be empty)
	courseList1.retrieveAllCourse(myString1);
	cout << myString1 << endl;

	// Print courseList3 (should show 131 and 272)
	courseList3.retrieveAllCourse(myString3);
	cout << myString3 << endl;
}
