//Vet.h
#ifndef VET_H
#define VET_H

#include <iostream>
#include <string>
using namespace std;

class Vet{
	private:
		string visitDate;
		string vetName;
		double cost;
		bool sick;
	public:
		Vet(){
			visitDate = "";
			vetName = "";
			cost = 0.0;
			sick = false;
		}
		Vet(string d, string name, double c, bool sick){
			visitDate = d;
			vetName = name;
			cost = c;
			this->sick = sick;
		}
		~Vet(){
			cout << "Vet object with visit date on " << visitDate << " has been removed from memory.\n";
		}
		
		void setVisitDate(string d){
			visitDate = d;
		}
		void setVetName(string name){
			vetName = name;
		}
		void setCost(double c){
			cost = c;
		}
		void setSick(bool sick){
			this->sick = sick;
		}
		
		string getVisitDate() const{
			return visitDate;
		}
		string getVetName() const{
			return vetName;
		}
		double getCost() const{
			return cost;
		}
		bool getSick() const{
			return sick;
		}
		
		friend ostream &operator << (ostream &strm, Vet &v)
		{
			strm << "Visit to " << v.vetName << " on " << v.visitDate << ", cost was $";
			strm <<	v.cost << " and pet was";
			if(v.sick == true)
				strm << " sick (poor thing).\n";
			else
				strm << " not sick.\n";
			return strm;
		}
};


#endif