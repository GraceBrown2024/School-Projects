/*
DEVELOPER   : Grace Brown
DATE STARTED: 10 Nov 2026
LAST EDITED : 20 Nov 2026
------------------------
PURPOSE     : Functions to calculate the daily calorie count and macronutrients...
              Will be connected to userInfo and store the updated daily count in daily_logs/
*/

#include <iostream>
#include <string>
#include "calculations.h"
using namespace std;

/*
NAME: totalCalories
Parameters: foodItem and Servings
Returns: NONE
Purpose: Calculates the total cals of the inputted 
        food and places it into the 2D array
*/
void Calculations::totalCalories(Food foodItem, double servings){
    //TO DO:
    // calculate the servings x gramsPerServing ... put that in varible for GRAMS EATEN
    //calculate GRAMS EATEN x calories ... PUT IN USER ARRAY FOR TODAYS DATE
    int totalGrams = servings * foodItem.getGramsServ();
    int totalCals = totalGrams * foodItem.getCals();

}

/*
NAME: totalMacros
Parameters: foodItem and Servings
Returns: NONE
Purpose: Calculates the total macros of the inputted 
        food and places it into the 2D array
*/
void Calculations::totalMacros(Food foodItem, double servings){
    /*TO DO:
        calculate servings X gramsPerServing ... put in GRAMS EATEN
        calculate each GRAMS EATEN x macro ... PUT IN USER ARRAY FOR TODAYS DATE
    */
    int totalGrams = servings * foodItem.getGramsServ();

    
}

