/************************************
* Editor      : Grace Brown			*
* Last Edited : 6 March 2026    	*
* File Name   : prog2.cpp			*
* Purpose     : Player gets to TEST *
*				their luck in a fun *
*				game of dice!		*
************************************/

#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include "prog2.h"
using namespace std;

int main(){ 		
	
	srand(time(0)); //CREATES UNQIUE TIMESTAMP SEED FOR DICEROLL FUNCTIONS

	string playerName; // used in lucky dice game
	int choice; //Holds the return value for displayMenuChoice()
	cout << "\n┏━━━━━━━━━━✦❘༻༺❘✦━━━━━━━━━━━┓"
	 	 << "\n    Welcome to Dice Casino     "
		 << "\n ----------------------------- "
		 << "\n   Here you can choose one     "
		 << "\n  of three unique dice games   "
		 << "\n ----------------------------- "
		 << "\n┗━━━━━━━━━━✦❘༻༺❘✦━━━━━━━━━━━┛\n"
		 << "\n[ENTER TO CONTINUE]\n";
	cin.ignore(100, '\n');

	gameDescription(); //Gives rules to game


	do{ // creates game loop! ends if player enters 4
		cout << "\n[ENTER TO CONTINUE]\n";
		cin.ignore(100, '\n');

		choice = displayMenuChoice(); //assigns the return of function to choice variable
		
		switch(choice){ //uses function return to command switch
			case 1:  // ROLL CALL
				int num; //holds user guess
				cout << "\nWhat do you think the total of the two dice will be?\n"
					 << "--> ";
				cin >> num;

				while(cin.fail()){ // user validation
					cin.clear();
					cin.ignore(100, '\n');

					cout << "\nPlease enter an integer! --> ";
					cin >> num;
				}
				cin.ignore(100, '\n');

				if(num == rollDice()){
					cout << "\n☄. *. ⋆\n"
						 << "\nCongratulations! You win."
						 << "\n☄. *. ⋆\n";
				}else{
					cout << "\n☄. *. ⋆\n"
						 << "Ah! So sorry! Not the answer :("
						 << "\n☄. *. ⋆\n";
				}
				break;

			case 2:  // OVER UNDER
				char guess; //holds user guess
				int firstRoll, secondRoll; // holds stationary diceRoll returns... prevents randomization each call!
				
				firstRoll = rollDice(); //holds unique dice roll values
				secondRoll = rollDice();

				cout << "\nThe first Roll was " << firstRoll << "."
					<< "\nWill the next roll be OVER, UNDER, or MATCH?!"
					<< "\n---------------"
					<< "\n CHOICE - TYPE"
					<< "\n---------------"
					<< "\n OVER   -  o   "
					<< "\n UNDER  -  u   "
					<< "\n MATCH  -  m   "
					<< "\n---------------\n"
					<< "\n--> ";
				cin >> guess;
				guess = toupper(guess); //converts Guess to UPPER for standardization https://cplusplus.com/reference/cctype/

				while(cin.fail() || (guess != 'O' && guess != 'U' && guess != 'M')){ //user validation
					cin.clear();
					cin.ignore(100, '\n');

					cout << "Please enter a valid choice! [o, u, m] --> ";
					cin >> guess;
					guess = toupper(guess);
				}
				cin.ignore(100, '\n');

				switch(guess){ //brings guess letter to a comparison statement
					case 'O':
						if(firstRoll < secondRoll){ //compares value of both rolls
							cout << "\n☄. *. ⋆\n"
								 << "Congratulations! You right :)"
								 << "\n☄. *. ⋆\n";
						}else{
							cout << "\n☄. *. ⋆\n"
								 << "Ah! So sorry. Wrong."
								 << "\nThe second roll was " << secondRoll << "."
								 << "\n☄. *. ⋆\n";
						}
						break;

					case 'U':
						if(firstRoll > secondRoll){ //compares value of both rolls
							cout << "\n☄. *. ⋆\n"
								 << "Congratulations! You right :)"
								 << "\n☄. *. ⋆\n";
						}else{
							cout << "\n☄. *. ⋆\n"
								 << "Ah! So sorry. Wrong."
								 << "\nThe second roll was " << secondRoll << "."
								 << "\n☄. *. ⋆\n";
						}
						break;

					case 'M':
						if(firstRoll == secondRoll){ //compares value of both rolls
							cout << "\n☄. *. ⋆\n"
								 << "Congratulations! You right :)"
								 << "\n☄. *. ⋆\n";
						}else{
							cout << "\n☄. *. ⋆\n"
								 << "Ah! So sorry. Wrong."
								 << "\nThe second roll was " << secondRoll << "."
								 << "\n☄. *. ⋆\n";
						}
						break;
				}
				break;
		
			case 3:  // LUCKY DICE
				int playerCount, playerTotal, highScore = 0; //intializing high score to give basis of comparison
				string winner;
				cout << "\nHow many friends are playing? --> ";
				cin >> playerCount;
				
				while(cin.fail() || playerCount <= 0 || playerCount > 10){ //User validation loop
					if(cin.fail()){
						cout << "\nPlease enter a number!\n";
					}else if(playerCount <0){
						cout << "\nPlease enter more than 0 players! --> ";
					}else{
						cout << "\nThats a lie. No one has more than 9 friends."
							 << "\nPlease enter a REASONABLE number (between 1 and 9) --> ";
					}

					cin.clear();
					cin.ignore(100, '\n');

					cin >> playerCount;
				}
				cin.ignore(100, '\n');

				for(int i = 1 ; i <= playerCount ; i++){ //begins loop that plays ONLY amount of players selected
					cout << "\n★・・・・・・★\n"
						 << "\nPlease enter Friend " << i << " Name --> ";
					getline(cin, playerName);
					cout << "\n★・・・・・・★\n";
					playerTotal = luckyDice(playerName);

					if(playerTotal > highScore){ //updates names and values for comparison
						winner = playerName;
						highScore = playerTotal;
					}
				}
				
				if(highScore){
					cout << "\n●・○・●・○・●・○・●・○・●・○・●・○・●"
					 << "\n      CONGRATULATIONS            "
					 << "\n       " << winner << " WINS!!       "
					 << "\n   They had " << highScore << " points!"
					 << "\n●・○・●・○・●・○・●・○・●・○・●・○・●\n";
				}else{
					cout << "\n●・○・●・○・●・○・●・○・●・○・●・○・●"
						 << "\n      Ah!  So sorry!             "
						 << "\n       Nobody wins               "
						 << "\n●・○・●・○・●・○・●・○・●・○・●・○・●\n";
				}
				
				break;
		}

	}while(!(choice == 4));

	cout << "\n┏━━━━━━━━━━✦❘༻༺❘✦━━━━━━━━━━━━┓"
	 	 << "\n•           Goodbye!            • "
		 << "\n┗━━━━━━━━━━✦❘༻༺❘✦━━━━━━━━━━━━┛\n";

	return 0;
}