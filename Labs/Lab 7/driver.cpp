/*
    Name        : Grace Brown
    Last Updated: 23 March 2026
    File Name   : driver.cpp
    Purpose     : Main function for lab 7 -- holds loops for file input/output
*/

#include "lab7.h"

int main(){
    cout << "\n✧*̥˚ Welcome to the Dino-almanac *̥˚✧"
         << "\n  Here you can see info on Dinos   "
         << "\n   Hope you have fun haha yay      "
         << "\n-----------------------------------\n"
         << "\n What is the name of your Dino-almanac? --> ";
    
    string almanac, dinoName;
    ifstream dinoDirFile;
    

    cin >> almanac;

    dinoDirFile.open(almanac);
    while(!dinoDirFile.is_open()){
        cin.clear();
        cin.ignore(100, '\n');
        cout << "\nAlmanac not Found :( \nPlease enter a valid name! --> ";
        cin >> almanac;

        dinoDirFile.open(almanac);
    }
    cin.ignore(100, '\n');

    cout << setfill('-') << setw(50) << " " << endl;
    
    while(getline(dinoDirFile, dinoName, '#')){
        
    }
    dinoDirFile.close();
    return 0;
}