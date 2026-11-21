/*
DEVELOPER   : Grace Brown
DATE STARTED: 10 Nov 2026
LAST EDITED : 20 Nov 2026
------------------------
PURPOSE     : Runs all code from helper files
*/

#include <iostream>
#include <string>
#include <unordered_map>
#include "calculations.h"
#include "food.h"
#include "UserInfo.h"
using namespace std;

int main(){
    UserInfo user;
    Food food;
    unordered_map<int, Food> FoodTable;

    user.loadUsers();
    Food::loadFoods("Data/food.csv", FoodTable);

    user.profileMenu();
    return 0;
}