// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// czehner

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "LinkedNode.h"

class LinkedList : public Node
{
	public:
		// LinkedList constructor
		LinkedList();
		// ADD COPY CONSTRUCTOR
		LinkedList(const LinkedList & linkedList);
		// Linked List destructor
		virtual ~LinkedList();
		
		// Checks to see if linked list is empty
		virtual bool isEmpty();
		
		// Gets length of the linked list
		virtual int getLength();
		
		// Inserts a specified element into the linked list
		virtual void insert(int element);
		
		// Prints the linked list
		virtual void printList();
		
		//Helpers
		// Inserts linked node to list
		void insertLinkedNode(LinkedNode * node, int element);
		
		// Gets head node of list
		LinkedNode * getHead();
		
		// Gets tail node of list
		LinkedNode * getTail();
		
		// Sets head node of list
		void setHead(LinkedNode * head);
		
		// Sets tail node of list
		void setTail(LinkedNode * tail);
		
	private:
		LinkedNode * head_;		// Head node of list
		LinkedNode * tail_;		// Tail node of list
};

#endif