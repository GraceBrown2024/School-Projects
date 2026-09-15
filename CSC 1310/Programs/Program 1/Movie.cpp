/*
Name        : Grace Brown
File        : Movie.cpp
Created     : 9/8/2026
Last Updated: 9/14/2026
Purpose     : Define functions for Movie class
*/

#include "Movie.h"

//setters and getters for the movies objects
void Movie::setTitle(string t){
    title = t;
}
void Movie::setReleaseYear(int rY){
    releaseYear = rY;
}
void Movie::setRuntimeMinutes(int rM){
    runtimeMinutes = rM;
}
void Movie::setRating(string r){
    rating = r;
}
string Movie::getTitle(){   
   return title; 
}
int Movie::getReleaseYear(){
    return releaseYear;
}
int Movie::getRuntimeMinutes(){
    return runtimeMinutes;
}
string Movie::getRating(){
    return rating;
}
/* allows user to edit specific values in the move array objects
    returns void
*/
void Movie::editMovie(){
    int x;
   do{  //loop allows menu options to repeat

    cout << "Please select a Choice:\n"
         << "1.) Change Title\n"
         << "2.) Change Release Year\n"
         << "3.) Change Runtime\n"
         << "4.) Change Rating\n"
         << "5.) QUIT EDITING \n"
         << "----- ENTER NUMBER --> ";
    cin >> x;

    while(!cin || (x < 1 || x > 5)){    //verification for int
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Please enter a VALID choice!\n"
             << "--> ";
        cin >> x;
    }

    cin.ignore(100, '\n');

    switch(x){  //different cases for user to choose from in menu
        case 1:
            cout << "\nPlease enter your New Title: ";
            getline(cin, title, '\n');
            break;

        case 2:
            cout << "Please enter your New Release Year: ";
            cin >> releaseYear;

            while(!cin){    //verification
                cin.clear();
                cin.ignore(100, '\n');
                cout << "\nPlease enter a VALID year: ";
                cin  >> releaseYear;
            }
            cin.ignore(100, '\n');
            break;
        
        case 3:
            cout << "Please enter your New Runtime: ";
            cin >> runtimeMinutes;

            while(!cin){    //verification
                cin.clear();
                cin.ignore(100, '\n');
                cout << "\nPlease enter a VALID amount: ";
                cin  >> runtimeMinutes;
            }
            cin.ignore(100, '\n');
            break;
        
        case 4:
            cout << "Please enter your New Rating: ";
            getline(cin, rating, '\n');
            break;
    }
    cout << "\n";

   }while(x != 5);  //loops until user selects to quit
        
}

/* Prints details for one movie
    is used in a loop to print all movies in a array
    returns void
*/
void Movie::printMovie(){
    //PRINT ALL MOVIE DETAILS
    //if runtime or RY is 0, print "unknown"
    string printRunTime;
    if(getRuntimeMinutes() == 0){
        printRunTime = "Unknown";
    }else{
        printRunTime = to_string(getRuntimeMinutes());
    }
    cout << '\n' << title << " DETAILS\n"
         << "Title       : " << getTitle() << '\n'
         << "Release Year: " << getReleaseYear() << '\n'
         << "Runtime     : " << printRunTime << '\n'
         << "Rating      : " << getRating() << '\n' << endl;
 
}