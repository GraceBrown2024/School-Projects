/*
    Author: Kelsey Rainey, Grace Brown
    Date Modified: 4/8/26
    Filename: functions.cpp
    Summary: This file contains the implementations of the functions for "Jeopardy"
*/

/* 
    Returns: bool
    Params: string[], int[][], int, int

    This function should print the current state of the board. 
    A spot will have 0 if the question has been answered, 1 if the question is still available, and 2 if the question is a daily double.
    It will return true if there are still spots on the board available to answer

*/
#include "jeopardy.h"

bool showBoard(string categories[], int** board, int rows, int columns) {
    bool available = false;
    string separator(60, '-');
    cout << "\n" << setw(15) << " ";
    for (int c = 0; c < columns; ++c) {
        cout << right << setw(7) << "|   " << (c+1);
    }
    
    cout << "   |\n";
    cout << separator << "\n";
    for (int i = 0; i < rows; ++i) {
        cout << left << i+1 << left << ". " << setw(15) << categories[i];
        for (int j = 0; j < columns; ++j) {
            cout << "|  ";
            if (board[i][j] == 0) {
                cout << "  X  ";
            } else {
                cout << setw(4) << (j+1)*100 << " ";
                available = true;
            }
        }
        cout << "|\n";
    }
    cout << separator << "\n";
    return available;
}

/* 
    Returns: void

    This functions should print the welcome message for the game.

*/
void printWelcomeMessage() {
    string lineOfStars(60, '*');
    string blankSpacePart(17, ' ');
    string blankSpaceFull(58, ' ');

    cout << lineOfStars << endl;
    cout << "*" << blankSpaceFull << "*" << endl;
    cout << "*" << blankSpacePart << "Welcome to \"Jeopardy...\"" << blankSpacePart << "*" << endl;
    cout << "*" << blankSpaceFull << "*" << endl;
    cout << lineOfStars << endl << endl;
}

void loadQuestionAndAnswers(string categories[], string **questions, string **answers, int CATEGSIZE, int NUMQUESTIONS){
    
    /*USING THIS SOURCE FOR THE IDEA OF CONCATENATING THE 
       NAME IN THE ARRAY TO MATCH THE FILE IN MY COMPUTER!!!
       https://stackoverflow.com/questions/38553895/c-using-a-loop-to-open-files
       (see where the answer has "+ filename +" !!! )*/
    for(int i = 0; i < CATEGSIZE; i++){
        ifstream infile;
        int numPoints;
        string strPoints, strQuestions, strAnswers; //temp variables that will be put into the arrays
        string categFile = categories[i] + ".txt"; //Here i concatenate the extension to the name in the array!!!

        infile.open(categFile);
        
        if(infile.is_open()){
            for(int j = 0; j < NUMQUESTIONS; j++){
                getline(infile, strQuestions, '#');
                getline(infile, strAnswers, '#');
                getline(infile, strPoints);

                numPoints = stoi(strPoints);

                if(numPoints == 100){
                    questions[i][0] = strQuestions;
                    answers[i][0]= strAnswers;
                }else if(numPoints == 200){
                    questions[i][1] = strQuestions;
                    answers[i][1]= strAnswers;
                }else if(numPoints == 300){
                    questions[i][2] = strQuestions;
                    answers[i][2]= strAnswers;
                }else if(numPoints == 400){
                    questions[i][3] = strQuestions;
                    answers[i][3]= strAnswers;
                }else{
                    questions[i][4] = strQuestions;
                    answers[i][4]= strAnswers;
                }
            }

          infile.close();  
        }
        else{
            cout << "Could not open " << categFile << "!";
        }
    }
}

void initializeBoard(int **boardStatus, int CATEGSIZE, int NUMQUESTIONS){
    int dailyDoubles = 0; //intializing amount chosen to 0 . as a new one is places the number will increase until it hits the three quota

    for(int i = 0; i < CATEGSIZE; i++){ //Loop to set every spot to 1
        for(int j = 0; j < NUMQUESTIONS; j++){ //inner loop that ensures each column is iterated through
            boardStatus[i][j] = 1;
        }
    }
    
    while(dailyDoubles < 3){ //repeats until the 3 quota is hit
        int randCateg = rand() % CATEGSIZE; //picks random index for category
        int randQuestion = rand() % NUMQUESTIONS; //random index for questions

        if(boardStatus[randCateg][randQuestion] != 2){ //checks if specific spot has been chosen already
            boardStatus[randCateg][randQuestion] = 2;
            dailyDoubles++; //adds one to the daily doubles counter
        }
    }
}

int getWinner(int points[], int USERSIZE){
    /*
        takes in array with user points and its parralel user names array
        RETURN !!!INDEX!!!! OF THE USER WITH MOST POINTS (see lab 8 for how i did it)
    */
   return 0; //CHANGE
}

string printQuestionsGetAnswer(string **questions, int **boardStatus, int userCategory, int userQuestion){
    string userAnswer; //holds user answer

    cout << "\nQuestion: " << questions[userCategory][userQuestion] << "\n"
         << "Your Answer: ";
    getline(cin, userAnswer);

    boardStatus[userCategory][userQuestion] = 0; //changes the array value based on user inputted index
    
   return userAnswer; 
}

string toLowerString(string input){
    string lowerString;
    /*
        change EACH CHARACTER to lowercase 
        RETURN NEW LOWERCASE STRING
    */
   return lowerString; 
}

bool checkAnswer(string **answers, string userAnswer, int userCategory, int userQuestion){
    /*
        MAKE SURE USERS ANSWER IS ALL LOWERCASE!
        return TRUE if user answer == correct answer EXACTLY OR CONTAINS a correct phrase
        return false otherwise
    */
   return false; 
}