// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// czehner

#include "HashTableCuckoo.h"

// Constructor
HashTableCuckoo::HashTableCuckoo(int size) : HashTable(), size_(0), cycle_(false)
{
	// If the size is greater than 0...
	if(size > 0)
	{
		// Create 2 new entry arrays
		entry_ = new HashEntry[size];
		entry2_ = new HashEntry[size];	
		
		// Loop through the size of the arrays 
		for(int i = 0; i < size_; i++)
		{
			// Fill them with new, empty entries
			HashEntry newEntry;
			newEntry.setStatus(EMPTY);
			entry_[i] = newEntry;
			entry2_[i] = newEntry;
		}
		
		// Set size
		size_ = size;
	}
}

// COPY CONSTRUCTOR SAVE FOR LATER
HashTableCuckoo::HashTableCuckoo(const HashTableCuckoo & hashCuckoo) : size_(hashCuckoo.size_), entry_(new HashEntry[hashCuckoo.size_]), entry2_(new HashEntry[hashCuckoo.size_]), cycle_(false)
{
	// Loop for size of table 
	for(int i = 0; i < size_; i++)
	{
		// Copy valules over from tables
		entry_[i] = hashCuckoo.entry_[i];
		entry2_[i] = hashCuckoo.entry2_[i];
	}
}

// Destructor
HashTableCuckoo::~HashTableCuckoo()
{
	// Deletes both entry arrays
	delete [] entry_;
	delete [] entry2_;
}

// Gets entry1
HashEntry * HashTableCuckoo::getEntryOne()
{
	return entry_;
}

// Gets entry2
HashEntry * HashTableCuckoo::getEntryTwo()
{
	return entry2_;
}

// Gets the size
int HashTableCuckoo::getSize()
{
	return size_;
}
	
// Set entry one	
void HashTableCuckoo::setEntryOne(HashEntry * hashEntry)
{
	entry_ = hashEntry;
}

// Set entry 2
void HashTableCuckoo::setEntryTwo(HashEntry * hashEntry)
{
	entry2_ = hashEntry;
}

// Set size
void HashTableCuckoo::setSize(int size)
{
	size_ = size;
}

// Inserts into the two entry tables	
void HashTableCuckoo::insert(int key, int value)
{
	// Two flags to indicate relocation and if there is a cycle
	bool relocated = false;
	bool cycle = false;
	
	// Keep track of relocation tries
	int count = 0;
	
	// Keeps track of hash values
	int hashVal = 0;
	
	//int hashProbing = key % size_;
	
	// New entry with passed key and value
	HashEntry newEntry(key, value);
	newEntry.setStatus(OCCUPIED);
	
	// First calculate hash value with first hash function
	hashVal = getHashFunction1(key);
	
	// If the position is empty
	if(entry_[hashVal].getStatus() == EMPTY)
	{
		// Place entry into position
		entry_[hashVal] = newEntry;
	}
	else
	{
		// Holds the entries that will be pushed out
		HashEntry firstEntry;
		
		// Check cycle
		while(relocated == false && cycle == false)
		{
			// Relocation is odd, so it moves to the second table
			if(count % 2 == 1)
			{
				// Relocate to second table
				firstEntry = entry2_[hashVal];
				entry2_[hashVal] = newEntry;
				
				// Calculate hash value for entry that is pushed
				hashVal = getHashFunction1(firstEntry.getKey());
				
				// If position is empty 
				if(entry_[hashVal].getStatus() == EMPTY)
				{
					// Place entry in position. Relocation successful.
					entry_[hashVal] = firstEntry;
					relocated = true;
				}
				else
				{
					// New entry becomes the first entry. Relocation unsuccessful. It must continue.
					newEntry = firstEntry;
					relocated = false;
				}
			}
			else
			{
				// Relocate entry in first table
				firstEntry = entry_[hashVal];
				entry_[hashVal] = newEntry;
				
				// Calculate hash value using second hash function
				hashVal = getHashFunction2(firstEntry.getKey());
				
				// If the slot is empty in second table
				if(entry2_[hashVal].getStatus() == EMPTY)
				{
					// Place entry in position. Relocation successful
					entry2_[hashVal] = firstEntry;
					relocated = true;
					
				}
				else
				{
					// New entry becomes first entry. Relocation unsuccessful.
					newEntry = firstEntry;
					relocated = false;
				}
			}
			
			// Increase count for relocation tries
			count++;
			
			// Count equals size... Cycle detected
			if(count == size_)
			{
				// Cycle bool becomes true
				cycle = true;
				
				// Sets cycle to true, helper for driver's sake
				setCycle(cycle);
				
				// Print message
				std::cout << std::endl;
				std::cout << "Cycle Present - Rehash!" << std::endl;
				std::cout << "Key Unpositioned: " << key << std::endl;
				std::cout << std::endl;
				std::cout << "<<<--- Insufficient Hash Table Size! Re-hash! --->>>" << std::endl;
				std::cout << std::endl;
			}
		}
	}
}

