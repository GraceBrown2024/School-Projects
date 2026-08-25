#ifndef LAB_1

#define LAB_1
#include <iostream>
#include <string>
#include <iomanip>
using namespace std; 

#endif 

struct Course{
    string name;
    string location;
    string* sections;
    int section;
    int credits;
};

Course* createCourse(string, string, int, int);
void destroyCourse(Course* mycourse);
void printCourse(Course* myCourse);
