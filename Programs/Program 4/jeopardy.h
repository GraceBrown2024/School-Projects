/*
    Author: Grace Brown
    Date Modified: 3/30/26
    Filename: jeopardy.h
    Summary: prototype functions for jeopardy.cpp
*/

#ifndef JEOPARDY_H
#define JEOPARDY_H

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cctype>
using namespace std;

const int USERSIZE = 3;
const int CATEGSIZE = 5;
const int NUMQUESTIONS = 5;

bool showBoard(string[], int**, int, int);

void printWelcomeMessage();

void loadQuestionAndAnswers(string[], string**, string**, int, int);

void initializeBoard(int**, int, int);

int getWinner(int[], int);

string printQuestionsGetAnswer(string**, int**, int, int);

string toLowerString(string);

bool checkAnswer(string**, string, int, int);


#endif