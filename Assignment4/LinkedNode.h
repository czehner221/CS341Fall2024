// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// czehner

#ifndef LINKEDNODE_H
#define LINKEDNODE_H

#include "Node.h"

class LinkedNode : public Node
{
	public:
		// Linked node default constructor
		LinkedNode(int data, LinkedNode * nextLinkedNode, LinkedNode * prevLinkedNode);
		
		// Linked Node copy constructor
		LinkedNode(const LinkedNode & node);
		
		// Linked node destructor
		virtual ~LinkedNode();
		
		// Gets the next linked node
		LinkedNode * getNextLinkedNode();
		
		// Sets the next linked node
		void setNextLinkedNode(LinkedNode * node);
		
		// Checks to see if there is a linked node
		bool hasNextLinkedNode();
		
		// Gets previous linked node
		LinkedNode * getPrevLinkedNode();
		
		// Sets previous linked node
		void setPrevLinkedNode(LinkedNode * prevLinkedNode);
		
		// Checks to see if there is a previous linked node
		bool hasPrevLinkedNode();
	
	private:
		LinkedNode * nextLinkedNode_;	// Next linked node pointer
		LinkedNode * prevLinkedNode_;	// Previous linked node pointer
};

#endif