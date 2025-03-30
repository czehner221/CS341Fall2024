// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// czehner

#include "bitarray.h"

// BitArray default constructor
BitArray::BitArray(int size) : data_(nullptr), LENGTH(BYTES * BIT_IN_BYTE), BYTES(size)
{

}

// BitArray copy constructor
BitArray::BitArray(const BitArray & array) : LENGTH(array.LENGTH), BYTES(array.BYTES)
{
	// Deep Copy
	// Initialize new bitarray
	data_ = new char[LENGTH/BYTES];
	
	// Copies over contents to new bit array
	for(int i = 0; i < LENGTH/BYTES; i++)
	{
		data_[i] = array.data_[i];
	}
}

// BitArray destructor
BitArray::~BitArray()
{
	// Takes it off the heap if not null
	if(data_ != nullptr)
	{
		delete [] data_;
	}
	
}

// Gets bit at a certain position
bool BitArray::get(int position) const
{
	// Calculate index in array and position of bit within the byte
	int index = (position)/BIT_IN_BYTE;
	position = position % BIT_IN_BYTE;
	
	// If bit found with bitwise AND and shifting bits is not 0
	if((data_[index] & (1 << ((BIT_IN_BYTE - 1) - position))) != 0)
	{
		return 1; // Returns 1 bit
	}
	else // The bit is 0
	{
		return 0; // Returns 0 bit
	}
}

// Initializes bit array with a word and its size
void BitArray::initialize(char * word, int size)
{
	// Sets the size of the bit array
	BYTES = size;
	LENGTH = size * BIT_IN_BYTE;
	
	// Deletes any existing memory
	delete [] data_;
	
	// Allocates new memory for bit array
	data_ = new char[size];
	
	// Runs for size of word
	for(int i = 0; i < size; i++)
	{
		// Copies each character from the word array into the bit array.
		data_[i] = word[i];
	}
}

// Sets a bit at a certain position to a certain bit
bool BitArray::set(int position, int bit)
{
	// Calculate index where bit is
	int index = position / BIT_IN_BYTE;
	
	// If position is within the bounds
	if(position < LENGTH)
	{
		// Calculate position of bit within the byte
		position = position % BIT_IN_BYTE;
		
		// If the bit is 1
		if(bit == 1)
		{
			// Sets the bit using OR on bit mask
			data_[index] |= (1 << ((BIT_IN_BYTE - 1) - position));
		}
		else // If the bit is 0
		{
			// Sets the bit using AND on complement of bit mask
			data_[index] &= ~(1 << ((BIT_IN_BYTE - 1) - position));
		}
		
		return true;
	
	}
	else
	{
		// Returns false if position is out of bounds
		return false; 
	}
}

// Flips the bit at a certain position
bool BitArray::flip(int position)
{
	// If position is within the bounds of the bit array
	if(position < LENGTH)
	{
		// Calculate byte index and position of the byte
		int index = position/BIT_IN_BYTE;
		position = position % BIT_IN_BYTE;
		
		// XOR flips the bit at the given position
		data_[index] = ((data_[index]) ^ (1 << (7-position)));
		
		return true;
	}
	else
	{
		// If position is out of bounds
		return false;
	}
}

// Compliment inverts the bits in the bit array
void BitArray::complement()
{
	// Runs for the length of the bit array
	for(int i = 0; i < LENGTH; i++)
	{
		// Flips each bit
		flip(i);
	}
}

// Returns the character in the byte (8 bits) within the BitArray given a specified position
char BitArray::get8(int position) const
{
	// Return byte that contains the bit at certain position
	return data_[position/BIT_IN_BYTE];
}

// Sets the character in given byte with a specified index for the character array.
void BitArray::set8(char c, int index)
{
	// set byte at certain index to given char c
	data_[index] = c;
}

// Clears the bit array (sets all bits to 0)
void BitArray::clear()
{
	// Runs for number of BYTES in bit array
	for(int i = 0; i < BYTES; i++)
	{
		// Sets each bit to 0
		data_[i] = 0;
	}
}

//
// void print()
//
void BitArray::print()
{	
	std::cout << "|";
	
	for (int i=0; i < BYTES; i++)
	{
		std::bitset<BIT_IN_BYTE> bits = data_[i];
		std::cout << bits << "|";
	}
	
	std::cout << std::endl;	
}