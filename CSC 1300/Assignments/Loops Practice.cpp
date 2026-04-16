/*****************************
* Last Editor: Grace Brown	 *
* Last Edited: 22 Feb 2026	 *
* File Name  : mod5Loops.cpp *
* Purpose    : Many loops	 *
******************************/

//Hello. This program is aimless
//Enjoy
 
#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>
using namespace std;

int main(){
	
	string sentence, border(30, '='), replay;
	int userNum, loopNum = 1, choice;
	char yesNo;
	
	// First loop: a for loop
	cout << "\nHello\nThis first loop is a for loop.\nPlease enter the thing you want repeated.\nHere --> ";
	getline(cin, sentence);
	
	cout << "\nOkay cool.\nNow enter the amount of times you want it repeated.\nHere --> ";
	cin >> userNum;
	cin.ignore(100, '\n');	//Ignores the terminating character to allow the cin.get to work
	
	// While loop for validation yay
	while(cin.fail()){ // Flags incorrect input type 
		cin.clear();
		cin.ignore(100, '\n'); // Cleans buffer after cin.clear wipes the flag
		cout << "PLEASE ENTER AN INTEGER RIGHT NOW PLEASE ENTER AN INTEGER PLEASE\nHere --> ";
		cin >> userNum;
		
	}
	//For loop that repeats not only the string you typed, but the number of times it iterates
	for(int i = userNum ; i > 0 ; i--){
		cout << "[" << loopNum << "] " << sentence << endl;
		loopNum++;
	}
	
	cout << "\n[PRESS ENTER TO CONTINUE]";
	cin.ignore(100, '\n');  //Clears up buffer once enter is pressed
	
	cout << "\nYeah that was pretty cool.\nHope you'rere ready for t he next one\n"
		 << "\nThe next one is a DO-WHILE LOOP!! I like these ones.\n"
		 << "In fact. I love these so much Imma make a game.\n"
		 << "\n[PRESS ENTER TO CONTINUE]";
	cin.ignore(100, '\n');  // Clears up buffer once enter is pressed
	
	do{
		int health = 3;  //Variables defined and used ONLY in do-while game... nothing bad happens if it hits 0
		
		cout << "\n ╒═══════════════════════════╕"
			 << "\n |         THE GAME          |"
			 << "\n ╘═══════════════════════════╛"
		 	<< "\n" << border << "\n"
		 	<< setw(5) << " " << "✧*̥˚ THE RULES *̥˚✧\n"
		 	<< "\n1.) Answer questions CORRECTLY\n"
		 	<< "2.) DONT BREAK MY PROGRAM please\n"
		 	<< "3.) Dont google tehe ansers. thanks\n"
		 	<< "\nYOU HAVE 3 HEALTHS!!!!!!!!! \n Every Wrong answer KILLS ONE!!!!\n"
		 	<< "\n" << border << endl
		 	<< "\n°°••QUESTION ONE••°°\n"
		 	<< "\n\"What da best drinkg??\"\n"
		 	<< "\t1.)Pepsiei\n\t2.)CokaeCola\n\t3.)White Gatorade Frost\n"
		 	<< "ENTER NUMBER HERE --> ";
		cin >> choice;
	
		while(cin.fail() || choice < 1 || choice > 3){   //Another validation loop (there are many)
			cin.clear();
			cin.ignore(100, '\n');  
			cout << "\nSELECT A VALID ANSWER -->";
			cin >> choice;
		}
		cin.ignore();  // Clears buffer from cin
	
		switch(choice){  // Determines dialogue and decrements bad answers
			case 1:
				cout << "\nWrong :(\n"
					 << "You lost a heart :(\n";
				health--;
				break;
			case 2:
				cout << "\nDOUBLE WRONG \n"
					 << "YOU LOSE HEART\n";
				health--;
				break;
			case 3:
				cout << "\nyay you are right  horay :)";
				break;
		}
		
		cout << "\nHERES YOUR CURRENT HEALTH!!! --> " << health
			 << "\n\n[PRESS ENTER TO CONTINUE]\n";
		cin.ignore(100, '\n');
		
		cout << "\n" << border << endl;
		
		cout << "\n°°••QUESTION TWO••°°\n"   // NEXT QUESTION
			 << "\n\"Best 90s-2000s toy???\"\n"
			 << "\t1.)Furby\n\t2.)Tamagotchi\n\t3.)Mighty Beanz\n"
			 << "ENTER NUMBER HERE --> ";
		cin >> choice;
		
		while(cin.fail() || choice < 1 || choice > 3){
			cin.clear();
			cin.ignore(100, '\n');
			cout << "\nSELECT A REAL ANSWER --> ";
			cin >> choice;	
		}
		cin.ignore();
		
		switch(choice){  // Another dialogue switch
			case 1:
				cout << "\nCORRECT CORRET COTRRECR!!!!!\n"
					 << "in fact you  GAIN A HEALTH!!!!\n"
					 << "Furby is the BEST and STILL IS\n";
				health++;
				break;
			case 2:
				cout << "\nWrong BUT fun fact:\n"
					 << "This toy INSPIRED the best toy\n"
					 << "Remember this.\n";
				health--;
				break;
			case 3:
				cout << "\n WRONG... but i can understand why you'd say they are the best\n"
					 << "My brother and I had so many of these\n"
					 << "I wonder if he still thinks of me\n";
				health--;
				break;
		}
		
		cout << "\nYour current Health is " << health << " hearts!!!\n"
			 << "\n[PRESS ENTER TO CONTINUE]";
		cin.ignore(100, '\n');   
		
		cout << "\n" << border << endl
			 << "\n°°••QUESTION THREE••°°\n"
			 << "\n\"What Grade is Grace gonna get on this assignment?\"\n"
			 << "\t1.)Negative Points :(\n\t2.)100\n\t3.)59 (evil)\n"
			 << "ENTER NUMBER HERE --> ";
		cin >> choice;
		
		while(cin.fail() || choice < 1 || choice > 3){  // Another validation loop
			cin.clear();
			cin.ignore(100, '\n');
			cout << "\nPLEASE ENTER A VALID OPTION! --> ";
			cin >> choice;
		}
		cin.ignore(100, '\n');
		
		switch(choice){   // Dialogue switch
			case 1:
				cout << "\nThats actually insane. You lose all your hearts idc\n";
				health -= health;
				break;
				
			case 2:
				cout << "\nYAY thanks :) hahaha yeay\n";
				break;
				
			case 3:
				cout << "\ndude. Minus one heart.";
				health--;
				break;
		}
		
		cout << "\n FINAL HEALTH: " << health << endl
			 << "\n ╒═════════•●•═════════╕"
			 << "\n |     PLAY AGAIN?     |"
			 << "\n |  1.) Yes            |"
			 << "\n |  2.) NO!!!          |"
			 << "\n ╘═════════•●•═════════╛"
			 << "\n ENTER CHOICE HERE --> ";
		cin >> choice;  						// CHOICE DETERMINES IF GAME LOOPS AGAIN
		
		while(cin.fail() || choice > 2 || choice < 1){
			cin.clear();
			cin.ignore(100, '\n');
			cout << "\n PLEASE SELECT A VALID OPTION --> ";
			cin >> choice;
		}
		cin.ignore(100, '\n');
		
		if(choice == 1)
			replay = "YES";
		else if(choice == 2)
			replay = "NO";
		
	}while(replay == "YES"); // IF THE USER CHOOSES TO PLAY AGAIN THE GAME RESETS HEALTH AS WELL
	
	cout << "\n" << border << endl
		 << "Okay you experienced a do while loop AND a for loop.\n"
		 << "Do you wanna experience an infinite loop?\n"
		 << "[Y/N] --> ";
	cin >> yesNo;
	yesNo = toupper(yesNo); // toupper used to standardize the char for if statements
	
	while(cin.fail() || yesNo != 'Y' && yesNo != 'N'){  //Validation loop
		cin.clear();
		cin.ignore(100, '\n');
		cout << "\nPLEASE SELECT A VALID OPTION! --> ";
		cin >> yesNo;
	}
	cin.ignore(100, '\n');
	
	if(yesNo == 'Y'){  //Allows user to enter a sentence for looping
		cout << "\nOkay. please enter a phrase: ";
		getline(cin, sentence);
		cout << "\nAre you sure you want to repeat \"" << sentence << "\" FOREVER?"
			 << "\n [Y/N] --> ";
		cin >> yesNo;
		yesNo = toupper(yesNo);
		
		while(cin.fail() || yesNo != 'Y' && yesNo != 'N'){ //Validation loop
		cin.clear();
		cin.ignore(100, '\n');
		cout << "\nPLEASE SELECT A VALID OPTION! --> ";
		cin >> yesNo;
		yesNo = toupper(yesNo);
		}
		cin.ignore(100, '\n'); //Clears buffer for NEW sentence
		
		if(yesNo == 'Y'){
			cout << "Okay if you say so...\n"
				 << "[PRESS ENTER FOR ETERNITY]";
			cin.ignore(100, '\n');
			
			while(yesNo == 'Y'){ //Begins illegal infinite loop
				cout << "\n" << sentence;
			}
		}else{
			while(yesNo == 'N'){ // JUST IN CASE user wants to enter a new sentence -- validation loop plays
				cout << "\nDo you want to type a NEW sentence or skip the infinite loop altogether...\n"
					 << "1. New Sentence\n2. Forget infinite Loop\n"; //Choices for user
				cin >> choice;
			
				while(cin.fail() || choice > 2 || choice < 1){ //Validation loop
					cin.clear();
					cin.ignore(100, '\n');
					cout << "PLEASE ENTER A VALID OPTION --> ";
					cin >> choice;
				}
				cin.ignore(100, '\n');
			
				switch(choice){  
					case 1:    //Allows user to select NEW sentence
						cout << "\nPLEASE ENTER NEW SENTENCE: ";
						getline(cin, sentence);
						cout << "\nIs the sentence \"" << sentence << "\" Good?\n"
							 << "[Y/N] --> ";
						cin >> yesNo;
						yesNo = toupper(yesNo);
						
						while(cin.fail() || yesNo != 'Y' && yesNo != 'N'){ // Validation loop
							cin.clear();
							cin.ignore(100, '\n');
							cout << "\n PLEASE ENTER A VALID OPTION! --> ";
							cin >> yesNo;
							yesNo = toupper(yesNo);
						}
						cin.ignore(100, '\n');
							
						if(yesNo == 'Y'){  //If user FINALLY agrees to the sentence, the loop plays and MIGHT crash computer
							cout << "\nokay.\n [PRESS ENTER FOR ETERNITY]";
							cin.ignore(100, '\n');
							
							while(yesNo == 'Y'){
								cout << sentence << endl;
							}
						}else{ // Repeats loop from above-- allows user to either ignore loop or choose new sentence
							yesNo = 'N';
						}
						break;
						
					case 2: // Breaks out of loop completely
						cout << "\nOkay.\n";
						yesNo = 'Y';
						break;
				}
			}
		}
	}else{ 
		cout << "\nokay cool.\nI implemented a billion validation while-loops throughout the code anyway\n"
			 << "Anyway thanks for playing my game. Hope you had fun.\n"
			 << border << endl;
	}
	cout << "Bye.\n\t-Grace Brown\n";
	return 0;
}
