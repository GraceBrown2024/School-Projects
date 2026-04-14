/*
    Author: Grace Brown
    Date Modified: 4/8/26
    Filename: prog4.cpp
    Summary: Jeopardy
*/

#include "jeopardy.h"

int main(){

    string categories[CATEGSIZE] = {"comics", "history", "math", "music", "science"};
    string userNames[USERSIZE];
    int points[USERSIZE] = {0}; 

    string **questions = new string *[CATEGSIZE]; //poinyst to a new array that holds questions (parallel to categories array)
    string **answers = new string *[CATEGSIZE]; //points to new array that holds ANSWERS to the questions (parrallel to categories)
    int **boardStatus = new int *[CATEGSIZE]; //points to new array that holds the 1, 2, or 0 for question availability 

    for(int i = 0; i < CATEGSIZE; i++){     //begins loop that goes column by column and allocates questions 
        questions[i] = new string [NUMQUESTIONS];
        answers[i] = new string [NUMQUESTIONS];
        boardStatus[i] = new int [NUMQUESTIONS];
    }

    bool gameCont = false;
    loadQuestionAndAnswers(categories, questions, answers, CATEGSIZE, NUMQUESTIONS);
    initializeBoard(boardStatus, CATEGSIZE, NUMQUESTIONS);
    printWelcomeMessage();

    srand(time(0)); //for randomized double points

    for(int i = 0; i < USERSIZE; i++){
        cout << "\nPlayer " << i + 1 << ", what is your name? --> ";
        getline(cin, userNames[i]);
    }
    
    do{
        for(int i = 0; i < USERSIZE; i++){
            int userCategChoice;    //these variables hold user input
            string userAnswer;
            int userQuestionChoice;

            showBoard(categories, boardStatus, CATEGSIZE, NUMQUESTIONS);    //prints out board with the assigned question values

            cout << userNames[i] << ", it's YOUR TURN!\n"
                 << "Select a Category (1-5): ";
            cin >> userCategChoice;
            while(!cin || (userCategChoice > 5 || userCategChoice < 1)){    //user validation
                cin.clear();
                cin.ignore(100, '\n');
                cout << "INVALID INPUT -- Please select a question 1-5: ";
                cin >> userCategChoice;
            }
            cin.ignore();

            cout << "Select a Question (1-5): ";
            cin >> userQuestionChoice;
            while(!cin || (userQuestionChoice > 5 || userQuestionChoice < 1)){  //user validationb
                cin.clear();
                cin.ignore(100, '\n');
                cout << "INVALID INPUT -- Please select a question 1-5: ";
            cin >> userQuestionChoice;
            }
            cin.ignore();

        }
        
    }while(gameCont);
    /*
        GAME LOOP BEGINS -- continue until there are NO MORE QUESTIONS
        - call showBoard()
        - allow user input to choose category and question
        - VALIDATE USER INPUT!!!
        - check if question is "daily double" -- print message if so
        - call printQuestionGetAnswer()
        - user input answer ... VALIDATE
        - PASS answer to checkAnswer()
            - IF CORRECT: message prints and new total is added to user points
            - IF INCORRECT: SUBTRACT points from user points 
        - End round after ALL PLAYERS HAVE HAD TURN 
        - Program prints current standing
        -------
        ONCE ALL QUESTIONS ANSWERED -- call getWinner() and print message
        at END OF MAIN -- RELEASE ALL DYNAMICALLY ALLOCATED MEMORY!!!!
    */
    
    return 0; 
}