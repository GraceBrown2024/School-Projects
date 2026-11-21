/*
DEVELOPER   : Grace Brown
DATE STARTED: 10 Nov 2026
LAST EDITED : 20 Nov 2026
------------------------
PURPOSE     : definitions for userInfo. Allows user to create an account, add their 
              goals, and keep track of what they log based on their account
*/


/*
############ FUNCTIONS TO COMPLETE ###########
profileCreation()
profileLogIn()
updateInfo()
deleteProfile()
displayProfile()
settings() --- JUST CASE 3!

*/



#include <iostream>
#include <string>
#include <filesystem>   //used for creating subdirectories!
#include <fstream>  //updates the Users.txt in Data/ 
#include <cctype>    //username correcting 
#include <vector>   //for username storing and updating
#include "UserInfo.h" 
using namespace std;


/*
NAME: loadUsers
PARAMETERS: NONE
RETURNS: NONE
USE: Opens the users file, adds all the names to a vector for iteration 
*/
vector<string> UserInfo::loadUsers(){
    vector<string> usersList;
    ifstream users;
    users.open("Data/Users.txt");

    if(users.is_open()){
        string input;
        while(getline(users, input, '#')){
            usersList.push_back(input); //adds a name to the vector
        }
        users.close();
    }else{
        cout << "\nError: Could not find User Database\n";
    }

    return usersList;

}

/*
NAME: assignedSex
PARAMETERS: integer with user choice from profileCreation
RETURNS: string with the users choice
USE: ensures MALE and FEMALE are uniform in each profile
*/
string UserInfo::assignedSex(int userChoice){
    string sex;
    if(userChoice == 1){
        sex = "MALE";
    }else{
        sex = "FEMALE";
    }
    return sex;
}

/*
NAME: correctedUserName
PARAMETERS: string holding users inserted name
RETURNS: corrected string
USE: Ensures the custom directory doesnt have random stuff in the name
*/
string UserInfo::correctedUserName(string tempName){
    string correctName = "";
    for(long unsigned int i = 0; i < tempName.length(); i++){
        if(!(isalnum(tempName[i]))){
            continue;
        }else{
            correctName = correctName + tempName[i];
        }
    }
    return correctName;
}

/* -------------------- WIP -------------------
NAME: profileCreation
PARAMETERS: NONE
RETURNS: NONE
USE: Allows user to create a profile. This will create a subfolder in the Profiles folder
     that holds their information in a file, their custom foods, and daily logs
*/
void UserInfo::profileCreation(){
    string tempName;
    string newUser;

    filesystem::path profileFolder = "Profiles"; 
    cin.clear();
    cin.ignore(100, '\n');

    cout << "Please enter Username: ";
    getline(cin, tempName);
    newUser = correctedUserName(tempName); //corrects the username to elimate non alphanum chars
    filesystem::path newProfile = profileFolder / newUser;

    while(newUser.empty() || exists(newProfile)){
        cin.clear();

        if(newUser.empty()){
            cout << "Username Cannot be Blank!\n";
        }else{
            cout << "Username already taken!\n";
        }
            cout << "Please choose a different Username: ";
        getline(cin, newUser);

        newProfile = profileFolder / newUser;
    }
    //USING https://www.geeksforgeeks.org/cpp/file-system-library-in-cpp-17/
    filesystem::create_directories(newProfile);

    UserInfo newUserObj; //creates new user object
    string pWord;
    cout << "Please create a password: ";
    getline(cin, pWord); //will create validation later
    newUserObj.setPassword(pWord);

    string tempString;
    int tempInt;
    double tempDoub;
    newUserObj.setUsername(newUser);
    cout << "\nWelcome " << newUser << "!" << endl
         << "Let's get some information from you...\n"
         << "--------------------------------------\n"
         << "Enter Name: ";
    getline(cin, tempString);
    newUserObj.setName(tempString);
    cout << "Enter Age: "; //FUTURE IDEA: Implement birthday real-time tracking for updated age
    cin >> tempInt;
    newUserObj.setAge(verification(tempInt, 1000, 18));
    cout << "Sex Assigned at Birth: \n"
         << "[1. MALE]\n[2.FEMALE]\nSelect: ";
    cin >> tempInt;
    newUserObj.setSex(assignedSex(verification(tempInt, 2, 1))); //holy composition
    cout << "Calorie Limit (Minimum 1200): ";
    cin >> tempInt;
    newUserObj.setCalorieLimit(verification(tempInt, 10000, 1200));
    cout << "Enter Current Weight(lbs): ";
    cin >> tempDoub;
    tempInt = tempDoub * 10.0; //for array purposed we will convert to int
    newUserObj.setCurrentWeight(verification(tempInt, 10000, 0));
    newUserObj.setStartingWeight(verification(tempInt, 10000, 0));
    
    ofstream userFile;
    userFile.open("Data/Users.txt", ios::app);
    userFile << newUserObj.getUsername() << "#";
    userFile.close();

    cout << newUserObj.getUsername() << " ADDED TO FILE\n";

}

