/*
DEVELOPER   : Grace Brown
DATE STARTED: 10 Nov 2026
LAST EDITED : 20 Nov 2026
------------------------
PURPOSE     : Functions to calculate the daily calorie count and macronutrients
*/

#ifndef CALCULATIONS_H
#define CALCULATIONS_H
#include <iostream>
#include <string>
#include <cmath>
#include "food.h"
#include "UserInfo.h"
using namespace std;

class Calculations{
    private:
        Food foodItem;
        UserInfo user;
    
    public: 
        void totalCalories(Food foodItem, double servings); //Adds up all calories for today ... ROUNDS UP
        void totalMacros(Food foodItem, double servings); //Adds up each macro count for today ... ROUNDS UP
        
        
};

#endif