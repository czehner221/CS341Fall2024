// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// czehner

#ifndef HASHTABLECHAINING_H
#define HASHTABLECHAINING_H

#include "HashTable.h"
#include "DoubleLinkedList.h"

class HashTableChaining : public HashTable
{

	public:
		// HashEntry default constructor
		HashTableChaining(int size);
		
		// HashEntry copy constructor
		HashTableChaining(const HashTableChaining & hashChain);
		
		// HashEntry destructor
		virtual ~HashTableChaining();
		
		// Gets the entry
		DoubleLinkedList * getEntry();
		
		// Gets the size
		int getSize();
		
		// Sets the entry
		void setEntry(DoubleLinkedList * hashEntry);
		
		// Sets the size
		void setSize(int size);
		
		// Inserts into table
		virtual void insert(int key, int value);
		
		// Searches the table
		virtual int search(int key);
		
		// Remove from table
		virtual void remove(int key);
		
		// Prints the table
		virtual void print();
	
	private:
		HashTableChaining() {}
		
		DoubleLinkedList * entry_;	// Entry in hash table chaining
		int size_;			// Size of hash table
};

#endif