/***************************************************************
	Title:  	Animal.h
	Author:  	April Crockett
	Date:		8/26/2026
	Purpose:	Animal class
****************************************************************/

#ifndef ANIMAL_H
#define ANIMAL_H

#include "Vet.h"
#include <iostream>
#include <iomanip>
using namespace std;

class Animal
{
	private:
		string name;
		int age;
		float weight;
		string animalType; //dog, cat, rat, etc.
		Vet vetVisitArray[25];
		int numVisits; //number of vet visits
	
	public:
		// Default constructor
		Animal(){			
			name = "";
			age = 0;
			weight = 0;
			animalType = "";
			numVisits = 0;
		}
		//overloaded constructor
		Animal(string n, int a, float w, string t){ 
			name = n;
			age = a;
			weight = w;
			animalType = t;
			numVisits = 0;
		}
		//destructor
		~Animal(){
			cout << "DELETED the animal, " << name << ", from memory.\n";
		}
		//mutator function
		void setName(string n){
			name = n;
		}
		void setAge(int a){
			age = a;
		}
		void setWeight(float w){
			weight = w;
		}
		void setAnimalType(string type){
			animalType = type;
		}
		void visitVet(){
			string date, vet;
			char sickYesNo;
			double cost;
			
			cout << "\nDescribe the Vet Visit:\n";
			cout << "DATE: ";
			cin.ignore();
			getline(cin, date);
			vetVisitArray[numVisits].setVisitDate(date);
			cout << "VET NAME: ";
			getline(cin, vet);
			vetVisitArray[numVisits].setVetName(vet);
			cout << "COST: $";
			cin >> cost;
			vetVisitArray[numVisits].setCost(cost);
			cout << "ANIMAL SICK? (y/n) ";
			cin >> sickYesNo;
			if(sickYesNo == 'y')
				vetVisitArray[numVisits].setSick(true);
			else
				vetVisitArray[numVisits].setSick(false);
			numVisits++;				
		}
		
		//accessor functions
		string getName() const{
			return name;
		}
		int getAge() const{
			return age;
		}
		string getAnimalType() const{
			return animalType;
		}
		float getWeight() const{
			return weight;
		}
		
		/*
			overloaded << operator
			when printing out an Animal object with cout << it will print out 
			all attributes in the Animal class.
		*/
		friend ostream &operator << (ostream &strm, Animal &a)
		{
			strm << setw(18) << "NAME:  " << a.name << endl;
			strm << setw(18) << "AGE:  " << a.age << endl;
			strm << setw(18) << "WEIGHT:  " << a.weight << endl;
			strm << setw(18) << "ANIMAL:  " << a.animalType << endl;
			if(a.numVisits > 0){
				strm << setw(18) << "VET VISITS:" << endl;
				for(int i=0; i<a.numVisits; i++){
					strm << setw(18) << "" << a.vetVisitArray[i] << endl;
				}
			}
			return strm;
		}
		
		/*
			overloaded == operator
			used when comparing two Animal objects - will compare the name string attribute
		*/
		bool operator == (const Animal &a)
		{
			if(name == a.name)
				return true;
			else
				return false;
		}
};

#endif
