/*
Name        : Grace Brown
File        : Movie.h
Created     : 9/8/2026
Last Updated: 9/8/2026
Purpose     :
*/

#ifndef MOVIE_H
#define MOVIE_H
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Movie{
    private:
        string title;
        int releaseYear;
        int runtimeMinutes;
        string rating;

    public:
        Movie(){
            //DEFAULT
        }
        Movie(string t, int rY, int rM, string r){
            //OVERLOADED CONSTRUCTOR
        }
        void setTitle(string t);
        void setReleaseYear(int rY);
        void setRuntimeMinutes(int rM);
        void setRating(string r);
        string getTitle();
        int getReleaseYear();
        int getRuntimeMinutes();
        string getRating();
        void editMovie();
        void printMovie();
};

#endif