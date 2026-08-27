/*******************************************************************************
	Filename: AnimalDriver.cpp
	Author:   the April Crockett
	Date:	  8/26/2026
	Purpose:  To demo DMA with objects, and destructors
********************************************************************************/
#include <iostream>
#include "Animal.h"
using namespace std;

int main(){
	Animal ** animalArray; 
	int maxAnimals;
	int numAnimals = 0; //current number animals added to array
	
	cout << "\nWhat is the max number of anmials you can have in your home? ";
	cin >> maxAnimals; //must be at least 8 or my program will break =(
	
	animalArray = new Animal* [maxAnimals]; 
	
	animalArray[0] = new Animal("Jack",12,30.5,"dog");
	numAnimals++;
	animalArray[1] = new Animal("Jolene",3,28.4,"dog");
	numAnimals++;
	animalArray[2] = new Animal("Billy Dean",2,12.1,"dog");
	numAnimals++;
	animalArray[3] = new Animal("Yella Cat",18,9.4,"cat");
	numAnimals++;
	animalArray[4] = new Animal("Loki",5,8,"cat");
	numAnimals++;
	animalArray[5] = new Animal("Reuben",2,1.5,"rat");
	numAnimals++;
	animalArray[6] = new Animal("Diamond",1,1.2,"rat");
	numAnimals++;
	animalArray[7] = new Animal("Charlie",2,49.2,"pig");
	numAnimals++;
	
	//make some animals visit vet
	animalArray[0]->visitVet(); //because the array element is a pointer, have to use ->
	animalArray[0]->visitVet();
	animalArray[0]->visitVet();
	animalArray[5]->visitVet();
	
	for(int i=0; i<numAnimals; i++){
		cout << *animalArray[i]; 
		cout << endl;
	}
	
	//release memory or I have a memory leak!
	for(int i=0; i<numAnimals; i++){
		delete animalArray[i]; //deletes the animal object
	}
	delete [] animalArray; //deletes the array
	
	return 0;
}