/* ---------------------- WIP ---------------------
NAME: profileLogIn
PARAMETERS: NONE
RETURNS: NONE
USE: Allows user to log back in to their account. 
     Goes through a 2d array with their information to match the password and username
*/
void UserInfo::profileLogIn(){

}

/*
NAME: verification
PARAMETERS: integer with users previous choice
RETURNS: corrected userChoice
USE: allows program to stay within bounds for user entry
*/
int UserInfo::verification(int userChoice, int upperBound, int lowerBound){
    while((userChoice < lowerBound) || (userChoice > upperBound)){
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Please enter a value between " << lowerBound << " and " << upperBound << "!\n";
        cin >> userChoice;
    }
    return userChoice;
}

/*
NAME: profileMenu
PARAMETERS: NONE
RETURNS: NONE
USE: displays menu upon booting program to either log in or sign up
*/
void UserInfo::profileMenu(){
    int userChoice;
    cout << "-----------------\n"
         << "Food Tracker 1310\n"
         << "-----------------\n"
         << "[1. Log In]   [2. Create Account]\n"
         << "ENTER CHOICE -> ";
    cin >> userChoice;
    while(!cin){    //verification for incorrect data type
        cin.clear();
        cin.ignore(100, '\n');
        cout << "\nPlease enter an Integer!\n"
             << "ENTER CHOICE -> ";
        cin >> userChoice;
    }
    switch(verification(userChoice, 2, 1)){
        case 1:
            profileLogIn(); 
            break;
        case 2:
            profileCreation();
            break;
    }

}


/* --------------- WIPPPPP --------------------
NAME: updateInfo
PARAMETERS: NONE
RETURNS: NONE
USE: User can update any of their profile features. 
     This updates their subfolder and the 2D array of profile
*/
void UserInfo::updateInfo(){

}

/* ----------------- WIPPPPPPPPPPPPP -------------------
NAME: deleteProfile
PARAMETERS: NONE
RETURNS: NONE
USE: allows user to delete their account.
    This removes their subfolder and their entries from the user 2D array
*/
void UserInfo::deleteProfile(){

}

/* ----------------- WIPPPPPPPPPPPPP -------------------
NAME: displayProfile
PARAMETERS: NONE
RETURNS: NONE
USE: Prints all info from user's profile text file
*/
void UserInfo::displayProfile(){


}

/* -------------- WIPPP ADD CASE 3 LOGOUT
NAME: settings
PARAMETERS: NONE
RETURNS: NONE
USE: gives user the choice to either delete, update, or log out of their profile
     displays a menu for choice
*/
void UserInfo::settings(){
    int userChoice;
    cout << "\n----- SETTINGS ----- \n"
         << "[1. Update Profile ]\n"
         << "[2. View Profile ]\n"
         << "[3. Log Out ]\n"
         << "[4. Delete Account ]\n"
         << "\n[5. BACK TO HOME]\n"
         << "--------------------\n"
         << "SELECT CHOICE: ";
    cin >> userChoice;
    while(!cin){
        cin.clear();
        cin.ignore(100, '\n');
        cout << "\nPlease enter an INTEGER: ";
        cin >> userChoice;
    }
    switch(verification(userChoice, 5, 1)){
        case 1:
            updateInfo();
            break;
        case 2:
            displayProfile();
            break;
        case 3:
            //ADD LOGOUT STUFF
            break;
        case 4:
            deleteProfile();
            break;
        case 5:
            //nothing
            break;
    }

}  

//GETTERS------------------------------
string UserInfo::getName() const {
    return name;
}

int UserInfo::getAge() const {
    return age;
}

string UserInfo::getSex() const {
    return sex;
} 

int UserInfo::getCalorieLimit() const {
    return calorieLimit;
}

double UserInfo::getStartingWeight() const {
    return startingWeight;
}

double UserInfo::getCurrentWeight() const {
    return currentWeight;
}

string UserInfo::getUsername() const {
    return username;
}

//SETTERS ------------------
void UserInfo::setName(string n){
    name = n;
}

void UserInfo::setAge(int a){
    age = a;
}

void UserInfo::setSex(string s){
    sex = s;
}

void UserInfo::setCalorieLimit(int cL){
    calorieLimit = cL;
}

void UserInfo::setStartingWeight(double sW){
    startingWeight = sW;
}

void UserInfo::setCurrentWeight(double cW){
    currentWeight = cW;
}

void UserInfo::setUsername(string uN){
    username = uN;
}

void UserInfo::setPassword(string pW){
    password = pW;
}

