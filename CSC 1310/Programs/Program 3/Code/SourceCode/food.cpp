/*
DEVELOPER   : Grace Brown
DATE STARTED: 10 Nov 2026
LAST EDITED : 20 Nov 2026
------------------------
PURPOSE     : Keeps track of all the foods created and generated from the csv file
              Will update the custom.csv when user enters their own food
*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <fstream>
#include <vector>
#include "food.h"
using namespace std;

/*
	Function: parseCSVLine()
	Purpose: Splits one CSV row into fields.
			 Commas inside quotation marks are part of the field.
			 Two quotation marks in a quoted field represent one quotation mark.
			 Returns false if the quotation marks are not properly closed.
			 Returns true otherwise.
			 fields vector is passed by reference so that vector is filled within this function.
*/
bool Food::parseFoods(string line, vector<string>& fields){
    string current = "";
    bool inQuotes = false;
    char ch;

    fields.clear(); //clears vector

    for(int i = 0; i < (int)line.length(); i++){
        ch = line[i];

        if(ch == '"'){
            if(inQuotes && i + 1 < (int)line.length() && line[i+1] == '"'){
                current += '"'; //ADD DOUBLE QUOTES TO STRING
                i++;
            }else{
                inQuotes = !inQuotes;
            }
        }else if(ch == ',' && !inQuotes){ //delimeter char
            fields.push_back(current);
            current = ""; //gets ready for next string

        }else{
            current += ch; //adds char to stirng
        }
    }

    if(inQuotes){ //Straight up stole this from the CSVHelper.h from Lab 8
        return false;
    }
    // Remove carriage return when reading a Windows CSV on some systems.
    if (!current.empty() && current[current.length() - 1] == '\r') {
        current.erase(current.length() - 1);
    }

    fields.push_back(current);
    return true;
}

void Food::loadFoods(string foodFile, unordered_map<int, Food>& foodTable){
    ifstream file(foodFile);
    if (!file.is_open()){
        cout << "Error: Food.CSV not found!\n";
        return; //quits if file somehow got deleted
    }

    string line;
    getline(file, line); //skips header

    while(getline(file, line)){
        vector<string> fields;
        Food tempFood;
        tempFood.parseFoods(line, fields);

        //ensuring indices match the amount of fields
        //FoodID,FoodName,GramsPerServing,Calories,Fiber,Protein,Carb,Sugar,Fats,Category
        if(fields.size() >= 10){
            int foodID = stoi(fields[0]);
            string name = fields[1];
            double gramsServing = stod(fields[2]);
            int calories = stod(fields[3]);
            double fiber = stod(fields[4]);
            double protein = stod(fields[5]);
            double carbohydrates = stod(fields[6]);
            double sugar = stod(fields[7]);
            double fats = stod(fields[8]);
            string category = fields[9];

            Food currentFood(foodID, name, gramsServing, calories, fiber, protein, carbohydrates, sugar, fats, category);

            foodTable[foodID] = currentFood;
        }
        
    }

    file.close();
}

//GETTERS---------------------------------------------------
string Food::getName() const {
    return name;
}

double Food::getGramsServ() const {
    return gramsServing;
}

int Food::getCals() const {
    return calories;
}

double Food::getFiber() const {
    return fiber;
}

double Food::getProt() const {
    return protein;
}

double Food::getCarb() const {
    return carbohydrates;
}

double Food::getSugar() const{
    return sugar;
}

double Food::getFat() const {
    return fats;
}

string Food::getCategory() const{
    return category;
}


