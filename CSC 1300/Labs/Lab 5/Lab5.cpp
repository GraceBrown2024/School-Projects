/****************************
* Name       : Grace Brown  *
* Last Edited: 2 March 2026 *
* File Name  : Lab5.cpp     *
* Purpose    : Battle sim   *
****************************/

#include <cstdlib>
#include <iostream>
#include <string>
#include <ctime>
#include <cctype>
using namespace std;

int main(){
	
	/*CONCEPT : INCEL DUEL!
		 You are at an anime convention
		 You are wearing a poorly made cosplay of your favorite anime character
		 You find another person ALSO wearing a cosplay of the SAME CHARACTER
		 You have to fight -- NERD STYLE -- to determine who TRULY deserves to embody the character
		 */

		string name, cosplayChar, catchPhrase, border(50, '-'), prop;
		int playerHealth, enemyHealth, playerDamage, enemyDamage, menuChoice, rageMultiplierPlayer, rageMultiplierEnemy, defense, turn = 0, randnum, enemyDamageDisplay;
		char yesNo;
		bool propBool, rageBoolPlayer, rageBoolEnemy;

	do{ // Allows replay at very end
		randnum = rand() % 5 + 1;

		//Determines your signature catchphrase. These are all very good. Used on a random generator for Rummage
		if(randnum == 1){ 
			catchPhrase = "Booper Dooper!";
		}else if(randnum == 2){
			catchPhrase = "Little Booty Pooty Tooty!";
		}else if(randnum == 3){
			catchPhrase = "You just got Banned!";
		}else if (randnum == 4){
			catchPhrase = "Was that the bite of 87?!";	
		}else{
			catchPhrase = "You just got #owned!";
		}


		srand(time(0)); 
		//Ascii Art -- Once again using this reference https://stackoverflow.com/questions/37765925/ascii-art-in-c
		cout << R"(
●・○・●・○・●・○・●・○・●・○・●・○・●・○・●・○・●・○・●・○・●・○
      _____                 _                            
     /  __ \               | |                           
     | /  \/ ___  ___ _ __ | | __ _ _   _                
     | |    / _ \/ __| '_ \| |/ _` | | | |               
     | \__/\ (_) \__ \ |_) | | (_| | |_| |               
      \____/\___/|___/ .__/|_|\__,_|\__, |               
                     | |             __/ |               
                     |_|            |___/                
 _____             _                                     
/  __ \           | |                                    
| /  \/ ___  _ __ | |_ _ __ _____   _____ _ __ ___ _   _ 
| |    / _ \| '_ \| __| '__/ _ \ \ / / _ \ '__/ __| | | |
| \__/\ (_) | | | | |_| | | (_) \ V /  __/ |  \__ \ |_| |
 \____/\___/|_| |_|\__|_|  \___/ \_/ \___|_|  |___/\__, |
                                                    __/ |
                                                   |___/ 
●・○・●・○・●・○・●・○・●・○・●・○・●・○・●・○・●・○・●・○・●・○)";

		//Story Setup ... Madlibs that determine stats and name
		cout << "\n" << border << endl 
				<< "\nYou enter the convention lobby..."
				<< "\nThere are booths beyond your scope of vision"
				<< "\nCharacters posing for pictures at every corner"
				<< "\nEverything is perfect..."
				<< "\nUntil you see them.\n"
				<< "\n" << border << "\n"
				<< "\nBut first, what is your name? --> ";
		getline(cin, name);

		do{ //Allows you to choose your name
			cout << "\nAre you sure your name is " << name << "?\n"
					<< "[Y/N] --> ";
			cin >> yesNo;
			yesNo = toupper(yesNo); //USING THE CCYTPE LIBRARY FOR THIS FUNCTION AGAIN [https://cplusplus.com/reference/cctype/] !!!!!!!

			while(cin.fail() || yesNo != 'Y' && yesNo != 'N'){ //User validation for name
				cin.clear();
				cin.ignore(100, '\n');
				cout << "\nPlease Enter a Valid Choice! --> ";
				cin >> yesNo;
				yesNo = toupper(yesNo);
			}
			cin.ignore(100, '\n');

			if(yesNo == 'N'){ //Chooses NEW name if you mistyped
				cout << "\nPlease enter your REAL name --> ";
				getline(cin, name);
			}
		}while(yesNo == 'N');

		cout << "\nNow, " << name << ", who are you cosplaying as? --> ";
		getline(cin, cosplayChar);

		do{ //Allows you to choose your cosplay character
			cout << "\n" << cosplayChar << "! Did I hear that right?\n"
				<< "[Y/N] --> ";
			cin >> yesNo;
			yesNo = toupper(yesNo);

			while(cin.fail() || yesNo != 'Y' && yesNo != 'N'){ //User validation for cosplay
				cin.clear();
				cin.ignore(100, '\n');
				cout << "\nPlease Enter a Valid Choice! --> ";
				cin >> yesNo;
				yesNo = toupper(yesNo);
			}
			cin.ignore(100, '\n');

			if(yesNo == 'N'){ //Chooses NEW cosplay if you mistyped
				cout << "\nI'm sorry! Who are you cosplaying as then? --> ";
				getline(cin, cosplayChar);
			}
		}while(yesNo == 'N');

		cout << "\n" << cosplayChar << ", SURELY you have a prop? A weapon?\n"
				<< "[Y/N] --> ";
		cin >> yesNo;
		yesNo = toupper(yesNo);

		do{ //Allows you to choose or reject a weapon
			while(cin.fail() || yesNo != 'Y' && yesNo != 'N'){ //User validation for weapon
				cin.clear();
				cin.ignore(100, '\n');
				cout << "\nPlease Enter a Valid Choice! --> ";
				cin >> yesNo;
				yesNo = toupper(yesNo);
			}
			cin.ignore(100, '\n');

			if(yesNo == 'Y'){ //Allows you to enter the name of your prop
				cout << "\nWhat is your prop?"
					 << "\n[Enter Name of Prop] --> ";
				getline(cin, prop);

				do{
					cout << "\nYour prop is " << prop << ", did I hear that right?"
							<< "\n[Y/N] --> ";
					cin >> yesNo;
					yesNo = toupper(yesNo);

					while(cin.fail() || yesNo != 'Y' && yesNo != 'N'){ //User validation for weapon
						cin.clear();
						cin.ignore(100, '\n');
						cout << "\nPlease Enter a Valid Choice! -->";
						cin >> yesNo;
						yesNo = toupper(yesNo);
					}
					cin.ignore(100, '\n');

					if(yesNo == 'N'){
						cout << "\nOh! I'm sorry, its very hard to hear in here!\n"
								<< "What is your prop? --> ";
						getline(cin, prop);
					}
					propBool = true; // If player HAS a prop, attack stats are RAISED
					playerDamage = 20; //Initializes damage points so line 275 and 276 are correct
				}while(yesNo == 'N');
			}else{
				cout << "\nAre you sure you don't have a prop?"
						<< "\n[Y/N] --> ";
				cin >> yesNo;
				yesNo = toupper(yesNo);

				while(cin.fail() || yesNo != 'Y' && yesNo != 'N'){ //User validation for weapon
						cin.clear();
						cin.ignore(100, '\n');
						cout << "\nPlease Enter a Valid Choice! -->";
						cin >> yesNo;
						yesNo = toupper(yesNo);
					}
				cin.ignore(100, '\n');

				if(yesNo == 'Y'){
					propBool = false; //If player does NOT have a prop, attack stats stay neutral at 10
					playerDamage = 10; //Initializes damage points so line 275 and 276 are correct
				}else{
					cout << "\nWhat is your prop?"
							<< "\n[Enter Name of Prop] --> ";
					getline(cin, prop);

					do{
						cout << "\nYour prop is " << prop << ", did I hear that right?"
								<< "\n[Y/N] --> ";
						cin >> yesNo;
						yesNo = toupper(yesNo);

						while(cin.fail() || yesNo != 'Y' && yesNo != 'N'){ //User validation for weapon
							cin.clear();
							cin.ignore(100, '\n');
							cout << "\nPlease Enter a Valid Choice! -->";
							cin >> yesNo;
							yesNo = toupper(yesNo);
						}
						cin.ignore(100, '\n');

						if(yesNo == 'N'){
							cout << "\nOh! I'm sorry, its very hard to hear in here!\n"
									<< "What is your prop? --> ";
							getline(cin, prop);
						}
						propBool = true; // If player HAS a prop, attack stats are RAISED (seen in do-while game loop)
						playerDamage = 20; //Initializes damage points so line 275 and 276 are correct
					}while(yesNo == 'N');
				}
			}
		}while(yesNo == 'N');

		cout << "\n[PRESS ENTER TO CONTINUE STORY]\n";
		cin.ignore(100, '\n');

		//////////////////////////////// BEGINS STORY BLOCK ////////////////////////////////////
		cout << " " << border << endl
				<< "\nAs you were walking along the convention floor..."
				<< "\nYou see Them."
				<< "\nYour doppleganger. "
				<< "\nAnother " << cosplayChar << ". But their cosplay is significantly better than yours."
				<< "\nYou cant let them mog you...\n"
				<< "\n" << border << endl
				<< "\n[PRESS ENTER TO CONTINUE]";
		cin.ignore(100, '\n');

		cout << "\n" << border << endl
				<< "\nYou approach the other " << cosplayChar << ".\n"
				<< "\nEvil " << cosplayChar << ": Hey! Nice cosplay!"
				<< "\nEvil " << cosplayChar << ": Did you buy it off of Temu?!\n"
				<< "\n[Evil " << cosplayChar << " laughs and high fives their friends.]\n"
				<< "\n[PRESS ENTER TO CONTINUE]\n";
		cin.ignore(100, '\n');

		cout << "\n" << border << endl
				<< "\nYour face turns red as your clench your fist in rage...\n"
				<< "\n" << name << ": N-No!! I made it with my mom..."
				<< "\n" << name << ": It's made with love and dedication. You wouldn't get it...\n"
				<< "\n[Evil " << cosplayChar << " steps closer, nearly nose to nose with you]\n"
				<< "\nEvil " << cosplayChar << ": What's that supposed to mean, CHUD?\n"
				<< "\n[Evil " << cosplayChar << " flashes their homemade prop and hits you in the knees]\n"
				<< "\n[PRESS ENTER TO CONTINUE]\n";
		cin.ignore(100, '\n');

		cout << "\n" << border << endl
				<< "\nYou fall to the ground and groan. Your counterpart is mocking you."
				<< "\nSlowly, you get up and stand up straight. They are still laughing.\n"
				<< "\n[PRESS ENTER TO CONTINUE]\n";
		cin.ignore(100, '\n');

		cout << "\n" << border << endl
				<< "\n" << name << ": You know what? I won't stand for this...\n"
				<< name << ": I challenge you.. to a DUEL\n"
				<< "\n[Evil " << cosplayChar << " and their friends stop laughing]\n"
				<< "\nEvil " << cosplayChar << ": Okay then. show me what you got.\n"
				<< "\nEvil " << cosplayChar << ": But if I win, you have to strip your cosplay for the rest of the convention.\n"
				<< "\n[PRESS ENTER TO CONTINUE]";
		cin.ignore(100, '\n');
		////////////////////////////////////// STORY BLOCK END ///////////////////////////////////////

		enemyDamageDisplay = rand() % 11 + 10; //Randomizes enemy stats from 10 - 20
		enemyHealth = enemyDamageDisplay * 3.5; //Balances enemy damage and health



		playerHealth = playerDamage * 3.5; //Balances enemy health and damage (potential for 20 or 40)


		cout << "\n" << border << endl // Stats for both characters
				<< "\n┌────── ⋆⋅☆⋅⋆ ──────┐"
				<< "\n|    -- STATS --    |"
				<< "\n| ★  • • • • • •  ★ |"
				<< "\n| You --            |"
				<< "\n|     HEALTH: " << playerHealth << "    |"
				<< "\n|     ATTACK: " << playerDamage << "    |"
				<< "\n| ★  • • • • • •  ★ |"
				<< "\n| Enemy --          |"
				<< "\n|     HEALTH: " << enemyHealth << "    |"
				<< "\n|     ATTACK: " << enemyDamageDisplay << "    |"
				<< "\n└────── ⋆⋅☆⋅⋆ ──────┘\n";

		//DO WHILE GAME LOOP -- Players will continue until one of them die
		do{
			enemyDamage = enemyDamageDisplay; //Reinitializes damage in case either player chose to defend (defense temporarily reduces damage)
			if(propBool == true){
				playerDamage = 20;
			}else if(propBool == false){
				playerDamage = 10;
			}

			cout << "\n[PRESS ENTER FOR TURN " << ++turn << "]";
			cin.ignore(100, '\n');

			cout << "\n" << border << endl
					<< "\n•°. *࿐ YOUR TURN\n"
					<< "\n╔───────────────────────╗"
					<< "\n|   WHAT WILL YOU DO?   |"
					<< "\n|-----------------------|"
					<< "\n| 1.) Attack            |"
					<< "\n| 2.) Defend            |"
					<< "\n| 3.) Rummage Bag       |" // This one offers a randomizer for a boost
					<< "\n| 4.) Give Up           |" // Automatically sets player health to 0
					<< "\n╚───────────────────────╝\n"
					<< "\n Enter Choice Here --> ";
			cin >> menuChoice;

			//user validation
			while(cin.fail() || menuChoice < 1 || menuChoice > 4){
				if(cin.fail()){
					cout << "\nPlease enter a NUMBER! --> ";
				}else{
					cout << "\nPlease enter a value in range! --> ";
				}
				cin.clear();
				cin.ignore(100, '\n');

				cin >> menuChoice;
			}
			cin.ignore(100, '\n');

			//switch case for choices
			switch(menuChoice){
				case 1: //Case for ATTACK
				if(rageBoolPlayer == true){
					playerDamage = rageMultiplierPlayer;
				}
					if(randnum == 2){
						playerDamage -= defense;
						cout << "\nYou tried to land a massive attack on your doppleganger, but tripped!"
								<< "\nYou only managed to bump into them, taking " << playerDamage << " health from them!" << endl;
					}else{
						cout << "\nYou ATTACKED Evil " << cosplayChar << " for " << playerDamage << " health!\n";
					}
					enemyHealth -= playerDamage; // Subtracts players attack points from the enemy's current health
					rageBoolPlayer = false;
					break;
				case 2: //Case for DEFEND (blocks enemy attack to an extent for one round)
					defense = (enemyDamage * 1.75) - enemyDamage ; //formula I made up to defend in case enemy attacks. Pretty sure it works.

					cout << "\nYou DENFENDED against Evil " << cosplayChar << "!" << endl;
					rageBoolPlayer = false; //ensures the rageBool resets to false after it is used
					break;
				case 3: //Case for RUMMAGE (random chance for power up)
					randnum = rand() % 3 + 1;
					if(randnum == 1){ //SIGNATURE CATCH PHRASE!!! 
						cout << "\nYou find nothing in your bag..."
							 << "\nBUT You use your signature catch phrase:\n"
							 << "\n\"" << catchPhrase << "\"\n" << endl
							 << "... Nothing else happens\n";
						rageBoolPlayer = false;

					}else if(randnum == 2){
						cout << "\nYou look through your bag and find a bottle of Mountain Dew"
							 << "\nDrinking it, you feel healed..."
							 << "\nYOUR HEALTH INCREASED 10 POINTS!\n";
						playerHealth += 10; // Adds ten points total to the players HP
						rageBoolPlayer = false;
						
					}else{
						cout << "\nYou take a quick Reddit break"
							 << "\nYou notice you got a comment on your recent meme\n"
							 << "\n\"ElonBaby69 commented on your post: L meme enjoy your downvote lol.\"\n"
							 << "\nThis ENRAGES you! Your Attack INCREASED for next round!";
						rageMultiplierPlayer = (playerDamage * 1.75) + playerDamage; //Formula similar to Defene except ADDS damage instead of removes
						playerDamage = rageMultiplierPlayer;
						rageBoolPlayer = true; //SETS RAGE TO TRUE TO USE FOR NEXT ROUND ONLY!
					}
					break;
			}
			if(enemyHealth <= 0){
				enemyHealth = 0;
				
			}else{ // added to ensure turn doesnt play if enemy has died
				//Display results of choice
				cout << "\nEvil " << cosplayChar << " now has " << enemyHealth << " health!\n"
						<< "\n[PRESS ENTER FOR ENEMY TURN]\n";
				cin.ignore(100, '\n');

				cout << "\n" << border << endl
						<< "\n •°. *࿐ ENEMY TURN \n";

				//Enemy Turn
				randnum = rand() % 4 + 1;

				if(randnum == 1 || randnum == 4){ //ATTACK
					if(rageBoolEnemy == true){
						enemyDamage = rageMultiplierEnemy;
					}
						if(menuChoice == 2){
							enemyDamage -= defense; //subtracts the defense number (menu choice 2) from the enemy's initial attack points
							cout << "\nEvil " << cosplayChar << " slipped and barely scratched you!";
						}
						cout << "\nEvil " << cosplayChar << " attacked you with their prop for " << enemyDamage << " of your health!";
					
						playerHealth -= enemyDamage; // Subtracts enemy's current damage from players current health
					rageBoolEnemy = false; //RESETS RAGE BOOL 
				}else if(randnum == 2){
					//DEFEND FOR ONE ROUND
						defense = (playerDamage * 1.75) - playerDamage ; //formula from above
						cout << "\nEvil " << cosplayChar << " DENFENDED against you!";
						rageBoolEnemy = false; //RESETS RAGE BOOL
				}else{ //RANDOM CHANCE FOR POWERUP
					randnum = rand() % 3 + 1;

					if(randnum == 1){ //Does NOTHING
						cout << "\nEvil " << cosplayChar << " looked through their bag and found unused deodorant..."
							 << "\nThey sigh and move on. Nothing happened.\n";
						rageBoolEnemy = false;	 //RESETS RAGE BOOL

					}else if(randnum == 2){ //Increases HEALTH
						cout << "\nEvil " << cosplayChar << " looked through their bag and found some Doritos!"
							 << "\nThey eat the whole bag instantly. THEIR HEALTH RAISED 10 POINTS!\n";
						enemyHealth += 10; //adds ten total points to enemy health
						cout << "They now have " << enemyHealth << " health!\n";
						rageBoolEnemy = false; // RESETS RAGE BOOL

					}else{ //adds RAGE MULTIPLIER
						cout << "\nEvil " << cosplayChar << " gets a Discord notification:\n"
							 << "\nSide Kitten: \"I think I want to break up... uwu\"\n"
							 << "\nEvil " << cosplayChar << " is ENRAGED! ATTACK INCREASED NEXT ROUND!\n";
						rageMultiplierEnemy = (enemyDamage * 1.75) + enemyDamage; //forumla similar, but opposite effect, of the defense
						enemyDamage = rageMultiplierEnemy;
						rageBoolEnemy = true; //ENFORCES RAGE BOOL
					}
				} 
				//Display results of enemy turn
				cout << "\nYou now have " << playerHealth << " health!\n";

				if(playerHealth <= 0){
					playerHealth = 0; //Reinitilized player health if it reaches below zero -- cuts to death sequence if so
				} 
			}

		// KEEP LOOPING UNTIL DEATH OR QUIT
		}while(playerHealth > 0 && enemyHealth > 0);

		if(playerHealth <= 0){ //Death Sequence for player
			cout << "\n" << border << endl
					<< "\nEvil " << cosplayChar << " swiped your feet and pinned you down.\n"
					<< "\nEvil " << cosplayChar << ": I win...\n";

			cout << "\n" << border << endl
					<< "\n┌──────────────────┐"
					<< "\n|     YOU DIED     |"
					<< "\n|------------------|"
					<< "\n|    You've been   |"
					<< "\n|     STRIPPED     |"
					<< "\n|  of your cosplay |"
					<< "\n|------------------|"
					<< "\n|    PLAY AGAIN?   |"
					<< "\n|       [Y/N]      |"
					<< "\n└──────────────────┘\n";
			cin >> yesNo;
			yesNo = toupper(yesNo);
			while(cin.fail() || yesNo != 'Y' && yesNo != 'N'){ //User validation for replay
				cin.clear();
				cin.ignore(100, '\n');
				cout << "\nPlease Enter a Valid Choice! --> ";
				cin >> yesNo;
				yesNo = toupper(yesNo);
			}
			cin.ignore(100, '\n');

		}else if(enemyHealth <= 0){ //Death Sequence for Enemy
			cout << "\n" << border << endl
					<< "\nYou kicked the prop out of your evil twin's hands..."
					<< "\nTriumphent, you take their prop and snap it in half.\n"
					<< "\nThe victor is clear!";
			
			cout << "\n" << border << endl
					<< "\n┌──────────────────┐"
					<< "\n|     YOU WIN!     |"
					<< "\n|------------------|"
					<< "\n|    Your ENEMY    |"
					<< "\n|     has been     |"
					<< "\n|     STRIPPED     |" 
					<< "\n| of their cosplay |"
					<< "\n|------------------|"
					<< "\n|    PLAY AGAIN?   |"
					<< "\n|       [Y/N]      |"
					<< "\n└──────────────────┘\n";
			cin >> yesNo;
			yesNo = toupper(yesNo);
			while(cin.fail() || yesNo != 'Y' && yesNo != 'N'){ //User validation for replay
				cin.clear();
				cin.ignore(100, '\n');
				cout << "\nPlease Enter a Valid Choice! --> ";
				cin >> yesNo;
				yesNo = toupper(yesNo);
			}
			cin.ignore(100, '\n');
		}
	}while(yesNo == 'Y');	 
	return 0;
}
	