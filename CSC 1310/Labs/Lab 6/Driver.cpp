/********************************************************
	Title:  		Driver.cpp (given)
	Date Created:	10-4-2026
	Date Updated:
	Authors: 		April Crockett and Grace Brown
	
	Purpose:		To demonstrate a Linked List of Spotify
					Music Tracks
*********************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>
#include <limits>
#include <list>

#include "LinkedList.h"
#include "Track.h"
using namespace std;

vector<string> parseCSVLine(string);

int main()
{
	//!!!!!     LOOK     !!!!! Create the LinkedList object (and call it list)
	list<int> list;
	
	
	ifstream inFile;
	string line;
	string track_id,artist,album_name,track_name,track_genre;
	int popularity, num;
	bool expl;
	char yesno;
	vector<string> fields;
	
	cout << "\n\nReading from the dataset.csv file and adding Spotify Tracks to Linked List\n";
	inFile.open("dataset.csv");
	if(!inFile.is_open()) {
		cout << "\nUnable to read from dataset.csv.\n\n";
		return 1;
	}
	getline(inFile, line); //read whole first line with headers & "throw away"
	
	//read the rest of the lines
	while (getline(inFile, line)) {

		fields = parseCSVLine(line);
		num 		 = stoi(fields[0]);
		track_id     = fields[1];
		artist       = fields[2];
		album_name   = fields[3];
		track_name   = fields[4];
		popularity   = stoi(fields[5]);
		expl         = (fields[7] != "FALSE");
		track_genre  = fields[20];

		//only un-comment out when troubleshooting your code
		//cout << "Num: " << num << endl;
		
		//!!!!!     LOOK     !!!!! now create the Track object
		
		
		//!!!!!     LOOK     !!!!! now append to linked list
		
	}
			
	cout << "\nThe list now has " << list.getLength() << " nodes with Spotify Music Tracks.\n";
	
	do{
		cout << "\nWhich Spotify Music Track would you like to display?\n";
		cout << "Enter 0 through " << (list.getLength()-1) << ":  ";
		cin >> num;
		
		//validate user input
		while(!cin || num < 0 || num > (list.getLength()-1)){
			cin.clear();
			//ignore (remove) everything in the keyboard buffer up through '\n' or EOF - whichever comes first
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "\nInvalid Input. Enter 0 through " << (list.getLength()-1) << ":  ";
			cin >> num;
		}
		
		//!!!!!     LOOK     !!!!! now call the displayNode() function for the list object
		
	
		cout << "\n\nDisplay another? Enter y or n:  ";
		cin >> yesno;
		
		//validate user input
		while(!cin || (tolower(yesno) != 'y' && tolower(yesno) != 'n')){
			cin.clear();
			//ignore (remove) everything in the keyboard buffer up through '\n' or EOF - whichever comes first
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "\nInvalid input. Enter y or n:  ";
			cin >> yesno;
		}
	}while(tolower(yesno) == 'y');
	
	return 0;
}

/*
	Function: 	parseCSVLine()
	Purpose: 	This function parses a single line of CSV data and 
				returns a vector containing each field.
				This funciton correctly handles commas that appear inside
				double quotes by ignoring them as separators.
				
	Parameter: 	line - a string containing one full line from a CSV file
	Returns: 	A vector<string> containing each parsed field
*/
vector<string> parseCSVLine(string line) {
    vector<string> fields; 
    string current;  
	char c;
    bool inQuotes = false; // tracks whether we are inside double quotes

    // Loop using an index of vector
    for (unsigned int i=0; i < line.length(); i++) {
		
		c = line[i]; //get current character from string
		
        if (c == '"')  // If we encounter a double quote, flag the inQuotes flag
            inQuotes = !inQuotes;  

        else if (c == ',' && !inQuotes) { // If we see a comma AND we are not inside quotes, this marks the end of a field
            fields.push_back(current);
            current.clear();
        }
		
        else  // Otherwise, add character to current field
            current += c;
    }
	// Push the last field (no trailing comma to trigger it)
    fields.push_back(current);
	
    return fields;
}