/*
Name        : Grace Brown
File        : Theatre.h
Created     : 9/8/2026
Last Updated: 9/14/2026
Purpose     : create and list attributes of theater class
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


class Theater{  //class attributes for Theatre
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

            numShowings = 0;    //sets num to 0 until updated w new indices
            numMovies = 0;

            movieArray = new Movie*[maxMovies]; //dynamically creates new arrays for items to be placed into
            showingArray = new Showing*[maxShowings];

            
        }
        ~Theater(){
            //DECONSTRUCTOR
            for(int i = 0; i < numShowings; i++){   //deletes each object 
                delete showingArray[i];
            }
            delete [] showingArray; //deletes array

            for(int i = 0; i < numMovies; i++){ //deletes each object
                delete movieArray[i];   
            }
            delete [] movieArray;   //deletes array
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

