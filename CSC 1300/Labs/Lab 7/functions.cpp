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
    overTenOut.open("over10Grand.txt", ios::app); //opens file... appends to allow more dinos to be added
    overTenOut << "\n"
               << "DINOSAUR NAME: " << dName << endl
               << "HEIGHT/LENGTH: " << dHeight << endl
               << "MASS:" << setw(10) << " " <<  dMass << endl
               << "EATS:" << setw(10) << " " << dEat << endl
               << "DESCRIPTION:" << setw(3) << " " << dDesc << endl;
    overTenOut.close();

}

void printSaurus(string dName, string dHeight, string dMass, string dEat, string dDesc){
    ofstream saurusOut;
    ifstream saurusIn;
    saurusOut.open("saurus.txt", ios::app); //opens file... appends to allow more dinos to be added
    saurusOut << "\n"
              << "DINOSAUR NAME: " << dName << endl
              << "HEIGHT/LENGTH: " << dHeight << endl
              << "MASS:" << setw(10) << " " <<  dMass << endl
              << "EATS:" << setw(10) << " " << dEat << endl
              << "DESCRIPTION:" << setw(3) << " " << dDesc << endl;
    saurusOut.close();
}

bool overTenGrand(string dMass){
    string massContainer = ""; //empty string that will later hold the new isolated mass
    int largeMass = 0; //empty int for the LARGEST mass we can find in the couple
    int numMass;

    //Using THIS for loop syntax setup
    //https://www.geeksforgeeks.org/cpp/iterate-over-characters-of-a-string-in-c/
    for(int i = 0; i < dMass.length(); i++){
        if(isdigit(dMass[i])){
            massContainer += dMass[i]; //adds the number to the mass Container
        }else if(dMass[i] == ','){
            continue; //USING https://www.geeksforgeeks.org/cpp/continue-statement-cpp/ FOR THIS IDEA
        }else if(!massContainer.empty()){
            int numMass = stoi(massContainer); //USING THIS REFERENCE FOR STOI() https://www.geeksforgeeks.org/cpp/stdstoi-function-in-cpp/
            if(numMass > largeMass){
                largeMass = numMass;
            }
            massContainer = ""; //cleaning the container to allow for the SECOND number
        }
        
        if(!massContainer.empty()){ //reads to see if container is ready for second number
            numMass = stoi(massContainer);
            if (numMass > largeMass){
                largeMass = numMass;
            }
        }

        if(largeMass >= 10000){ //checks weight condition
            return true;
        }
    }
    return false; //returns false if it doesnt hit the if condition
    
}