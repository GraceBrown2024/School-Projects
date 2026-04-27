/*
    Author      : Grace Brown
    Created     : 16 April 2026
    Last Edited : 26 April 2026
    File Name   : Prog5.cpp
    Purpose     : 
*/

#include "Prog5.h"

int main(){
    int numHeroes = 0;  //initial amount of heroes in numheroes
    int max = 10;
    int choice;
    int homelanderStatus = 0;

    cout << "\n₊˚ ✧ ━━━━━━━━━━━━⊱⋆⊰━━━━━━━━━━━━ ✧ ₊˚\n"
         << setw(5) << " " << "☆☆☆ 50 STAR CONDOS ☆☆☆"
         << "\n-------------------------------------";

    Heroes* heroArray = new Heroes[max];

    do{
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
                numHeroes = enterHeroes(max, numHeroes, heroArray);
                break;
            case 2:
                numHeroes = deleteHero(numHeroes, heroArray, homelanderStatus);
                break;
            case 3:
                printHeroes(numHeroes, heroArray);
                break;
            case 4:
                printRentDetails(numHeroes, heroArray);
                break;
            case 5:
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

    }while(choice != 5);
    
    delete [] heroArray;
    return 0;
}