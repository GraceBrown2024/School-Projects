/******************************************************************
	To compile: 	g++ -Wall -fopenmp prog2_solution.cpp -o prog2
	Filename: 		GIVEN: program2.h
	Author: 		April Crockett & PUT YOUR NAME HERE
	Last Updated:	PUT TODAYS DATE HERE
	Purpose: 		Practice with sort algorithms and compare time 
					efficiency when running the algorithms 
					sequentially and in parallel

******************************************************************/
#ifndef PROGRAM2_H
#define PROGRAM2_H

#include <vector>
#include <string>

using namespace std;

template <typename T>
bool readFromFile(vector<T>&, string);
template <typename T>
void printVector(vector<T>&);
template <typename T>
void scramble(vector<T>&);

/********************************************************
 * Declare the function prototypes below for each sort
 * function 
 ********************************************************/
template <typename T>
void bubbleSort(vector<T>& v);
template <typename T>
void mergeSort(vector<T>& v, int lowIndex, int highIndex); //input a vector, low index, and high index
template <typename T>
void parallelMergeSort(vector<T>& v, int left, int right, int depth); //input a vector, left index, right index, and DEPTH of int var for parallelization
template <typename T>
void quickSort(vector<T>& v, int left, int right); //inout a vector, left and right indices
template <typename T>
void parallelQuickSort(vector<T>& v, int left, int right); //input a vector, left and right indices
template <typename T>
void merge(vector<T>& v, int left, int mid, int right); //input a vector, right and left indices, middle index... CALLED BY MERGESORT AND PARALLELMERGESORT
template <typename T>
int partition(vector<T> & v, int left, int right);
void swap(int& one, int& two);
#endif
