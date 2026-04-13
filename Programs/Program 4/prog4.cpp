/*
    Author: Grace Brown
    Date Modified: 4/8/26
    Filename: prog4.cpp
    Summary: Jeopardy
*/

#include "jeopardy.h"

int main(){
    const int USERSIZE = 3;
    const int CATEGSIZE = 5;
    const int NUMQUESTIONS = 5;

    string categories[CATEGSIZE] = {"Comics", "History", "Math", "Music", "Science"};
    string userNames[USERSIZE];
    int points[USERSIZE]; 

    string **questions = nullptr;
    string **answers = nullptr;
    int **boardStatus = nullptr;

    loadQuestionAndAnswers(categories, questions, answers, CATEGSIZE, NUMQUESTIONS);
    initializeBoard(boardStatus, CATEGSIZE, NUMQUESTIONS);
    printWelcomeMessage();



    /*
        -------
        Then user input for NAMES (put in array)
        -------
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