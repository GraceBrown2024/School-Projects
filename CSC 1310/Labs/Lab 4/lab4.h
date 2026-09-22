/*
Name            : Grace Brown
File            : lab4.h
Date Created    : 9/22/26 (GIVEN FILE)
Last Modified   : 9/22/26
Purpose         : functions and libraries for sorting algorthims
*/
#ifndef LAB4_H
#define LAB4_H

#include <chrono>	//used for measuring elapsed time
#include <fstream>  //used to read in from text file
#include <iostream> //used for console input and output
#include <cstdlib>  //used for rand() and srand()
#include <ctime>    //used to seed random number generator with time(0)
#include <string>   //used for string data type
#include <limits>   //used for numeric_limits<streamsize>::max() which I use to clear input buffer

/*
	As we are starting to get into more complex code, 
	it is better practice to avoid "using namespace std;" in header files.

	WHY?
	When you write "using namespace std;", you're telling the compiler:
	"make everything in std available without needing std::"
	That seems convenient, but in header files, this creates namespace pollution -
	you put all the names from std into the global scope. This increases the
	chance that something in your code (or another library you include) has
	the same name as something in std, causing name conflicts and confusing errors.
	For example, if you have a function or variable named "count" and you include
	<iostream>, there will be a conflict with std::count.

	Instead, we will use "using std::..." for the specific standard library
	components we need. This way, we avoid namespace pollution and make it
	clear which parts of the standard library we are using. It also still allows us
	to omit std:: for those specific components, which makes the code cleaner.
*/
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;
using std::swap;
using std::streamsize;
using std::numeric_limits;
using namespace std::chrono; 
/* 
	chrono, which is used to measure elapsed time, is a bit different
	because it is a namespace inside std. When you write this, you are
	telling the compiler :"bring all the names from the std::chrono namespace 
	into the current scope"
*/


//Function prototypes - YOU SHOULD NOT HAVE TO MODIFY THESE!!
void readFromFile(string*&, int&, int&);
void bubbleSort(string*, int);
void selectionSort(string*, int);
void insertionSort(string*, int);
void printArray(string*, int);
int doubleArray(string*&, int);
void scramble(string*, int);

#endif