/*
DEVELOPER   : Grace Brown
DATE STARTED: 10 Nov 2026
LAST EDITED : 20 Nov 2026
------------------------
PURPOSE     : Class for userInfo
*/

#ifndef USERINFO_H
#define USERINFO_H
#include <iostream>
#include <string>

    class userInfo{
        private:
            string name;
            int age;
            string sex; //haha
            int calorieLimit;
            double startingWeight;
            double currentWeight;
            string password; //very secure. trust me
            string username;
        public:
            userInfo(){
                name = "John Doe"; 
                age = 18;
                sex = "MALE";
                calorieLimit = 2500;
                startingWeight = 190;
                currentWeight = 190;
            }
            userInfo(string name, int age, string sex, int calorieLimit, double startingWeight, double currentWeight, string password, string username){
            name = name;
            age = age;
            sex = assignedSex(); 
            calorieLimit = calorieLimit;
            startingWeight = startingWeight;
            currentWeight = currentWeight;
            password = password; //very secure. trust me. 
            username = username;
            }

            string assignedSex(int userChoice); //assigns sex to user based on previous choice given
            void profileCreation(); //creates a folder in daily_logs with their info in a file ... WIP
            void profileLogIn(); // accesses 2d array with user info that accesses the logs folder ... WIP
            void profileMenu(); // displays menu upon booting program to log in or create account
            int verification(int userChoice, int upperBound, int lowerBound); //verification for user input
            void updateInfo(); //allows user to choose what items to update in their profile
            void deleteProfile(); //allows user to delete their account once logged in
            void settings(); // user settings to either log out, delete profile, or update info
            void displayProfile(); //displays all the information for the user's profile
    }
#endif