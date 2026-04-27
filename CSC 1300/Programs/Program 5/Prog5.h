/*
    Author      : Grace Brown
    Created     : 16 April 2026
    Last Edited : 26 April 2026
    File Name   : Prog5.h
    Purpose     : 
*/


#ifndef PROG5_H
#define PROG5_H

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <cctype>
using namespace std;

struct Heroes{
    string name;
    string description;
    bool dangerous;
    double rentPrice;
    double damageCost;
    double numYears;
};

int enterHeroes(int, int, Heroes*);

int deleteHero(int, Heroes*, int&);

bool moveArrayElements(string, int, Heroes*&);

void printHeroes(int, Heroes*);

void printRentDetails(int, Heroes*);

void saveToFile(int, Heroes*);

#endif