#include "Prog5.h"

/*
	Function: enterHeroes()
	Purpose:  YOU NEED TO FILL THIS OUT
	
*/
int enterHeroes(int max, int numHeroes , Heroes* heroList)
{
	int numHeroesFromFile=0;
	//there is code that you have to add right here
	//make sure not already at capacity
	//give user the enterheroes menu items, get their choice & validate their choice
	
		switch (choice)
		{
			case 1: //Load heroes from a file
			
					cout << "What is the name of the file with your list of superheroes? (ex: filename.txt)\n";
					cin.ignore();
					cout << "FILENAME:  ";
					getline(cin,filename);
					cout << endl;
					
					inputFile.open(filename, ios::in);
					
					if(!inputFile)
					{
						cout << filename << " does not exist or is corrupt.  Sorry.  Can't load heroes.\n";
						cout << endl << numHeroesFromFile << " heroes from " << filename << " have been added to your condo 
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
	
					break;
					
		} //end of switch		

	
	return numHeroes;
}