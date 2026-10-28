/******************************************************************
	To compile: 	g++ -Wall -fopenmp prog2_solution.cpp -o prog2
	Filename: 		program2.cpp
	Author: 		Eddie Gannod & April Crockett & Grace Brown
	Last Updated:	October 21 2026
	Purpose: 		Practice with sort algorithms and compare time 
					efficiency when running the algorithms 
					sequentially and in parallel

******************************************************************/
#include <iostream>
#include <vector>				// used to create and use vectors
#include <fstream>
#include <parallel/algorithm> 	// used for sort function
#include <omp.h>              	// used for OpenMP directives
#include <ctime>             	// used for seeding randome number generator
#include <thread>				//used for calculating number of logical processors on computer
#include <cstdlib>           	// used for random number generation
#include <chrono>				//used for measuring elapsed time
#include "program2.h"

using namespace std;

int main() 
{
	//create two vectors	
    vector<int> nums;       	
    vector<string> words;  		
	string filename;
	bool success;
    
	//determine number of logical processors on your computer
	const  auto processor_count = thread::hardware_concurrency();
	
    //Number of threads OpenMP will use. 
    int num_threads;
	
	//ask the user for the number of threads
	cout << "\nHow many threads do you want OpenMP to use? (Enter 1-500) ";
	cin >> num_threads;
	
	//validation for user input
	while(!cin || (num_threads < 1 || num_threads > 500)){
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Please enter a number 1-500: ";
		cin >> num_threads;
	}
	cin.ignore(100, '\n');
	
	omp_set_dynamic(false);
    omp_set_num_threads(num_threads);
	cout << "\nNumber of Threads Used: " << num_threads << endl;
	cout << "Number of Processors: " << processor_count << endl;
	
	//read from files & place in vectors
	do {
		cout << "\nWhat is the name of the string (word) text file?\n(wordsSmall.txt or wordsLarge.txt)\nFILENAME: ";
		cin >> filename;
		success = readFromFile(words, filename);	
	} while(!success);
	do {
		cout << "\nWhat is the name of the number (int) text file?\n(numsSmall.txt or numsLarge.txt)\nFILENAME: ";
		cin >> filename;
		success = readFromFile(nums, filename);
	} while(!success);
	cout << "SIZE of words: " << words.size() << endl;
	cout << "SIZE of nums: " << nums.size() << endl;
	
	//prior to calling any of the sort algorithms, you need to scramble (unsort) the vectors
	scramble(nums);
    scramble(words);
	
	/*************************************************************************Parallel Sort in Algorithm Library*****************************
	
	 * For more information about this algorithm in particular, take a look at 
	 * https://www.geeksforgeeks.org/internal-details-of-stdsort-in-c/
	 * It uses the IntroSort algorithm, which is a hybrid between Quicksort, Heapsort,
	 * and Insertion Sort.
     *********************************************************************************/
	//****************************Parallel Sort in Algorithm Library*****************************/
    auto start = chrono::high_resolution_clock::now();
    __gnu_parallel::sort(nums.begin(), nums.end());
    auto end = chrono::high_resolution_clock::now();
    cout << "\n<parallel/algorithm> library sort(int): " 
	     << chrono::duration<double>(end - start).count() << " seconds" << endl;

    start = chrono::high_resolution_clock::now();
    __gnu_parallel::sort(words.begin(), words.end());
    end = chrono::high_resolution_clock::now();
    cout << "<parallel/algorithm> library sort(words): " 
	     << chrono::duration<double>(end - start).count() << " seconds" << endl;



	scramble(nums);
	scramble(words);

	start = chrono::high_resolution_clock::now();
	bubbleSort(nums);									//calls bubbleSort with the int vector
	 end = chrono::high_resolution_clock::now();
	cout << "\nBubble Sort (int): " 
	     << chrono::duration<double>(end - start).count() << " seconds" << endl;

	 start = chrono::high_resolution_clock::now();	
	bubbleSort(words);									//calls bubbleSort with the string vector
	 end = chrono::high_resolution_clock::now();
	cout << "\nBubble Sort Runtime (String): " 
	     << chrono::duration<double>(end - start).count() << " seconds" << endl;


	scramble(nums);		//scrambles the vectors to allow for unique sorting each run
	scramble(words);

	 start = chrono::high_resolution_clock::now();
	mergeSort(nums, 0 , nums.size() - 1);	//calls mergeSort with the int vector
	 end = chrono::high_resolution_clock::now();
	cout << "\nMerge Sort (int): " 			
	     << chrono::duration<double>(end - start).count() << " seconds" << endl;

	 start = chrono::high_resolution_clock::now();
	mergeSort(words,  0 , words.size() - 1);	//calls MergeSort with the string vector
	 end = chrono::high_resolution_clock::now();
	cout << "\nMerge Sort Runtime (String): " 
	     << chrono::duration<double>(end - start).count() << " seconds" << endl;


	scramble(nums);
	scramble(words);

	 start = chrono::high_resolution_clock::now();
	parallelMergeSort(nums, 0, nums.size() - 1, 0);	//calls parallelMergeSort with the int vector
	 end = chrono::high_resolution_clock::now();
	cout << "\nParallel Merge Sort (int): " 
	     << chrono::duration<double>(end - start).count() << " seconds" << endl;

	 start = chrono::high_resolution_clock::now();
	parallelMergeSort(words, 0 , words.size() - 1, 0);	//calls parallelMergeSort with the string vector
	 end = chrono::high_resolution_clock::now();
	cout << "\nParallel Merge Sort Runtime (String): " 
	     << chrono::duration<double>(end - start).count() << " seconds" << endl;

    
	scramble(nums);		
	scramble(words);

	 start = chrono::high_resolution_clock::now();
	quickSort(nums, 0 , nums.size() - 1);	//calls quickSort with the int vector
	 end = chrono::high_resolution_clock::now();
	cout << "\nQuick Sort (int): " 
	     << chrono::duration<double>(end - start).count() << " seconds" << endl;

	 start = chrono::high_resolution_clock::now();
	quickSort(words, 0, words.size() - 1);	//calls quickSort with the string vector
	 end = chrono::high_resolution_clock::now();
	cout << "\nQuick Sort Runtime (String): " 
	     << chrono::duration<double>(end - start).count() << " seconds" << endl;

	scramble(nums);
	scramble(words);

	 start = chrono::high_resolution_clock::now();
	parallelQuickSort(nums, 0, nums.size() - 1);	//calls parallelQuickSort with the int vector
	 end = chrono::high_resolution_clock::now();
	cout << "\nParallel Quick Sort (int): " 
	     << chrono::duration<double>(end - start).count() << " seconds" << endl;

	 start = chrono::high_resolution_clock::now();
	parallelQuickSort(words, 0, words.size() - 1);	//calls parallelQuickSort with the string vector
	 end = chrono::high_resolution_clock::now();
	cout << "\nParallel Quick Sort Runtime (String): " 
	     << chrono::duration<double>(end - start).count() << " seconds" << endl;


    return 0; 
}

