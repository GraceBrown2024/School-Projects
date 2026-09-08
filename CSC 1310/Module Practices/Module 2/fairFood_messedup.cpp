/*
	CSC 1310 - Class Template Debugging Practice
	Theme: Fair Food Calorie Tracker

	DIRECTIONS:
	This program is supposed to use ONE class template so that the FairFood
	class can work with more than one numeric data type.

	The template class contains MULTIPLE errors.
	Correct the program so that it compiles and produces sensible output.

	Do NOT rewrite the entire program from scratch.
	Fix the template-related problems you find.
*/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

template <typename T>	//include a class identifier 
class FairFood
{
	private:
		string foodName;
		T servingOne;
		T servingTwo; //changed data type of servingTwo

	public:
		FairFood(string name, T one, T two){	//Match data types for One and Two
			foodName = name;
			servingOne = one;
			servingTwo = two;
		}

		T getTotal(){	//change int return type to T 
			return servingOne + servingTwo;
		}

		double getAverage(){
			return (servingOne + servingTwo) / 2.0;	//ensure a double can be produced... 2 -> 2.0
		}

		T getHighest(){					//Change return data type of function to return properly
			if (servingOne > servingTwo)
				return servingOne;
			else
				return servingTwo;
		}

		void swapServings(){
			T temp = servingOne;	//change data type to T to match One and Two data types
			servingOne = servingTwo;
			servingTwo = temp;
		}

		void setServingOne(T value);
		
		void print(){
			cout << "\nFood: " << foodName << endl;
			cout << "Serving 1: " << servingOne << endl;
			cout << "Serving 2: " << servingTwo << endl;
		}
};

template <typename T> //need to add before the template call so it knows where to pull the info 
void FairFood<T>::setServingOne(T value){
    servingOne = value;
}


int main(){
	cout << "=== COUNTY FAIR FOOD TRACKER ===\n";

	FairFood funnelCake("Funnel Cake Calories", 760, 540);

	funnelCake.print();
	cout << "Total calories: " << funnelCake.getTotal() << endl;
	cout << "Average calories: " << funnelCake.getAverage() << endl;
	cout << "Higher-calorie serving: " << funnelCake.getHighest() << endl;

	funnelCake.swapServings();
	cout << "\nAfter swapping the two servings:";
	funnelCake.print();

	funnelCake.setServingOne(900);
	cout << "\nAfter changing serving 1:";
	funnelCake.print();

	FairFood<int> friedOreos("Fried Oreo Prices", 7.50, 9.25);

	friedOreos.print();
	cout << "Total cost: $" << friedOreos.getTotal() << endl;
	cout << "Average cost: $" << friedOreos.getAverage() << endl;
	cout << "Higher price: $" << friedOreos.getHighest() << endl;

	return 0;
}
