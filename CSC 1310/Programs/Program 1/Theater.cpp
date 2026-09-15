/*
Name        : Grace Brown
File        : Theater.cpp
Created     : 9/8/2026
Last Updated: 9/14/2026
Purpose     : define theatre class functions
*/

#include "Theater.h"
#include <iostream>
#include <string>

//getters for Theatre class
int Theater::getNumMovies(){
    return numMovies;
}
int Theater::getNumShowings(){
    return numShowings;
}
/* allows user to add movie and create a new item in the movie array
*/
void Theater::addMovie(){
    cin.ignore(100,'\n');
    if(numMovies == maxMovies){ //returns function to prevent overflowing the array
        cout << "\nYour Movie List is Full!" << endl;
        return;
    }else{  //if not full, movie is allowed to be added in array
        string title, rating;
        int releaseY, runT;
        cout << "\nWhat is the title of your movie? ";
        getline(cin, title, '\n');
        cout << "\nWhen was the release Year? ";
        cin >> releaseY;
        while(!cin){    //verification
            cin.clear();
            cin.ignore(100, '\n');
            cout << "\nPlease enter a valid number! ";
            cin >> releaseY;
        }
        cin.ignore(100,'\n');
        cout << "\nWhat is the Runtime? ";
        cin >> runT;
        while(!cin){    //verification
            cin.clear();
            cin.ignore(100, '\n');
            cout << "\nPlease enter a valid number! ";
            cin >> runT;
        }
        cin.ignore(100,'\n');
        cout << "\nWhat is your rating of the movie? ";
        getline(cin, rating, '\n');

        movieArray[numMovies] = new Movie(title, releaseY, runT, rating);   //dynamically allocates a new movie object and assigns it to the newest index on array
        numMovies++;

        cout << title << " added to list!\n"
             << "You now have " << numMovies << " in your list.\n";

    }
}

/* allows user to edit a movie they select. Accesses the members attributes and alters the values
    returns void 
*/
void Theater::editMovie(){
    if(numMovies == 0){ //prevents printing to occur without an item in the array
        cout << "No movies present in your list!";
    }else{
        bool confirm = true;
        int arrayIndex;
        do{ //allows user to choose which movie to edit and which attributes to edit
            int x;
            cout << "Which movie would you like to edit?\n";
            for(int i = 0; i < numMovies; i++){
                cout << i+1 << ".) " << movieArray[i]->getTitle() << endl;  //prints the title of the movie correlating to the index
            }
            cin >> x;
            while(!cin || (x < 1 || x > numMovies)){    //verification
                cin.clear();
                cin.ignore(100, '\n');
                cout << "Please enter a valid number: ";
                cin >> x;
            }
            cin.ignore(100, '\n');

        
            char yn;    //created yesNo character variable to allow the user to verify later
            cout << "Are you sure you want to edit " << movieArray[x - 1]->getTitle() << "?\n"
                 << "[Y/N]: ";  //here is later lol
            cin >> yn;
            yn = toupper(yn);   //converts the char to uppercase to provide a standard comparison model
            while(!cin || (yn != 'Y' && yn != 'N')){    //verification
                cin.clear();
                cin.ignore(100, '\n');
                cout << "Please enter a valid answer: ";
                cin >> yn;
                yn = toupper(yn);
            }
            cin.ignore(100, '\n');

            if(yn == 'N'){
                confirm = false;    //switches bool to allow menu to repeat
            }else{
                confirm = true;
                arrayIndex = x - 1;
            }

        }while(!confirm);   //evaluates bool for menu

        movieArray[arrayIndex]->editMovie();    //changes the items in the chosen index
        
    }
}

