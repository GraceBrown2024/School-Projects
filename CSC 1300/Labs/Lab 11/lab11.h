#include <iostream>
#include <string>
#include <limits>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

// ----- STRUCT DEFINITIONS -----
struct Place
{
    string name;
    string country;
    int year;
};
struct Traveler
{
    string name;
    int numPlaces;
    Place *placeArray; 
};

//function prototypes
void inputTravelerData(Traveler*, int);
void displayTravelerData(Traveler*, int);
void editTravelerData(Traveler*, int);
//void deleteTravelerData(Traveler*, int);
void printToFile(Traveler*, int);




