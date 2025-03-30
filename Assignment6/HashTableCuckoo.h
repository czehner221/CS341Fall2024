// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// czehner

#ifndef HASHTABLECUCKOO_H
#define HASHTABLECUCKOO_H

#include "HashTable.h"

class HashTableCuckoo : public HashTable
{

	public:
		// HashEntry default constructor
		HashTableCuckoo(int size); // int data = -1;
		
		// HashEntry copy constructor
		HashTableCuckoo(const HashTableCuckoo & hashCuckoo);
		
		// HashEntry destructor
		virtual ~HashTableCuckoo();
		
		// Gets entry1
		HashEntry * getEntryOne();
		
		// Gets entry2
		HashEntry * getEntryTwo();
		
		// Gets the size
		int getSize();
		
		// Sets entry1
		void setEntryOne(HashEntry * hashEntry);
		
		// Sets entry2
		void setEntryTwo(HashEntry * hashEntryTwo);
		
		// Sets the size
		void setSize(int size);
		
		// Inserts to the table
		virtual void insert(int key, int value);
		
		// Searches the table
		virtual int search(int key);
		
		// Removes from the table
		virtual void remove(int key);
		
		// Prints the table
		virtual void print();
		
		// Sets the cycle bool
		void setCycle(bool cycle);
		
		// Returns a true or false cycle
		bool getCycle();
	
	private:
		HashTableCuckoo() {}
		
		int getHashFunction1(int key);	// Helper function for hash1 function
		int getHashFunction2(int key);	// Helper functino for hash2 function
		
		HashEntry * entry_;			// Entry 1 for cuckoo
		HashEntry * entry2_;		// Entry 2 for cuckoo
		int size_;				// Size of table
		
		bool cycle_;			// If there is or isn't a cycle
};

#endif