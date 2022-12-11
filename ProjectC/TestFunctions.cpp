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

 void testCourseList()
 {
    //Create an object of the class CourseList.
    CourseList myList;

    //Call function CourseList::isEmpty and print a message.
    if(myList.isEmpty())
    {
    	cout << "My list is empty" << endl;
    }
    else
    {
    	cout << "Not empty" << endl;
    }

     /*NOTE: To properly test the functions, it is 
     recommended you use the course number 
     suggested in this guideline.*/

    //Create three objects of the class Course using
    //the overloaded constructor.
    //Courses: 250, 150, 200
    set<int> a;
    Course cs250(250, "Cs250", 4, a);
    Course cs150(150, "Cs150", 4, a);
    Course cs200(200, "Cs200", 3, a);

    //Call function CourseList::addCourse(Course) to add the three courses.
    myList.addCourse(cs250);
    myList.addCourse(cs150);
    myList.addCourse(cs200);

    /* Call function CourseList::addCourse(int, string, int, set)
     to add three additional courses: 131, 272, 216*/
    myList.addCourse(131, "Cs131", 4, a);
    myList.addCourse(272, "Cs272", 4, a);
    myList.addCourse(216, "Cs216", 5, a);

    /*Create a string and use it as a parameter to 
    call function CourseList::retrieveAllCourses().
    Print the string.*/
    string myString;
    myList.retrieveAllCourse(myString);
    cout << myString << endl;

    // Call CourseList::search(int) to search for 150.
    if(myList.searchCourse(150))
    {
    	cout << "My list contains course cs150 \n";
    }
    else
    {
    	cout << "My list does not contain course cs150 \n";
    }

     /*Create a string to store a course name, and */
    string courseName200 = "cs200";

    //  call CourseList::search(int, string) to 
    // retrieve the name of the course and print it.
    if(myList.searchCourse(200, courseName200))
    {
    	cout << "Course cs 200 is found in my list \n";
    }
    else
    {
    	cout << "Course cs 200 is not found in my list \n";
    }

    //Create an empty course by using the default constructor.
    Course emptyCourse;
    
    //Call function CourseList::search(int, Course) to 
    //retrieve the course and print the prefix, the number
    //the name and the units.
    if (myList.searchCourse(0, emptyCourse))
    {
    	cout << "Course empty is found in my list \n";
    }
    else
    {
    	cout << "Course empty is not found in my list \n";
    }

    //  Call function CourseList::deleteCourse to delete 131.
    myList.deleteCourse(131);

    //  Call function CourseList::deleteCourse to delete 272.
    myList.deleteCourse(272);

    //  Call function CourseList::deleteCourse to delete 150.
    myList.deleteCourse(150);

    //  Call function CourseList::deleteCourse to delete 250.
    myList.deleteCourse(250);

    //  Print all courses to see what is left in the list.
    myList.retrieveAllCourse(myString);
    cout << myString << endl;
 }
