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
using namespace std;

class Food{
    private:
        int foodID;
        string name;
        double gramsServing;
        int calories;
        int fiber;
        int protein;
        int carbohydrates;
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
        Food(int fid, string n, double gS, int cal, int f, int p, int carb, int s, int fat, string c){
        foodID = fid;
        name = n;
        gramsServing = gS;
        calories = cal;
        fiber = f;
        protein = p;
        carbohydrates = carb;
        sugar = s;
        fats = fat;
        category = c;
        }

        void parseFoods(); //Splits the CSV rows into fields

    




};

#endif