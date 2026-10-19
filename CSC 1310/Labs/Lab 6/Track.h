/*
Name        : Grace Brown
Last Edited : October 19 2026
File Name   : Track.h
*/

#ifndef TRACK_H
#define TRACK_H

#include <iostream>

class Track{
    private:
        string track_id;
        int popularity;
        string track_name;
        string album_name;
    public:
        Track(){
            track_id = "NULL";
            popularity = 0;
            track_name = "NULL";
            album_name = "NULL";
        }
        Track(string id, int pop, string tName, string aName){
            track_id = id;
            popularity = pop;
            track_name = tName;
            album_name = aName;
        }
        friend ostream &operator << (ostream &strm, Track &a){
            strm << "Track ID: " << a.track_id << "\n"
                 << "Album Name: " << a.album_name << "\n"
                 << "Track Name: " << a.track_name << "\n"
                 << "Popularity: " << a.popularity << "\n";
            return strm;
        }
};


#endif 