/*  allows user to add a showing for a movie
returns void
*/
void Theater::addShowing(){
    if(numMovies == 0 ){
        cout << "\nYou do not have any movies in your list!\n"; //prevents function from playing without showing in array
    }else if(numShowings == maxShowings){
        cout << "\nYour Showings list is full!\n";
    }else{
        bool confirm = true;    //will allow replay of menu in future
        int auditoriumN, seatsA;
        float ticketP;
        string showT;
        Movie* title;  

        do{ //creates menu for user to add a showing to a specific movie
            int x;
            char yn;
            cout << "\nWhich Movie's Showing would you like to add?\n";
            printMovieNames();  //calls the loop for printing names 
            cout << "\nEnter Choice Here: ";
            cin >> x;
            while(!cin || (x < 0 || x > numMovies)){ //verification
                cin.clear();
                cin.ignore(100, '\n');
                cout << "Please enter a valid option! ";
                cin >> x;
            }
            cin.ignore(100, '\n');

            cout << "\nAre you sure you want to add to " << movieArray[x-1]->getTitle() << "'s showings?\n"
                 << "[Y/N] --> ";
            cin >> yn;
            yn = toupper(yn);   //standardizes char
            while(!cin || (yn != 'Y' && yn != 'N')){    //verification
                cin.clear();
                cin.ignore(100, '\n');
                cout << "Please enter a valid Option: ";
                cin >> yn;
                yn = toupper(yn);
            }
            if(yn == 'N'){
                confirm = false;    //switches bool to allow menu to repeat
            }else{
                confirm = true;
            }
            title = movieArray[x-1];    //assigns title to the showing to prevent dupes
        }while(!confirm);
        cin.ignore(100, '\n');

        cout << "When is the showtime? ";
        getline(cin, showT, '\n');
        cout << "What is the Auditorium Number? ";
        cin >> auditoriumN;

        while(!cin){    //verif
            cin.clear();
            cin.ignore(100, '\n');
            cout << "\nPlease enter a valid number! ";
            cin >> auditoriumN;
        }  
        cin.ignore(100, '\n'); 

        cout << "What is the Ticket Price? ";
        cin >> ticketP;

        while(!cin){    //verif
            cin.clear();
            cin.ignore(100, '\n');
            cout << "\nPlease enter a valid number! ";
            cin >> ticketP;
        }  
        cin.ignore(100, '\n');
        
        cout << "How many seats are available? ";
        cin >> seatsA;

        while(!cin){    //verif
            cin.clear();
            cin.ignore(100, '\n');
            cout << "\nPlease enter a valid number! ";
            cin >> seatsA;
        }  
        cin.ignore(100, '\n'); 

        showingArray[numShowings] = new Showing(title, showT, auditoriumN, ticketP, seatsA); //dynamically creates new Showing object to add to showing array last index
        numShowings++;

        cout << "\nShowing has been added to " << title->getTitle() << "!\n"
             << "There are now " << numShowings << " in " << title << ".\n";    //confirms showing has been added
    }
}

/*  Allows user to edit showing info
    returns void
*/
void Theater::editShowing(){
    if(numShowings == 0){
        cout << "\nYou have no showings!\n";    //prevents function from proceeding
        return;
    }else{
        int x;
        cout << "\nWhich Showing would you like to edit? ";
        printShowingNames();    //prints list of showings added

        cin >> x;
        if(!cin || (x < 1 || x > numShowings)){ //verif
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Please enter a valid option! ";
            cin >> x;
        }
        cin.ignore(100, '\n');

        showingArray[x-1]->editShowing();   //updates the array index with new values
    }
}
/* Prints a list of movies by iterating through the movies array
returns void
*/
void Theater::printMovies(){
    if(numMovies == 0){
        cout << "You have No movies!";
    }else{
        for(int i = 0; i < numMovies; i++){
            movieArray[i]->printMovie();
        }
    }
}
/* prints list of showings by iterating through the showings array
returns void
*/
void Theater::printShowings(){
    if(numMovies == 0){
        cout << "\nYou have No Showings!\n";    //prevents printing nothing
    }else{
        for(int i = 0; i < numShowings; i++){
            showingArray[i]->printShowing();
        }
    }
}
/*  prints the TITLES of the movie by iterating through the movies array and showing the title attribute
returns void
*/
void Theater::printMovieNames(){
    if(numMovies == 0){
        cout << "\nYou have No movies!\n";  //prevents printing nothing
    }else{
        for(int i = 0; i < numMovies; i++){
            cout << "\n" << i + 1 << ".)" << movieArray[i]->getTitle();
        }
    }
}

/*prints the list of names of the movies and their showings attributed
returns void
*/
void Theater::printShowingNames(){
    if(numMovies == 0){
        cout << "\nYou have No Showings!!\n";   //prevents printing nothing
    }else{
        for(int i = 0; i < numShowings; i++){
            cout << "\n" << showingArray[i]->getMovie()->getTitle()
                 << showingArray[i]->getShowTime() << endl;
            
        }
    }
}