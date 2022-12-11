#ifndef INTERFACE_H
#define INTERFACE_H

#include "CourseList.h"

void displayMenu();
void processChoice(CourseList& courseList);
void searchCourse(CourseList& courseList);
void addCourse(CourseList& courseList);
void deleteCourse(CourseList& courseList);
void displayAllCourse(CourseList& courseList);
void displayTotalUnits(CourseList& courseList);
void toContinue(CourseList& courseList);
void toExit();
int restart();

#endif
