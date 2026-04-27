/*
    Author      : Grace Brown
    Created     : 16 April 2026
    Last Edited : 26 April 2026
    File Name   : functions.cpp
    Purpose     : 
*/


#include "Prog5.h"

/*
	Function: enterHeroes()
	Purpose:  Returns new updated number of heroes
			 after user inputs info of their new hero
	
*/
int enterHeroes(int max, int numHeroes , Heroes* heroList)
{
	ifstream inputFile;
	string filename, data;
	int choice;
	int numHeroesFromFile=0;
	
	if(max == numHeroes){	//if number of heroes is equal to the max, returns the number and quits function
		cout << "Sorry! Your complex can only hold " << max << " heroes!\n"
			 << "You cannot add more!\n";
		return numHeroes;
	}

	cout << "What do you want to do?\n"
		 << setw(5) << "1.)" << " Load the heroes from a file\n"
		 << setw(5) << "2.)" << " Enter a hero manually\n"
		 << setw(5) << "Choose" << " 1 or 2\n"
		 << "CHOICE: ";
	cin >> choice;

	while(!cin || (choice > 2 || choice < 1)){	//user validation
		cin.clear();
		cin.ignore();

		cout << "Please enter a valid option!\n"
			 << "CHOICE: ";
		cin >> choice;
	}
	cin.ignore(100, '\n');
	
		switch (choice)
		{
			case 1: //Load heroes from a file
			
					cout << "What is the name of the file with your list of superheroes? (ex: filename.txt)\n";
					cout << "FILENAME:  ";
					getline(cin,filename);
					cout << endl;
					
					inputFile.open(filename, ios::in);
					
					if(!inputFile)
					{
						cout << filename << " does not exist or is corrupt.  Sorry.  Can't load heroes.\n";
						cout << endl << numHeroesFromFile << " heroes from " << filename << " have been added to your condo"; 
						return numHeroes;
					}
					//load heroes from file	
										
					while(getline(inputFile, data, '#') && numHeroes < max) 
					{
						heroList[numHeroes].name = data;
						getline(inputFile, heroList[numHeroes].description, '#');
						getline(inputFile, data, '#');
						heroList[numHeroes].dangerous = stoi(data);
						getline(inputFile, data, '#');
						heroList[numHeroes].rentPrice = stof(data);
						getline(inputFile, data, '#');
						heroList[numHeroes].damageCost = stof(data);
						getline(inputFile, data, '#');
						heroList[numHeroes].numYears = stof(data);
						//increment current num heroes in array				
						numHeroes++;
						//increment num heroes read in from the file
						numHeroesFromFile++;			
					}
					inputFile.close();
					inputFile.clear();
					
					cout << endl << numHeroesFromFile << " heroes from " << filename << " have been added to your condo complex.\n";
					break;
					
			case 2: //enter one hero manually
					
					//YOU HAVE TO FINISH THIS CASE - allow user to add a hero one at a time from keyboard until they want to stop
					do{
						char tempChar;

						cout << "SUPERHERO NAME: ";
						getline(cin, heroList[numHeroes].name);
						
						cout << "DESCRIPTION: ";
						getline(cin, heroList[numHeroes].description);

						cout << "\nARE THEY DANGEROUS? (y/n): ";
						cin >> tempChar;
						tempChar = toupper(tempChar);
						while(!cin || (tempChar != 'Y' && tempChar != 'N')){
							cin.clear();
							cin.ignore(100, '\n');
							cout << "Please enter a valid option! (y/n): ";
							cin >> tempChar;
							tempChar = toupper(tempChar);
						}
						cin.ignore();
						if(tempChar == 'Y'){
							heroList[numHeroes].dangerous = true;
						}else{
							heroList[numHeroes].dangerous = false;
						}

						cout << "\nHow much does " << heroList[numHeroes].name << " pay for rent per month?\n"
							 << "RENT PRICE: ";
						cin >> heroList[numHeroes].rentPrice;
						while(!cin || heroList[numHeroes].rentPrice < 0){
							cin.clear();
							cin.ignore(100, '\n');
							cout << "Please enter a valid price: ";
							cin >> heroList[numHeroes].rentPrice;
						}
						cin.ignore();

						cout << "What is the typical cost of damage " << heroList[numHeroes].name << " has each month?\n"
							 << "DAMAGE COST: ";
						cin >> heroList[numHeroes].damageCost;
						while(!cin || heroList[numHeroes].damageCost < 0){
							cin.clear();
							cin.ignore();
							cout << "Please enter a valid option: ";
							cin >> heroList[numHeroes].damageCost;
						}
						cin.ignore();

						cout << "How many years has " << heroList[numHeroes].name << " lived in your condo?\n"
							 << "YEARS: ";
						cin >> heroList[numHeroes].numYears;
						while(!cin || heroList[numHeroes].numYears < 0){
							cin.clear();
							cin.ignore();
							cout << "Please enter a valid option: ";
							cin >> heroList[numHeroes].numYears;
						}
						cin.ignore();

						cout << heroList[numHeroes].name << " has been added!\n"
							 << "\nWant to add more heroes?\n1.) Yes\n2.) No\nCHOICE: ";
						cin >> choice;
						while(!cin || (choice < 1 || choice > 2)){
							cin.clear();
							cin.ignore(100, '\n');
							cout << "Please enter a valid option: ";
							cin >> choice;
						}
						numHeroes++;
					}while(choice == 1);
					break;	
		} //end of switch		
	return numHeroes;
}

