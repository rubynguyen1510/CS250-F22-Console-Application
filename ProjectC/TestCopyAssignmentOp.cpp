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

void testOpEqualEmptyObjs()
{
	// TEST ASSIGNMENT OPERATOR: PARAMETER OBJECT IS EMPTY
	
	// To print, create a variable of type string and use it
	// as an argument to call the function retrieveAllCourses().
	//string myString;
	string myString;

	// Create two objects of the class CourseList:
	// courseList1 and courseList2
	CourseList courseList1;
	CourseList courseList2;

	// Print courseList1 (should be empty)
	courseList1.retrieveAllCourse(myString);
	cout << myString << endl;

	// Print courseList2 (should be empty)
	courseList2.retrieveAllCourse(myString);
	cout << myString << endl;

	// CALL: courseList1 = courseList2;
	courseList1 = courseList2;

	// Print courseList1 (should be empty)
	courseList1.retrieveAllCourse(myString);
	cout << myString << endl;

	// Print courseList2 (should be empty)
	courseList2.retrieveAllCourse(myString);
	cout << myString << endl;
}

void testOpEqSameLengthObjs()
{
	//TEST ASSIGNMENT OPERATOR: OBJECTS HAVE SAME LENGTH

	// To print, create a variable of type string and use it
	// as an argument to call the function retrieveAllCourses().
	//string myString;
	string myString;

	// Create courseList1 with two courses: 131 and 272
	set<int> a;
	Course cs131(131, "cs131", 4, a);
	Course cs272(272, "cs272", 4, a);
	CourseList courseList1;
	courseList1.addCourse(cs131);
	courseList1.addCourse(cs272);
	// Create courseList2 with two courses: 150 and 250
	Course cs150(150, "cs150", 4, a);
	Course cs250(250, "cs250", 4, a);
	CourseList courseList2;
	courseList2.addCourse(cs150);
	courseList2.addCourse(cs250);

	// Print courseList1 (should show 131 and 272)
	courseList1.retrieveAllCourse(myString);
	cout << "1\n" << myString << endl;

	// Print courseList2 (should show 150 and 170)
	courseList2.retrieveAllCourse(myString);
	cout << "2\n" << myString << endl;

	// CALL: courseList1 = courseList2
	courseList1 = courseList2;

	// Print courseList1 (should show 150 and 170)
	courseList1.retrieveAllCourse(myString);
	cout << "3\n" << myString << endl;

	// Print courseList2 (should show 150 and 170)
	courseList2.retrieveAllCourse(myString);
	cout << "4\n" << myString << endl;

	// CLEAR courseList2
	courseList2.clearList();

	// Print courseList1 (should show 150 and 170)
	courseList1.retrieveAllCourse(myString);
	cout << "5\n" << myString << endl;

	// Print courseList2 (should be empty)
	courseList2.retrieveAllCourse(myString);
	cout << "6\n" << myString << endl;
}

void testOpEqCallingLonger()
{
	//TEST ASSIGNMENT OPERATOR : CALLING OBJ IS LONGER

	// To print, create a variable of type string and use it
	// as an argument to call the function retrieveAllCourses().
	string myString;

	// Create courseList1 with four courses: 131, 170, 257, and 272
	set<int> a;
	CourseList courseList1;
	courseList1.addCourse(131, "CS131", 4, a);
	courseList1.addCourse(170, "CS170", 4, a);
	courseList1.addCourse(257, "CS257", 4, a);
	courseList1.addCourse(272, "CS272", 4, a);

	// Create courseList2 with two courses: 150, and 250
	CourseList courseList2;
	courseList2.addCourse(150, "CS150", 4, a);
	courseList2.addCourse(250, "CS250", 4, a);

	// Print courseList1 (should show 131, 170, 257, 272)
	courseList1.retrieveAllCourse(myString);
	cout << "1\n" << myString << endl;

	// Print courseList2 (should show 150 and 170)
	courseList2.retrieveAllCourse(myString);
	cout << "2\n" << myString << endl;

	// CALL: courseList1 = courseList2
	courseList1 = courseList2;

	// Print courseList1 (should show 150 and 250)
	courseList1.retrieveAllCourse(myString);
	cout << "3\n" << myString << endl;

	// Print courseList2 (should show 150 and 250)
	courseList2.retrieveAllCourse(myString);
	cout << "4\n" << myString << endl;

	// CLEAR courseList2
	courseList2.clearList();

	// Print courseList1 (should show 150 and 170)
	courseList1.retrieveAllCourse(myString);
	cout << "5\n" << myString << endl;

	// Print courseList2 (should be empty)
	courseList2.retrieveAllCourse(myString);
	cout << "6\n" << myString << endl;
}
void testOpEqCallingShorter()
{
	//TEST ASSIGNMENT OPERATOR: CALLING OBJ IS SHORTER

	// To print, create a variable of type string and use it
	// as an argument to call the function retrieveAllCourses().
	string myString;

	// Create courseList1 with two courses: 131, 272 
	set<int> a;
	CourseList courseList1;
	courseList1.addCourse(131, "CS131", 4, a);
	courseList1.addCourse(272, "CS272", 4, a);

	// Create courseList2 with four courses: 150, 170, 250, and 257
	CourseList courseList2;
	courseList2.addCourse(150, "CS150", 4, a);
	courseList2.addCourse(170, "CS170", 4, a);
	courseList2.addCourse(250, "CS250", 4, a);
	courseList2.addCourse(257, "CS257", 4, a);
	// Print courseList1 (should show 131 and 272)
	courseList1.retrieveAllCourse(myString);
	cout << "1\n" << myString << endl;

	// Print courseList2 (should show 150, 170, 250, 257)
	courseList2.retrieveAllCourse(myString);
	cout << "2\n" << myString << endl;

	// CALL: courseList1 = courseList2 
	courseList1 = courseList2;

	// Print courseList1 (should show 150, 170, 250, 257)
	courseList1.retrieveAllCourse(myString);
	cout << "3\n" << myString << endl;

	// Print courseList2 (should show 150, 170, 250, 257)
	courseList2.retrieveAllCourse(myString);
	cout << "4\n" << myString << endl;

	// CLEAR courseList2
	courseList2.clearList();

	// Print courseList1 (should show 150, 170, 250, 257)
	courseList1.retrieveAllCourse(myString);
	cout << "5\n" << myString << endl;

	// Print courseList2 (should be empty)
	courseList2.retrieveAllCourse(myString);
	cout << "6\n" << myString << endl;
}

