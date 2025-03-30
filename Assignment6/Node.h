// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// czehner

#ifndef NODE_H
#define NODE_H

#include "HashEntry.h"

class Node
{
	public:
		// Node default constructor
		Node(HashEntry entry);
		
		// Node destructor
		virtual ~Node();
		
		// Data getter method ( const helps for linked node copy constructor )
		virtual HashEntry getData() const;
		
		void setData(HashEntry entry);
	private:
		//int data_; // Holds the data aka value of a node
		HashEntry entry_;
	
	protected:
		Node() {}
};

#endif