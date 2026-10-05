/*
	Filename: lab5.cpp
	Author: April Crockett and Grace Brown
	Date: 9/27/2026
	Purpose: Practice with vectors
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void printActivities(vector<string> activities, vector<int> rating);
void selectionSort(vector<string>  activities, vector<int> rating);


int main() {

	string temp;
	int rate;
	//*********************LOOK! Create activities vector (should be a string vector)
    vector<string> activities;
	
	//*********************LOOK! Create rating vector (should be a int vector)
    vector<int> rating;
	

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
		activities.push_back(temp);

		cout << "\nRating: ";
		cin >> rate;
		cin.ignore();
		
		//*********************LOOK! Add rate to the end of the rating vector
		rating.push_back(rate);
		
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
void printActivities(vector<string>  activities, vector<int> rating) {
	cout << "\n\nFall Activities:\n";
    cout << "---------------\n";
	for (int i = 0; i < static_cast<int>(activities.size()); i++){
		cout << activities[i] << ": " << rating[i] << "\n";
			
	}

}

//*********************LOOK! Write the selectionSort function
// Make sure to use the sort function (from the algorithm library) when you have to swap elements
// Sort activities from highest popularity to lowest popularity
void selectionSort(vector<string>  activities, vector<int> rating) {
	int minIndex;
	string minValue;

	for(int i = 0; i + 1 < static_cast<int>(activities.size()); i++){ //static casting the vector to ensure correct comparison type (USED GEMINI TO TROUBLESHOOT)
		minIndex= i;
		minValue = activities[i];

		for(int j = i + 1; j < static_cast<int>(activities.size()); j++){	//compares the current item to the smallest item chosen in the list
			if(activities[j] < minValue){
				minValue = activities[j];
				minIndex = j;
			}
		}
		swap(activities[i], activities[minIndex]);	//swaps the two items in the act. vector
		swap(rating[i], rating[minIndex]);	//swaps the two items in the rating vector
	}
}