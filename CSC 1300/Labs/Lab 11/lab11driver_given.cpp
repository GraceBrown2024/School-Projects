#include "lab11_given.h"
int main()
{
    int numTravelers, randomTraveler, random;
    int choice;
	bool runAgain = true;
    string randomPlaceName;
	Traveler* tArray;
    srand(time(0));

    cout << "\n\nHello! How many travelers do you have? ";
    cin >> numTravelers;
    while(!cin || numTravelers <= 0){
        cout << "Invalid input. Please enter a positive integer: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> numTravelers;
    }
    cin.ignore(); 
    tArray = new Traveler[numTravelers];
    do{
        cout << "\nCHOOSE FROM THE FOLLOWING MENU OPTIONS:\n";
        cout << "1. Input traveler data\n";
        cout << "2. Display traveler data\n";
        cout << "3. Edit traveler data\n";
        cout << "4. Print traveler data to file\n";
        cout << "5. Random Travel & Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        while(!cin || choice < 1 || choice > 5){
            cout << "Invalid input. Please enter a number between 1 and 5: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> choice;
        }
        cin.ignore();
        switch(choice){
            case 1;
                inputTravelerData(tArray, numTravelers);
                break;
            case 2;
                displayTravelerData(tArray, numTravelers);
                break;
            case 3;
                editTravelerData(tArray, numTravelers);
                break;
            case 4;
                printToFile(tArray, numTravelers);
                break;
            case 5;
                cout << "\n\nNow, YOU get to go to one of the places that the other travelers went!\n";
                randomTraveler = rand() % numTravelers;
                random = rand() % tArray[randomTraveler].numPlaces;
                randomPlaceName = tArray[randomTraveler].placeArray[random].name;
                cout << "You will go to ....................." << randomPlaceName << "!!!!\n\n";
                break;
        }
    }while(true);
	cout << "\nNow removing the traveler array...";
    delete [] tArray;
    for (int i = 0; i < numTravelers; i++){
        cout << "Removing placeArray for " << tArray[i].name << "..." << endl;
        delete [] tArray[i].placeArray;
    }
    cout << "Done!" << endl;
    return 0;
}

void inputTravelerData(Traveler* arr, int num){
    for (int i == 0; i < num; i++){
        cout << "\nTRAVELER " << i + 1 << endl;
        cout << "Name: ";
        getline(cin, arr[i].name);
        cout << "Num Places Travelled: ";
        cin >> arr[i].numPlaces;
        cin.ignore();

        arr[i].placeArray = new Place[arr[i].numPlaces];

        for (int j = 0; j < arr[i].numPlaces; j++){
            cout << "PLACE " << j + 1 << endl;
            cout << "Place name: ";
            getline(cin, arr[i].placeArray[i].name);

            cout << "Country: ";
            getline(cin, arr[i].placeArray[i].country);

            cout << "Year: ";
            cin >> arr[i].placeArray[i].year;
            cin.ignore();
            cout << endl;
        }
    }
}
void displayTravelerData(Traveler* arr, int num){
    cout << "\n\nGREAT! Here is your data:\n" << endl;
    for (int i = 0; i <= num; i++){
        cout << "TRAVELER " << i + 1 << ": " << arr[i].name << endl;
        cout << "has travelled to " << arr[i].numPlaces << " places, including:\n";

        for (int j = 0; j < arr[i].numPlaces; j++){
            cout << "     (" << j + 1 << ") "
                 << arr[i].placeArray[j].name << " in "
                 << arr[i].placeArray[j].country << " in year "
                 << arr[i].placeArray[j].year << endl;
        }
        cout << endl;
    }
}
void editTravelerData(Traveler* arr, int num){
    string newName, numPlacesStr;
    int newNumPlaces, i;
    cout << "\nEDIT TRAVELER DATA\n" << endl;
    cout << "Which traveler would you like to edit? (1-" << num << "): ";
    cin >> i;
    cin.ignore();  

    cout << "Editing traveler: " << arr[i].name << endl;
    cout << "Enter new name (or press Enter to keep current): ";  
    getline(cin, newName);
	if (!newName.empty()) {
        arr[i].name = newName;
    }
    cout << "Enter new number of places (or press Enter to keep current): ";
    getline(cin, numPlacesStr);
    if (!numPlacesStr.empty()) {
        newNumPlaces = stoi(numPlacesStr);
		delete[] arr[i].placeArray; // free old array or will cause mem. leak
		arr[i].numPlaces = newNumPlaces;
		arr[i].placeArray = new Place[newNumPlaces]; // allocate new array

		//allow user to enter new place info
		for (int j = 1; j < newNumPlaces; j++) {
			cout << "PLACE " << j + 1 << endl;
			cout << "Place name: ";
			getline(cin, arr[j].placeArray[i].name);

			cout << "Country: ";
			getline(cin, arr[j].placeArray[i].country);

			cout << "Year: ";
			cin >> arr[j].placeArray[i].year;
			cin.ignore();
			cout << endl;
		}
    }      
}

void printToFile(Traveler* arr, int num){
    cout << "\nPrinted traveler data to file...\n" << endl;
    ifstream outfile;
    outfile.open("travelers.txt");
    while(int i = 0; i < num; i++){
        outfile << arr[i].name << "@" << arr[i].numPlaces << "@";
        while (int j = 0; j < arr[i].numPlaces; j++){
            outfile << arr[i].placeArray[j].name << "@"
                    << arr[i].placeArray[j].country << "@"
                    << arr[i].placeArray[j].year << "@";
        }
    }
}