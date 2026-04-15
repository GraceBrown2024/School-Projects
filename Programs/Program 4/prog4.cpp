/*
    Author: Grace Brown
    Date Modified: 4/15/26
    Filename: prog4.cpp
    Summary: Jeopardy
*/

#include "jeopardy.h"

int main(){

    srand(time(0)); //for randomized double points AND for random question index 

    string categories[CATEGSIZE] = {"comics", "history", "math", "music", "science"};
    string userNames[USERSIZE];
    int points[USERSIZE] = {0}; 

    string **questions = new string *[CATEGSIZE]; //poinyst to a new array that holds questions (parallel to categories array)
    string **answers = new string *[CATEGSIZE]; //points to new array that holds ANSWERS to the questions (parrallel to categories)
    int **boardStatus = new int *[CATEGSIZE]; //points to new array that holds the 1, 2, or 0 for question availability 

    int rounds = 0; //initializes rounds to keep track in gameloop
    bool dailyDouble; //keeps track of the daily doubles
    int potentialPoints; //keeps track of possible points from userQuestion

    for(int i = 0; i < CATEGSIZE; i++){     //begins loop that goes row by row and allocates columns (questions) 
        questions[i] = new string [NUMQUESTIONS];
        answers[i] = new string [NUMQUESTIONS];
        boardStatus[i] = new int [NUMQUESTIONS];
    }

    loadQuestionAndAnswers(categories, questions, answers, CATEGSIZE, NUMQUESTIONS);
    initializeBoard(boardStatus, CATEGSIZE, NUMQUESTIONS);
    printWelcomeMessage();

    for(int i = 0; i < USERSIZE; i++){
        cout << "Player " << i + 1 << ", what is your name? --> ";
        getline(cin, userNames[i]);
    }
    
    do{
        string strip(20, '=');

        if(rounds > 0){
            cout << endl << strip << " Round " << rounds + 1 << "!" << strip;
        }else{
            cout << endl << strip << " Game Start! " << strip;
        }

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

            if((boardStatus[userCategChoice - 1][0] == 0) && (boardStatus[userCategChoice - 1][1] == 0) && (boardStatus[userCategChoice - 1][2] == 0) && (boardStatus[userCategChoice - 1][3] == 0) && (boardStatus[userCategChoice - 1][4] == 0)){
                int oldChoice = userCategChoice;
                while(oldChoice == userCategChoice){
                    cout << "\nAll the questions in this row are taken! Please choose another row: ";
                    cin >> userCategChoice;
                    while(cin.fail() || (userCategChoice > 5 || userCategChoice < 1)){ //embedded user validation??
                        cin.clear();
                        cin.ignore(100, '\n');
                        cout << "Please enter a valid Category: ";
                        cin >> userCategChoice;
                    }
                    cin.ignore();
                }
            }

            userCategChoice -= 1;   //adjusts user input to match index

            cout << "Select a Question (1-5): ";
            cin >> userQuestionChoice;
            while(!cin || (userQuestionChoice > 5 || userQuestionChoice < 1) || ((userQuestionChoice >= 1 && userQuestionChoice <= 5) && boardStatus[userCategChoice][userQuestionChoice - 1] == 0)){  //user validationb
                cin.clear();
                cin.ignore(100, '\n');
                if(boardStatus[userCategChoice][userQuestionChoice - 1] == 0){
                    cout << "\nThat Question is not available! Please select another choice: ";
                }else{
                    cout << "\nINVALID INPUT -- Please select a question 1-5: ";
                }
                cin >> userQuestionChoice;
            }
            cin.ignore();

            userQuestionChoice -= 1; //adjusts user input to match index

            if(boardStatus[userCategChoice][userQuestionChoice] == 2){
                cout << "\nDAILY DOUBLE!!!!!\n";
                dailyDouble = true;
            }else{
                dailyDouble = false;
            }

            userAnswer = printQuestionsGetAnswer(questions, boardStatus, userCategChoice, userQuestionChoice); //stores function return in variable
            potentialPoints = (userQuestionChoice + 1) * 100; //finds the allotted points for the chosen question index

            if(checkAnswer(answers, userAnswer, userCategChoice, userQuestionChoice) == true){
                cout << userNames[i] << " is CORRECT! The answer was " << answers[userCategChoice][userQuestionChoice] << ".\n";
                if(dailyDouble == true){
                    potentialPoints *= 2;
                    points[i] += potentialPoints;
                    cout << "You won double points! You now have " << points[i] << " points." << endl;
                }else{
                    points[i] += potentialPoints;
                    cout << "You now have " << points[i] << " points." << endl;
                }

            }else{
                cout << userNames[i] << " is INCORRECT! The answer was " << answers[userCategChoice][userQuestionChoice] << ".\n";
                points[i] -= potentialPoints;
                cout << "You LOST " << potentialPoints << " points! You now have " << points[i] << " points." << endl;
            }
        }
        rounds++;
    }while(rounds < 9); 

    cout << "Congratulations " << userNames[getWinner(points, USERSIZE)] << "! You WIN with " << points[getWinner(points, USERSIZE)] << " points!" << endl;

    for(int i = 0; i < CATEGSIZE; i++ ){ //deleted the columns dynamically allocated memory
        delete [] questions[i];
        delete [] answers[i];
        delete [] boardStatus[i];
    }
    delete [] questions; //begin deleting the rows of the dynamically allocated arrays
    delete [] answers;
    delete [] boardStatus;

    /*
        GAME LOOP BEGINS -- continue until there are NO MORE QUESTIONS
            - IF CORRECT: message prints and new total is added to user points
            - IF INCORRECT: SUBTRACT points from user points 
        - End round after ALL PLAYERS HAVE HAD TURN 
        - Program prints current standing
        -------
        ONCE ALL QUESTIONS ANSWERED -- call getWinner() and print message
    */
    
    return 0;
}