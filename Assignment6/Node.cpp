// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// czehner

#include "Node.h"

// Node default constructor
Node::Node(HashEntry entry) : entry_(entry)
{
	//entry_ = entry;
}

// Node destructor
Node::~Node()
{
	
}

// Gets data ( const helps for linked node copy constructor )
HashEntry Node::getData() const
{
	return entry_;
}

void Node::setData(HashEntry entry)
{
	entry_ = entry;
}