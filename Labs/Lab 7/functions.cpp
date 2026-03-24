/*
    Name        : Grace Brown
    Last Updated: 24 March 2026
    File Name   : functions.cpp
    Purpose     : Defines functions for driver.cpp 
*/

#include "lab7.h"

void printOver10(string dName, string dHeight, string dMass, string dEat, string dDesc){
    //print out file holding the dinos that are over 10 grand
    ofstream overTenOut;
    ifstream overTenIn;
    overTenOut.open("over10Grand.txt", ios::app);
    overTenOut << "\n"
               << "DINOSAUR NAME: " << dName << endl
               << "HEIGHT/LENGTH: " << dHeight << endl
               << "MASS:" << setw(10) << " " <<  dMass << endl
               << "EATS:" << setw(10) << " " << dEat << endl
               << "DESCRIPTION:" << setw(3) << " " << dDesc << endl;
    overTenOut.close();

    /*
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
    */

}

void printSaurus(string dName, string dHeight, string dMass, string dEat, string dDesc){
    ofstream saurusOut;
    ifstream saurusIn;
    saurusOut.open("saurus.txt", ios::app);
    saurusOut << "\n"
              << "DINOSAUR NAME: " << dName << endl
              << "HEIGHT/LENGTH: " << dHeight << endl
              << "MASS:" << setw(10) << " " <<  dMass << endl
              << "EATS:" << setw(10) << " " << dEat << endl
              << "DESCRIPTION:" << setw(3) << " " << dDesc << endl;
    saurusOut.close();

    /*
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
    */

}

bool overTenGrand(string){
    
    return true;
}