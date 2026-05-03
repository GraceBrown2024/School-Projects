/* 
Name        : Grace Brown
Date Created: 15 April 2026
Date Edited : 15 April 2026
File Name   : mod10b.cpp
Purpose     : boring ahh program lets you store your phone info
*/
#include <iostream>
#include <string>
using namespace std;

const int SIZE = 3;

struct Phone{
    string type;
    string color;
    int memory;
};


void addPhone(Phone[], int);

void printArray(Phone[], int);

int main(){
    Phone *phoneArray;
    phoneArray = new Phone[SIZE]; //dynamically allocates space for the rows of the array


    addPhone(phoneArray, SIZE);

    printArray(phoneArray, SIZE);

    delete [] phoneArray;  // deletes the rows

    return 0;
}

void addPhone(Phone *phoneArray, int SIZE){
    for(int i = 0; i < SIZE; i++){
        cout << "PHONE " << i + 1 << endl
             << "PHONE TYPE: ";
        getline(cin, phoneArray[i].type);

        cout << "PHONE COLOR: ";
        getline(cin, phoneArray[i].color);

        cout << "PHONE CAPACITY (in GB): ";
        cin >> phoneArray[i].memory;

        while(!cin){
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Please enter a valid integer: ";
            cin >> phoneArray[i].memory;
        }
        cin.ignore();
        cout << endl;
    }
}

void printArray(Phone *phoneArray, int SIZE){
    string banner(20, '-');

    for(int i = 0; i < SIZE; i++){
        cout << "\n" << banner << "\n"
             << "\nPhone: " << phoneArray[i].type
             << "\nColor: " << phoneArray[i].color
             << "\nMemory: " << phoneArray[i].memory << "GB\n";
    }
    cout << "\n" << banner;
}