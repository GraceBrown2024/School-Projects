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
        Theater(string tN, int mM, int mS){
            theaterName = tN;
            maxMovies = mM;
            maxShowings = mS;

            numShowings = 0;
            numMovies = 0;

            movieArray = new Movie*[maxMovies];
            showingArray = new Showing*[maxShowings];

            
        }
        ~Theater(){
            //DECONSTRUCTOR
            for(int i = 0; i < numShowings; i++){
                delete showingArray[i];
            }
            delete [] showingArray;

            for(int i = 0; i < numMovies; i++){
                delete movieArray[i];
            }
            delete [] movieArray;
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

