/*
Name        : Grace Brown
File        : Showing.cpp
Created     : 9/8/2026
Last Updated: 9/8/2026
Purpose     :
*/

#include "Showing.h"

void Showing::setMovie(Movie* m){
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
Movie* Showing::getMovie(){
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
void Showing::editShowing(){
    int x;
    do{
    int tempNum = 0;
    string tempStrng = "";
    float tempFloat;

    cout << "Please select a Choice:\n"
         << "1.) Change Show Time\n"
         << "2.) Change Auditorium Number\n"
         << "3.) Change Ticket Price\n"
         << "4.) Change Seats Available\n"
         << "5.) QUIT EDITING \n"
         << "----- ENTER NUMBER --> ";
    cin >> x;

    while(!cin || (x < 1 || x > 5)){
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Please enter a VALID choice!\n"
             << "--> ";
        cin >> x;
    }

    cin.ignore(100, '\n');

    switch(x){
        case 1:
            cout << "\nPlease enter your New Show Time: ";
            getline(cin, tempStrng, '\n');
            Showing::setShowTime(tempStrng);
            break;

        case 2:
            cout << "Please enter your New Auditorium Number: ";
            cin >> tempNum;

            while(!cin){
                cin.clear();
                cin.ignore(100, '\n');
                cout << "\nPlease enter a VALID Number: ";
                cin  >> tempNum;
            }
            cin.ignore(100, '\n');
            Showing::setAuditoriumNumber(tempNum);
            break;
        
        case 3:
            cout << "Please enter your New Ticket Price: ";
            cin >> tempFloat;

            while(!cin){
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

            while(!cin){
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

   }while(x != 5);
}
void Showing::printShowing(){
    string currentTitle;

    if(movie == nullptr){
        currentTitle = "[NO MOVIE ASSIGNED]";
        cout << currentTitle;
    }else{
        currentTitle = movie->getTitle();
    

        cout << "\nSHOWING DETAILS\n"
            << "Movie Title        : " << currentTitle << "\n"
            << "Showing Time       : " << getShowTime() << "\n"
            << "Auditorium Number  : " << getAuditoriumNumber() << "\n"
            << "Ticket Price       : $" << setprecision(2) << getTicketPrice() << "\n"
            << "Seats Available    : " << getSeatsAvailable() << "\n";
    }
}