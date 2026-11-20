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


############ FUNCTIONS TO FIX ###############
profileMenu()  [FORMATTING]

*/



#include <iostream>
#include <string>
#include "UserInfo.h"
using namespace std;

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

/* -------------------- WIP -------------------
NAME: profileCreation
PARAMETERS: NONE
RETURNS: NONE
USE: Allows user to create a profile. This will create a subfolder in the daily_logs folder
     that holds their information in a file, their custom foods, and daily logs
*/
void UserInfo::profileCreation(){


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

/* ---- FIX FORMATIING ----
NAME: profileMenu
PARAMETERS: NONE
RETURNS: NONE
USE: displays menu upon booting program to either log in or sign up
*/
void UserInfo::profileMenu(){
    int userChoice;
    cout << "\n-----------------\n"
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
USE: iterates through profile array and prints all the info
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