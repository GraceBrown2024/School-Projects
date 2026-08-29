/*
	Functions Course Structure
	LAB 1 CSC 1310
	Authors:Grace Brown 
	
	Date Created: 8/24/2026
	Date Updated: 8/29/2026 
*/


#include "Course.h"

/*
NAME        : createCourse  
PARAMETER   : string, int
FUNCTION    : creates the new course from Course struct. Assigns values to each member in struct
RETURN      : memory address of course
*/
Course* createCourse(string a, string b, int c, int d){
    // This will DYNAMICALLY create a new Course struct variable and enter given data into struct members
    Course* myCourse = new Course;
    myCourse->name = a; //LEARNED FROM https://stackoverflow.com/questions/31222806/or-as-member-access-operator-in-c
    myCourse->location = b;
    myCourse->section = c;
    myCourse->credits = d;


    //dynamically create the sections array containing NUMBER of ELEMENTS as there are sections of course;
    myCourse->sections = new string[c];

    // returns the memory address of the course struct variable from this function
    return myCourse;
}

/*
NAME        : destroyCourse  
PARAMETER   : myCourse pointer
FUNCTION    : frees memory of the dynamically allocated memory from Curse struct arrays
RETURN      : NA
*/
void destroyCourse(Course* myCourse){
    //deleted both dynamically created sections array and course
    delete [] myCourse->sections;
    delete myCourse;
}

/*
NAME        : printCourse  
PARAMETER   : myCourse pointer
FUNCTION    : prints out user-fed information to the terminal screen
RETURN      : NA
*/
void printCourse(Course* myCourse){
    cout << "COURSE NAME    : " << setw(5) << myCourse->name << endl;
    cout << "COURSE LOCATION: " << setw(5) << myCourse->location << endl;
    cout << "COURSE HOURS   : " << setw(5) << myCourse->credits << endl;
    cout << "COURSE SECTIONS:" << endl;

    for(int i = 0; i < myCourse->section; i++){
        cout << setw(22) << myCourse->sections[i] << endl;
    }

    cout << "\n";
}