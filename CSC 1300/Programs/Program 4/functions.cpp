/*
    Author: Kelsey Rainey, Grace Brown
    Date Modified: 4/15/26
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

/* 
    Returns: void
    Params: string[], string**, string**, int, int

   This function will assign and load all the questions into the right spots on the board

*/
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

        //Here I am throwing ideas at the wall. There is probably an easier way to do this but Im not figuring that out right now
        //I am going to put all the questions of the same point value in an array... then I will SELECT A RANDOM INDEX from that array
        //if this works, then call me telso the way im so smart
        string points100[3][2]; //three for three questions, two for question slot and answer slot 
        string points200[3][2];
        string points300[3][2];
        string points400[3][2];
        string points500[3][2]; //this MIGHt be the new meta

        infile.open(categFile);
        
        if(infile.is_open()){
            int k1 = 0; //counter for amount of items in array
            int k2 = 0; // once again, throwing things at the wall. 
            int k3 = 0; // Thought process is: I loop 15 times (amoutn of questions in the txt files) but k# keeps the 3 index for each array?
            int k4 = 0; 
            int k5 = 0; // i tried to do JUST k++ but got a billion errors. But this worked

            int randIndex = rand() % 3;  //chooses a random number that will pick an index in each questions array
            
            for(int j = 0; j < 15; j++){ //begins loop for columns
                
                getline(infile, strQuestions, '#');
                getline(infile, strAnswers, '#');
                getline(infile, strPoints, '\n');

                numPoints = stoi(strPoints); //converts the string points from file into integer ... https://www.geeksforgeeks.org/cpp/stdstoi-function-in-cpp/

                if(numPoints == 100){
                    points100[k1][0] = strQuestions;
                    points100[k1][1] = strAnswers;
                    k1++;
                }else if(numPoints == 200){
                    points200[k2][0] = strQuestions;
                    points200[k2][1] = strAnswers;
                    k2++;
                }else if(numPoints == 300){
                    points300[k3][0] = strQuestions;
                    points300[k3][1] = strAnswers;
                    k3++;
                }else if(numPoints == 400){
                    points400[k4][0] = strQuestions;
                    points400[k4][1] = strAnswers;
                    k4++;
                }else if(numPoints == 500){
                    points500[k5][0] = strQuestions;
                    points500[k5][1] = strAnswers;
                    k5++;
                }
            }
            infile.close();  
            
            questions[i][0] = points100[randIndex][0]; //beginning of me assigning the questions/answers array some values
            answers[i][0] = points100[randIndex][1];

            questions[i][1] = points200[randIndex][0];
            answers[i][1] = points200[randIndex][1];

            questions[i][2] = points300[randIndex][0];
            answers[i][2] = points300[randIndex][1];

            questions[i][3] = points400[randIndex][0];
            answers[i][3] = points400[randIndex][1];

            questions[i][4] = points500[randIndex][0];  //do you guys actually read these comments please lmk
            answers[i][4] = points500[randIndex][1];
        }
        else{
            cout << "Could not open " << categFile << "!";
        }
    }
}

/* 
    Returns: void
    Params: int**, int, int

    This function assigns "point value" to each question which marks if their single points or double points, 

*/
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

/* 
    Returns: int
    Params: int[], int

   This function iterates through the points array and picks out the highest number, returns the index which is parallel to the Username array

*/
int getWinner(int points[], int USERSIZE){
    int winner = 0;                     //holds points of the current winner 
    int winnerIndex = 0;                //holds index of the owner of said points

    for(int i = 0; i < USERSIZE; i++){ //used same concept from lab 8 with finding the greatest value's index 
        if(points[i] > winner){
            winner = points[i];
            winnerIndex = i;
        }  
    }
   return winnerIndex; 
}

/* 
    Returns: string
    Params: string**, int**, int, int

   This function prints the question that corresponds to the user's selected position on the board. It will return the user's answer 
*/
string printQuestionsGetAnswer(string **questions, int **boardStatus, int userCategory, int userQuestion){
    string userAnswer; //holds user answer

    cout << "\nQuestion: " << questions[userCategory][userQuestion] << "\n"
         << "Your Answer: ";
    getline(cin, userAnswer);

    boardStatus[userCategory][userQuestion] = 0; //changes the array value based on user inputted index
    
   return userAnswer; 
}

/* 
    Returns: string
    Params: string

   This function iterates through the inputted string and converts whatever uppercase letter there is to lowercase

*/
string toLowerString(string input){
    string lowerString = ""; //initializing an empty string container

    for(int i = 0; i < input.length(); i++){
        if(isupper(input[i])){ //used the cctype library https://cplusplus.com/reference/cctype/
            input[i] = tolower(input[i]);
        }
        lowerString += input[i]; //adding the individual letter to the empty string container?? idk if this works 
    }
   return lowerString; 
}

/* 
    Returns: bool
    Params: string**, string, int, int

    This function iterates through the user's string and the file's string then compares the two answers based on the lowercase relation.
    There is a setup I made where if the file has two words, each word was split into two elements in an array which are 
    individually compared to the concatenated user string as a whole.

*/
bool checkAnswer(string **answers, string userAnswer, int userCategory, int userQuestion){
    string lowerUserAnswer = toLowerString(userAnswer); //calling the above function to ensure the answer is all lowercase
    string lowerRealAnswer = toLowerString(answers[userCategory][userQuestion]);

    string realAnswerArray[2] = {"", ""}; // will be filled with the split strings 
    int words = 0;
    string tempRealString = ""; //holds container for the real answer

    for(int i = 0; i < lowerRealAnswer.length(); i++ ){ //Made up this concept. Not sure if its legal
        
        if(lowerRealAnswer[i] != ' '){
            tempRealString += lowerRealAnswer[i];
        }else{
            realAnswerArray[words] = tempRealString;
            words++; //keeps track of how many words are in the array
            tempRealString = ""; //cleans container for second string
        }
    }

    if(lowerUserAnswer == lowerRealAnswer){
        return true;
    }else if(realAnswerArray[0] != "" && lowerUserAnswer.find(realAnswerArray[0]) != string::npos){ //using same sources as LAB 7!!!
        return true;
    }else if(realAnswerArray[1] != "" && lowerUserAnswer.find(realAnswerArray[1]) != string::npos){
        return true;
    }
    
   return false; 
}