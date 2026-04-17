/*
    Author      : Grace Brown
    Created     : 16 April 2026
    Last Edited : 16 April 2026
    File Name   : Lab10.cpp
    Purpose     : Sell your furbies on eBay! Keep track of
                  your listings!
*/

#include "Lab10.h"

int main(){
    string userName;                //holds name of YOU! doesnt really impact gameplay

    Furby *listings;
    listings = new Furby[LISTSIZE]; //dynamically allocates a new furby array

    
    userName = homeScreen();        //calls the login and intro screen function
    
    delete [] listings;             //deallocates the list 
    return 0;
}

/*
    Return Type : string
    Parameters  : n/a
    Returns     : username of YOU!
    Purpose     : Allows user to login to ebay account
                  Adds some "realism" to the listing program
*/
string homeScreen(){
    
    bool matchedAccount;
    string existingAccount, userName, password;
    string border(40, '=');
    string smallBorder(40, '-');

    cout << "\n" << border << "\n"
         << setw(14) << " " << "My eBay Login\n"
         << smallBorder
         << "\nDo you have an eBay account?\n[Y/N]: ";
    getline(cin, existingAccount);
    
    while(!cin || (lowerCase(existingAccount) != "y" && lowerCase(existingAccount) != "n")){
        existingAccount = userValidation();
    }

    if(existingAccount == "y"){
        cout << "\nEnter Username: ";
        getline(cin, userName);
        matchedAccount = userNameFound(userName);

        if(matchedAccount == false){
            cout << "\nUsername not found!";

        }else{
            cout << "\nWelcome back, " << userName << "!\n"
                 << "\nEnter Password: ";
            getline(cin, password);
            matchedAccount = passwordMatch(password);
        }
    }else{
        addAccount();
    }

    return userName;
}

/*
    Return Type : int
    Parameters  : 
    Returns     : user choice for the menu to be used for a switch statement in main()
    Purpose     : displays the menu to alter/view your furbies that you are selling
*/
int menu(){
    int userChoice;

    return userChoice;
}

/*
    Return Type : void
    Parameters  : 
    Returns     : n/a
    Purpose     : displays all the Furbies in your listing!!
*/
void viewListings(){

}

/*
    Return Type : void
    Parameters  :
    Returns     : n/a
    Purpose     : creates a new struct Furby listing! Adds to the listing number in the first array
*/
void addListing(){

}

/*
    Return Type : void
    Parameters  :
    Returns     : n/a
    Purpose     : removes a furby in your listing array
*/
void removeListing(){

}

/*
    Return Type : void
    Parameters  :
    Returns     : n/a
    Purpose     : allows you to edit any of your listing's qualities!
*/
void editListing(){

}

/*
    Return Type : string
    Parameters  : n/a
    Returns     : user inputted string that is acceptable 
    Purpose     : halts the user if they put in an unacceptable input and allows chance to retype answer
*/
string userValidation(){
    string validatedInput;

    cin.clear();
    cout << "Please enter a valid option: ";
    getline(cin , validatedInput);

    return validatedInput;
}

/*
    Return Type : string
    Parameters  : string
    Returns     : user's string but completely lowercased and bunched together 
    Purpose     : used for menu items where alphabetic words/characters are needed for sorting or verification
                  allows sorting and conditionals to be standardized with an all lowercased string to compare
*/
string lowerCase(string userInput){
    string loweredInput = ""; //empty container for the new lowercase string

    for(int i = 0; i < userInput.length(); i++){
        if(isalpha(userInput[i]) && userInput[i] != ' '){
            loweredInput += userInput[i];
        }else{
            continue;
        }
    }
    return loweredInput;
}

/*
    Return Type : bool
    Parameters  : string
    Returns     : true if name is found in array, false if name not found
    Purpose     : accesses array containing all created usernames and 
                  transverses through it to find a matching name 
                  ... Adds realism!!!
*/
bool userNameFound(string userInput){
    /*                                                //NOTE!!!! Fix this to be sorting through an ARRAY 
    ifstream usernames;
    string names;

    usernames.open("usernames.txt");
    while(getline(usernames, names)){
        if(names == userInput){
            return true;
        }
    }
    return false;
    */
}

/*
    Return Type : bool
    Parameters  : string
    Returns     : true if password is found in array, false if password not found
    Purpose     : accesses array containing all created passwords and 
                  transverses through it to find a matching password
                  ... Adds realism!!!
*/
bool passwordMatch(string userInput){
   /*                                                   //NOTE!!!! Fix this to be sorting through an ARRAY 
   ifstream passwords;
    string inputPassword;

    passwords.open("passwords.txt");
    while(getline(passwords, inputPassword)){
        if(userInput == inputPassword){
            return true;
        }
    }
    return false;
    */
}

/*
    Return Type : string
    Parameters  : n/a
    Returns     : newly created account name
    Purpose     : adds new username and password to respective files for future program use
*/
string addAccount(){
    string addedName, addedPassword;
    ofstream usernames, passwords;

    usernames.open("usernames.txt");
    passwords.open("passwords.txt");


    return addedName;
}

/*
    Return Type : void
    Parameters  : n/a
    Returns     : n/a
    Purpose     : transverses username/passwords files and adds each respective name 
                  and password to a 2d array
*/
void createAccountArray(){

}