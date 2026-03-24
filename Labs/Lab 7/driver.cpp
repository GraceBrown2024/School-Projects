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
    string dName, dHeight, dMass, dEat, dDesc, dino, almanac; //holds the info for each line

    cout << "\nDinosaur Directory File Name (dinoDirectory.txt): ";
    
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

    while(getline(dinoDirFile, dName, '#')){ //stays looping as long as text is being read
        getline(dinoDirFile, dHeight, '#'); //grabs the next line and puts it in variable
        getline(dinoDirFile, dMass, '#'); //ditto 
        getline(dinoDirFile, dEat, '#'); 
        getline(dinoDirFile, dDesc, '#'); 
        totalDinoAccum++;           //total dinos: acculumator for reading lines

        //USING THIS REFERENCE FOR FIND FUNCTION
        //https://en.cppreference.com/w/cpp/string/basic_string/find
        //USING THIS REFERENCE FOR NPOS CONSTANT
        //https://www.geeksforgeeks.org/cpp/stringnpos-in-c-with-examples/
        if(dName.find("saurus") != string::npos){ //searches for word "saurus" in the dino NAME
            saurusAccum++;
            printSaurus(dName, dHeight, dMass, dEat, dDesc);
        }

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
    ifstream saurusIn;
    saurusIn.open("saurus.txt");
    if(saurusIn.is_open()){
        string lineOfData;
        while(getline(saurusIn, lineOfData)){
            cout << lineOfData << endl;;
         }
        
    }else{
        cout << "File could not be found!" << endl;
    }
    saurusIn.close();
    
    cout << "\n" << setfill('-') << setw(50) << "\n"
         << setfill(' ') << setw(10) << " " << "DINO OVER TEN GRAND" << endl;
    ifstream overTenIn;
    overTenIn.open("over10Grand.txt");
    if(overTenIn.is_open()){
        string lineOfData;
        while(getline(overTenIn, lineOfData)){
            cout << lineOfData << endl;;
         }
        
    }else{
        cout << "File could not be found!" << endl;
    }
    overTenIn.close();

    return 0;
}