/*
    Author      : Grace Brown
    Created     : 16 April 2026
    Last Edited : 16 April 2026
    File Name   : Lab10.h
    Purpose     : Header file for functions and structs Lab 10
*/

#ifndef LAB_10

#define LAB_10

#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>
#include <fstream>
using namespace std;

struct Furby{       //main struct for Furby info
    string design;  //more info about designs can be found at https://official-furby.fandom.com/wiki/Official_Furby_Wiki
    int year;       
    double price;
    bool goodCondition; //will raise price if true
    bool inBox;         //will raise price if true
}; 

struct Account{
    string username;
    string password;
};

const int LISTSIZE = 0; // initializes list size to nothing 

string homeScreen(Account*, int, int*);

int menu();

void viewListings();

void addListing();

void removeListing();

void editListing();

string userValidation();

string lowerCase(string);

string addAccount(Account*, int);

void createAccountArray(Account*);

int countPeople();

bool accountExists(Account*, string, int, int, int*);


#endif