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
        string questions, answers, points;
        string categFile = categories[i] + ".txt"; //Here i concatenate the extension to the name in the array!!!

        infile.open(categFile);

        if(infile.is_open()){
            while(getline(infile, questions, '#')){
                getline(infile, answers, '#');
                getline(infile, points); //no delimiter since txt ends with blank line
            }
                //ASSIGN TO 2d POINTER ARRAY
            infile.close();
        }else{
            cout << "Could not open " << categFile << "!";
        }

    }
    /*
        the points attributed to the question should be used to determine WHERE answer is put
        IF QUESTION/ANSWER OF THAT POINT VALUE HAS BEEN FILLED -- SKIP LINE
    */
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

string printQuestionsGetAnswer(string**, int**, int, int){
    /*
        print correct question attributed to category and point amount
        UPDATE board status to 0 for the selected question
        RETURN USERS ANSWER INPUT!!!
    */
   return "Hello"; //CHANGE
}

string toLowerString(string){
    /*
        change EACH CHARACTER to lowercase 
        RETURN NEW LOWERCASE STRING
    */
   return "Hello"; //CHANGE
}

bool checkAnswer(string**, string, int, int){
    /*
        MAKE SURE USERS ANSWER IS ALL LOWERCASE!
        return TRUE if user answer == correct answer EXACTLY OR CONTAINS a correct phrase
        return false otherwise
    */
   return true; //CHANGE
}