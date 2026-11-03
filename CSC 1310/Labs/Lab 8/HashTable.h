/*
	NAME: Grace Brown
	Last edited: 2 November 2026
	File Name: HashTable.h
	Purpose: Creates and stores the entries from the youtube file to a hash table
*/
#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Complete TODOs in this given file. Do not use map or unordered_map.
template <typename T>
class HashTable {
	private:
		struct HashEntry {
			string key;
			T value;
			HashEntry* next;
		};
		int tableSize;
		HashEntry** hashArray;
		int entries;

		//compute & return bucket index based on the key
		int indexFor(string key) {
			int h = 0;
			for(int i = 0; i < static_cast<int>(key.length()); i++){		//runs loop as long as the string still has characters
				char ch = key[i];
				h = (h * 31 + static_cast<unsigned char>(ch)) % tableSize;	//provides valid index for string char
			}
			
			return h;
		}
	
	public:
		//constructor
		HashTable(int size) {
			tableSize = size;
			entries = 0;
			
			//dynamically allocates a new hash table 
			hashArray = new HashEntry*[tableSize];

			//creates a loop that puts a null pointer to each node
			for (int i = 0; i < tableSize; i++) {
				hashArray[i]= nullptr;
			}
		}
		
		//destructor
		~HashTable() {
			// TODO: delete every node in every chain, then delete[] hashArray.
			for(int i = 0; i < tableSize; i++){
				HashEntry* current = hashArray[i];

				while(current != nullptr){
					HashEntry* nextNode = current->next;
					delete current;
					current = nextNode;
				}
			}

			delete[] hashArray;
		}
		
		/*
			The function below (overloading = operator) prevents assigning one existing hash table to another because this could cause memory leaks, dangling pointers, and double deletion, You do not need to change this line.
		*/
		HashTable& operator=(HashTable& other) = delete;


		/*
			Function: putValue()
			Purpose: To add an item to the hashTable with a given key & value
					 If a duplicate item, then update existing value.
			Returns: true if was able to add the item and false when just 
					 updating value (if duplicate)
		*/
		bool putValue(string key, T value) {
			// TODO: traverse the WHOLE chain for this key; update or insert.
			int bucketIndex = indexFor(key);

			HashEntry* current = hashArray[bucketIndex]; //keeps track of the current node
			while(current != nullptr){
				if(current->key == key){
					//replace key value with the current value if it is the same
					current->value = value;
					return false;	//leaves function if the value is updated this way
				}
				current = current->next; //moves to the next node in the entry; 
			}
			
			
			//dynamically allocates a new Hash Entry if there is no duplicate
			HashEntry* newHE = new HashEntry;
			newHE->key = key;
			newHE->value = value;
			newHE->next = hashArray[bucketIndex];
			hashArray[bucketIndex] = newHE;

			entries++;	//updates the amount of entries number in the table
			return true;


		}
		
		/*
			Function: getValue()
			Purpose: To retrieve an item given key & value
			Returns: true if was able to find the item and false when item
			         wasn't found
		*/			
		bool getValue(string key, T& value) {
			// TODO: return true and write to value when the key is found.
			int bucketIndex = indexFor(key);
			if(hashArray[bucketIndex] == NULL){	//checks if there is anything in the index
				return false;
			}else{
				HashEntry *entry = hashArray[bucketIndex];	//if there is something in the index
				while(entry != NULL && entry->key != key){	//checks if the entry itself is empty or if it does not match the key
					entry = entry->next;	
				}
				if(entry == NULL){
					return false;
				}else{
					value = entry->value; //assigns the value
					return true;
				}	
			}
		}
		
		/*
			Function: removeValue()
			Purpose: To remove an item with a given key
			Returns: true if was able to find the item and remove it and false otherwise
		*/			
		bool removeValue(string key) {
			// TODO: unlink and delete an entry (head, middle, or tail).
			bool removed = false;
			HashEntry *entry;
			HashEntry *prevEntry;
			int bucketIndex = indexFor(key);
			if(hashArray[bucketIndex] != NULL){
				//transverse through list and find key
				prevEntry = NULL;
				entry = hashArray[bucketIndex];
				while((entry->next != NULL) && (entry->key != key)){
					prevEntry = entry;
					entry = entry->next;
				}
				if(entry->key == key){
					if(prevEntry == NULL){
						HashEntry *nextEntry = entry->next;

						delete entry;
						hashArray[bucketIndex] = nextEntry; //re-link list
					}else{
						HashEntry *next = entry->next;
						delete entry;
						prevEntry->next = next;
					}
					removed = true;
				}
			}
			return removed;
		}
		
		//accessor functions
		int getSize() const { 
			return entries; 
		}
		int getBucketCount() const { 
			return tableSize; 
		}
		int bucketIndex(string key) const { 
			return indexFor(key); 
		}
		
		
		int bucketLength(int index) {
			// TODO: count nodes in this bucket (return -1 for an invalid index).
			if(index < 0 || index >= tableSize){
				return -1;
			}
			int count = 0; //start with an initial count
			HashEntry* current = hashArray[index];
			while(current != nullptr){	//transverses through the bucket and counts each entry
				count++;
				current = current->next;	//moves to the next entry
			}
			return count;
		}
		
		
		void printBucket(int index) {
			// TODO: display the keys in the chain, or report an invalid index.
			if(index < 0 || index >= tableSize){
				cout << "No bucket found!";
				return;
			}

			HashEntry* current = hashArray[index];
			if(current == nullptr){
				cout << "Bucket " << index << " is EMPTY!" << endl;
				return;
			}

			cout << "Bucket " << index << ": ";
			while(current != nullptr){
				cout << current->key << " -> ";
				current = current->next;
			}
			cout << "NULL" << endl;
		}
		
		
		void printHashTable() {
			//display every bucket and its chain.
			cout << "----------\n";
			
			for(int i=0; i<tableSize; i++)
			{
				if(hashArray[i] != NULL)
				{
					HashEntry* entry = hashArray[i];
					while(entry->next != NULL)
					{
						cout << "---->" << setw(8) << entry->value;
						entry = entry->next;
					}
					cout << "---->" << setw(8) << entry->value;
					cout << "\n";
				}
				else
					cout << setw(8) << "NULL" << "\n";
			}
			cout << "----------\n\n";
		}
		
		
		void printStatistics() {
			// TODO: total unique videos, buckets, occupied/collision buckets,
			// longest chain, and average entries per bucket.
			int occupied = 0;
			int collision = 0;
			int longChain = 0;
			double avgEntries = 0.0;

			for(int i = 0; i < tableSize; i++){
				int len = bucketLength(i);
				if(len > 0){
					occupied++;
					if(len > 1){
						collision++;
					}
					if(len > longChain){
						longChain = len; //updates the longest chain to the newest length
					}
				}
			}

			if(tableSize == 0){
				avgEntries = 0.0; //in case there are no entries in any buvkets
			}else{
				avgEntries = static_cast<double>(entries) / tableSize; //casts as a double
			}

			cout << "Unique Videos: " << entries << "\n"
				 << "Buckets: " << tableSize << "\n"
				 << "Occupied " << occupied << "\n"
				 << "Buckets with collision: " << collision << "\n"
				 << "Longest Chain: " << longChain << "\n"
				 << "Average Entries per Bucket (Load factor): " << avgEntries << "\n";
		}
};
#endif
