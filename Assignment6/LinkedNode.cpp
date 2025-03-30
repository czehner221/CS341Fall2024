// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// czehner

#include "LinkedNode.h"

// Linked Node default constructor
LinkedNode::LinkedNode(HashEntry entry, LinkedNode * nextLinkedNode, LinkedNode * prevLinkedNode) : Node(entry), nextLinkedNode_(nextLinkedNode), prevLinkedNode_(prevLinkedNode)
{
	
}

// Linked Node Copy Constructor
LinkedNode::LinkedNode(const LinkedNode & node) : Node(node.getData()), nextLinkedNode_(nullptr), prevLinkedNode_(nullptr)
{
	
	// Main node starts from the next node from head
    LinkedNode * mainNode = node.nextLinkedNode_;
	
	// Current node is set to this, which is referring to the linked node being constructed
    LinkedNode * currentNode = this;

    // While the main node is not a nullptr
    while (mainNode != nullptr)
    {
        // New node with data from the main node
        LinkedNode * newNode = new LinkedNode(mainNode->getData(), nullptr, currentNode);

        // The current node's next node becomes the new node
        currentNode->nextLinkedNode_ = newNode;

        // Move on in list for while loop's sake
        currentNode = newNode;
		
		// Moves on for sake of the while loop
        mainNode = mainNode->getNextLinkedNode();
    }
	
}

// Linked Node destructor
LinkedNode::~LinkedNode()
{
	//TODO
	// If there is a next linked Node, delete it
	if(hasNextLinkedNode())
	{
		delete nextLinkedNode_;
	}
}

// Gets the next linked node
LinkedNode * LinkedNode::getNextLinkedNode()
{
	// If there is a next linked node, it is returned
	if(hasNextLinkedNode())
	{
		return nextLinkedNode_;
	}
	
	// If not, returns a nullptr
	return nullptr;
}

// Sets the next linked node
void LinkedNode::setNextLinkedNode(LinkedNode * node)
{
	// Set to node that was passed through
	nextLinkedNode_ = node;
}

// Checks to see if there is a next linked node
bool LinkedNode::hasNextLinkedNode()
{
	// If the next linked node is a nullptr, there is no next node
	if(nextLinkedNode_ == nullptr)
	{
		// So, returns false
		return false;
	}
	
	// Otherwise returns true, since there is a next linked node
	return true;
}

// Gets the previous linked node
LinkedNode * LinkedNode::getPrevLinkedNode()
{
	// If there is a previous linked node, it is returned
	if(hasPrevLinkedNode())
	{
		return prevLinkedNode_;
	}
	
	// Otherwise returns nullptr
	return nullptr;
}

// Sets the previous linked node
void LinkedNode::setPrevLinkedNode(LinkedNode * prevLinkedNode)
{
	// Sets previous linked node to passed parameter
	prevLinkedNode_ = prevLinkedNode;
}

// Checks to see if there is a previous linked node
bool LinkedNode::hasPrevLinkedNode()
{
	// If the previous linked node is nullptr, there is no previous linked node
	if(prevLinkedNode_ == nullptr)
	{
		// Therefore, returns false
		return false;
	}
	
	// Otherwise it returns true.
	return true;
}
