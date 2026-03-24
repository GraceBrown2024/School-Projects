/*
    Name        : Grace Brown
    Last Updated: 24 March 2026
    File Name   : driver.cpp
    Purpose     : Main function for lab 7 -- holds loops for file input/output
*/

#include "lab7.h"

int main(){
    int overTenAccum = 0;
    int saurusAccum = 0;
    int totalDinoAccum = 0;

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

    while(getline(dinoDirFile, dinoName, '#')){ //stays looping as long as text is being read
        //total dinos: acculumator for reading lines

        //begin if statement for saurus
        //begin accululator for that total


        //begin if statement for overTenGrand
        //call overTenGrand for acculumator to add up
        
    }

    dinoDirFile.close();

    cout << setfill('-') << setw(50) << " " << endl
         << setfill(' ') << setw(16) << " " << "TOAL DINOS: " << totalDinoAccum << "\n"
         << setw(4) << " " << "DINOS OVER 100,000 LBS: " << overTenAccum << "\n"
         << "DINO NAMES END IN 'SAURUS': " << saurusAccum << "\n"
         << setfill('-') << setw(50) << " " << endl;

    cout << "\n" <<  setw(50) << "\n"
         << setfill(' ') << setw(10) << " " << "DINOSAURS WITH SAURUS" << endl;
    printOver10("Hello", "This works", "Dino", "Yay", "Hooray");
    
    cout << "\n" << setfill('-') << setw(50) << "\n"
         << setfill(' ') << setw(10) << " " << "DINO OVER TEN GRAND" << endl;
    printSaurus("Hello", "This works", "Dino", "Yay", "Hooray");

    return 0;
}