/*
Name        : Grace Brown
File        : Theater.cpp
Created     : 9/8/2026
Last Updated: 9/8/2026
Purpose     :
*/

#include "Theater.h"
#include <iostream>
#include <string>


int Theater::getNumMovies(){
    return numMovies;
}
int Theater::getNumShowings(){
    return numShowings;
}
void Theater::addMovie(){
    cin.ignore(100,'\n');
    if(numMovies == maxMovies){
        cout << "\nYour Movie List is Full!" << endl;
        return;
    }else{
        string title, rating;
        int releaseY, runT;
        cout << "\nWhat is the title of your movie? ";
        getline(cin, title, '\n');
        cout << "\nWhen was the release Year? ";
        cin >> releaseY;
        while(!cin){
            cin.clear();
            cin.ignore(100, '\n');
            cout << "\nPlease enter a valid number! ";
            cin >> releaseY;
        }
        cin.ignore(100,'\n');
        cout << "\nWhat is the Runtime? ";
        cin >> runT;
        while(!cin){
            cin.clear();
            cin.ignore(100, '\n');
            cout << "\nPlease enter a valid number! ";
            cin >> runT;
        }
        cin.ignore(100,'\n');
        cout << "\nWhat is your rating of the movie? ";
        getline(cin, rating, '\n');

        movieArray[numMovies] = new Movie(title, releaseY, runT, rating);
        numMovies++;

        cout << title << " added to list!\n"
             << "You now have " << numMovies << " in your list.\n";

    }
}
void Theater::editMovie(){
    if(numMovies == 0){
        cout << "No movies present in your list!";
    }else{
        bool confirm = true;
        int arrayIndex;
        do{
            int x;
            cout << "Which movie would you like to edit?\n";
            for(int i = 0; i < numMovies; i++){
                cout << i+1 << ".) " << movieArray[i]->getTitle() << endl;
            }
            cin >> x;
            while(!cin || (x < 1 || x > numMovies)){
                cin.clear();
                cin.ignore(100, '\n');
                cout << "Please enter a valid number: ";
                cin >> x;
            }
            cin.ignore(100, '\n');

        
            char yn;
            cout << "Are you sure you want to edit " << movieArray[x - 1]->getTitle() << "?\n"
                 << "[Y/N]: ";
            cin >> yn;
            yn = toupper(yn);
            while(!cin || (yn != 'Y' && yn != 'N')){
                cin.clear();
                cin.ignore(100, '\n');
                cout << "Please enter a valid answer: ";
                cin >> yn;
                yn = toupper(yn);
            }
            cin.ignore(100, '\n');

            if(yn == 'N'){
                confirm = false;
            }else{
                arrayIndex = x - 1;
            }

        }while(!confirm);

        movieArray[arrayIndex]->editMovie();
        
    }
}
void Theater::addShowing(){
    if(numMovies == 0 ){
        cout << "\nYou do not have any movies in your list!\n";
    }else if(numShowings == maxShowings){
        cout << "\nYour Showings list is full!\n";
    }else{
        bool confirm = true;
        int auditoriumN, seatsA;
        float ticketP;
        string showT;
        Movie* title;

        do{
            int x;
            char yn;
            cout << "\nWhich Movie's Showing would you like to add?\n";
            printMovieNames();
            cout << "\nEnter Choice Here: ";
            cin >> x;
            while(!cin){
                cin.clear();
                cin.ignore(100, '\n');
                cout << "Please enter a valid option! ";
                cin >> x;
            }
            cin.ignore(100, '\n');

            cout << "\nAre you sure you want to add to " << movieArray[x-1]->getTitle() << "'s showings?\n"
                 << "[Y/N] --> ";
            cin >> yn;
            yn = toupper(yn);
            while(!cin || (yn != 'Y' && yn != 'N')){
                cin.clear();
                cin.ignore(100, '\n');
                cout << "Please enter a valid Option: ";
                cin >> yn;
                yn = toupper(yn);
            }
            if(yn == 'N'){
                confirm == false;
            }
            title = movieArray[x-1];
        }while(!confirm);
        cin.ignore(100, '\n');

        cout << "When is the showtime? ";
        getline(cin, showT, '\n');
        cout << "What is the Auditorium Number? ";
        cin >> auditoriumN;

        while(!cin){
            cin.clear();
            cin.ignore(100, '\n');
            cout << "\nPlease enter a valid number! ";
            cin >> auditoriumN;
        }  
        cin.ignore(100, '\n'); 

        cout << "What is the Ticket Price? ";
        cin >> ticketP;

        while(!cin){
            cin.clear();
            cin.ignore(100, '\n');
            cout << "\nPlease enter a valid number! ";
            cin >> ticketP;
        }  
        cin.ignore(100, '\n');
        
        cout << "How many seats are available? ";
        cin >> seatsA;

        while(!cin){
            cin.clear();
            cin.ignore(100, '\n');
            cout << "\nPlease enter a valid number! ";
            cin >> seatsA;
        }  
        cin.ignore(100, '\n'); 

        showingArray[numShowings] = new Showing(title, showT, auditoriumN, ticketP, seatsA);
        numShowings++;

        cout << "\nShowing has been added to " << title->getTitle() << "!\n"
             << "There are now " << numShowings << " in " << title << ".\n";
    }
}
void Theater::editShowing(){
    if(numShowings == 0){
        cout << "\nYou have no showings!\n";
        return;
    }else{
        int x;
        cout << "\nWhich Showing would you like to edit? ";
        printShowingNames();

        cin >> x;
        if(!cin || (x < 1 || x > numShowings)){
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Please enter a valid option! ";
            cin >> x;
        }
        cin.ignore(100, '\n');

        showingArray[x-1]->editShowing();
    }
}
void Theater::printMovies(){
    if(numMovies == 0){
        cout << "You have No movies!";
    }else{
        for(int i = 0; i < numMovies; i++){
            movieArray[i]->printMovie();
        }
    }
}
void Theater::printShowings(){
    if(numMovies == 0){
        cout << "You have No Showings!";
    }else{
        for(int i = 0; i < numShowings; i++){
            showingArray[i]->printShowing();
        }
    }
}
void Theater::printMovieNames(){
    if(numMovies == 0){
        cout << "You have No movies!";
    }else{
        for(int i = 0; i < numMovies; i++){
            cout << "\n" << i + 1 << ".)" << movieArray[i]->getTitle();
        }
    }
}
void Theater::printShowingNames(){
    if(numMovies == 0){
        cout << "You have No Showings!!";
    }else{
        for(int i = 0; i < numShowings; i++){
            cout << "\n" << showingArray[i]->getMovie()->getTitle()
                 << showingArray[i]->getShowTime() << endl;
            
        }
    }
}