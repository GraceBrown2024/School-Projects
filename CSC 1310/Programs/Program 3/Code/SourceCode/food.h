/*
DEVELOPER   : Grace Brown
DATE STARTED: 10 Nov 2026
LAST EDITED : 20 Nov 2026
------------------------
PURPOSE     : Functions for food.cpp
*/

#ifndef FOOD_H
#define FOOD_H
#include <iostream>
#include <string>

class Food{
    private:
        int foodID;
        string name;
        double gramsServing;
        int calories;
        int fiber;
        int protein;
        int carb;
        int sugar;
        int fats;
        string category;

    public:
        //constructor for the food class
        // creates an array for the foods list
        Food(){

        }
    //overloaded constructor for food class. 
    //Items will be loaded from list and added based on class attributes 
        Food(int foodID, string name; double gramsServing, int calories, int fiber, int protein, int carb, int sugar, int fat, string category){
        int foodID = foodID;
        string name = name;
        double gramsServing = gramsServing;
        int calories = calories;
        int fiber = fiber;
        int protein = protein;
        int carb = carb;
        int sugar = sugar;
        int fats = fats;
        string category = category;
        }  

    //Splits the CSV rows into fields
        void parseFoods();
    




}

#endif