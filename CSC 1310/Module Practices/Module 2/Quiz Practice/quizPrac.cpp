#include <iostream>
#include <string>
using namespace std;

int getTotal(int SIZE, int myArray[]);
string recursFunc(string prac, int position);

int main(){
    int SIZE = 5;
    int myArray[SIZE] = {7, 14, 1 , 5, 3};
    string prac = "FUCK";
    int choice;

    cout << "Please enter a practice to go to: \n"
         << "1.) Get Total \n"
         << "2.) String Manipulation \n"
         << "CHOICE -> ";
    cin >> choice;

    switch(choice){
        case 1:
            cout << "Total: ";
            cout << getTotal(SIZE, myArray) << endl; 
            break;
        
        case 2:
            cout << recursFunc(prac, prac.length()) << endl;

    }
    return 0;
}

int getTotal(int SIZE, int myArray[]){
    if(SIZE <= 0){
        return 0;
    }
    return myArray[SIZE - 1] + getTotal(SIZE - 1, myArray);
}

string recursFunc(string prac, int position){
    if(position < 0){
        return "";
    }
    return prac[position] + recursFunc(prac, position - 1);
    
}

