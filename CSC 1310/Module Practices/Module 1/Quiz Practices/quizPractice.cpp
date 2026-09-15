#include "quizPractice.h"
#include <iostream>

int main(){
    int x;
    string y;
    char z;
    Pickle myPickle;
   
    cout << "What size is your pickle? --> ";
    cin >> x;

    while(!cin){
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Please enter a valid Pickle Amount! -> ";
            cin >> x;
    }
    cin.ignore(100, '\n');

    myPickle.setSize(x);

    cout << "What COLOR is your pickle? --> ";
    getline(cin, y, '\n');
    myPickle.setColor(y);

    cout << "\nLastly, is your pickle Tasty? [Y/N] -> \n";
    cin >> z;
    z = toupper(z);

    while(!cin || (z != 'Y' && z != 'N')){
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Please enter a valid Taste! -> ";
        cin >> z;
    }

    myPickle.setTasty(z);
    cout << myPickle;
}