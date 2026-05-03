/*
    Author      : Grace Brown
    Created     : 16 April 2026
    Last Edited : 19 April 2026
    File Name   : Lab10.h
    Purpose     : Header file for functions and structs Lab 10
*/

/*
    Hello. Just wanted to leave a note as this semester is ending.
    This class genuinely has been the most fun I've had in college so far.
    Even though some of the programs (program 4) made me want to rip my skin off,
    I still am very proud of how far I've come in understanding this language.

    Even if I make a poor grade on this lab, I can confidently say this program
    is my favorite out of everything Ive ever written.

    Sorry if im a cornball I just feel it's important to leave an ending note.

    Okay bye
*/

#ifndef LAB_10

#define LAB_10

#include <iostream>
#include <string>   
#include <iomanip>  //used for displaying listings
#include <cctype>   //used for lowercase function
#include <fstream>  //used for storing accounts
#include <cmath>    //used for rounding price
#include <array>    //used for removing a listing
using namespace std;

struct Furby{       //main struct for Furby info
    string design;  //more info about designs can be found at https://official-furby.fandom.com/wiki/Official_Furby_Wiki
    int year;       //this is the FIRST year this furby was produced
    int yearEnd;    //this is the LAST year this furby was produced    
    double price;
    bool goodCondition; //will raise price if true
    bool inBox;         //will raise price if true
}; 

struct Account{ //struc for account info... does NOT affect gameplay i just wanted to add it for funnies
    string username;
    string password;
};

string homeScreen(Account*, int, int*);

int menu();

void viewListings(Furby*, int);

void addListing(Furby*&, int*);

void removeListing(Furby*&, int*);

void editListing(Furby*, int);

string userValidation();

string lowerCase(string);

string addAccount(Account*, int&);

void createAccountArray(Account*);

int countPeople();

bool accountExists(Account*, string, int, int, int*);

double suggestedPrice(Furby*, int);

void roundPrice(Furby*, int, double);

int intValidation();

#endif