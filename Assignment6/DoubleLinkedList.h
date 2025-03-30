// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// czehner

#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

#include "LinkedList.h"

class DoubleLinkedList : public LinkedList
{
	public:
		// Default constructor
		DoubleLinkedList();
		
		// Destructor
		virtual ~DoubleLinkedList();
		
		// Prints the list
		virtual void printList();
		
		// Inserts linked node to double linked list
		void insertLinkedNode(LinkedNode * node, HashEntry entry);
		
		// Inserts after linked node
		void insertAfterLinkedNode(LinkedNode * node, HashEntry data);
		
		// Inserts before linked node
		void insertBeforeLinkedNode(LinkedNode * node, HashEntry data);
		
		// Finds a key in a list
		int find(int key);
		
		// Removes a linked node from a list
		void removeLinkedNode(int key);
		
	private:
		
};

#endif