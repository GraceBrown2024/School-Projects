/*
Name        : Grace Brown
File        : Theatre.h
Created     : 9/8/2026
Last Updated: 9/8/2026
Purpose     :
*/

#ifndef THEATRE_H
#define THEATRE_H
#include <iostream>
#include <iomanip>
#include <string>
#include "Movie.h"
#include "Showing.h"


class Theatre{
    private:
        string theatreName;
        Movie** movieArray;
        int numMovies;
        int maxMovies;
        Showing** showingArray;
        int numShowings;
        int maxShowings;

    public:
        Theatre(string tN, Movie** mA, int nM, int mM, Showing** sA, int nS, int mS){
            //OVERLOADED CONSTRUCTOR
        }
        ~Theatre(){
            //DECONSTRUCTOR
        }
        

};

#endif