/*
	Function: readFromFile()
	Purpose: 
		readFromFile reads values from a file into a vector<T>. 
		It returns true if the file was successfully opened and 
		read, and false otherwise.
*/
template <typename T>
bool readFromFile(vector<T>& v, string filename)
{
    ifstream file;
    T tmp;
	
    file.open(filename);
	if(file.is_open())
	{
		//place file contents into vector
		while(file >> tmp)
		{
			v.push_back(tmp);
		}
		file.close();
		return true;
	}
	return false;
}

/*
	Function: printVector()
	Purpose: 
		printVector prints each element of the vector to the screen
*/
template <typename T>
void printVector(vector<T>& v)
{
    for (int i = 0; i < 20; i++)
    {
        cout << v[i] << endl;
    }
}

/*
	Function: scramble()
	Purpose: 
		scramble will randomly scramble the vector contents to
		make the vector unsorted
*/
template <typename T>
void scramble(vector<T>& v)
{
    srand(time(0));
    int randomIndex;
    for (unsigned int i = 0; i < v.size(); i++)
    {
        randomIndex = rand() % v.size();
        swap(v[i], v[randomIndex]);
    }
}

// SORTING FUNCTIONS
/*
	Function: bubbleSort()
	Purpose: 
		Sorts the vectors repeatedly by comparing each pair of ADJACENT items and swaps them if they are in incorrect order
*/
template <typename T>
void bubbleSort(vector<T>& v){
	T tempForSwap;	
	bool swapped;	//used to signal if the two elements being compared are fully in order
	for(size_t i = 0; i < v.size(); i++){
		swapped= false;
		for(size_t j = 0; j < v.size() - i - 1; j++){	//iterates through the vector 
			if(v[j] > v[j+1]){	//checks to see if the two elements next to each other are larger than the other
				tempForSwap = v[j];	//swaps the two elements if left is greater than right
				v[j] = v[j+1];
				v[j+1] = tempForSwap;	
				swapped = true;
			}
		}
		if(!swapped){	//stops checking if the elements have been swapped
			break;
		}
	}
}

