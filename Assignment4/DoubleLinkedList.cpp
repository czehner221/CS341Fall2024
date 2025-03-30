// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// czehner

#include "DoubleLinkedList.h"

// Default Constructor
DoubleLinkedList::DoubleLinkedList() : LinkedList()
{
	
}


// Copy Constructor
DoubleLinkedList::DoubleLinkedList(const DoubleLinkedList & doubleLinkedList) : LinkedList()
{
	// If list is not empty aka no head
	if(LinkedList::getHead() != nullptr)
	{
		// New head node for copied list with data from original list
		LinkedList::setHead(new LinkedNode(LinkedList::getHead()->getData(), nullptr, nullptr));
		
		// New pointer starting form second node in list
		LinkedNode * mainNode = LinkedList::getHead()->getNextLinkedNode();
		
		// Current node pointer starting at head
		LinkedNode * currentNode = LinkedList::getHead();
		
		// while main nodes next node is not nullptr
		while(mainNode->getNextLinkedNode() != nullptr)
		{
			// New node for copied list
			LinkedNode * linkedNode = new LinkedNode(mainNode->getData(), nullptr, currentNode);
			
			// Set current nodes next node to new linked node for copied list
			currentNode->setNextLinkedNode(linkedNode);
			
			// Set current node to the new node
			currentNode = linkedNode;
			
			// Move main node to its next node for iteration
			mainNode = mainNode->getNextLinkedNode();
			
		}
		
		// Set the tail to the current node
		LinkedList::setTail(currentNode);
	}
}

// Destructor
DoubleLinkedList::~DoubleLinkedList()
{
	/*
	if(getHead() != nullptr)
	{
		delete getHead();
	}*/
}

// Prints the doubly linked list
void DoubleLinkedList::printList()
{
	// If the list is not empty
	if(!isEmpty())
	{
		// New linked node for the current node is set to the head of the list
		LinkedNode * currentNode = LinkedList::getHead();
		
		// Prints the head first
		std::cout << currentNode->getData();
		
		// While the current node has a next node loop runs
		while(currentNode->hasNextLinkedNode())
		{
			// Current node is set to its next node
			currentNode = currentNode->getNextLinkedNode();
			
			// Print doubly linkedlist arrows then the current node
			std::cout << "<-->" << currentNode->getData();
		}
		
		// Line space
		std::cout << std::endl;
	}
	else // If the list is empty
	{
		// Prints message indicating empty list
		std::cout << "The Doubly Linked List is empty." << std::endl;
	}
}

// Inserts the linked node into the doubly linked list
void DoubleLinkedList::insertLinkedNode(LinkedNode * node, int data)
{
	// Creates New linked node with the passed data integer
	LinkedNode * newLinkedNode = new LinkedNode(data, nullptr, nullptr);
	
	// If the linked list is not empty
	if(!isEmpty())
	{
		// If the passed node equals the tail of the list
		if(node == LinkedList::getTail())
		{
			// Node's next linked node is set to the new linked node
			node->setNextLinkedNode(newLinkedNode);
			
			// The new linked node's previous node is set to the passed node
			newLinkedNode->setPrevLinkedNode(node);
			
			// The tail is set to the new linked node
			LinkedList::setTail(newLinkedNode);
		}
		else if(node == LinkedList::getHead()) // If the node is the head of the list
		{
			// The node's previous node is set to the new linked node
			node->setPrevLinkedNode(newLinkedNode);
			
			// The new linked node's next linked node is set to the passed node
			newLinkedNode->setNextLinkedNode(node);
			
			// The head is set to the new linked node
			LinkedList::setHead(newLinkedNode);
		}
		else // If the list is empty
		{
			// Passed node's next linked node's previous node is set to the new linked node
			node->getNextLinkedNode()->setPrevLinkedNode(newLinkedNode);
			
			// The new linked node's next node is set to the passed node's next linked node
			newLinkedNode->setNextLinkedNode(node->getNextLinkedNode());
			
			// The passed node's next linked node is set to the new linked node
			node->setNextLinkedNode(newLinkedNode);
			
			// The new linked node's previous linked node is set to the passed node
			newLinkedNode->setPrevLinkedNode(node);
		}
	}
	else // If the list is empty
	{
		// The head is set to the new linked node
		LinkedList::setHead(newLinkedNode);
		
		// The tail is set to the new linked node
		LinkedList::setTail(newLinkedNode);
	}
	
	// Testing purposes to print the data of what node is being inserted
	//std::cout << "Inserting " << newLinkedNode->getData() << "..." << std::endl;
}

