/*
	Function Prototypes for Course.cpp
	LAB 1 CSC 1310
	Authors:Grace Brown 
	
	Date Created: 8/24/2026
	Date Updated: 8/29/2026 
*/


#ifndef LAB_1

#define LAB_1
#include <iostream>
#include <string>
#include <iomanip>
using namespace std; 

#endif 

struct Course{  //structure with course information... values inputted by user
    string name;
    string location;
    string* sections;
    int section;
    int credits;
};

Course* createCourse(string a, string b, int c, int d);
void destroyCourse(Course* mycourse);
void printCourse(Course* myCourse);
