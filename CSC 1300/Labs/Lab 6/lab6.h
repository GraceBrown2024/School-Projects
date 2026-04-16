/*************************************
* Name          : Grace Brown
* Last Edited   : 9 March 1016
* File Name     : lab6.h
* Purpose       : functions and constant declaration
                  for lab 6
**************************************/

#ifndef LAB_SIX_H

#define LAB_SIX_H

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

const double PI = 3.14159; //global constant for π

int displayMenu(); // displays menu, allows user choice, RETURNS user choice
void areaSquare(double);  //calculated area of square based on user input
void areaRectangle(double, double); //calculates area of rectangle based on user input
void areaParallelogram(double, double ); //calculates area of parallelogram based on user input
void areaCircle(double); //calculates area of circle based on user input
#endif