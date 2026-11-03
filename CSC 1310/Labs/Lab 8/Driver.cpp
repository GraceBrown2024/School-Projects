/*
	NAME: Grace Brown
	Last edited: 2 November 2026
	File Name: Driver.cpp
	Purpose: Uses functions from HashTable.h and Video.h 
	to sort through stored video data
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
void printVideo(const Video& v);
void printMenu();
int userChoice();

// TODO: implement printVideo and any helper functions you choose.
// TODO: create the menu from the assignment (options 1-7).
// TODO: handle invalid numeric input.

int main() {
	const int BUCKETS = 1010;
    HashTable<Video> videos(BUCKETS);
    
	int processed = 0;
	int inserted = 0;
	int updated = 0;
	int skipped = 0;
	string filename = "youtube_hash_lab_data.csv";
	// TODO: call loadVideos function sending the appropriate arguments
	if(!loadVideos(filename, videos, processed, inserted, updated, skipped)){
		cout << "Error! Could not load file!\n";
		return -1; //returns error and quits program
	}
	cout << "Loaded " << processed << " rows; " << inserted << " unique videos; " << 
	 		updated << " updates; " << skipped << " skipped.\n";
	//print how many processed, inserted, updated, & skipped
	int choice;
	
	do{
		cout << "\n========== YOUTUBE VIRAL VIDEO TRACKER ==========\n";
		printMenu();
		choice = userChoice();
		
		switch(choice){
			case 1:{
				string id;
				cout << "You chose Find Video by ID\n";
				cout << "Enter video ID: ";
				getline(cin, id);
				Video v; //create video object
				if(videos.getValue(id, v)){
					printVideo(v);
				}else{
					cout << "Video not found!\n";
				}
				break;
			}
			case 2:{
				string vidIdNew, titleNew, commentsNew, channelNew;
				long long views, likes, comments;

				cout << "You chose to add a new video\n";
				cout << "Enter new video ID: ";
				getline(cin, vidIdNew);

				Video exist; //new Video object
				if(videos.getValue(vidIdNew, exist)){
					cout << "Error: Video ID already Exists\n";
				}else{
					cout << "Title: ";
					getline(cin, titleNew);
					cout << "Channel: ";
					getline(cin, channelNew);
					cout << "Comment Count: ";
					cin >> comments;
					while(!cin){
						cin.clear();
						cin.ignore(100, '\n');
						cout << "Please enter a valid number: ";
						cin >> comments;
					}
					cin.ignore(100, '\n');
					cout << "Views: ";
					cin >> views;
					while(!cin){
						cin.clear();
						cin.ignore(100, '\n');
						cout << "Please enter a valid number: ";
						cin >> views;
					}
					cin.ignore(100, '\n');
					cout << "Likes: ";
					while(!cin){
						cin.clear();
						cin.ignore(100, '\n');
						cout << "Please enter a valid number: ";
						cin >> likes;
					}
					cin.ignore(100, '\n');

					Video newVid{vidIdNew, titleNew, channelNew, views, likes, comments}; //creates new video
					videos.putValue(vidIdNew, newVid);
				}
				break;
			}
			case 3:{
				cout << "You chose to Update video Stats\n";
				string id;
				cout << "Enter Video ID to update: ";
				getline(cin, id);
				Video v;

				if(videos.getValue(id, v)){
					cout << "Enter new Statistics\n"
						 << "New Views: ";
					cin >> v.views;
					while(!cin){
						cin.clear();
						cin.ignore(100, '\n');
						cout << "Please enter a valid number: ";
						cin >> v.views;
					}
					cin.ignore(100, '\n');
					cout << "New Likes: ";
					cin >> v.likes;
					while(!cin){
						cin.clear();
						cin.ignore(100, '\n');
						cout << "Please enter a valid number: ";
						cin >> v.likes;
					}
					cin.ignore(100, '\n');
					cout << "New Comment Count: ";
					cin >> v.commentCount;
					while(!cin){
						cin.clear();
						cin.ignore(100, '\n');
						cout << "Please enter a valid number: ";
						cin >> v.commentCount;
					}
					cin.ignore(100, '\n');
					videos.putValue(id, v);
					cout << "Updated.\n";

				}else{
					cout << "Video not Found!\n";
				}
				break;
			}
			case 4:{
				string id;
				cout << "You chose to Remove a video\n";
				cout << "Enter Video ID to remove: ";
				getline(cin, id);
				if(videos.removeValue(id)){
					cout << "Removed.\n";
				}else{
					cout << "Video not found.\n";
				}
				break;
			}
			case 5:{
				cout << "You chose to Display Hash Table Stats\n";
				videos.printStatistics();
				break;
			}
			case 6:{
				int bucketIndex;
				cout << "You chose to Display a Bucket\n";
				cout << "Enter Bucket Index (0-" << videos.getBucketCount() << "): ";
				cin >> bucketIndex;
				while(!cin || (bucketIndex < 0 || bucketIndex >= videos.getBucketCount())){
						cin.clear();
						cin.ignore(100, '\n');
						cout << "Please enter a valid number: ";
						cin >> bucketIndex;
					}
				cin.ignore(100, '\n');
				videos.printBucket(bucketIndex);
				break;
			}
		}
	}while(choice != 7);
	cout << "\nGoodbye!\n";
    // TODO: implement all requirements.
	
    return 0;
}

/*
	Function Name: loadVideos
	Return Type: Bool
	Purpose: opens the csv file and rips all the information from it to be put into a table
*/
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

/*
Function Name: printMenu()
Return Type: void
Purpose: Prints out menu options
*/
void printMenu(){
	cout << "\n1.) Find video by ID\n"
		 << "2.) Add new Video\n"
		 << "3.) Update Video Statistics\n"
		 << "4.) Remove Video\n"
		 << "5.) Display Hash Table Statistics\n"
		 << "6.) Display a Bucket\n"
		 << "7.) Exit\n"
		 << "CHOOSE 1-7: ";
}

/*
Function Name: userChoice()
Return Type: int
Purpose: Allows user to choose the menu option and returns the value they chose after validaton
*/
int userChoice(){
	int choice;
	cin >> choice;
	while(!cin || (choice < 1 || choice > 7)){
		if(!cin){
			cout << "\nPlease enter an integer!\n";
		}else{
			cout << "\nPlease enter an integer 1-7!\n";
		}
		cin.clear();
		cin.ignore(100, '\n');
		cout << "CHOOSE 1-7: ";
		cin >> choice;
	}
	cin.ignore(100,'\n');

	return choice;
}

void printVideo(const Video& v){
	cout << "\nID: " << v.videoId << endl
		 << "Title: " << v.title << endl
		 << "Channel: " << v.channelTitle << endl
		 << "Views: " << v.views << endl
		 << "Likes: " << v.likes << endl
		 << "Comments: " << v.commentCount << endl;
}