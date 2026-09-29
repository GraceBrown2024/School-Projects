/*
	Filename: lab5.cpp
	Author: April Crockett and PUT YOUR NAME HERE
	Date: 9/27/2026
	Purpose: Practice with vectors
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

////*********************LOOK! Add function prototypes here




int main() {

	string temp;
	int rate;
	//*********************LOOK! Create activities vector (should be a string vector)
    
	
	//*********************LOOK! Create rating vector (should be a int vector)
    
	

	//Tell user what is going on (give instructions)
	cout << "\n\nWelcome to Crockett Farms Pumpkin Festival!\n";
	cout << "Please enter each activity you did at the festival and score the activities.\n";
	cout << "\nThen, rate the activity from 1 to 100 where 1 means the activity was buns \n"
		     << "and 100 means it was your favorite activity you have ever done in your life.";
	cout << "\n\nEnter \"done\" to quit entering activities.\n\n";
	
	//Begin getting the activities from the user.
	cout << "Activity: ";
	getline(cin, temp);
	while(temp != "done"){
		//*********************LOOK! Add activity to the end of the activities vector
		
		cout << "\nRating: ";
		cin >> rate;
		cin.ignore();
		
		//*********************LOOK! Add rate to the end of the rating vector
		
		
		cout << "\nActivity: ";
		getline(cin, temp);
	}
	
	//Print the full list of activities
    cout << "\n\nActivities Entered:";
    printActivities(activities, rating);

    // Sort the parallel vectors by rating
    selectionSort(activities, rating);

    cout << "\nActivities Sorted by Rating:";
    printActivities(activities, rating);

    return 0;
}

//*********************LOOK! Complete the printActivities function
// Print all activities and popularity scores
void printActivities() {
	cout << "\n\nFall Activities:\n";
    cout << "---------------\n";

}

//*********************LOOK! Write the selectionSort function
// Make sure to use the sort function (from the algorithm library) when you have to swap elements
// Sort activities from highest popularity to lowest popularity
void selectionSort() {

}