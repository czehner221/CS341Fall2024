// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// czehner

#include "HashTableArray.h"

// Default constructor
HashTableArray::HashTableArray(int size, ProbingType type) : HashTable(), size_(0), type_(LINEAR)
{
	// If the size is greater than 0...
	if(size > 0)
	{
		
		// Create new HashEntry array
		entry_ = new HashEntry[size];
		
		// Then load it with empty entries 
		for(int i = 0; i < size_; i++)
		{
			HashEntry newEntry;
			newEntry.setStatus(EMPTY);
			entry_[i] = newEntry;
		}
		
		// Set size and type
		size_ = size;
		type_ = type;
	}
}

// Copy constructor
HashTableArray::HashTableArray(const HashTableArray & hashArray) : size_(hashArray.size_), entry_(new HashEntry[hashArray.size_]), type_(LINEAR)
{
	// Copy values!
	for(int i = 0; i < size_; i++)
	{
		entry_[i] = hashArray.entry_[i];
	}
}

// Destructor deletes the entry array
HashTableArray::~HashTableArray()
{
	delete [] entry_;
}

// Gets the entry
HashEntry * HashTableArray::getEntry()
{
	return entry_;
}

// Gets the size of the array
int HashTableArray::getSize()
{
	return size_;
}

// Sets the entry
void HashTableArray::setEntry(HashEntry * hashEntry)
{
	entry_ = hashEntry;
}

// Sets teh size of the table
void HashTableArray::setSize(int size)
{
	size_ = size;
}
		
// Inserts into the table
void HashTableArray::insert(int key, int value)
{
	// Make new entry with key and value that were passed. The entry becomes occupied as well.
	HashEntry newEntry(key, value);
	newEntry.setStatus(OCCUPIED);
	
	// Holds computed hash value
	int hashValue = 0;
	
	// Gets value from function
	hashValue = getHashFunction(key);
	
	// If the entry status is empty, entry is placed at that location
	if(entry_[hashValue].getStatus() == EMPTY)
	{
		entry_[hashValue] = newEntry;
	}
	else // Entry isn't empty
	{
		// Resolve collision
		// Loops for size of table
		for(int i = 0; i < size_; i++)
		{
			int newHashValue = 0;
			
			// If linear, determine next position with linear probing method
			if(type_ == LINEAR)
			{
				newHashValue = (key + i) % size_;
			}
			else // If quadratic, determine next position with quadratic probing method
			{
				newHashValue = (key + (i * i)) % size_; 
			}
			
			// If position is empty
			if(entry_[newHashValue].getStatus() == EMPTY)
			{
				// Place entry and break from loop
				entry_[newHashValue] = newEntry;
				break;
			}
		}
	}
}
		
// Searches for entry in table
int HashTableArray::search(int key)
{
	// Hash index and value initializations
	int hashIndex = 0;
	int value = -1;
	
	// Find hash index with hash function
	hashIndex = getHashFunction(key);
	
	// If the key is found and the status is occupied
	if(entry_[hashIndex].getKey() == key && entry_[hashIndex].getStatus() == OCCUPIED)
	{
		// Value becomes values at index
		value = entry_[hashIndex].getValue();
	}
	else
	{
		// Keep track of starting index and count
		int startHash = hashIndex;
		int count = 0;
		
		// Do while loop while key is not found, start hash is different from index and count is less than size
		do
		{
			// If type is linear, apply linear probing strategy
			if(type_ == LINEAR)
			{
				hashIndex = (hashIndex + 1) % size_;
			}
			else // It's quadratic
			{
				// Quadtratic strategy
				hashIndex = (getHashFunction(key) + (count * count)) % size_;
				
				// Handles cycle if present
				if(startHash == hashIndex)
				{
					count++;
					hashIndex = (hashIndex + (count * count)) % size_;
				}
			}
			
			// If the key exists and is occupied
			if(entry_[hashIndex].getKey() == key && entry_[hashIndex].getStatus() == OCCUPIED)
			{
				// Get the value and leave the loop
				value = entry_[hashIndex].getValue();
				break;
			}
			
			// Increment counter
			count++;
		}
		while(entry_[hashIndex].getKey() != key && startHash != hashIndex && count < size_);
	}
	
	// Return the value
	return value;
}

// Removes key from hash table
void HashTableArray::remove(int key)
{
	// Hash index and value initializations
	int hashIndex = 0;
	int value = -1;
	
	// Calculate hash index with hash function
	hashIndex = getHashFunction(key);
	
	// If the key is found and status is occupied
	if(entry_[hashIndex].getKey() == key && entry_[hashIndex].getStatus() == OCCUPIED)
	{
		// Value becomes value of the key
		value = entry_[hashIndex].getValue();
		
		// Make a new entry and mark it as removed
		HashEntry newEntry;
		newEntry.setStatus(REMOVED);
		entry_[hashIndex] = newEntry;
	}
	else
	{
		// Keep track of starting index and count
		int startHash = hashIndex;
		int count = 0;
		
		// Do while loop while key is not found, start hash is different from index and count is less than size
		do
		{
			// If type is linear, apply linear probing
			if(type_ == LINEAR)
			{
				hashIndex = (hashIndex + 1) % size_;
			}
			else // Quadtratic
			{
				// Quadtratic probing to find hash index
				hashIndex = (getHashFunction(key) + (count * count)) % size_;
				
				// Handles cycle if present
				if(startHash == hashIndex)
				{
					count++;
					hashIndex = (hashIndex + (count * count)) % size_;
				}
			}
			
			// If the key is found and is occupied
			if(entry_[hashIndex].getKey() == key && entry_[hashIndex].getStatus() == OCCUPIED)
			{
				// Value becomes value of the key
				value = entry_[hashIndex].getValue();
				
				// Make a new entry and mark it as removed
				HashEntry newEntry;
				newEntry.setStatus(REMOVED);
				entry_[hashIndex] = newEntry;
			}
			
			// Increase count
			count++;
		}
		while(entry_[hashIndex].getKey() != key && startHash != hashIndex && count < size_);
	}
	
	// If the value is -1, the key isn't found in the table
	if(value == -1)
	{
		// Print message
		std::cout << "Invalid Key " << key << " not found in table!" << std::endl;
		std::cout << std::endl;
	}
	else
	{
		// Print message if key is removed
		std::cout << std::endl;
		std::cout << "Key " << key << " removed." << std:: endl;
		std::cout << std::endl;
	}
}

// Prints the table
void HashTableArray::print()
{
	// Formatted to print table
	// Loops through the table printing each element, or printing nothing if it's not occupied
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
}

// Helper function for hash function
int HashTableArray::getHashFunction(int key)
{
	return(key % size_);
}