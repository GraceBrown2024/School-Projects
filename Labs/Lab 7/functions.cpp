/*
    Name        : Grace Brown
    Last Updated: 24 March 2026
    File Name   : functions.cpp
    Purpose     : Defines functions for driver.cpp 
*/

#include "lab7.h"

void printOver10(string dName, string dHeight, string dMass, string dEat, string dDesc){
    //print out file holding the dinos that are over 10 grand
    ofstream overTenOut;
    ifstream overTenIn;
    overTenOut.open("over10Grand.txt", ios::app); //opens file... appends to allow more dinos to be added
    overTenOut << "\n"
               << "DINOSAUR NAME: " << dName << endl
               << "HEIGHT/LENGTH: " << dHeight << endl
               << "MASS:" << setw(10) << " " <<  dMass << endl
               << "EATS:" << setw(10) << " " << dEat << endl
               << "DESCRIPTION:" << setw(3) << " " << dDesc << endl;
    overTenOut.close();

}

void printSaurus(string dName, string dHeight, string dMass, string dEat, string dDesc){
    ofstream saurusOut;
    ifstream saurusIn;
    saurusOut.open("saurus.txt", ios::app); //opens file... appends to allow more dinos to be added
    saurusOut << "\n"
              << "DINOSAUR NAME: " << dName << endl
              << "HEIGHT/LENGTH: " << dHeight << endl
              << "MASS:" << setw(10) << " " <<  dMass << endl
              << "EATS:" << setw(10) << " " << dEat << endl
              << "DESCRIPTION:" << setw(3) << " " << dDesc << endl;
    saurusOut.close();
}

bool overTenGrand(string dMass){
    //Using THIS for reference
    //https://www.geeksforgeeks.org/cpp/iterate-over-characters-of-a-string-in-c/
    int num = dMass.length();
    for(int i = 0; i < num; i++){
        char innerChar = dMass[i];
        while(!isdigit(innerChar)){
            dMass.erase(i, 1);
        }
    }
    return true;
}