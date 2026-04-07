/***************************
    	 Name: Grace Brown
 Date Created: 26 March 2026
Date Modified: 6 April 2026 
  	File Name: driver.cpp
	  Purpose: Budget tracking sheet (super cool wow)
*****************************/

#include "budget.h"

int main(){
	string categ1, categ2, categ3, categ4; 	//holds the names of each category
	string students[3]; 					//creates a 3 space array for student names
	double studentIncome[3];				//3 space array for starting income
	double remainingBalance[3];				//3 space array for REMAINING moniezzzz
	double expenditures[4][3];				//2d array that holds 3 colums for each student and 4 rows for each user-inputted expenditure
	int highestIndex, lowestIndex;			//Holds the returned index from getHighest and getLowest
	double highestBalance, lowestBalance;	//Holds the actual number of the highest and lowest balance

	cout << "\n Welcome to the Student Budget Calculator for the Month of April" << endl
		 << "Please enter the expenditure category names -- " << endl;
	for(int i = 1; i <= 4 ; i++){			//loops through 4 iterations to name each variable 
		cout << "\tNAME OF CATEGORY --> ";	// NO IDEA why i did it like this im so sorry. It was 2am when I started this part
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
	
	getUserInput(students, studentIncome, expenditures, 3, categ1, categ2, categ3, categ4); //Allows for user inputted incomes

	calculateBalance(studentIncome, expenditures, remainingBalance, 3); //places all the students' balances in an array

	highestIndex = getHighest(remainingBalance, 3); // getHighest/Lowest returns the INDEX of the corresponding student
	lowestIndex = getLowest(remainingBalance, 3);

	highestBalance = remainingBalance[highestIndex]; //uses the indeces to locate the corresponding balance
	lowestBalance = remainingBalance[lowestIndex];
	
	cout << "\nThe student with the HIGHEST remaining balance is " 							//Showcases the winner
		 << students[highestIndex] << " with a balance of " << highestBalance << ".\n"
		 << "They BEGAN with $" << studentIncome[highestIndex] << "...\n"
		 << "Here is their breakdown:\n"
		 << "\t" << categ1 << ": $" << expenditures[0][highestIndex] << "\n"
		 << "\t" << categ2 << ": $" << expenditures[1][highestIndex] << "\n"
		 << "\t" << categ3 << ": $" << expenditures[2][highestIndex] << "\n"
		 << "\t" << categ4 << ": $" << expenditures[3][highestIndex] << "\n" << endl;
	
	cout << "\nThe student with the LOWEST remaining balance is " 							//Showcases the LOSER
		 << students[lowestIndex] << " with a balance of " << lowestBalance << ".\n"
		 << "They BEGAN with $" << studentIncome[lowestIndex] << "...\n"
		 << "Here is their breakdown:\n"
		 << "\t" << categ1 << ": $" << expenditures[0][lowestIndex] << "\n"
		 << "\t" << categ2 << ": $" << expenditures[1][lowestIndex] << "\n"
		 << "\t" << categ3 << ": $" << expenditures[2][lowestIndex] << "\n"
		 << "\t" << categ4 << ": $" << expenditures[3][lowestIndex] << "\n" << endl;
	
	return 0;
}