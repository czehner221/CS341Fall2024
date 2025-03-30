// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// czehner

#include "LinkedList.h"

// Linked List Default constructor
LinkedList::LinkedList() : head_(nullptr), tail_(nullptr)
{
	
}


// Linked List Copy Constructor
LinkedList::LinkedList(const LinkedList & linkedList) : head_(nullptr), tail_(nullptr)
{
	// If the head is not a nullptr aka list isn't empty
	if(head_ != nullptr)
	{
		
		// Initialize new lists head with original lists head
		head_ = new LinkedNode(linkedList.head_->getData(), nullptr, nullptr);
		
		// New pointer starting form second node in list
		LinkedNode * mainNode = linkedList.head_->getNextLinkedNode();
		
		// Current node pointer starting at head
		LinkedNode * currentNode = head_;
		
		// while main nodes next node is not nullptr
		while(mainNode != nullptr)
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
		tail_ = currentNode;
	}
	
}

// Linked List Destructor
LinkedList::~LinkedList()
{
	// Only delete if the head is not nullptr
	if(head_ != nullptr)
	{
		delete head_;
	}
}

// Checks to see if the linked list is empty
bool LinkedList::isEmpty()
{
	// If the head is nullptr, the list is empty
	if(head_ == nullptr)
	{
		// The list IS empty
		return true;
	}
	else // The head is not nullptr
	{
		// The List IS NOT empty
		return false;
	}
}

// Gets the length of the linked list
int LinkedList::getLength()
{
	// Increment variable for the nodes in the list
	int count = 0;
	
	// As long as the list is not empty
	if(!isEmpty())
	{
		// Count increases
		count++;
		
		// Temporary node set to head
		LinkedNode * node = head_;
		
		// While that node has a next linked node, the loop runs
		while(node->hasNextLinkedNode())
		{
			// Count increases each for each next node
			count++;
			
			// The node is set to its next node to continue the loop
			node = node->getNextLinkedNode();
		}
	}
	
	// Returns the count of the nodes
	return count;
}

// Inserts an element into the linked list
void LinkedList::insert(HashEntry element)
{
	// Calls insert helper function
	insertLinkedNode(tail_, element);
}

// Prints the linked list
void LinkedList::printList()
{
	// If the list is not empty
	if(!isEmpty())
	{
		// Current node starts on the head
		LinkedNode * currentNode = head_;
		
		// Prints head first
		std::cout << currentNode->getData().getKey();
		
		// Then loops while the current node has a next node
		while(currentNode->hasNextLinkedNode())
		{
			// The current node is set to the next linked node.
			currentNode = currentNode->getNextLinkedNode();
			
			// Print single linked list indicator along with the current node.
			std::cout << "-->" << currentNode->getData().getKey();
		}
		
		// Print some space
		std::cout << std::endl;
	}
	else // The list is empty
	{
		// Prints message indicating empty list
		std::cout << "The Linked List is empty." << std::endl;
	}
}

// Helper Function stuff
// Helper function with insert linked node
// Takes in a specific node and element to insert into linked list
void LinkedList::insertLinkedNode(LinkedNode * node, HashEntry element)
{
	// New linked node
	LinkedNode * linkedNode = new LinkedNode(element, nullptr, nullptr);
	
	// If the list is not empty
	if(!isEmpty())
	{
		// If the node is the tail
		if(node == tail_)
		{
			// The tail is set to new linked node
			tail_ = linkedNode;
			
			// Passed node is set to the tail
			node->setNextLinkedNode(tail_);
		}
		else if(node == head_) // If the node is the head
		{
			// Head becomes the new linked node
			head_ = linkedNode;
			
			// Head is set to the passed in node
			head_->setNextLinkedNode(node);
		}
		else // If the node is neither the head or tail
		{
			// The new linked node is set to the node after the node
			linkedNode->setNextLinkedNode(node->getNextLinkedNode());
			
			// Node is set to the new linked node
			node->setNextLinkedNode(linkedNode);
		}
	}
	else // If the list is empty
	{
		head_ = linkedNode; // Head is set to the new linked node
		tail_ = linkedNode; // The tail is set to the new linked node
	}
	
}

// Gets the head linked node value
LinkedNode * LinkedList::getHead()
{
	// Returns LinkedList's head
	return head_;
}

// Gets the tail linked node value
LinkedNode * LinkedList::getTail()
{
	// Returns LinkedList's tail
	return tail_;
}

// Sets the head linked node value
void LinkedList::setHead(LinkedNode * head)
{
	// Sets head to passed node
	head_ = head;
}

// Sets the tail linked node vaile
void LinkedList::setTail(LinkedNode * tail)
{
	// Sets tail to passed node
	tail_ = tail;
}
