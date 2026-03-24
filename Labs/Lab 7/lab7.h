/*
    Name        : Grace Brown
    Last Updated: 24 March 2026
    File Name   : lab7.h
    Purpose     : declares functions for driver.cpp and functions.cpp
*/

#ifndef LAB_7_H

#define LAB_7_H

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cctype>
#include <cstdlib>
using namespace std;

/*
    Return Type : Void
    Name        : printOver10
    Parameters  : string for name, height, mass, what it eats, and descrpition
    Use         : Throws all read info from main loop into a text file
    Return      : N/A
*/
void printOver10(string dName, string dHeight, string dMass, string dEat, string dDesc);

/*
    Return Type : Void
    Name        : printSaurus
    Parameters  : string for name, height, mass, what it eats, and descrpition
    Use         : Throws all read info from main loop into a text file
    Return      : N/A
*/
void printSaurus(string dName, string dHeight, string dMass, string dEat, string dDesc);

/*
    Return Type : Boolean
    Name        : overTenGrand
    Parameters  : string for mass
    Use         : converts and interprets values of mass to determine if it is GREATER than 10,000 lbs
    Return      : True/False
*/
bool overTenGrand(string);

#endif