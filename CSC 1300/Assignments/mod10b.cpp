/* 
Name        : Grace Brown
Date Created: 15 April 2026
Date Edited : 15 April 2026
File Name   : mod10b.cpp
Purpose     : idk (change this)
*/
#include <iostream>
#include <string>
using namespace std;

const int SIZE = 3;

struct Phone;

void addPhone(Phone**, int);

void printArray(Phone**, int);

int main(){
    Phone **phoneArray;
    phoneArray = new Phone *[SIZE]; //dynamically allocates space for the rows of the array

    for(int i = 0; i < SIZE; i++){
        phoneArray[i] = new Phone[SIZE];  //now each index points to a new array 
    }

    addPhone(phoneArray, SIZE);

    printArray(phoneArray, SIZE);

    delete [] phoneArray;  // deletes the rows

    for(int i = 0; i < SIZE; i++){
        delete [] phoneArray[i]; //deletes tje arrays in each index
    }

    return 0;
}

struct Phone{
    string type;
    string color;
    int memory;
};

void addPhone(Phone **phoneArray, int SIZE){
    for(int i = 0; i < SIZE; i++){
        Phone item;
        cout << "PHONE " << i + 1 << endl
             << "PHONE TYPE: ";
        getline(cin, item.type);

        cout << "PHONE COLOR: ";
        getline(cin, item.color);

        cout << "PHONE CAPACITY (in GB): ";
        cin >> item.memory;

        while(!cin){
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Please enter a valid integer: ";
            cin >> item.memory;
        }
        cin.ignore();
        cout << endl;

        phoneArray[i][0].type = item.type;
        phoneArray[i][1].color = item.color;
        phoneArray[i][2].memory = item.memory;
    }

}

void printArray(Phone **phoneArray, int SIZE){
    string names[3] = {"Phone", "Color", "Capacity"};

    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            cout << names[j] << ": " << phoneArray[i][j];
        }
    }
}