/*
    Author      : Grace Brown
    Created     : 16 April 2026
    Last Edited : 16 April 2026
    File Name   : Prog5.h
    Purpose     : 
*/


#ifndef PROG5_H
#define PROG5_H

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
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

int deleteHero();

bool moveArrayElements();

void printHeroes();

void printRentDetails();

void saveToFile();

#endif