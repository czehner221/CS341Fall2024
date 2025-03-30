// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// czehner

#include "HashEntry.h"

// HashEntry default constructor
HashEntry::HashEntry() : key_(0), value_(0), status_(EMPTY)
{
	
}

// HashEntry Parameterized Constructor (Copy not needed. No Dynamic memory)
HashEntry::HashEntry(int key, int value) : key_(key), value_(value), status_(OCCUPIED)
{
	
}

// HashEntry destructor
HashEntry::~HashEntry()
{
	
}

// Gets the key
int HashEntry::getKey()
{
	return key_;
}

// Gets the value
int HashEntry::getValue()
{
	return value_;
}

// Gets the status
Status HashEntry::getStatus()
{
	return status_;
}


// Sets the key
void HashEntry::setKey(int key)
{
	key_ = key;
}


// Sets the value
void HashEntry::setValue(int value)
{
	value_ = value;
}

// Sets the status
void HashEntry::setStatus(Status status)
{
	status_ = status;
}
