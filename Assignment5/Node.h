// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// czehner

#ifndef NODE_H
#define NODE_H

#include <iostream>

class Node
{
	public:
		// Node default constructor
		Node(int data = -1);
		
		// Node destructor
		~Node();
		
		// Data getter method ( const helps for linked node copy constructor )
		int getData() const;
	private:
		int data_; // Holds the data aka value of a node
};

#endif