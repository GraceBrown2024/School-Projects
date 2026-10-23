#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <list>
using namespace std;

int main(){
    list<int> myList;

    myList.push_back(8);
    myList.push_back(19);
    myList.push_back(4);
    myList.remove(8);
    myList.insert(myList.begin(), 4);
    myList.insert(myList.begin(), 5);
    myList.remove(4);
    myList.push_back(7);
    cout << "\nList: " << myList.back() << endl;

    stack<double> myStack;
    double num;

    myStack.push(2.1);
    myStack.push(4.3);
    myStack.push(6.5);
    myStack.pop();
    myStack.push(8.7);
    myStack.pop();
    myStack.push(10.9);
    myStack.push(12.1);
    myStack.pop();
    myStack.pop();
    num = myStack.top();
    cout <<  "\n" << num << endl;
    myStack.pop();

    stack<double> tempStack = myStack;

    cout << "Stack elements (top to bottom): ";
    while (!tempStack.empty()) {
        cout << tempStack.top() << " ";
        tempStack.pop(); // Removes from the copy, not the original
    }
    cout << endl;
    
    return 0;
}