/*
	TODO: add your comment block here and delete this comment
*/
#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <iostream>
#include <string>
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
			// TODO: hash every character using h = (h * 31 + ch) % tableSize.
			// Convert the character to unsigned char before adding it.
			
			
			return 0;
		}
	
	public:
		//constructor
		HashTable(int size) {
			tableSize = size;
			entries = 0;
			//TODO: create the hash table
			//TODO: set all buckets in hash table to NULL

		}
		
		//destructor
		~HashTable() {
			// TODO: delete every node in every chain, then delete[] hashArray.
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
			
			
			return false;
		}
		
		/*
			Function: getValue()
			Purpose: To retrieve an item given key & value
			Returns: true if was able to find the item and false when item
			         wasn't found
		*/			
		bool getValue(string key, T& value) {
			// TODO: return true and write to value when the key is found.
			
			
			return false;
		}
		
		/*
			Function: removeValue()
			Purpose: To remove an item with a given key
			Returns: true if was able to find the item and remove it and false otherwise
		*/			
		bool removeValue(string key) {
			// TODO: unlink and delete an entry (head, middle, or tail).
			
			
			return false;
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
			return 0;
		}
		
		
		void printBucket(int index) {
			// TODO: display the keys in the chain, or report an invalid index.
		}
		
		
		void printHashTable() {
			// TODO: display every bucket and its chain.
		}
		
		
		void printStatistics() {
			// TODO: total unique videos, buckets, occupied/collision buckets,
			// longest chain, and average entries per bucket.
		}
};
#endif
