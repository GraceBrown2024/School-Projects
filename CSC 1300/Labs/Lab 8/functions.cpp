/***************************
    	 Name: Grace Brown
 Date Created: 26 March 2026
Date Modified: 6 April 2026 
  	File Name: functions.cpp
	  Purpose: holds function definitions for lab 8
*****************************/

#include "budget.h"


void getUserInput(string students[], double studentIncome[], double expenditures[][3], int size, string categ1, string categ2, string categ3, string categ4){
	for(int i = 0; i < size; i++){					//loops through this block of inputs based on the size of the parralel arrays
		cout << "STUDENT " <<  i+1 << ":" << endl
			 << "\tNAME --> ";
		getline(cin, students[i]);

		cout << "\tINCOME --> $";
		cin >> studentIncome[i];
		while(cin.fail()){
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Please enter a valid input! --> $";
			cin >> studentIncome[i];
		}

		cout << "\tEXPENDITURES\n"					//expenditutes are only changed in index by COLUMN (student)
			 << "\t" << categ1 << ": $";
		cin >> expenditures[0][i];
		while(cin.fail()){ 							//user validation loop
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Please enter a valid input! --> $";
			cin >> expenditures[0][i];
		}

		cout << "\t" << categ2 << ": $";
		cin >> expenditures[1][i];
		while(cin.fail()){							//user validation loop
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Please enter a valid input! --> $";
			cin >> expenditures[1][i];
		}

		cout << "\t" << categ3 << ": $";
		cin >> expenditures[2][i];
		while(cin.fail()){							//user validation loop
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Please enter a valid input! --> $";
			cin >> expenditures[2][i];
		}

		cout << "\t" << categ4 << ": $";
		cin >> expenditures[3][i];
		while(cin.fail()){							//user validation loop
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Please enter a valid input! --> $";
			cin >> expenditures[3][i];
		}

		cin.ignore();								//eliminates space in buffer just in case
	}
}

void calculateBalance(double studentIncome[], double expenditures[][3], double remainingBalance[], int size){ //BORROWED this setup form Gold 002 slides for Module 8
	for(int i = 0; i < size; i++){
		double total = 0;

		total = studentIncome[i] - (expenditures[0][i] + expenditures[1][i] + expenditures[2][i] + expenditures[3][i]); //adds all expenditures and subtracts it from the students initial income
		remainingBalance[i] = total;
	}
	
}

int getHighest(double remainingBalance[], int size){ //BORROWED this setup from Gold 002 slides for Module 8
	int maxValue = 0;
	int maxIndex = 0;
	for(int i = 0; i < size; i++){					// Iterates through array and compares the highest CURRENT value to i
		if(remainingBalance[i] > maxValue){
			maxValue = remainingBalance[i];
			maxIndex = i;
		}
	}
	return maxIndex;								//returns the INDEX in order to easily find parralel index in other arrays
}

int getLowest(double remainingBalance[], int size){ //BORROWED this setup from gold 002 slides for Module 8
	int minValue = remainingBalance[0];	
	int minIndex = 0;
	for(int i = 0; i < size; i++){					// itereates through array and compares the lowest CURRENT value to i
		if(remainingBalance[i] < minValue){
			minValue = remainingBalance[i];
			minIndex = i;
		}
	}
	return minIndex;								//returns the INDEX in order to easily find parralel index in other arrays
}