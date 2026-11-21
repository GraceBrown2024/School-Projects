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
#include <unordered_map> //for hash table
#include <vector>
using namespace std;

class Food{
    private:
        int foodID;
        string name;
        double gramsServing;
        int calories;
        double fiber;
        double protein;
        double carbohydrates;
        double sugar;
        double fats;
        string category;

    public:
        //constructor for the food class
        // creates an array for the foods list
        Food(){

        }
    //overloaded constructor for food class. 
    //Items will be loaded from list and added based on class attributes 
        Food(int fid, string n, double gS, int cal, double f, double p, double carb, double s, double fat, string c){
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

        bool parseFoods(string line, vector<string>& fields); //Splits the CSV rows into fields
        static void loadFoods(string foodFile, unordered_map<int, Food>& foodTable);

        //getters
        string getName() const ;
        double getGramsServ() const ;
        int getCals() const ;
        double getFiber() const ;
        double getProt() const ;
        double getCarb() const ;
        double getSugar() const ;
        double getFat() const ;
        string getCategory() const ;

};

#endif