// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// czehner

#include "dictionary.h"

// Dictionary default constructor
Dictionary::Dictionary() : lookupTable_(new int[DICTIONARY_SIZE])
{
	// Temporary set
	Set set;
	
	// Runs for dictionary size
	for(int i = 0; i < DICTIONARY_SIZE; i++)
	{
		// Temporary array holding byte value
		char temp[1];
		temp[0] = i;
		
		// Initialize set with temporary array
		set.initialize(temp, 1);
		
		// Stores cardinality to lookup table
		lookupTable_[i] = set.getCardinality();
	}
}

// Dictionary copy constructor
Dictionary::Dictionary(const Dictionary & dict) : lookupTable_(nullptr)
{
	// Deep copy
	if(dict.lookupTable_)
	{
		// Initialize new lookupTable
		lookupTable_ = new int[DICTIONARY_SIZE];
		
		// Runs for size of the dictionary
		for(int i = 0; i < DICTIONARY_SIZE; i++)
		{
			// Copies values to new array.
			lookupTable_[i] = dict.lookupTable_[i];
		}
	}
}

// Dictionary destructor
Dictionary::~Dictionary()
{
	if(lookupTable_ != nullptr)
	{
		delete [] lookupTable_;
	}
}

// Initializes dictionary
void Dictionary::initialize(char * word, int size)
{
	// Initialize Bit Array with passed word and size
	data_.initialize(word, size);
}

// Counts the requested bits in a certain range (Left to right)
int Dictionary::rank_range(int start, int end, int bit)
{
	// Count variable to track bits
	int count = 0;
	
	// Runs from given start to given end (The range)
	// Range is [start, end). End is exclusive so I did i < end
	for(int i = start; i < end; i++)
	{
		// If the bit is 1 we're counting for 1s
		if(bit == 1)
		{
			// If bit at index i is 1 count increases for 1
			if(data_.get(i))
			{
				count++;
			}
		}
		else // Counting for 0s
		{
			// If bit at index i is not 1, count increases for 0
			if(!data_.get(i))
			{
				count++;
			}
		}
	}
	
	// Return count
	return count;
}

// Finds the kth occurence of a bit within a certain range (Left to right)
int Dictionary::select_range(int start, int end, int k, int bit)
{
	
	// Keeps track of count of occurences
	int count = 0;
	
	// Loops for given range. Start to end
	// Range is [start, end). End is exclusive so I did i < end
	for(int i = start; i < end; i++)
	{
		// Counting for 1s
		if(bit == 1)
		{
			// If the bit is 1 at i increase count for 1
			if(data_.get(i))
			{
				// Increment count
				count++;
				
				// If the count is the kth occurence return the index
				if(count == k)
				{
					return i;
				}
			}
		}
		else // Counting for 0s
		{
			// If the bit is not 1 at i increase count for 1
			if(!data_.get(i))
			{
				// Increment count
				count++;
				
				// If the count is the kth occurence return the index
				if(count == k)
				{
					return i;
				}
			}
		}
	}
	
	// Return -1 to prevent program from crashing in worst case scenario
	return -1;
}

// Finds number of a certain bit until the given end point (Left to right)
int Dictionary::rank(int end, int bit)
{
	// PHASE IV
	/*
	// Count tracker
	int count = 0;
	
	// Runs for length of 0 to given end point
	for(int i = 0; i < end; i++)
	{
		// Counting for 1s
		if(bit == 1)
		{
			// If the bit at i is 1, count for 1 increases
			if(data_.get(i))
			{
				count++;
			}
		}
		else // Counting for 0s
		{
			// If the bit at i is not 1, count for 0 increases
			if(!data_.get(i))
			{
				count++;
			}
		}
	}
	
	// Return the count
	return count;*/
	
	
	// PHASE V OPTIMIZED
	
	// Variables
	int count = 0;						// Keeps track of number of bits
	int fullBytes = end / BIT_IN_BYTE;	// Full bytes up to end point
	int extraBits = 0;					// Left over bits that don't fit into byte
	
	// Loops for full bytes
	for(int i = 0; i < fullBytes; i++)
	{
		// Add count of bits in byte from lookupTable_
		count += lookupTable_[data_.get8(i * BIT_IN_BYTE)];
	}

	// Calculates left overs
	extraBits = end % BIT_IN_BYTE;
	
	// If there are extra bits in the last byte
	if(extraBits != (BIT_IN_BYTE - 1))
	{
		// Add bits in last byte to count
		count += rank_range((fullBytes * BIT_IN_BYTE), end, bit);
	}
	
	// Return the count
	return count;
}

// Finds the kth occurence of a certain bit (Left to right)
int Dictionary::select(int k, int bit)
{
	// PHASE IV
	/*
	// Counter
	int count = 0;
	
	// Runs for the length of the data bit array.
	for(int i = 0; i < data_.length(); i++)
	{
		// Counting for 1s
		if(bit == 1)
		{
			// If the bit is 1 at i, count increases
			if(data_.get(i))
			{
				count++;
				
				// If the count matches the kth occurence, return the index
				if(count == k)
				{
					return i;
				}
			}
		}
		else // Counting for 0s
		{
			// If the bit is not 1 at i, count increases for 0
			if(!data_.get(i))
			{
				count++;
				
				// If the count matches kth occurence, return the index
				if(count == k)
				{
					return i;
				}
			}
		}
	}
	
	// Return -1 to prevent crashing in worst case scenario
	return -1;
	*/
	
	// PHASE V OPTIMIZED
	
	// Variables
	int count = 0;		// Keeps track of occurence of certain bit
	int lastByte = 0;	// Keeps track of count of last byte
	int position = 0;	// Position of kth occurence
	
	// Runs for bytes in data
	for(int i = 0; i < data_.bytes(); i++)
	{
		// Add occurrences of bit to count
		count += lookupTable_[data_.get8(i * BIT_IN_BYTE)];
		
		// If kth occurence is in the current byte
		if((count + lastByte) >= k)
		{
			// Return exact position of the kth occurence
			return select_range((i * BIT_IN_BYTE), ((i + 1) * BIT_IN_BYTE), k - lastByte, bit);
		}
		else
		{
			// If not in current byte, updates last byte to be count
			lastByte = count;
		}
	}
	
	// Prevents edge case in case the for loop doesn't end up finding specific position of k
	// Just searches the whole range
	position = select_range(0, BIT_IN_BYTE, k, bit);
	
	// Returns position to prevent edge case
	return position;
}

// Print the lookup table to a file
void Dictionary::printLookupTable(std::ostream & output)
{
	
	// Loops for size of the dictionary
	for(int i = 0; i < DICTIONARY_SIZE; i++)
	{
		std::bitset<BIT_IN_BYTE> bits = i;
		// Prints formatted lookup table
		output << "lookupTable_[" << i << "] " << lookupTable_[i] << std::endl;
	}
}

