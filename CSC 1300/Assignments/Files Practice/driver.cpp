/*
Name       :  Grace Brown
Last Edited:  March 4 2026
File Name  :  driver.cpp
Purpose    :  Test out header files
*/

#include "referenceVars.h"
#include <iostream>
#include <string>
using namespace std;

int main(){
    int yearOne, yearTwo;
    string furbyOne, furbyTwo;

    cout << "\nHello. Please enter the name of your first furby: ";
    getline(cin, furbyOne);
    cout << "\nAwesome. Now please enter the name of your seconf furby: ";
    getline(cin, furbyTwo);

    furbyName(furbyOne, furbyTwo);

    cout << "\nOkay. What year was " << furbyOne << " made? --> ";
    cin >> yearOne;
    cin.ignore(100, '\n');
    cout << "\nNow what year was " << furbyTwo << "made? --> ";
    cin >> yearTwo;
    cin.ignore(100, '\n');

    generation(yearOne, yearTwo);

    return 0;
}
