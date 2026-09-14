/*
Name        : Grace Brown
File        : Movie.cpp
Created     : 9/8/2026
Last Updated: 9/8/2026
Purpose     :
*/

#include "Movie.h"


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
void Movie::editMovie(){
    int x;
   do{

    cout << "Please select a Choice:\n"
         << "1.) Change Title\n"
         << "2.) Change Release Year\n"
         << "3.) Change Runtime\n"
         << "4.) Change Rating\n"
         << "5.) QUIT EDITING \n"
         << "----- ENTER NUMBER --> ";
    cin >> x;

    while(!cin || (x < 1 || x > 5)){
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Please enter a VALID choice!\n"
             << "--> ";
        cin >> x;
    }

    cin.ignore(100, '\n');

    switch(x){
        case 1:
            cout << "\nPlease enter your New Title: ";
            getline(cin, title, '\n');
            break;

        case 2:
            cout << "Please enter your New Release Year: ";
            cin >> releaseYear;

            while(!cin){
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

            while(!cin){
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

   }while(x != 5);
        
}
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