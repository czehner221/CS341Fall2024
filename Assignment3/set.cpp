// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// czehner

#include "set.h"

// Set Constructor
Set::Set(int size) : data_(size)
{
	
}

// Set Destructor
Set::~Set()
{
	
}

// Initializes a set
void Set::initialize(char * word, int size)
{
	// Initializes data_ bit array with word array and size
	data_.initialize(word, size);
}

// Finds cardinality of a set
int Set::getCardinality() const
{
	// Variables
	int count = 0;		// Count tracker. Also cardinality
	int bitType = 0;	// Type of bit 1 or 0
	
	// Loops for the length of the bit array
	for(int i = 0; i < data_.length(); i++)
	{
		// The bit type is set to the data at index i
		bitType = data_.get(i);
		
		// If the bit is 1, the count will increase
		if(bitType == 1)
		{
			count++;
		}
	}
	
	// Returns the count as the Cardinality of the set
	return count;
}

BitArray & Set::getData()
{
	// Returns the bit array data_
	return data_;
}

bool Set::setUnion(Set & B)
{
	// Combine elements of two sets
	
	// If the length of the initial set equals the length of set B
	if(data_.length() == B.getData().length())
	{
		// Initializes chars for each set
		unsigned char setA = ' ';
		unsigned char setB = ' ';
		
		// Loops for the bytes in the data set
		for(int i = 0; i < data_.bytes(); i++)
		{
			// Sets setA to ith byte in current set
			setA = data_.get8(i * BIT_IN_BYTE);
			
			// Sets setB to the ith byte in B set
			setB = B.data_.get8(i * BIT_IN_BYTE);
			
			// OR setA with setB
			setA = setA | setB;
			
			// Set the result to current set
			data_.set8(setA, i);
		}
		// Return true if set lengths are equal
		return true;
	}
	else
	{
		// Return false if sets are not equal
		return false;
	}
}

bool Set::setIntersection(Set & B)
{
	// What both sets have in common
	// And both sets
	if(data_.length() == B.getData().length())
	{
		// Initializes chars for each set
		unsigned char setA = ' ';
		unsigned char setB = ' ';
		
		// Loops for the bytes in the data set
		for(int i = 0; i < data_.bytes(); i++)
		{
			// Sets setA to ith byte in current set
			setA = data_.get8(i * BIT_IN_BYTE);
			
			// Sets setB to the ith byte in B set
			setB = B.data_.get8(i * BIT_IN_BYTE);
			
			// AND setA with setB
			setA = setA & setB;
			
			// Set the result to current set
			data_.set8(setA, i);
		}
		// Return true if set lengths are equal
		return true;
	}
	else
	{
		// Return false if sets are not equal
		return false;
	}
}