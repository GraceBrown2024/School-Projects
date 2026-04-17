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
    string userName;                //holds YOU!
    int peopleNum = countPeople();
    int *userNameIndex = nullptr;   //creates pointer variable that will hold a username's index
    bool loggedIn = true;           //initializes login for menu to keep looping

    Furby *listings;
    listings = new Furby[LISTSIZE]; //dynamically allocates a new furby array

    Account *account;
    account = new Account[peopleNum];    // allocates new account array

    createAccountArray(account);
    
    userName = homeScreen(account, peopleNum, userNameIndex);     //calls the login and intro screen function

    do{                                 //begins loop that continues as long as we are logged in
        switch(menu()){
            case 1:                     //each case is attributed to a function
                viewListings();
                break;
            case 2:
                addListing();
                break;
            case 3:
                editListing();
                break;
            case 4:
                removeListing();
                break;
            case 5:
                loggedIn = false;   //changes the bool variable to exit the switch loop
                break;
        }
    }while(loggedIn == true);
    
    cout << "\n" << userName << " has logged out.\n"; //goodbye message
    
    delete [] listings;             //deallocates the list 
    delete [] account;              // deallocates the accounts
    return 0;
}

/*
    Return Type : string
    Parameters  : struct array for Furby
    Returns     : username of YOU!
    Purpose     : Allows user to login to ebay account
                  Adds some "realism" to the listing program
*/
string homeScreen(Account *account, int peopleNum, int *userNameIndex){
    
    bool matchedAccount;
    string existingAccount, userName, password;
    string border(40, '=');
    string smallBorder(40, '-');

    int indexContainer = -1;        //creates space for userIndex to be stores in password check function
    userNameIndex = &indexContainer;    //holds that space


    cout << "\n" << border << "\n"
         << setw(14) << " " << "My eBay Login\n"
         << smallBorder
         << "\nDo you have an eBay account?\n[Y/N]: ";
    getline(cin, existingAccount);
    
    while(!cin || (lowerCase(existingAccount) != "y" && lowerCase(existingAccount) != "n")){    //validation loop!
        existingAccount = userValidation();
    }

    if(existingAccount == "y"){     //allows user to enter their existing account info
        cout << "\nEnter Username: ";
        getline(cin, userName);
        matchedAccount = accountExists(account, userName, peopleNum, 1, userNameIndex);                  

        if(matchedAccount == false){
            cout << "\nUsername not found!";                //add option to retype username OR add account
                                                    
        }else{
            cout << "\nWelcome back, " << userName << "!\n"
                 << "\nEnter Password: ";
            getline(cin, password);
            matchedAccount = accountExists(account, password, peopleNum, 2, userNameIndex);
        }
    }else{
        userName = addAccount(account, peopleNum);  //adds username from addAccount function 
    }
    return userName;
}

/*
    Return Type : int
    Parameters  : string
    Returns     : user choice for the menu to be used for a switch statement in main()
    Purpose     : displays the menu to alter/view your furbies that you are selling
*/
int menu(){
    int userChoice;   
    string border(40, '-');

    cout << "\n" << border << "\n"
         << setw(14) << "Select" << " One" << endl
         << "1.) View Furbies\n"
         << "2.) Add Furby Listing\n"
         << "3.) Edit Furby Listing\n"
         << "4.) Remove Furby Listing\n"
         << "5.) Log Out\n"
         << border << endl
         << "Select Option: ";
    cin >> userChoice;

    while(!cin || (userChoice < 1 || userChoice > 5)){
        userChoice = stoi(userValidation());
    }

    return userChoice;
}

/*
    Return Type : void
    Parameters  : 
    Returns     : n/a
    Purpose     : displays all the Furbies in your listing!!
*/
void viewListings(){
    cout << "View listings works";
}

/*
    Return Type : void
    Parameters  :
    Returns     : n/a
    Purpose     : creates a new struct Furby listing! Adds to the listing number in the first array
*/
void addListing(){
    cout << "Add listings works";
}

/*
    Return Type : void
    Parameters  :
    Returns     : n/a
    Purpose     : removes a furby in your listing array
*/
void removeListing(){
    cout << "Remove listings works";
}

