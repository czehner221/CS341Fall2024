// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// czehner

#include "HashTableChaining.h"

// Hash Table Chaining default constructor
HashTableChaining::HashTableChaining(int size) : HashTable(), size_(0)//, entry_(new DoubleLinkedList[size_])
{
	// Sets size
	size_ = size;
	
	// Makes new double linked list array
	entry_ = new DoubleLinkedList[size_];
	
	// Loops through size making empty entries
	for(int i = 0; i < size; i++)
	{
		entry_[i].getData().setStatus(EMPTY);
	}
}

// Copy Constructor
HashTableChaining::HashTableChaining(const HashTableChaining & hashChain) : size_(hashChain.size_), entry_(new DoubleLinkedList[hashChain.size_])
{
	// Copies data over to copied table
	for(int i = 0; i < size_; i++)
	{
		entry_[i] = hashChain.entry_[i];
	}
}

// Destructor
HashTableChaining::~HashTableChaining()
{
	delete [] entry_;
}

// Gets the entry
DoubleLinkedList * HashTableChaining::getEntry()
{
	return entry_;
}

// Gets the size
int HashTableChaining::getSize()
{
	return size_;
}

// Sets the entry	
void HashTableChaining::setEntry(DoubleLinkedList * hashEntry)
{
	entry_ = hashEntry;
}

// Sets the size
void HashTableChaining::setSize(int size)
{
	size_ = size;
}

// Inserts into the table
void HashTableChaining::insert(int key, int value)
{
	// Calculate hash value
	int hashProbing = key % size_;
	
	// New hash entry with passed key and value
	HashEntry newEntry(key, value);
	
	// New linked node
	LinkedNode * newNode = new LinkedNode(newEntry, nullptr, nullptr);
	
	// If the list is empty
	if(entry_[hashProbing].getHead() == nullptr)
	{
		// Insert the new entry
		entry_[hashProbing].insert(newEntry);
	}
	else
	{
		// If it's not empty insert to the tail of the list
		entry_[hashProbing].insertLinkedNode(entry_[hashProbing].getTail(), newEntry);
	}
	
	// Delete temporary node
	delete newNode;
}

// Search the table
int HashTableChaining::search(int key)
{
	// Calculate hash value
	int hashProbing = key % size_;
	
	// If the key is found 
	if(entry_[hashProbing].getData().getKey() == key)
	{
		// Return the value of the key
		return entry_[hashProbing].getData().getValue();
	}
	else
	{
		// If it's not foundm search the linked list for the key
		return entry_[hashProbing].find(key);
	}
	
}

// Removes from the table	
void HashTableChaining::remove(int key)
{
	// Calculate hash value
	int hashProbing = key % size_;
	
	// If the key is -1, it is not found
	if(entry_[hashProbing].find(key) == -1)
	{
		// Print message
		std::cout << "Invalid Key " << key << " not found in table!" << std::endl;
		std::cout << std::endl;
	}
	else
	{
		// If the key is found, node containing the key is removed
		entry_[hashProbing].removeLinkedNode(key);
	}
}

// Print the table
void HashTableChaining::print()
{
	// Formatted to assignment details
	// Loops through size, and prints each entry.
	std::cout << std::endl;
	std::cout << "***********************************" << std::endl;
	for(int i = 0; i < size_; i++)
	{
		std::cout << "[" << i << "]: ";
		entry_[i].printList();
		
	}
	std::cout << "***********************************" << std::endl;
	std::cout << std::endl;
}