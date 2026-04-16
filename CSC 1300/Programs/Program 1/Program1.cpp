/**************************************************
* Filename: GraceBrown_Program1.cpp               *
* Author: Grace Brown                             *
* Last Edited: 2 Feb 2026 (12:03 AM)              *
* Purpose: Personality quiz to determine          *
*          which of the main six (My little pony) *
*          you are      						  *
***************************************************/

// DISCLAIMER!!!! Vandergriff gave me permission to diverge from the Donuts theme. 
// Also I had NO CLUE what to add for comments since EVERYTHING is copy and pasted :( 

#include <iostream>
#include <iomanip>
using namespace std;

int main(){

	// VARIABLES
	int choice;							// Holds the user input which then tallies up the ponies in switch statements
	int appleJack = 0;
	int rarity = 0;
	int twilightSparkle = 0;
	int pinkiePie = 0;
	int rainbowDash = 0;
	int flutterShy = 0;
	string winner;						// Holds the name for the RESULTING PONY to be displayed in the end
	string border(30, '-');				// creates the middle border for the title and results
	// END VARIABLES
	
	cout << "+" << border << "+\n";          				
	cout << setw(11) << "WHICH " << "PONY ARE YOU" << endl;    
	cout << setw(9) << "IN " << "THE MAIN SIX" << endl;         
	cout << "+" << border << "+\n";			 				// Once again using setfill() to avoid typing a million dashes
	
	
	// QUESTION ONE 
	cout <<"\n°❀⋆.ೃ࿔*:･ QUESTION ONE :*࿔:ೃ.･⋆❀°\n" << endl;
	cout << setw(5) << right << ' ' << "What do you do in your free time?\n";  // Resetting the setfill() so there wont be dashes appearing
	cout << setw(10) << "1.) " << "Catch up on homework\n";					//Twilight								
	cout << setw(10) << "2.) " << "Workout at the gym\n";					//RainbowDash						
	cout << setw(10) << "3.) " << "Find he nearest Frat Party!\n";			//Pinkiepie				
	cout << setw(10) << "4.) " << "Go on a nature walk\n";					//Fluttershy		
	cout << setw(10) << "5.) " << "Shop at the mall\n";						//Rarity
	cout << setw(10) << "6.) " << "Spend time with friends and family\n";	//Applejack
	cout << "\n[PLEASE ENTER AN INTEGER CORRESPONDING TO YOUR CHOICE] --> ";
	cin >> choice;
	
	switch(choice){						// EVERY SWITCH STATEMENT INCREMENTALLY ADDS 1 EACH TIME CHOSEN
		case 1:
			twilightSparkle += 1;
			break;
		case 2:
			rainbowDash += 1;
			break;
		case 3:
			pinkiePie += 1;
			break;
		case 4:
			flutterShy += 1;
			break;
		case 5:
			rarity += 1;
			break;
		case 6:
			appleJack += 1;
			break;
	}
	
	// QUESTION TWO 
	cout <<"\n°❀⋆.ೃ࿔*:･ QUESTION TWO :*࿔:ೃ.･⋆❀°\n" << endl;
	cout << setw(5) << right << ' ' << "What is your DREAM career? \n";  
	cout << setw(10) << "1.) " << "F1 racer \n";				//Rainbowdash			
	cout << setw(10) << "2.) " << "Fashion Designer \n";		//Rarity
	cout << setw(10) << "3.) " << "Zoologist \n";				//Fluttershy
	cout << setw(10) << "4.) " << "Professor \n";				//Twilight
	cout << setw(10) << "5.) " << "Farmer \n";					//AppleJack
	cout << setw(10) << "6.) " << "DJ \n";						//Pinkipie
	cout << "\n[PLEASE ENTER AN INTEGER CORRESPONDING TO YOUR CHOICE] --> ";
	cin >> choice;
	
	switch(choice){					// EVERY SWITCH STATEMENT INCREMENTALLY ADDS 1 EACH TIME CHOSEN
		case 1:
			rainbowDash += 1;
			break;
		case 2:
			rarity += 1;
			break;
		case 3:
			flutterShy += 1;
			break;
		case 4:
			twilightSparkle += 1;
			break;
		case 5:
			appleJack += 1;
			break;
		case 6:
			pinkiePie += 1;
			break;
	}
	
	// QUESTION THREE
	cout <<"\n°❀⋆.ೃ࿔*:･ QUESTION THREE :*࿔:ೃ.･⋆❀°\n" << endl;
	cout << setw(5) << right << ' ' << "Describe your aesthetic \n";  
	cout << setw(10) << "1.) " << "Edgy and cool \n";   						//RainbowDash
	cout << setw(10) << "2.) " << "Librarian or grandma \n"; 					//Twilight
	cout << setw(10) << "3.) " << "Cottagecore \n";  							//Fluttershy
	cout << setw(10) << "4.) " << "Sparkly \n";    								//Rarity
	cout << setw(10) << "5.) " << "So Many Accessories \n";     				//Pinkiepie
	cout << setw(10) << "6.) " << "Tractor Supply Co. frequent flyer \n";     //Applejack
	cout << "\n[PLEASE ENTER AN INTEGER CORRESPONDING TO YOUR CHOICE] --> ";
	cin >> choice;
	
	switch(choice){					// EVERY SWITCH STATEMENT INCREMENTALLY ADDS 1 EACH TIME CHOSEN
		case 1:
			rainbowDash += 1;
			break;
		case 2:
			twilightSparkle += 1;
			break;
		case 3:
			flutterShy += 1;
			break;
		case 4:
			rarity += 1;
			break;
		case 5:
			pinkiePie += 1;
			break;
		case 6:
			appleJack += 1;
			break;
	}
	
	// QUESTION FOUR
	cout <<"\n°❀⋆.ೃ࿔*:･ QUESTION FOUR :*࿔:ೃ.･⋆❀°\n" << endl;
	cout << setw(5) << right << ' ' << "Which music genre resonates with you? \n";  
	cout << setw(10) << "1.) " << "Lofie \n";  						//Twilight 
	cout << setw(10) << "2.) " << "anything LOUD \n";  				//RainbowDash
	cout << setw(10) << "3.) " << "Country (NOT MORGAN WALLEN) \n"; //Applejack
	cout << setw(10) << "4.) " << "German House Music \n";  		//Pinkiepie
	cout << setw(10) << "5.) " << "Classical \n";  					//Rarity
	cout << setw(10) << "6.) " << "Indie Folk \n"; 					 //Fluttershy
	cout << "\n[PLEASE ENTER AN INTEGER CORRESPONDING TO YOUR CHOICE] --> ";
	cin >> choice;
	
	switch(choice){						// EVERY SWITCH STATEMENT INCREMENTALLY ADDS 1 EACH TIME CHOSEN
		case 1:
			twilightSparkle += 1;
			break;
		case 2:
			rainbowDash += 1;
			break;
		case 3:
			appleJack += 1;
			break;
		case 4:
			pinkiePie += 1;
			break;
		case 5:
			rarity += 1;
			break;
		case 6:
			flutterShy += 1;
			break;
	}
	
	// QUESTION FIVE
	cout <<"\n°❀⋆.ೃ࿔*:･ QUESTION FIVE :*࿔:ೃ.･⋆❀°\n" << endl;
	cout << setw(5) << right << ' ' << "Describe your ideal partner! \n";  
	cout << setw(10) << "1.) " << "Beastly and scary but kind \n"; //Fluttershy (i ship fluttercord)
	cout << setw(10) << "2.) " << "Career-oriented and driven \n"; //Twilight
	cout << setw(10) << "3.) " << "Actual Royalty \n";             //Rarity
	cout << setw(10) << "4.) " << "Hard-working and honest \n";    //Applejack
	cout << setw(10) << "5.) " << "Woman \n";                      //RainbowDash
	cout << setw(10) << "6.) " << "Fun and exciting!! \n";         //Pinkiepie
	cout << "\n[PLEASE ENTER AN INTEGER CORRESPONDING TO YOUR CHOICE] --> ";
	cin >> choice;
	
	switch(choice){ 					// EVERY SWITCH STATEMENT INCREMENTALLY ADDS 1 EACH TIME CHOSEN
		case 1:
			flutterShy += 1;
			break;
		case 2:
			twilightSparkle += 1;
			break;
		case 3:
			rarity += 1;
			break;
		case 4:
			appleJack += 1;
			break;
		case 5:
			rainbowDash += 1;
			break;
		case 6:
			pinkiePie += 1;
			break;
	}
	
	// QUESTION SIX
	cout <<"\n°❀⋆.ೃ࿔*:･ QUESTION SIX :*࿔:ೃ.･⋆❀°\n" << endl;
	cout << setw(5) << right << ' ' << "Which animal speaks to you? \n";  
	cout << setw(10) << "1.) " << "Little Baby Bunny Rabbit \n"; 		//Fluttershy
	cout << setw(10) << "2.) " << "Purple Lizard (unenergized) \n"; 	//Twilight
	cout << setw(10) << "3.) " << "Fast Turtle with Rockets\n";			//Rainbowdash
	cout << setw(10) << "4.) " << "Horse? \n";							//Applejack?
	cout << setw(10) << "5.) " << "Prissy fluffy cat \n";				//Rarity
	cout << setw(10) << "6.) " << "Green Lizard (energized) \n";		//Pinkiepie
	cout << "\n[PLEASE ENTER AN INTEGER CORRESPONDING TO YOUR CHOICE] --> ";
	cin >> choice;
	
	switch(choice){ 					// EVERY SWITCH STATEMENT INCREMENTALLY ADDS 1 EACH TIME CHOSEN
		case 1:
			flutterShy += 1;
			break;
		case 2:
			twilightSparkle += 1;
			break;
		case 3:
			rainbowDash += 1;
			break;
		case 4:
			appleJack += 1;
			break;
		case 5:
			rarity += 1;
			break;
		case 6:
			pinkiePie += 1;
			break;
	}
	
	// QUESTION SEVEN
	cout <<"\n°❀⋆.ೃ࿔*:･ QUESTION SEVEN :*࿔:ೃ.･⋆❀°\n" << endl;
	cout << setw(5) << right << ' ' << "Are you plagued by visions? \n";  
	cout << setw(10) << "1.) " << "Yes and its awful \n";  					//Twilight
	cout << setw(10) << "2.) " << "No are you okay? \n";        			//Fluttershy
	cout << setw(10) << "3.) " << "Sometimes but I outrun them \n"; 		//RainbowDash
	cout << setw(10) << "4.) " << "Been too busy to notice or care \n"; 	//Applejack
	cout << setw(10) << "5.) " << "Yes and I love it!! \n"; 				//Pinkiepie
	cout << setw(10) << "6.) " << "Not yet. Soon maybe. \n";				//Rarity
	cout << "\n[PLEASE ENTER AN INTEGER CORRESPONDING TO YOUR CHOICE] --> ";
	cin >> choice;
	
	switch(choice){ 				// EVERY SWITCH STATEMENT INCREMENTALLY ADDS 1 EACH TIME CHOSEN
		case 1:
			twilightSparkle += 1;
			break;
		case 2:
			flutterShy += 1;
			break;
		case 3:
			rainbowDash += 1;
			break;
		case 4:
			appleJack += 1;
			break;
		case 5:
			pinkiePie += 1;
			break;
		case 6:
			rarity += 1;
			break;
	}
	
	// QUESTION EIGHT
	cout <<"\n°❀⋆.ೃ࿔*:･ QUESTION EIGHT :*࿔:ೃ.･⋆❀°\n" << endl;
	cout << setw(5) << right << ' ' << "How well did you perform in Elementary School P.E. \n";  
	cout << setw(10) << "1.) " << "Very well. They all loved me \n";			//Rainbowdash
	cout << setw(10) << "2.) " << "They called me fatboy and made me cry \n";	//Fluttershy
	cout << setw(10) << "3.) " << "I dont remember. Probably well. \n";			//Applejack
	cout << setw(10) << "4.) " << "Not well. \n";								//Twilight
	cout << setw(10) << "5.) " << "I did great I loved running around \n";		//Pinkiepie
	cout << setw(10) << "6.) " << "I chose to walk instead \n";					//Rarity
	cout << "\n[PLEASE ENTER AN INTEGER CORRESPONDING TO YOUR CHOICE] --> ";
	cin >> choice;
	
	switch(choice){ 				// EVERY SWITCH STATEMENT INCREMENTALLY ADDS 1 EACH TIME CHOSEN
		case 1:
			rainbowDash += 1;
			break;
		case 2:
			flutterShy += 1;
			break;
		case 3:
			appleJack += 1;
			break;
		case 4:
			twilightSparkle += 1;
			break;
		case 5:
			pinkiePie += 1;
			break;
		case 6:
			rarity += 1;
			break;
	}
	
	// QUESTION NINE 
	cout <<"\n°❀⋆.ೃ࿔*:･ QUESTION NINE :*࿔:ೃ.･⋆❀°\n" << endl;
	cout << setw(5) << right << ' ' << "What is your GPA? \n";  
	cout << setw(10) << "1.) " << "Dropping out. Ts aint for me \n";  		//AppleJack
	cout << setw(10) << "2.) " << "4.0 \n";									//twilight
	cout << setw(10) << "3.) " << "2.0 and thriving \n";  					//Pinkiepie
	cout << setw(10) << "4.) " << "3.0 doing fine! \n";						//Rarity
	cout << setw(10) << "5.) " << "Havent checked  \n";						//Rainbowdash
	cout << setw(10) << "6.) " << "3.5 because math is hard :( \n";			//Fluttersy
	cout << "\n[PLEASE ENTER AN INTEGER CORRESPONDING TO YOUR CHOICE] --> ";
	cin >> choice;
	
	switch(choice){ 				// EVERY SWITCH STATEMENT INCREMENTALLY ADDS 1 EACH TIME CHOSEN
		case 1:
			appleJack += 1;
			break;
		case 2:
			twilightSparkle += 1;
			break;
		case 3:
			pinkiePie += 1;
			break;
		case 4:
			rarity += 1;
			break;
		case 5:
			rainbowDash += 1;
			break;
		case 6:
			flutterShy += 1;
			break;
	}
	
	// QUESTION TEN
	cout <<"\n°❀⋆.ೃ࿔*:･ QUESTION TEN :*࿔:ೃ.･⋆❀°\n" << endl;
	cout << setw(5) << right << ' ' << "What is your favorite color! \n";  
	cout << setw(10) << "1.) " << "Iridescent \n";		//Rarity
	cout << setw(10) << "2.) " << "ALL of them \n";		//Pinkiepie
	cout << setw(10) << "3.) " << "Pastels \n";			//Fluttershy
	cout << setw(10) << "4.) " << "Dark, cozy \n";		//Twilight
	cout << setw(10) << "5.) " << "NEON \n";			//Rainbowdash
	cout << setw(10) << "6.) " << "idk orange ig \n";	//Applejack
	cout << "\n[PLEASE ENTER AN INTEGER CORRESPONDING TO YOUR CHOICE] --> ";
	cin >> choice;
	
	switch(choice){ 				// EVERY SWITCH STATEMENT INCREMENTALLY ADDS 1 EACH TIME CHOSEN
		case 1:
			rarity += 1;
			break;
		case 2:
			pinkiePie += 1;
			break;
		case 3:
			flutterShy += 1;
			break;
		case 4:
			twilightSparkle += 1;
			break;
		case 5:
			rainbowDash += 1;
			break;
		case 6:
			appleJack += 1;
			break;
	}
	
	cout << "\n+" << border << "+" << endl;		//Results screen -- the integer variable shows the amount of times the character was selected
	cout << setw(20) << "RESULTS\n";
	cout << "Twilight Sparkle --> " << twilightSparkle << endl;
	cout << "Rainbow Dash     --> " << rainbowDash << endl;
	cout << "Pinkie Pie       --> " << pinkiePie << endl;   
	cout << "AppleJack        --> " << appleJack << endl;
	cout << "Rarity           --> " << rarity << endl;
	cout << "Fluttershy       --> " << flutterShy << endl;
	cout << "\n+" << border << "+" << endl;
	
	//if statements for FINAL RESULT ... using the logical AND to ensure the pony is either greater than or NOT greater than the rest 
	// LOGICAL AND ADDED FOR EACH POSSIBILITY 
	if(twilightSparkle > rainbowDash && twilightSparkle > pinkiePie && twilightSparkle > appleJack && twilightSparkle > rarity && twilightSparkle> flutterShy){  
		winner = "Twilight Sparkle";
		
		}else if(rainbowDash > twilightSparkle && rainbowDash > pinkiePie && rainbowDash > appleJack && rainbowDash > rarity && rainbowDash > flutterShy){
			winner = "Rainbow Dash";
		
		}else if(pinkiePie > rainbowDash && pinkiePie > twilightSparkle && pinkiePie > appleJack && pinkiePie > rarity && pinkiePie > flutterShy){
			winner = "Pinkie Pie";
		
		}else if(appleJack > rainbowDash && appleJack > pinkiePie && appleJack > twilightSparkle && appleJack > rarity && appleJack > flutterShy){
			winner = "Applejack";
		
		}else if(rarity > rainbowDash && rarity > pinkiePie && rarity > appleJack && rarity > twilightSparkle && rarity > flutterShy){
			winner = "Rarity";
		
		}else if(flutterShy > rainbowDash && flutterShy > pinkiePie && flutterShy > appleJack && flutterShy > rarity && flutterShy > twilightSparkle){
			winner = "Fluttershy";
		
		}else{					// If more than one pony have the same value, Null is assigned and given to the if statement below 
			winner = "Null";
		}
		
	if(winner != "Null"){		// If pony is assigned a name, the good ending plays   
		cout << "\n⋆✴︎˚｡⋆࣪ ִֶָ☾. Your pony is " << winner << "!" << endl;
		
		}else if(winner == "Null"){			// If pony is assigned Null the evil ending plays
			cout << "\n Hello I dont know what kind of pony are sorry!" << endl;
		}
 
	cout << "\n+" << border << "+" << endl;	  // FINAL BORDER
	
	return 0;
}