/*********************************************************************
	Filename:	Driver.cpp
	Author:		April Crockett
	Date:		August 25, 2026
	Purpose:	Driver containing main function for Program 1 in
				CSC 1310 practicing Classes & Objects
				
	DO NOT MODIFY THIS FILE!!!
	
**********************************************************************/

#include "Theater.h"
#include <iostream>
#include <limits>
#include <string>
using namespace std;

int main(){
	//variable definitions
    string theaterName;
    int maxMovieCapacity;
    int maxShowingCapacity;
	int choice = 0;
	string filename;

	//get beginning details from the user
    cout << "\n\nWelcome to the Movie Theater Management System!\n\n";
    cout << "What is the name of your theater? ";
    getline(cin, theaterName);
    cout << "Maximum number of movies: ";
    cin >> maxMovieCapacity;
	
	//validate user input
	while(!cin || maxMovieCapacity < 1){
		if(!cin)
			cout << "\nOops! Wrong data type.\n";
		else
			cout << "\nOops! You didn't enter a number greater than 0.\n";
		cout << "Maximum number of movies: ";
		cin >> maxMovieCapacity;
	}
	
    cout << "Maximum number of showings: ";
    cin >> maxShowingCapacity;
	//validate user input
	while(!cin || maxShowingCapacity < 1){
		if(!cin)
			cout << "\nOops! Wrong data type.\n";
		else
			cout << "\nOops! You didn't enter a number greater than 0.\n";
		cout << "Maximum number of showings: ";
		cin >> maxShowingCapacity;
	}
    
	//create Theater object
	Theater theater(theaterName, maxMovieCapacity, maxShowingCapacity);

    do{
		//display menu of options to user
        cout << "\nWhat would you like to do?\n";
        cout << "  1. Add One Movie\n";
        cout << "  2. Edit One Movie\n";
        cout << "  3. Add One Showing\n";
        cout << "  4. Edit One Showing\n";
        cout << "  5. Print All Movies\n";
        cout << "  6. Print All Showings\n";
        cout << "  7. Quit\n";
        cout << "CHOOSE 1-7: ";
        cin >> choice;
		
		//validate user's choice
		while(!cin || choice < 1 || choice > 7){
			if(!cin)
				cout << "\nOops! Wrong data type.\n";
			else
				cout << "\nOops! You didn't enter a number in the valid range.\n";
			cout << "Enter 1-7: ";
			cin >> choice;
		}

		//execute user's choice
        switch(choice){
			case 1:
				theater.addMovie();
				break;
			case 2:
			    theater.editMovie();
				break;
			case 3:
				theater.addShowing();
				break;
			case 4:
				theater.editShowing();
				break;
			case 5:
				theater.printMovies();
				break;
			case 6:
				theater.printShowings();
				break;
        }
	}while(choice != 7);

	//End the program
    cout << "\nClosing the theater program.\n";
    return 0;
}
