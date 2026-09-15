/*
Name        : Grace Brown
File        : Showing.cpp
Created     : 9/8/2026
Last Updated: 9/14/2026
Purpose     : define functions for Showing class
*/

#include "Showing.h"

//Setters and Getters for the Showing arrays
void Showing::setMovie(Movie* m){   //accesses the array that holds the movies
    movie = m;
}
void Showing::setShowTime(string sT){
    showTime = sT;
}
void Showing::setAuditoriumNumber(int aN){
    auditoriumNumber = aN;
}
void Showing::setTicketPrice(float tP){
    ticketPrice = tP;
}
void Showing::setSeatsAvailable(int sA){
  seatsAvailable = sA;  
}
Movie* Showing::getMovie(){     //getters allow the driver to access private attributes
    return movie;
}
string Showing::getShowTime(){
    return showTime;    
}
int Showing::getAuditoriumNumber(){
    return auditoriumNumber;
}
float Showing::getTicketPrice(){
    return ticketPrice;
}
int Showing::getSeatsAvailable(){
    return seatsAvailable;
}

/*Edit Showing Function
    Returns Void
    Allows user to enter new information to showing array members
*/
void Showing::editShowing(){
    int x;
    do{
    int tempNum = 0;
    string tempStrng = "";
    float tempFloat;
//Menu option for selection
    cout << "Please select a Choice:\n"
         << "1.) Change Show Time\n"
         << "2.) Change Auditorium Number\n"
         << "3.) Change Ticket Price\n"
         << "4.) Change Seats Available\n"
         << "5.) QUIT EDITING \n"
         << "----- ENTER NUMBER --> ";
    cin >> x;

    while(!cin || (x < 1 || x > 5)){    //Verification for int type
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Please enter a VALID choice!\n"
             << "--> ";
        cin >> x;
    }

    cin.ignore(100, '\n');

    switch(x){  //switch case allows user to choose which item they want to edit specifically
        case 1:
            cout << "\nPlease enter your New Show Time: ";
            getline(cin, tempStrng, '\n');
            Showing::setShowTime(tempStrng);    //sets a new show time
            break;

        case 2:
            cout << "Please enter your New Auditorium Number: ";
            cin >> tempNum;

            while(!cin){    //verification for int
                cin.clear();
                cin.ignore(100, '\n');
                cout << "\nPlease enter a VALID Number: ";
                cin  >> tempNum;
            }
            cin.ignore(100, '\n');
            Showing::setAuditoriumNumber(tempNum);  //sets the new info for auditorium num
            break;
        
        case 3:
            cout << "Please enter your New Ticket Price: ";
            cin >> tempFloat;

            while(!cin){    //verification 
                cin.clear();
                cin.ignore(100, '\n');
                cout << "\nPlease enter a VALID amount: ";
                cin  >> tempFloat;
            }
            cin.ignore(100, '\n');
            Showing::setTicketPrice(tempFloat);
            break;
        
        case 4:
            cout << "Please enter your New Seats Available: ";
            cin >> tempNum;

            while(!cin){    //verification
                cin.clear();
                cin.ignore(100, '\n');
                cout << "\nPlease enter a VALID amount: ";
                cin  >> tempNum;
            }
            cin.ignore(100, '\n');

            Showing::setSeatsAvailable(tempNum);
            break;
    }
    cout << "\n";

   }while(x != 5);  //repeats the menu if the user does not choose 5 (quit)
}

/* Prints a single showing's info. Returns void. Will be used in a loop to access each array in Showing
*/
void Showing::printShowing(){
    string currentTitle;

    if(movie == nullptr){
        currentTitle = "[NO MOVIE ASSIGNED]";   //renames the title to no movie if there is not a pointer located in the position
        cout << currentTitle;
    }else{
        currentTitle = movie->getTitle();   //accesses the actual title of the movie selected
    

        cout << "\nSHOWING DETAILS\n"   //selection of showing info 
            << "Movie Title        : " << currentTitle << "\n"
            << "Showing Time       : " << getShowTime() << "\n"
            << "Auditorium Number  : " << getAuditoriumNumber() << "\n"
            << "Ticket Price       : $" << fixed << setprecision(2) << getTicketPrice() << "\n" //sets price to two decimal points
            << "Seats Available    : " << getSeatsAvailable() << "\n";
    }
}