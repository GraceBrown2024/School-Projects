/*
Name        : Grace Brown
File        : Showing.h
Created     : 9/8/2026
Last Updated: 9/8/2026
Purpose     :
*/

#ifndef SHOWING_H
#define SHOWING_H
#include <iostream>
#include <iomanip>
#include <string>
#include "Movie.h"
using namespace std;

class Showing{
    private:
        Movie* movie;
        string showTime;
        int auditoriumNumber;
        float ticketPrice;
        int seatsAvailable;

    public:
        Showing(){
            movie = nullptr;
            showTime = "Unknown";
            auditoriumNumber = 0;
            ticketPrice = 0.00;
            seatsAvailable = 0;
        }
        Showing(Movie* m, string sT, int aN, float tP, int sA){
            movie = m;
            showTime = sT;
            auditoriumNumber = aN;
            ticketPrice = tP;
            seatsAvailable = sA;
        }
        void setMovie(Movie* m);
        void setShowTime(string sT);
        void setAuditoriumNumber(int aN);
        void setTicketPrice(float tP);
        void setSeatsAvailable(int sA);
        Movie* getMovie();
        string getShowTime();
        int getAuditoriumNumber();
        float getTicketPrice();
        int getSeatsAvailable();
        void editShowing();
        void printShowing();
};

#endif