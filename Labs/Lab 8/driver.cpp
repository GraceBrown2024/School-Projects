/***************************
    	 Name: Grace Brown
 Date Created: 26 March 2026
Date Modified: 6 April 2026 
  	File Name: driver.cpp
	  Purpose: Budget tracking sheet (super cool wow)
*****************************/

#include "budget.h"

int main(){
    //create 2d array
	string categ1, categ2, categ3, categ4;
	string students[3];
	double studentIncome[3];
	double remainingBalance[3];
	double expenditures[4][3];
	double highest = 0;
	double lowest = 0;

	cout << "\n Welcome to the Student Budget Calculator for the Month of April" << endl
		 << "Please enter the expenditure category names -- " << endl;
	for(int i = 1; i <= 4 ; i++){
		cout << "\tNAME OF CATEGORY --> ";
		if(i == 1){
			getline(cin, categ1);
		}else if(i == 2){
			getline(cin, categ2);
		}else if(i == 3){
			getline(cin, categ3);
		}else{
			getline(cin, categ4);
		}
	}
	
	getUserInput(students, studentIncome, expenditures, 3, categ1, categ2, categ3, categ4);

	/*UPDATES AND TO DO FOR TOMORROW!!!!
		1. Array loops for getUserInput work ... NEEDS USER INPUT VALIDATION!
		2. Pass array as reference to calculate balance
		3. call get high and low functions
		4. FIGURE OUT HOW TO PRINT FROM REFERENCE!!!
	*/
	//call calculateBalance()
	//call getHighest()
	//call getLowest()
	//PRINT OUT ALL INFO OF STUDENT WITH HIGHEST BALANCE
	//PRINT OUT ALL INFO OF STUDENT WITH LOWEST BALANCE

	return 0;
}