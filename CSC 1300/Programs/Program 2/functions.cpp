/*
Name		: Grace Brown
Last Edited	: 6 March 2026
File Name	: functions.cpp
Purpose		: holds function definitions for Program2.cpp
*/

#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <iomanip>
#include "prog2.h"
using namespace std;

/*
Name		: displayMenuChoice
Return type	: integer
Parameters	: N/A
Purpose		: displays meny choices and returns the user input for choice
*/
int displayMenuChoice(){ 		
	int choice;
	
	cout << "\n◤━━━━━━━━━━━━━━━━━━━━━━━━━◥\n"
		 << setw(5) << " " << "► SELECTION MENU ◄\n" << endl
		 << setw(3) << "1" << ".) Roll Call\n"
		 << setw(3) << "2" << ".) Over Under\n"
		 << setw(3) << "3" << ".) Lucky Dice\n"
		 << setw(3) << "4" << ".) Quit"
		 << "\n◣━━━━━━━━━━━━━━━━━━━━━━━━━◢\n"
		 << "Please Select Your Choice --> ";
	cin >> choice;
	
	//Validation loop for choice (using cin.fail() from module 6 slides failbit)
	while(cin.fail() || choice > 4 || choice < 1){ 
		if(cin.fail()){
			cout << "\nThats not a Number! Please select a valid option --> ";
		}else{
			cout << "\nPlease select a number 1-4 --> ";
		}
		cin.clear();
		cin.ignore(100, '\n');
		cin >> choice;
	}
	cin.ignore(100, '\n');
	return choice;
}

/*
Name		: rollDice
Return type	: integer
Parameters	: N/A
Purpose		: generates two unique dice totals -- returns total of the two
*/
int rollDice(){ 				
	int dice1, dice2, total;

	dice1 = rand() % 6 + 1;  
	dice2 = rand() % 6 + 1;

	total = dice1 + dice2;

	return total; 				// Gives the total to be used when function is called
}

/*
Name		: luckyDice
Return type	: integer
Parameters	: string for player name
Purpose		: allows user to roll two dice continuously until they roll identical values 
*/
int luckyDice(string player){ 	//Do-While loop for user choice to continue rolling
	int dice1, dice2, accumulatedTotal = 0, turn = 1;	
	char yesNo;					//Allows user to choose if they continue rolling
	do{							//Continues rolling BY USERS CHOICe
		int diceTotal;			// Stores temp dice total value to be added to accumulator
		string border(20, '-');

		
		cout << border << endl
			 << "Turn " << turn << "... \n";
		turn++; 				//Ensures turn number is updated each loop
		dice1 = rand() % 6 + 1;
		dice2 = rand() % 6 + 1;
		
		if(dice1 == dice2){		//If branches based on if dice are equal or not
			cout << "Oops!" << player << " rolled double " << dice1 << "'s!\n"
				 << "You lost all your points for this round!\n";
			accumulatedTotal = 0; //Automatically sets accumulated total to 0 -- ends round
		}else{
			cout << player << " rolled a " << dice1 << " and a " << dice2 << "!\n";
			diceTotal = dice1 + dice2;
			accumulatedTotal += diceTotal; //Adds running total to accumulator for total overall points
		}

		cout << "\n" << player << "\'s new total is " << accumulatedTotal << "!\n";

		if(accumulatedTotal > 0){  			// Allows user to keep plying IF they havent rolled a double
			cout << "Would you like to test your luck and ROLL AGAIN?\n"
				 << "[Y/N] --> ";
			cin >> yesNo;
			yesNo = toupper(yesNo);

			while(cin.fail() || (yesNo != 'Y' && yesNo != 'N')){	//User Validation loop
				cin.clear();
				cin.ignore(100, '\n');
				cout << "Please enter a valid choice! --> ";
				cin >> yesNo;
				yesNo = toupper(yesNo);
			}
			cin.ignore(100, '\n');
		}
	}while(yesNo == 'Y' && accumulatedTotal > 0); //Continues as long as player wants to keep playing OR total is above 0

	cout << "\n" << player << " ended their turn with " << accumulatedTotal << " points.\n";

	return accumulatedTotal;
	
}


/*
Name		: gameDescription
Return type	: Void
Parameters	: N/A
Purpose		: displays rules and description of games
*/
void gameDescription(){ 
	cout << "\n‿︵‿︵୨˚̣̣̣͙୧ - GAME DESCRIPTION - ୨˚̣̣̣͙୧‿︵‿︵\n"
		 << "\nRoll Call : You guess the TOTAL ROLL of two 6-sided die\n"
		 << "\nOver Under: Tells your the initial total of two 6-sided die and you have to guess if the NEXT total will be OVER or UNDER\n"
		 << "\nLucky Dice: Roll two 6-sided die until you want to HOLD your points.BUT BE CAREFUL! If you roll a DOUBLE...YOU LOSE ALL YOUR POINTS!\n" 
		 << setw(12) << " " << "(Multi-player friendly!)\n"
		 << "\n‿︵‿︵୨˚̣̣̣͙୧ -------------------- ୨˚̣̣̣͙୧‿︵‿︵\n";

}