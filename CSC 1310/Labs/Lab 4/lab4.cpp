/*
Name            : Grace Brown
File            : lab4.cpp
Date Created    : 9/22/26 (GIVEN FILE)
Last Modified   : 9/22/26
Purpose         : Driver for sorting algorthims and function definitions
*/
#include "lab4.h"

int main() {
    string* movies;
    int numMovies = 0;
    int maxMovies = 20;
	int choice;

    // initial allocation - array of 20 strings
    movies = new string[maxMovies];

    // read the file
    readFromFile(movies, maxMovies, numMovies);

    if (numMovies == 0) {
        cout << "No movies loaded. Exiting.\n";
        delete[] movies;
        return 1;
    }

	// Execute menu and user's choice until they choose to quit
    do{
        cout << "\n================ MENU ================\n";
        cout << "1) Print movies\n";
        cout << "2) Bubble sort (A->Z)\n";
        cout << "3) Selection sort (A->Z)\n";
        cout << "4) Insertion sort (A->Z)\n";
        cout << "5) Scramble array (randomize order)\n";
        cout << "6) Quit\n";
        cout << "Choose an option (1-6): ";
        cin >> choice;
        while (!cin || choice < 1 || choice > 6) {
            if(!cin)
                cout << "You didn't enter a number. Please try again: ";
            else
                cout << "Invalid choice. Please enter a number between 1 and 6: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> choice;
        }
        cout << endl;

        if(choice == 1){// Print
            printArray(movies, numMovies);
        }
        else if(choice == 2){ // Bubble sort with timing
            cout << "I am going to bubble sort the array of " << numMovies << " movies\n";
            auto t0 = steady_clock::now();
            //call bubble sort
            bubbleSort(movies, numMovies);
            auto t1 = steady_clock::now();
            auto ms_bubble = duration_cast<milliseconds>(t1 - t0).count();
            cout << "Bubble sort completed in " << ms_bubble << " ms.\n";
        }
        else if(choice == 5){ // Scramble
            scramble(movies, numMovies);
            cout << "Array scrambled.\n";
        }
        else // Quit
            cout << "Goodbye!\n";
    } while(choice != 6);

    // clean up dynamic memory
    delete[] movies;

    return 0;
}

/*
	Function: readFromFile()
	Purpose: Reads movie titles from a specified text file into a dynamic array.
	Parameters:
		arr - reference to the array pointer to store movie titles
		maxSize - reference to the maximum size of the array
		curSize - reference to the current number of movies stored
	Returns: void
*/
void readFromFile(string*& arr, int& maxSize, int& curSize) {
    ifstream inFile;
    string filename, movie;
    cout << "Filename (movies.txt): ";
    cin >> filename;

    inFile.open(filename);
    if (inFile.is_open()) {
        while (getline(inFile, movie)) {
            if (curSize == maxSize) {
                maxSize = doubleArray(arr, maxSize);
            }
            arr[curSize] = movie;
            curSize++;
        }
        inFile.close();
        cout << "Loaded " << curSize << " movies from '" << filename << "'.\n";
    } else {
        cout << "Unable to open file '" << filename << "'!\n";
    }
}

/*
	Function: scramble()
	Purpose: Randomly shuffles the elements of the array.
	Parameters:
		arr - the array to shuffle
		size - number of elements in the array
	Returns: void
*/
void scramble(string* arr, int size) {
	int j;
    if (size <= 1) 
        return;
    srand(static_cast<unsigned int>(time(0)));
	for (int i = size - 1; i > 0; i--) {
		j = rand() % (i + 1);
		swap(arr[i], arr[j]);
	}
}