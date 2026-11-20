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

class Calculations{
    private:
        Food foodItem;
    
    public: 
        int totalCalories(Food foodItem, double servings); //rounds UP
        int totalMacros(Food foodItem, double servings); //rounds UP
}

#endif