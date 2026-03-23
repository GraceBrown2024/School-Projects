/*
    Name        : Grace Brown
    Last Updated: 23 March 2026
    File Name   : driver.cpp
    Purpose     : Main function for lab 7 -- holds loops for file input/output
*/

#include "lab7.h"

int main(){
    cout << "\nDinosaur Directory File Name (dinoDirectory.txt): ";
    
    string almanac, dinoName;
    ifstream dinoDirFile;
    

    cin >> almanac;

    dinoDirFile.open(almanac);
    while(!dinoDirFile.is_open()){
        cin.clear();
        cin.ignore(100, '\n');
        cout << "\nText not Found :( \nPlease enter a valid text name! --> ";
        cin >> almanac;

        dinoDirFile.open(almanac);
    }
    cin.ignore(100, '\n');

    cout << setfill('-') << setw(50) << " " << endl;

    while(getline(dinoDirFile, dinoName, '#')){ //stays looping as long as text is being read
        //total dinos: acculumator for reading lines

        //begin if statement for saurus
        //begin accululator for that total

        //print "Dinos with Saurus: accululator"

        //printSaurus()

        //begin if statement for overTenGrand
        //call overTenGrand for acculumator to add up
        
        //Dinos over TEN THOUSAND pounds: overTenGrand()

        //printOver10()
    }
    cout << setfill('-') << setw(50) << " " << endl;

    dinoDirFile.close();
    return 0;
}