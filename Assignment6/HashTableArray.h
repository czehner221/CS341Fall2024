// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// czehner

#ifndef HASHTABLEARRAY_H
#define HASHTABLEARRAY_H

#include "HashTable.h"

enum ProbingType
{
	// LINEAR - 0, QUADRATIC - 1
	LINEAR, QUADRATIC
};

class HashTableArray : public HashTable
{

	public:
		// HashEntry default constructor
		HashTableArray(int size, ProbingType type); // int data = -1;
		
		
		// HashEntry copy constructor
		HashTableArray(const HashTableArray & hashArray);
		
		// HashEntry destructor
		virtual ~HashTableArray();
		
		// Gets the entry
		HashEntry * getEntry();
		
		// Gets the size
		int getSize();
		
		// Sets the entry
		void setEntry(HashEntry * hashEntry);
		
		// Sets the size
		void setSize(int size);
		
		// Inserts into the hash table
		virtual void insert(int key, int value);
		
		// Searches the hash table
		virtual int search(int key);
		
		// Removes from the hash table
		virtual void remove(int key);
		
		// Prints the hash table
		virtual void print();
		
		// Gets the hash function
		int getHashFunction(int key);
	
	private:
		HashEntry * entry_;		// Entry in table
		int size_;				// Size of the table
		ProbingType type_;		// Type of probing
};

#endif