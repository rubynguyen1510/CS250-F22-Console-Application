#include "Interface.h"

#include <iostream>
using namespace std;

void displayMenu()
{
	cout << "**************************************************************\n"
		<< "                          MAIN MENU\n"
		<< "**************************************************************\n";
	cout << "\nSelect one of the following:\n\n"
		<< "    1: Search course\n"
		<< "    2: Add course\n"
		<< "    3: Delete course\n"
		<< "    4: Display all courses\n"
		<< "    5: Display all units\n"
		<< "    6: To exit\n";
}

void processChoice(CourseList& courseList)
{
	int option = restart();
	if (option == 1)
	{
		searchCourse(courseList);
	}
	else if (option == 2)
	{
		addCourse(courseList);
	}
	else if (option == 3)
	{
		deleteCourse(courseList);
	}
	else if (option == 4)
	{
		displayAllCourse(courseList);
	}
	else if (option == 5)
	{
		displayTotalUnits(courseList);
	}
	else if(option == 6)
	{
		toExit();
	}
	else
	{
		cout << "Please enter a number from 1 to 6. \n";
		processChoice(courseList);
	}
}

void toContinue(CourseList& courseList)
{
	cout << "\n\nDo you want to continue? Press Y to continue, any other key to exit: ";
	char ch;
	cin >> ch;
	if(ch == 'Y')
	{
		processChoice(courseList);
	}
	else 
	{
		toExit();
	}
}
void searchCourse(CourseList& courseList)
{
	int userCourseNumber;
	cout << "Enter course number: ";
	cin >> userCourseNumber;

	Course userCourse;
	bool isFound = courseList.searchCourse(userCourseNumber, userCourse);
	if (isFound)
	{
		cout << "Your course is " 
			<< userCourse.getPrefix() << userCourse.getCourseNumber()
			<< " - " << userCourse.getCourseName()
			<< " " << userCourse.getCourseUnits() << " units";
	}
	else
	{
		cout << "You course is not the list.";
	}
	toContinue(courseList);
}

void addCourse(CourseList& courseList)
{
	cout << "Please contact the Curriculum Committee to start the process of adding a course";
	toContinue(courseList);
}

void deleteCourse(CourseList& courseList)
{
	int userCourseNumber;
	cout << "Enter course number that you want to delete: ";
	cin >> userCourseNumber;

	Course userCourse;
	bool isFound = courseList.searchCourse(userCourseNumber, userCourse);
	if (isFound)
	{
		char userMessage;
		cout << "Are you sure you want to delete? Press Y to confirm, any other key to cancel: ";
		cin >> userMessage;
		if (userMessage == 'Y')
		{
			courseList.deleteCourse(userCourseNumber);
			cout << "Successfully Deleted!";
		}
			toContinue(courseList);
	}
	else
	{
		cout << "Course that you want to delete is not in the list!\n";
		cout << "Pick another course!\n";
		deleteCourse(courseList);
	}
}

void displayAllCourse(CourseList& courseList)
{
	string allCourses;
	courseList.retrieveAllCourses(allCourses);
	cout << "All of your courses are listed below: \n";
	cout << allCourses;
	toContinue(courseList);
}

void displayTotalUnits(CourseList& courseList)
{
	cout << "You registered for a total of " << courseList.getTotalUnits() << " units.";
	toContinue(courseList);
}

int restart()
{
	int option;
	cout << "Your choice: ";
	cin >> option;
	return option;
}
void toExit()
{
	cout << "Thank you for using our app. Good bye and have a nice day!";
}


