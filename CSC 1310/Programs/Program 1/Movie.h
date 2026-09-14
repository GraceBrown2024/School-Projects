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
            title = "";
            releaseYear = 0;
            runtimeMinutes = 0;
            rating = "";
        }
        Movie(string t, int rY, int rM, string r){
            title = t;
            releaseYear = rY;
            runtimeMinutes = rM;
            rating = r;
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