// Search the tables
int HashTableCuckoo::search(int key)
{
	// Integers for hash values using probe functions 1 and 2
	int hashProbe1 = getHashFunction1(key);
	int hashProbe2 = getHashFunction2(key);
	
	// If the key is found in table 1
	if(entry_[hashProbe1].getKey() == key)
	{
		return entry_[hashProbe1].getValue();
	}
	else if(entry2_[hashProbe2].getKey() == key) // If the key is found in table 2
	{
		return entry2_[hashProbe2].getValue();
	}
	else // If its in neither, return -1
	{
		return -1;
	}
	
	// Return -1 by default. Prevents warnings
	return -1;
}

// Remove from table
void HashTableCuckoo::remove(int key)
{
	// Integers for hash values using probe functions 1 and 2
	int hashProbe1 = getHashFunction1(key);
	int hashProbe2 = getHashFunction2(key);
	
	//If the key is found in table 1
	if(entry_[hashProbe1].getKey() == key)
	{
		// It is removed from the table
		HashEntry newEntry;
		newEntry.setStatus(EMPTY);
		entry_[hashProbe1] = newEntry;
		std::cout << "Key " << key << " removed." << std:: endl;
	}
	else if(entry2_[hashProbe2].getKey() == key) // If the key is found in table 2
	{
		// It is removed from table 2
		HashEntry newEntry;
		newEntry.setStatus(EMPTY);
		entry2_[hashProbe2] = newEntry;
		std::cout << "Key " << key << " removed." << std:: endl;
	}
	else
	{
		// Otherwise, it is not in the table at all.
		std::cout << "Invalid Key " << key << " not found in table!" << std::endl;
		std::cout << std::endl;
	}
	
}

// Print the table
void HashTableCuckoo::print()
{
	// Formatted to match assignment details
	// Loops through table one printing values or showing empty entries
	// Then loops through table two printing values or showing empty entries
	std::cout << std::endl;
	std::cout << "***********************************" << std::endl;
	for(int i = 0; i < size_; i++)
	{
		if(entry_[i].getStatus() == OCCUPIED)
		{
			std::cout << "[" << i << "]: " << entry_[i].getKey() << std::endl;
		}
		else
		{
			std::cout << "[" << i << "]: " << std::endl;
		}
	}
	std::cout << "***********************************" << std::endl;
	
	std::cout << std::endl;
	
	std::cout << "***********************************" << std::endl;
	for(int i = 0; i < size_; i++)
	{
		if(entry2_[i].getStatus() == OCCUPIED)
		{
			std::cout << "[" << i << "]: " << entry2_[i].getKey() << std::endl;
		}
		else
		{
			std::cout << "[" << i << "]: " << std::endl;
		}
	}
	std::cout << "***********************************" << std::endl;
	std::cout << std::endl;
}

// Hash function 1 for first table
int HashTableCuckoo::getHashFunction1(int key)
{
	return (key % size_);
}

// Hash function 2 for second table
int HashTableCuckoo::getHashFunction2(int key)
{
	return (key / size_) % size_;
}

// Sets if cycle is true or false cycle
void HashTableCuckoo::setCycle(bool cycle)
{
	cycle_ = cycle;
}

// Returns a true or false cycle
bool HashTableCuckoo::getCycle()
{
	return cycle_;
}