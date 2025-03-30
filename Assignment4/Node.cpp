// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// czehner

#include "Node.h"

// Node default constructor
Node::Node(int data) : data_(data)
{
	
}

// Node destructor
Node::~Node()
{
	
}

// Gets data ( const helps for linked node copy constructor )
int Node::getData() const
{
	return data_;
}