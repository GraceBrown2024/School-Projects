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

    for(int i = 0; i < CATEGSIZE; i++){     //begins loop that goes row by row and allocates columns (questions) 
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
            while(!cin || (userQuestionChoice > 5 || userQuestionChoice < 1) || (boardStatus[userCategChoice - 1][userQuestionChoice - 1] == 0)){  //user validationb
                cin.clear();
                cin.ignore(100, '\n');
                if(boardStatus[userCategChoice - 1][userQuestionChoice - 1] == 0){
                    cout << "\nThat Question is not available! Please select another choice: ";
                }else{
                    cout << "\nINVALID INPUT -- Please select a question 1-5: ";
                }
            cin >> userQuestionChoice;
            }
            cin.ignore();

            userCategChoice -= 1;   //adjusts user input to match index
            userQuestionChoice -= 1;


            if(boardStatus[userCategChoice][userQuestionChoice] == 2){
                cout << "\n DAILY DOUBLE!!!!! \n";
            }

            userAnswer = printQuestionsGetAnswer(questions, boardStatus, userCategChoice, userQuestionChoice); //stores function return in variable

            checkAnswer(answers, userAnswer, userCategChoice, userQuestionChoice);
        }
        
    }while(gameCont);
    /*
        GAME LOOP BEGINS -- continue until there are NO MORE QUESTIONS
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