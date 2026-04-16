/*************************************
* Name          : Grace Brown
* Last Edited   : 9 March 1016
* File Name     : Lab6.cpp
* Purpose       : Main function for Lab 6
**************************************/

#include "lab6.h"

int main(){
    int choice; //holds return for displayMenu()
    do{ //Begins "gameplay" loop
        double length, width, height, radius, base;
        choice = displayMenu(); 

        switch(choice){ //takes return from menu and splits into different case functions
            case 1: //calls SQUARE
                cout << "\nPlease enter the length of the side -->  ";
                cin >> length;

                while(cin.fail() || length < 0){ //validation loop
                    cin.clear();
                    cin.ignore(100, '\n');
                    cout << "Please enter a valid measurement! --> ";
                    cin >> length;
                }
                cin.ignore(100, '\n');

                areaSquare(length); //calls for calculation
                break;

            case 2: //calls RECTANGLE
                cout << "\nPlease enter the Length and Width (Seperated by a space): \n ";
                cin >> length >> width;

                while(cin.fail() || length < 0 || width < 0){ //validation loop
                    cin.clear();
                    cin.ignore(100, '\n');
                    cout << "Please enter valid measurements!\n ";
                    cin >> length >> width;
                }
                cin.ignore(100, '\n');

                areaRectangle(length, width); //calls for calculation
                break;

            case 3: //calls PARALLELOGRAM
                cout << "\nPlease enter the Base and Height (Seperated by a space): \n ";
                cin >> base >> height;

                while(cin.fail() || base < 0 || height < 0){ //validation loop
                    cin.clear();
                    cin.ignore(100, '\n');
                    cout << "Please enter valid measurements! \n ";
                    cin >> base >> height;
                }
                cin.ignore(100, '\n');
                
                areaParallelogram(base, height); //calls for calculation
                break;

            case 4: //calls CIRCLE
                cout << "\nPlease enter the Radius of your Circe --> ";
                cin >> radius;

                while(cin.fail() || radius < 0){ //validation loop
                    cin.clear();
                    cin.ignore(100, '\n');
                    cout << "Please enter a valid measurement! --> ";
                    cin >> radius;
                }
                cin.ignore(100, '\n');
                
                areaCircle(radius); //calls for calculation
                break;
        }
        cout << "\n●・○・●・○・●・○・●・○・●・○・●・○・●・○・●・○・●"
             << "\n[PRESS ENTER TO RETURN TO MENU]"
             << "\n●・○・●・○・●・○・●・○・●・○・●・○・●・○・●・○・●\n";

        cin.ignore(100, '\n');
    }while(choice != 5); //continues to cycle loop until EXIT is chosen

    cout << "\nThanks for playing my riveting game hooray\n";
    return 0;
}


