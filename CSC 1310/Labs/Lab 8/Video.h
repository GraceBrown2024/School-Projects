/*
	Filename: Video.h
	Author: April R. Crockett
	Date: 10/25/2026
	Purpose: Creates a Video structure data type to use with Lab 8
*/
#ifndef VIDEO_H
#define VIDEO_H

#include <string>
using namespace std;

struct Video {
    string videoId;
    string title;
    string channelTitle;
    long long views = 0;
    long long likes = 0;
    long long commentCount = 0;
};
#endif
