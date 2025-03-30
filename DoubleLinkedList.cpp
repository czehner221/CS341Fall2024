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

// Destructor
DoubleLinkedList::~DoubleLinkedList()
{
	
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
		std::cout << currentNode->getData().getKey();
		
		// While the current node has a next node loop runs
		while(currentNode->hasNextLinkedNode())
		{
			// Current node is set to its next node
			currentNode = currentNode->getNextLinkedNode();
			
			// Print doubly linkedlist arrows then the current node
			std::cout << "<-->" << currentNode->getData().getKey();
		}
		
		// Line space
		std::cout << std::endl;
	}
	else // If the list is empty
	{
		// Prints message indicating empty list
		//std::cout << "The Doubly Linked List is empty." << std::endl;
		
		// For Assignment 6
		// Print nothing
		std::cout << std::endl;
	}
}

// Inserts the linked node into the doubly linked list
void DoubleLinkedList::insertLinkedNode(LinkedNode * node, HashEntry entry)
{
	// Creates New linked node with the passed data integer
	LinkedNode * newLinkedNode = new LinkedNode(entry, nullptr, nullptr);
	
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
void DoubleLinkedList::insertAfterLinkedNode(LinkedNode * node, HashEntry data)
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
void DoubleLinkedList::insertBeforeLinkedNode(LinkedNode * node, HashEntry data)
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

// Find a key in the list
int DoubleLinkedList::find(int key)
{
	
	// Start search with head of list
	LinkedNode * find = getHead();
	
	// Traverse list while find isn't nullptr aka the end
	while(find != nullptr)
	{
		// If the current nodes key matches the key
		if(find->getData().getKey() == key)
		{
			// It will return the value of the key
			return find->getData().getValue();
		}
		
		// Move on in the list
		find = find->getNextLinkedNode();
	}
	
	// If key isn't found, return -1
	return -1;
	
	// Delete find to prevent leaks
	delete find;
}

// Removes linked node from list
void DoubleLinkedList::removeLinkedNode(int key)
{
	// Tracks if key is found
	bool isFound(false);
	
	// If the list is empty
	if(isEmpty())
	{
		// Show message
		std::cout << "List is empty." << std::endl;
	}
	else
	{
		// List only has one node that matches the key
		if(key == getHead()->getData().getKey() && getHead() == getTail())
		{
			// Remove the node
			LinkedNode * currentNode = LinkedList::getHead();
			setHead(nullptr);
			setTail(nullptr);
			
			// Clear the memory
			delete currentNode;
			
			// Test. Used in HashTableChaining remove method
			//std::cout << "Key " << key << " removed" << std::endl;
			
			// Is found becomes true
			isFound = true;
		}
		else if(key == LinkedList::getHead()->getData().getKey()) // Key is the head, and there are nodes after
		{
			// Nodes to represend old head and new head
			LinkedNode * oldHead = LinkedList::getHead();
			LinkedNode * newHead = LinkedList::getHead()->getNextLinkedNode();
			
			// Update the head
			LinkedList::setHead(newHead);
			
			// Disconnect from list
			oldHead->setNextLinkedNode(nullptr);
			newHead->setPrevLinkedNode(nullptr);
			
			// Clear memory
			delete oldHead;
			
			// Testing. Used in HashTableChaining remove method
			//std::cout << "Key " << key << " removed" << std::endl;
			
			// If found becomes true
			isFound = true;
		}
		else if(key == LinkedList::getTail()->getData().getKey()) // The key is the tail
		{
			// New linked nodes to represent old tail and new tail
			LinkedNode * oldTail = LinkedList::getTail();
			LinkedNode * newTail = LinkedList::getTail()->getPrevLinkedNode();
			
			// Set the tail to the new tail
			LinkedList::setTail(newTail);
			
			// Disconnect
			newTail->setNextLinkedNode(nullptr);
			oldTail->setPrevLinkedNode(nullptr);
			
			// Clear memory
			delete oldTail;
			
			// Testing. Used in HashTableChaining remove method
			//std::cout << "Key " << key << " removed" << std::endl;
			
			// Is found becomes true
			isFound = true;
		}
		else // Key is in the middle of the list
		{
			// Current node starts at head
			LinkedNode * curNode = LinkedList::getHead();
			
			// While the node isn't nullptr or found
			while(curNode != nullptr && !isFound)
			{
				// If current node key equals passed key
				if(curNode->getData().getKey() == key)
				{
					// New linked nodes for next node and prev node
					LinkedNode * nextNode = curNode->getNextLinkedNode();
					LinkedNode * prevNode = curNode->getPrevLinkedNode();
					
					// Update pointers
					nextNode->setPrevLinkedNode(prevNode);
					prevNode->setNextLinkedNode(nextNode);
					
					// Disconnect
					curNode->setPrevLinkedNode(nullptr);
					curNode->setNextLinkedNode(nullptr);
					
					// Clear memory
					delete curNode;
					
					// Testing. Used in HashTableChaining remove method
					//std::cout << "Key " << key << " removed" << std::endl;

					// Is found becomes true
					isFound = true;
				}
				else
				{
					// Move on in list
					curNode = curNode->getNextLinkedNode();
				}
			}
		}
		
		// If the key is not found.
		if(!isFound)
		{ 
			// Display message
			std::cout << "Element does not exist in List." << std::endl;
		}
		else
		{
			// Otherwise, print the key and value
			std::cout << "Key " << key << " removed" << std::endl;
		}
	}
}