// Inserts a node after a specified node in the doubly linked list
void DoubleLinkedList::insertAfterLinkedNode(LinkedNode * node, int data)
{
	
	// Creates New linked node with the passed data integer	
	LinkedNode * newLinkedNode = new LinkedNode(data, nullptr, nullptr);
	
	// If the list is not empty
	if(!isEmpty())
	{
		// New current linked node is equal to the passed in node
		LinkedNode * currentLinkedNode = node;
		
		// If the current node equal to the tail of the list
		if(currentLinkedNode == LinkedList::getTail())
		{
			// The current node's next linked node is set to the new linked node 
			currentLinkedNode->setNextLinkedNode(newLinkedNode);
			
			// The new linked node's previous linked node is set to the current linked node
			newLinkedNode->setPrevLinkedNode(currentLinkedNode);
			
			// The tail is set to the new linked node
			LinkedList::setTail(newLinkedNode);
		}
		else // If the current node is something other than the tail
		{
			// The new linked node's previous node is set to the current linked node
			newLinkedNode->setPrevLinkedNode(currentLinkedNode);
			
			// The new linked node's next linked node is set to the current node's next link node
			newLinkedNode->setNextLinkedNode(currentLinkedNode->getNextLinkedNode());
			
			// The current linked node's next linked node's previous linked node is set to the new linked node
			currentLinkedNode->getNextLinkedNode()->setPrevLinkedNode(newLinkedNode);
			
			// The current linked node's next linked node is set to the new linked node
			currentLinkedNode->setNextLinkedNode(newLinkedNode);
		}
	}
	else // If the list is empty
	{
		// The head is set to the new linked node
		LinkedList::setHead(newLinkedNode);
		
		// The tail is set to the new linked node
		LinkedList::setTail(newLinkedNode);
	}
}

// Inserts a node before a specified node in the doubly linked list
void DoubleLinkedList::insertBeforeLinkedNode(LinkedNode * node, int data)
{
	// Creates New linked node with the passed data integer
	LinkedNode * newLinkedNode = new LinkedNode(data, nullptr, nullptr);
	
	// If the list is not empty
	if(!isEmpty())
	{
		// New current linked node is equal to the passed in node
		LinkedNode * currentLinkedNode = node;
		
		// If the current linked node is equal to the head
		if(currentLinkedNode == LinkedList::getHead())
		{
			// The current linked node's previous node is set to the new linked node
			currentLinkedNode->setPrevLinkedNode(newLinkedNode);
			
			// The new linked node's next linked node is set to the current linked node
			newLinkedNode->setNextLinkedNode(currentLinkedNode);
			
			// The head is set to the new linked node
			LinkedList::setHead(newLinkedNode);
		}
		else // Current linked node is not equal to head
		{
			// The new linked node's next linked node is set to the current linked node
			newLinkedNode->setNextLinkedNode(currentLinkedNode);
			
			// The new linked node's previous linked node is set to the current linked node's previous node
			newLinkedNode->setPrevLinkedNode(currentLinkedNode->getPrevLinkedNode());
			
			// The current linked node's previous linked node's next linked node is set to the new linked node
			currentLinkedNode->getPrevLinkedNode()->setNextLinkedNode(newLinkedNode);
			
			// The current linked node's previous linked node is set to the new linked node
			currentLinkedNode->setPrevLinkedNode(newLinkedNode);
		}
	}
	else // The list is empty
	{
		// Sets both head and tail to the new linked node
		LinkedList::setHead(newLinkedNode);
		LinkedList::setTail(newLinkedNode);
	}
}
