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

void getUserInput(string students[], double studentIncome[], double expenditures[][3], int size, string categ1, string categ2, string categ3, string categ4);

int calculateBalance();

int getHighest();

int getLowest();

#endif