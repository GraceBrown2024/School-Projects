#include "Course.h"

Course* createCourse(string a, string b, int c, int d){
    // This will DYNAMICALLY create a new Course struct variable and enter given data into struct members
    Course* myCourse = new Course;
    myCourse->name = a; //LEARNED FROM https://stackoverflow.com/questions/31222806/or-as-member-access-operator-in-c
    myCourse->location = b;
    myCourse->section = c;
    myCourse->credits = d;


    // Will also dynamically create the sections array containing NUMBER of ELEMENTS as there are sections of course
   
    // returns the memory address of the course struct variable from this function
}

void destroyCourse(Course* mycourse){
    //deleted both dynamically created sections array and course
}

void printCourse(Course* myCourse){
    //PRINTS all the data in the members of the course strct variable

}