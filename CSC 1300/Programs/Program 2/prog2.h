/*
Name        : Grace Brown
Last Edited : 6 March 2026
File Name   : prog2.h
Purpose     : Function declarations for program2.cpp
*/

#ifndef PROG_2

#define PROG_2

#include <string>
int displayMenuChoice();            //Shows menu choices and allows user selection... returns the user selection as an int
int rollDice();                     //Generates two unique random dice numbers and returns the total
int luckyDice(std::string player); //Allows seperate users to roll dice repeatedly -- has seperate dice-roll mechanic then rollDice()
void gameDescription();             //displays game descriptions and rule

#endif