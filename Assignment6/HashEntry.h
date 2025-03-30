// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// czehner

#ifndef HASHENTRY_H
#define HASHENTRY_H

#include <iostream>


// Enum to keep track of the hash entry status
enum Status
{
	// EMPTY - 0, OCCUPIED - 1, REMOVED - 2
	EMPTY, OCCUPIED, REMOVED
};

class HashEntry
{

	public:
		// HashEntry default constructor
		HashEntry(); // int data = -1;
		
		// HashEntry parameterized constructor
		HashEntry(int key, int value);
		
		// HashEntry destructor
		~HashEntry();
		
		// Gets the key of the entry
		int getKey();
		
		// Gets the value of the entry
		int getValue();
		
		// Gets the status of the entry
		Status getStatus();
		
		// Sets the key of the entry
		void setKey(int key);
		
		// Sets the value of the entry
		void setValue(int value);
		
		// Sets the status of the entry
		void setStatus(Status status);
	
	private:
		int key_;			// Key of entry
		int value_;			// Value of entry
		Status status_;		// Status of entry
};

#endif