/*
    Return Type : void
    Parameters  :
    Returns     : n/a
    Purpose     : allows you to edit any of your listing's qualities!
*/
void editListing(){
    cout << "Edit listings works";
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
    Return Type : string
    Parameters  : Account, int
    Returns     : newly created account name
    Purpose     : adds new username and password to accounts text file for future program use
*/
string addAccount(Account *account, int numPeople){
    string addedName, addedPassword, yesNo;
    string correctedName = "";      //creates container just in case name has space and needs to be corrected to underscore
    ofstream acc;                   //allows the accepted username and password to be written to the file
    bool userGood = false;
    int indexContainer = -1;
    int *userIndex = &indexContainer;

    acc.open("accounts.txt", ios::app);     //append mode for future entries

    do{                                     //begins loop that replays if the username is invalid or taken
        cout << "Desired Username: ";
        getline(cin, addedName);

        for(int i = 0; i < numPeople; i++){     //iterates through account array to check if a username already exists
            if(account[i].username == addedName){
                indexContainer = i;
                cout << "\nUser already exists! Log in as " << addedName << "?"     //allows you to log in right then and there if username exists
                     << "\n[Y/N]: ";
                getline(cin, yesNo);
                yesNo = lowerCase(yesNo);                   //forcibly lowercases user input for standardized testing

                while(yesNo != "y" && yesNo != "n"){     //calls my validation function to make sure y/n was entered
                    yesNo = userValidation();
                }
            
                if(yesNo == "y"){
                    cout << "Password for " << account[i].username << ": ";
                    getline(cin, addedPassword);            //allows user to put in their password attributed to the account

                    while(accountExists(account, addedPassword, numPeople, 2, userIndex) == false){
                        cin.clear();
                        cout << "Password incorrect! Try again: ";
                        getline(cin, addedPassword);
                    }

                    return account[i].username;       //stops this function
                }else{
                    userGood = false;       //allows user to input new username
                }
                break;
            }else{
                userGood = true;
            }
        } 
        
    }while(userGood == false);
    
    for(int i = 0; i < addedName.length(); i++){    //replaces all the spaces with an underscore
        if(addedName[i] == ' '){
            addedName[i] = '_';
        }
        correctedName += addedName[i];
    }

    do{                                             //allows user to input a new password
        cout << "\nDesired Password (No spaces!): ";
            getline(cin, addedPassword);
        
            for(int i = 0; i < addedPassword.length(); i++){
                if(addedPassword[i] == ' '){        //makes user retype password if it is illegal
                    cout << "Password not allowed!\n"
                        << "Enter a password with No spaces!";
                    userGood = false;
                    cin.clear();
                    break;
                }else{
                    userGood = true;
                }
            }
            
    }while(userGood == false);                      //replays if password is illegal
    
    acc << "\n" << correctedName + '#' + addedPassword; //adds username and password to file

    return correctedName;
}

/*
    Return Type : void
    Parameters  : Furby struct array
    Returns     : n/a
    Purpose     : transverses username/passwords files and processes given info into dynamic array
*/
void createAccountArray(Account *account){
    ifstream accounts;
    accounts.open("accounts.txt");
    int i = 0;
    while(getline(accounts, account[i].username, '#')){
        getline(accounts, account[i].password);
        i++;
    }

}

/*
    Return Type : void
    Parameters  : n/a
    Returns     : number of accounts in the acocunts file
    Purpose     : iterates through accounts file and counts up how many different accounts there are
                  return will be used to provide an itital array amount for account
*/
int countPeople(){
    int accountNum = 0;
    ifstream accounts;
    string data;

    accounts.open("accounts.txt");
    while(getline(accounts, data)){
        accountNum++;
    }
    return accountNum;
}

/*
    Return Type : bool
    Parameters  : Account, string, int, int, int*
    Returns     : True/False if username is found
    Purpose     : Iterates through accounts array and tells user if an account has been found
                  stores the index of the username so the parralel index can be matched with password
                this is possibly the smartest function i have ever written and possibly WILL ever write 
*/
bool accountExists(Account *account, string userInput, int numPeople, int situation, int *userNameIndex){
    if(situation == 1){
        for(int i = 0; i < numPeople; i++){
            if(account[i].username == userInput){
                *userNameIndex = i; //copies i into the pointers current slot of memory (in Homescreen() where -1 is currently at)
                return true;
            }
        }
    }else if(situation == 2){
        if(userInput == account[*userNameIndex].password){
            return true;
        }
    }
    return false;
}