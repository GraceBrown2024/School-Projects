/*
    Author: Kelsey Rainey, Grace Brown
    Date Modified: 3/30/26
    Filename: functions.cpp
    Summary: This file contains the implementations of the functions for "Jeopardy"
*/

/* 
    Returns: bool
    Params: string[], int[][], int, int

    This function should print the current state of the board. 
    A spot will have 0 if the question has been answered, 1 if the question is still available, and 2 if the question is a daily double.
    It will return true if there are still spots on the board available to answer

*/
#include "jeopardy.h"

bool showBoard(string categories[], int** board, int rows, int columns) {
    bool available = false;
    string separator(60, '-');
    cout << "\n" << setw(15) << " ";
    for (int c = 0; c < columns; ++c) {
        cout << right << setw(7) << "|   " << (c+1);
    }
    
    cout << "   |\n";
    cout << separator << "\n";
    for (int i = 0; i < rows; ++i) {
        cout << left << i+1 << left << ". " << setw(15) << categories[i];
        for (int j = 0; j < columns; ++j) {
            cout << "|  ";
            if (board[i][j] == 0) {
                cout << "  X  ";
            } else {
                cout << setw(4) << (j+1)*100 << " ";
                available = true;
            }
        }
        cout << "|\n";
    }
    cout << separator << "\n";
    return available;
}

/* 
    Returns: void

    This functions should print the welcome message for the game.

*/
void printWelcomeMessage() {
    string lineOfStars(60, '*');
    string blankSpacePart(17, ' ');
    string blankSpaceFull(58, ' ');

    cout << lineOfStars << endl;
    cout << "*" << blankSpaceFull << "*" << endl;
    cout << "*" << blankSpacePart << "Welcome to \"Jeopardy...\"" << blankSpacePart << "*" << endl;
    cout << "*" << blankSpaceFull << "*" << endl;
    cout << lineOfStars << endl << endl;
}