/*
	Function: mergeSort()
	Purpose: 
		divide and conquer sorting algorithm that divides list into TWO HALVES then recursively sorts through each half
		Merges the two halves in the end
*/
template <typename T>
void mergeSort(vector<T>& v, int lowIndex, int highIndex){
	int mid = 0;

	if(lowIndex < highIndex){ 
		mid = (lowIndex + highIndex) / 2; //find midpoint 

		mergeSort(v, lowIndex, mid);	//recursively calls mergeSort for the left and right sides 
		mergeSort(v, mid+1, highIndex);

		merge(v, lowIndex, mid, highIndex);	//combines the two new vectors from mergeSort
	}
} //input a vector, low index, and high index

/*
	Function: parallelMergeSort()
	Purpose: 
		creates seperate threads to sort through each half of the divided list at the same time, reducing sorting time
*/
template <typename T>
void parallelMergeSort(vector<T>& v, int left, int right, int depth){
	if(left < right){
		int mid = left + (right - left) / 2;

		//checking depth to control thread creation
		if (depth < 4){
			#pragma omp parallel sections
			{
				#pragma omp section	//creates two sections that can work simultaneously on the left vector and right vector
				{
					parallelMergeSort(v, left, mid, depth + 1);
				}
				#pragma omp section
				{
					parallelMergeSort(v, mid + 1, right, depth + 1);
				}
			}
		}else{
			parallelMergeSort(v, left, mid, depth + 1);	
			parallelMergeSort(v, mid + 1, right, depth + 1);
		}

		merge(v, left, mid, right);	//merges two vectors
	}
} //input a vector, left index, right index, and DEPTH of int var for parallelization

/*
	Function: quickSort()
	Purpose: 
		Divide and conquer strategy that quickly sorts data from a large itemized list using partitioning
*/
template <typename T>
void quickSort(vector<T>& v, int left, int right){
	int split = 0;
	//BASE CASE... allows the recursive function to not repeat forever when elements are partitioned and sorted
	if(left >= right){
		return;
	}

	split = partition(v, left, right);	//partitions the left and right sides of the vector evenly
	quickSort(v, left, split);	//sort left partition
	quickSort(v, split+1, right); //sort right partition
} //inout a vector, left and right indices

/*
	Function: parallelQuickSort()
	Purpose: 
		partitions the vector and creates seperate threads to sort at same time to increase time efficiency
*/
template <typename T>
void parallelQuickSort(vector<T>& v, int left, int right){
	if (left < right)
    {
        int pivot = partition(v, left, right);//returns sorted location of pivot
        
		//only parallelize this function call if num items to sort is less than 10000
		#pragma omp task shared(v) if(right-left > 10000)
		parallelQuickSort(v, left, pivot - 1);//recursively sort low partition
        
        #pragma omp task shared(v) if(right-left > 10000)
		parallelQuickSort(v, pivot + 1, right);//recursively sort high partition
        
        #pragma omp taskwait
    }
} //input a vector, left and right indices

/*
	Function: merge()
	Purpose: function to allow mergeSort and parallelMergeSort to function properly by dividing the vectors into left and right sides, then combines them once the sort is complete
		
*/
template <typename T>
void merge(vector<T>& v, int left, int mid, int right){
	int n1 = mid - left + 1;
	int n2 = right - mid;

	vector<T> leftV(n1);	//creating new temp vectors
    vector<T> rightV(n2);

	for(size_t i = 0; i < leftV.size(); ++i){ //copies data into the temp vectos
		leftV[i] = v[left + i];
	}
	for(size_t j = 0; j < rightV.size(); ++j){
		rightV[j] = v[mid + 1 + j];
	}

	int i = 0;
	int j = 0;
	int k = left;
 
	while( i < n1 && j < n2){	//merge the two vectors into a vector
		if (leftV[i] <= rightV[j]) {
            v[k] = leftV[i];
            i++;
        } else {
            v[k] = rightV[j];
            j++;
        }
        k++;
	}

	//copy remaining elements
	while(i < n1){
		v[k++] = leftV[i++];
	}
	while(j < n2){
		v[k++] = rightV[j++];
	}
	
} //input a vector, right and left indices, middle index... CALLED BY MERGESORT AND PARALLELMERGESORT

/*
	Function: partition()
	Purpose: 
		splits the vector in half to allow quickSort to divide and conquer
*/
template <typename T>
int partition(vector<T> & v, int left, int right){
	T pivot = v[left];	
	left--;
	right++;
	while(left < right){	//divides the vector given into a smaller left side and larger right side
		do{
			right--;
		}
		while(v[right] > pivot);
		do{
			left++;
		}
		while(v[left] < pivot);

		if(left < right){
			swap(v[left], v[right]);
		}
	}
	return right;
}

/*
	Function: swap()
	Purpose: 
		swaps the two items in a list 
*/
void swap(int& one, int& two){
	int temp = one;
	one = two;
	two = temp;
}