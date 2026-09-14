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
    int tempNum = 0;
    string tempStrng = "";

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
            getline(cin, tempStrng, '\n');
            Movie::setTitle(tempStrng);
            break;

        case 2:
            cout << "Please enter your New Release Year: ";
            cin >> tempNum;

            while(!cin){
                cin.clear();
                cin.ignore(100, '\n');
                cout << "\nPlease enter a VALID year: ";
                cin  >> tempNum;
            }
            cin.ignore(100, '\n');
            Movie::setReleaseYear(tempNum);
            break;
        
        case 3:
            cout << "Please enter your New Runtime: ";
            cin >> tempNum;

            while(!cin){
                cin.clear();
                cin.ignore(100, '\n');
                cout << "\nPlease enter a VALID amount: ";
                cin  >> tempNum;
            }
            cin.ignore(100, '\n');
            Movie::setRuntimeMinutes(tempNum);
            break;
        
        case 4:
            cout << "Please enter your New Rating: ";
            getline(cin, tempStrng, '\n');
            Movie::setRating(tempStrng);
            break;
    }
    cout << "\n";

   }while(x != 5);
        
}
void Movie::printMovie(){
    //PRINT ALL MOVIE DETAILS
    //if runtime or RY is 0, print "unknown"
    string printRunTime;
    if(Movie::getRuntimeMinutes() == 0){
        printRunTime = "Unknown";
    }else{
        printRunTime = Movie::getRuntimeMinutes();
    }
    cout << '\n' << title << " DETAILS\n"
         << "Title       : " << Movie::getTitle() << '\n'
         << "Release Year: " << Movie::getReleaseYear() << '\n'
         << "Runtime     : " << printRunTime << '\n'
         << "Rating      : " << Movie::getRating() << '\n\n';
 
}