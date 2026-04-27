/*
    Author      : Grace Brown
    Created     : 16 April 2026
    Last Edited : 27 April 2026
    File Name   : Prog5.cpp
    Purpose     : Allows you to manage your heroes in your(?) condo!
*/

#include "Prog5.h"

int main(){
    ifstream homelanderCheck;
    homelanderCheck.open("oi_ohmlanda.txt");    //stops program if you deleted homelander in a previous run
    if(homelanderCheck){
        cout << endl << "\nI know what you did.\n" << endl;
        return 0;
    }
    homelanderCheck.close();

    int numHeroes = 0;  //initial amount of heroes in numheroes
    int max = 10;
    int choice;
    int homelanderStatus = 0;

    cout << "\n₊˚ ✧ ━━━━━━━━━━━━⊱⋆⊰━━━━━━━━━━━━ ✧ ₊˚\n"
         << setw(5) << " " << "☆☆☆ 50 STAR CONDOS ☆☆☆"    //patriotic name for Homelanders condo
         << "\n-------------------------------------";

    Heroes* heroArray = new Heroes[max];
    
    //INITIALIZES WITH HOMELANDER!!!! Ensures he cannot be deleted permanently ...
    heroArray[0].name = "Homelander";
    heroArray[0].description = "America's Hero, Prophet, Savior, and Truth. Homelander is a shining light in the darkness of the world. No bullet can break the skin, nor the spirit, of this Hero.";
    heroArray[0].dangerous = true;  //dont worry about this one
    heroArray[0].rentPrice = 0.00; //he owns the condo i think
    heroArray[0].damageCost = 0.00; //hes fine dont worry about this one either
    heroArray[0].numYears = 25.00; //assuming we follow the theory of him being in the Seven since 9/11
    numHeroes++;

    do{ //beginning of gameplay loop
        cout << "\n₊˚ ✧ ━━━━━━━━━━━━⊱⋆⊰━━━━━━━━━━━━ ✧ ₊˚\n"
         << "\nWhat would you like to do?\n"
         << setw(5) << "1.)" << " Enter Superhero\n"
         << setw(5) << "2.)" << " Evict Superhero\n"
         << setw(5) << "3.)" << " Display all Heroes\n"
         << setw(5) << "4.)" << " Display all Rent Details\n"
         << setw(5) << "5.)" << " End Program\n"
         << "Enter Choice: ";
        cin >> choice;
        while(!cin || (choice < 1 || choice > 5)){
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Please enter a valid choice: ";
            cin >> choice;
        }
        cin.ignore(100, '\n');
        cout << "\n₊˚ ✧ ━━━━━━━━━━━━⊱⋆⊰━━━━━━━━━━━━ ✧ ₊˚\n";

        switch(choice){
            case 1:
                numHeroes = enterHeroes(max, numHeroes, heroArray); //updates hero array
                break;
            case 2:
                numHeroes = deleteHero(numHeroes, heroArray, homelanderStatus); //updates hero array
                break;
            case 3:
                printHeroes(numHeroes, heroArray);  //displays heroes
                break;
            case 4:
                printRentDetails(numHeroes, heroArray); //shows money info
                break;
            case 5:
                saveToFile(numHeroes, heroArray);   //quits program and saves heroes to files
                cout << "Goodbye.\n";
                break;
        }

        if(homelanderStatus == 1){    //quits program if you try to delete homelander
            ofstream uhOh;    
            uhOh.open("oi_ohmlanda.txt");   //prevents program from playing again if this is present on your folder 
            uhOh << "Warning.";

            cout << "\nYou shouldn't have done that.\n"
                 << "Goodbye. You are no longer safe.\n"
                 << "Program has exited\n";
            break;
            uhOh.close();
        }

    }while(choice != 5);    //exits loop if you choose to exit
    
    delete [] heroArray;    //deallocates array
    return 0;
}