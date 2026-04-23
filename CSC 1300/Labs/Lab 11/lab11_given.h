#include <iostream>
#include <string>
#include <limits>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

//function prototypes
void inputTravelerData(Traveler*, int);
void displayTravelerData(Traveler*, int);
void editTravelerData(Traveler*, int);
void deleteTravelerData(Traveler*, int);
void printToFile(Traveler*, int);

// ----- STRUCT DEFINITIONS -----
struct Traveler
{
    string name;
    int numPlaces;
    Place* placeArray; 
};
struct Place
{
    string name;
    string country;
    int year;
};




