/***************************
    	 Name: Grace Brown
 Date Created: 26 March 2026
Date Modified: 6 April 2026 
  	File Name: functions.cpp
	  Purpose: holds function definitions for lab 8
*****************************/

#include "budget.h"

void getUserInput(string students[], double studentIncome[], double expenditures[][3], int size, string categ1, string categ2, string categ3, string categ4){
	int j = 0;
	for(int i = 0; i < size; i++){
		cout << "STUDENT " <<  i+1 << ":" << endl
			 << "\tNAME --> ";
		getline(cin, students[i]);

		cout << "\tINCOME --> ";
		cin >> studentIncome[i];

		cout << "\tEXPENDITURES\n"
			 << "\t" << categ1 << ": ";
		cin >> expenditures[j][i];
		cout << "\t" << categ2 << ": ";
		cin >> expenditures[j][i];
		cout << "\t" << categ3 << ": ";
		cin >> expenditures[j][i];
		cout << "\t" << categ4 << ": ";
		cin >> expenditures[j][i];

		cin.ignore();
		j++;
	}
}

int calculateBalance(){
	return 0;
}

int getHighest(){
	return 0;
}

int getLowest(){
	return 0;
}