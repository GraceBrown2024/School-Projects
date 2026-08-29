#include "Course.h"

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

void destroyCourse(Course* myCourse){
    //deleted both dynamically created sections array and course
    delete [] myCourse->sections;
    delete myCourse;
}

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