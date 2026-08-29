/*
	Driver for Course Structure
	LAB 1 CSC 1310
	Authors: April Crockett and Grace Brown 
	
	Date Created: 1/19/2026
	Date Updated: 8/25/2026 
*/

#include "Course.h"

using namespace std;

int main ()
{
	Course** myCourses;

	
	int numCourses, numSections;
	string name, location;
	int numHours;
	
	cout << "\nHow many courses are you taking this semester?\n";
	cin >> numCourses;
	cin.ignore();
	
	Course* tempArray;
	tempArray = new Course[numCourses];
	//Dynamically allocate a new array of pointers to Courses of size numCourses and assign this array to myCourses
	
	
	for (int i=0; i< numCourses; i++)
	{
		cout << "\nCOURSE NAME:\t\t";
		getline(cin, name);
		cout << "\nCOURSE LOCATION:\t";
		getline(cin, location);
		cout << "\nCOURSE HOURS:\t\t";
		cin >> numHours;
		cout << "\nNUMBER OF SECTIONS?\t";
		cin >> numSections;
		cin.ignore();
		
		myCourses[i] = createCourse(name, location, numHours, numSections);
		//Call the createCourse function and make sure to assign the returned value to myCourses[i]

		
		for(int x=0; x<numSections; x++)
		{
			cout << "\nSECTION " << x+1 << ":\t\t";
			
			//Read in the string from the user and put in the correct array element of the sections array
		}
		cout << "\n*******************************\n";
	}
	
	//print results
	cout << "\n\nThe following are the courses you entered:\n\n";
	for(int i=0; i<numCourses; i++)
	{
		cout << "******************************* COURSE " << (i+1) << "*******************************\n";
		printCourse(myCourses[i]);
	}
	
	//release all dynamically allocated data
	for(int i=0;  i< numCourses; i++)
	{
		destroyCourse(myCourses[i]);
	}
	delete [] myCourses;
	
	cout << endl << endl;
	return 0;
}