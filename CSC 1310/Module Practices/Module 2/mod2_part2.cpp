#include <iostream>
using namespace std;

int getTotal(int num, int array[]);
const int SIZE = 5;

int main(){
    int myArray[SIZE] = { 7, 14, 1, 5, 3 };
    cout << "The total of the array elements: ";

    cout << getTotal(0, myArray) << endl << endl;
    return 0;
}

int getTotal(int num, int array[]){
    if( num < SIZE){
        return getTotal(num + 1, array) + array[num]; 
    } else{
        return 0;
    }
}