/*
	Function: 
	Purpose:  
	
*/
int deleteHero(int numHero, Heroes* heroArray, int& homelanderStatus){
	int choice, heroIndex;
	string matchedHero;

	cout << "\nHere are all your heroes:\n";
	for(int i = 0 ; i < numHero ; i++){
		cout << i + 1 << ".) "<< heroArray[i].name << "\n";
	}
	cout << "\nWhich hero are you Evicting? You Cannot Evict Homelander.\n"	//it is a sunday night. I thought this program was due on wednesday. No offense but i dont have time to make a string matching loop sobbing emoji
		 << "CHOICE: ";
	cin >> choice;
	while(!cin || (choice <= 0 || choice > numHero)){
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Please enter a valid choice: ";
		cin >> choice;
	}
	cin.ignore();

	heroIndex = choice - 1;

	if(heroArray[heroIndex].name == "Homelander"){	//consequences for removing homelander
		homelanderStatus = 1;
		return numHero;
	}

	for(int i = 0; i < numHero; i++){
		if(heroIndex == i){
			matchedHero = heroArray[i].name;
			break;
		}
	}

	if(moveArrayElements(matchedHero, numHero, heroArray) == true){
		numHero--;
		cout << "\n" << matchedHero << " has been Evicted\n";
	}else{
		cout << "\n" << matchedHero << " could NOT be evicted.\n";
	}

	return numHero;
}

/*
	Function: 
	Purpose:  
	
*/
bool moveArrayElements(string name, int numHero, Heroes*& heroArray){
	Heroes *tempArray;
	tempArray = new Heroes[numHero];

	for(int i = 0; i < numHero; i++){
		tempArray[i] = heroArray[i];
	}
	delete [] heroArray;	//frees heroArray for relisting
	heroArray = new Heroes[numHero - 1]; //reallocated hero array

	for(int i = 0; i < numHero ; i++){
		if(name == tempArray[i].name){
			int k = 0;
			for(int j = 0; j < numHero; j++){
				if(i == j){
					continue;
				}else{
					heroArray[k] = tempArray[j];
					k++;
				}
			}
			delete [] tempArray;
			return true;
		}
	}
	return false;
}

/*
	Function: 
	Purpose:  
	
*/
void printHeroes(int numHero, Heroes* heroArray){
	for(int i = 0; i < numHero ; i++){
		string yesNo;
		if(heroArray[i].dangerous == true){
			yesNo = "Yes";
		}else{
			yesNo = "No";
		}

		cout << "\n. . • ☆ . ° .• °:. *₊ ° . ☆. . • ☆ . ° .• °:. *₊ ° . ☆\n"
			 << "HERO " << i + 1 << ":\n"
			 << "\nNAME:" << setw(10) << heroArray[i].name << "\n"
			 << "DESC:" << setw(10) << heroArray[i].description << "\n"
			 << "DANGEROUS:" << setw(6) << yesNo << "\n"
			 << "RENT:" << setw(10) << "$" << heroArray[i].rentPrice << "\n"
			 << "DAMAGE COST:" << setw(4) << "$" << heroArray[i].damageCost << "\n"
			 << "YEARS:" << setw(9) << heroArray[i].numYears << "\n";
	}
		cout << "\n. . • ☆ . ° .• °:. *₊ ° . ☆. . • ☆ . ° .• °:. *₊ ° . ☆\n";
}

/*
	Function: 
	Purpose:  
	
*/
void printRentDetails(int numHero, Heroes* heroArray){
	string borderLine(50, '-');
	double totalPrice = 0;
	double totalDamage = 0;

	cout << fixed << setprecision(2); //for the decimal points

	cout << "\nRENT DETAILS OF EACH HERO:\n" << endl
		 << left << setw(20) << "SUPERHERO" << right << setw(15) << "MONTHLY" << " RENT" << right << setw(15) << "DAMAGE" << " COST" << endl;
	
	for(int i = 0; i < numHero; i++){

		cout << left << setw(20) << heroArray[i].name << " $"
			 << right << setw(10) << heroArray[i].rentPrice << " $"
			 << right << setw(10) << heroArray[i].damageCost << "\n";
		totalPrice += heroArray[i].rentPrice;
		totalDamage += heroArray[i].damageCost;
	}
	cout << borderLine << "\n" << endl
		 << left << setw(20) << "TOTALS:" << " $"
		 << right << setw(10) << totalPrice << " $"
		 << right << setw(10) << totalDamage << "\n";
}

/*
	Function: 
	Purpose:  
	
*/
void saveToFile(int numHero, Heroes* heroArray){
	ofstream heroFile;
	char choice;
	string filename;
	cout << "Would you like to save your Superheroes to a file? (y/n)\n" 
		 << "CHOICE: ";
	cin >> choice;
	choice = toupper(choice);
	while(!cin || (choice != 'Y' && choice != 'N')){
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Please enter a VALID choice: ";
		cin >> choice;
		choice = toupper(choice);
	}
	cin.ignore();

	if(choice == 'Y'){
		cout << "\nWhat is the name of the file you want to save your Heroes to?\n"
			 << "FILENAME (NO EXTENSION!): ";
		getline(cin, filename);
		for(int i = 0; i < filename.length() ; i++){
			if(filename[i] == ' '){
				filename[i] = '_';
			}
		}
		filename += ".txt";

		heroFile.open(filename);
		
		for(int i = 0; i < numHero; i++){
			heroFile << heroArray[i].name << "#" 
				 	 << heroArray[i].description << "#"
					 << heroArray[i].dangerous << "#"
					 << heroArray[i].rentPrice << "#"
					 << heroArray[i].damageCost << "#"
					 << heroArray[i].numYears << "#";
		}

		cout << "\nYour Heroes were succesfully saved to " << filename << "!\n";
	}else{
		cout << "\nYour Heroes were not saved!\n";
	}
	heroFile.close();
}
