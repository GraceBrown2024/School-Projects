/***************************
    	 Name: Grace Brown
 Date Created: 26 March 2026
Date Modified: 6 April 2026 
  	File Name: lab8.h
	  Purpose: holds function prototypes and constants for Lab 8
*****************************/

#ifndef BUDGET_H

#define BUDGET_H

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

/*
Function Name: getUserInput
Parameters	 : students array, income array, expenditure 2dArray, SIZE of arrays, each category name
Return		 : N/A
Type		 : void
Purpose		 : displays prompts for user input and updates each subsequent array in a loop
*/
void getUserInput(string students[], double studentIncome[], double expenditures[][3], int size, string categ1, string categ2, string categ3, string categ4);

/*
Function Name: calculateBalance
Parameters	 : income array, expenditures 2dArray, remaningBalance array, SIZE of arrays
Return		 : N/A
Type		 : void
Purpose		 : calculates remaning balance for each student and throws 
			   that balance in an array (remainingBalance) that correspond to each student
*/
void calculateBalance(double studentIncome[], double expenditures[][3], double remainingBalance[], int size);

/*
Function Name: getHighest
Parameters	 : remainingBalance array, SIZE of array
Return		 : index of highest balance
Type		 : integer
Purpose		 : iterates through remainingBalance and picks out the highest number
			   Then returns the index that corresponds to it
*/
int getHighest(double remainingBalance[], int size);

/*
Function Name: getLowest
Parameters	 : remainingBalance array, SIZE of array
Return		 : index of lowest balance
Type		 : integer
Purpose		 : iterates through remainingBalance and picks out the smallest number
			   Then returns the index that corresponds to it
*/
int getLowest(double remainingBalance[], int size);

#endif