/*
    Author: Grace Brown
    Date Modified: 4/8/26
    Filename: prog4.cpp
    Summary: Jeopardy
*/

#include "jeopardy.h"

int main(){
    /* 
    need 3 const size variables :
              num of users (3)
              num of categories (5)
              num of questions (5)

    need categories string array (HOLDS NAMES)

    need 3 POINTERS to an array of pointers (dynamic allocation)
              1.) holds questions
              2.) Holds answers
              3.) Board status
    
    need string array to hold NAMES
    need int array to hold POINTS


    */

    /*
        loadQuestionsAndAnswers()
        initializeBoard()
        printWelcome()
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