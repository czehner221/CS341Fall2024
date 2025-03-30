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
		
		// COPY CONSTRUCTOR
		DoubleLinkedList(const DoubleLinkedList & doubleLinkedList);
		
		// Destructor
		virtual ~DoubleLinkedList();
		
		// Prints the list
		virtual void printList();
		
		// Inserts linked node to double linked list
		void insertLinkedNode(LinkedNode * node, int data);
		
		// Inserts after linked node
		void insertAfterLinkedNode(LinkedNode * node, int data);
		
		// Inserts before linked node
		void insertBeforeLinkedNode(LinkedNode * node, int data);
		
	private:
		
};

#endif