/*
Name        : Grace Brown
File        : Theatre.h
Created     : 9/8/2026
Last Updated: 9/8/2026
Purpose     :
*/

#ifndef THEATER_H
#define THEATER_H
#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include "Movie.h"
#include "Showing.h"
using namespace std;


class Theater{
    private:
        string theaterName;
        Movie** movieArray;
        int numMovies;
        int maxMovies;
        Showing** showingArray;
        int numShowings;
        int maxShowings;

    public:
        Theater(string tN, Movie** mA, int nM, int mM, Showing** sA, int nS, int mS){
            //OVERLOADED CONSTRUCTOR
        }
        ~Theater(){
            //DECONSTRUCTOR
        }
        int getNumMovies();
        int getNumShowings();
        void addMovie();
        void editMovie();
        void addShowing();
        void editShowing();
        void printMovies();
        void printShowings();
        void printMovieNames();
        void printShowingNames();
        

};

#endif

