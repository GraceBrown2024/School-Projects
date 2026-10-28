/*
	TODO: add your comment block here and delete this comment
*/
#include "HashTable.h"
#include "Video.h"
#include "CSVHelper.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

//function prototypes
bool loadVideos(string, HashTable<Video>&, int&, int&, int&, int&);


// TODO: implement printVideo and any helper functions you choose.
// TODO: create the menu from the assignment (options 1-7).
// TODO: handle invalid numeric input.

int main() {
	const int BUCKETS = 1010;
    HashTable<Video> videos(BUCKETS);
    
	// TODO: call loadVideos function sending the appropriate arguments
	
	//print how many processed, inserted, updated, & skipped
	
	
	cout << "\n========== YOUTUBE VIRAL VIDEO TRACKER ==========\n"
	
    // TODO: implement all requirements.
	
    return 0;
}

//this function is given to you but you need to put a proper 
//comment block here to explain purpose of function
bool loadVideos(string filename, HashTable<Video>& table, int& processed, int& inserted, int& updated, int& skipped) {
    //variable definitions and initializations
	vector<string> fields;
	long long views, likes, comments;
    string line;
    processed = 0;
	inserted = 0;
	updated = 0; 
	skipped = 0;
	
	//open the input file
	ifstream input(filename);
	
	if (!input) 
		return false;
	
	getline(input, line); // Skip the CSV header line.
    while (getline(input, line)) 
	{
        processed++;
        if (!parseCSVLine(line, fields) || fields.size() != 6 ||
            fields[0].empty() || !readNonnegativeNumber(fields[3], views) ||
            !readNonnegativeNumber(fields[4], likes) ||
            !readNonnegativeNumber(fields[5], comments)) {
            skipped++;
        }
		else
		{
			Video video;
			video.videoId = fields[0];
			video.title = fields[1];
			video.channelTitle = fields[2];
			video.views = views;
			video.likes = likes;
			video.commentCount = comments;
			if (table.putValue(video.videoId, video)) 
				inserted++;
			else 
				updated++;
		}
    }
	
    return true;
}