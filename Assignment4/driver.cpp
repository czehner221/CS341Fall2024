// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// czehner

#include <iostream>
#include "Node.h"
#include "LinkedNode.h"
#include "LinkedList.h"
#include "DoubleLinkedList.h"

#include <fstream>

// Finds the number of tail insert hops
int checkTailInsert(DoubleLinkedList * doubleLinked, LinkedNode *& head, LinkedNode *& tail, int data, int tailHops)
{
	// Checks if data is greater than or equal to tail
	if(data > tail->getData() || data == tail->getData())
	{
		// Returns tail hops since correct point has been found
		return tailHops;
	}
	else
	{
		// If there is no previous linked node, the correct point has been found
		if(tail->getPrevLinkedNode() == nullptr)
		{
			return tailHops;
		}
		
		// Point tail at previous linked node
		tail = tail->getPrevLinkedNode();
		
		// Increment tail hops
		tailHops++;
		
		// Recursively call to keep searching
		tailHops = checkTailInsert(doubleLinked, head, tail, data, tailHops);
	}
	
	// Returns tailhops to prevent warnings
	return tailHops;
}

// Finds the number of head insert hops
int checkHeadInsert(DoubleLinkedList * doubleLinked, LinkedNode *& head, LinkedNode *& tail, int data, int headHops)
{
	// If inserted data is less than or equal to the heads data
	if(data < head->getData() || data == head->getData())
	{
		// Return headhops since position is found
		return headHops;
	}
	else
	{
		// If there is no next node after head
		if(head->getNextLinkedNode() == nullptr)
		{
			return headHops;
		}
		
		// Head points to the next linked node
		head = head->getNextLinkedNode();
		
		// Increment head hops
		headHops++;
		
		// Recursively call to keep searching
		headHops = checkHeadInsert(doubleLinked, head, tail, data, headHops);
	}
	
	// Return headhops to prevent warnings
	return headHops;
}

int main()
{
	// Phase I & II
	/*
	// New linked nodes
	LinkedNode * node1 = new LinkedNode(15);
	LinkedNode * node2 = new LinkedNode(7);
	LinkedNode * node3 = new LinkedNode(10);
	
	// Sets next linked nodes
	node1->setNextLinkedNode(node2);
	node2->setNextLinkedNode(node3);
	
	// Test node
	LinkedNode * test = node1;
	
	// Prints
	while(test->hasNextLinkedNode())
	{
		std::cout << test->getData() << "->";
		test = test->getNextLinkedNode();
	}
	
	// Prints tests data and next and previous node for node2
	std::cout << test->getData() << std::endl;
	std::cout << "Next: " << node2->getNextLinkedNode()->getData() << std::endl;
	std::cout << "Prev: " << node2->getPrevLinkedNode()->getData() << std::endl;
	
	// Delete node aka head
	delete node1;
	*/
	// Phase II
	/*
	// New linked list
	LinkedList * linkedList = new LinkedList();
	
	// Insert 15
	linkedList->insert(15);
	
	std::cout << "Inserting 15..." << std::endl;
	
	// Insert 7
	linkedList->insert(7);
	
	std::cout << "Inserting 7..." << std::endl;
	
	// Insert 10
	linkedList->insert(10);
	
	std::cout << "Inserting 10..." << std::endl;
	
	// Print list and length
	linkedList->printList();
	std::cout << "Length: " << linkedList->getLength() << std::endl;
	//std::cout << "Next: " << linkedList->getData() << std::endl;
	//std::cout << "Prev: " << linkedList->getPrevLinkedNode().getData() << std::endl;

	// Delete the linked list
	delete linkedList;*/
	
	// Phase III
	/*
	// New linked nodes
	LinkedNode * node1 = new LinkedNode(15, nullptr, nullptr);
	LinkedNode * node2 = new LinkedNode(7, nullptr, nullptr);
	LinkedNode * node3 = new LinkedNode(10, nullptr, nullptr);
	
	// Set the next linked nodes
	node1->setNextLinkedNode(node2);
	node2->setNextLinkedNode(node3);
	
	// Set the previous linked nodes
	node2->setPrevLinkedNode(node1);
	node3->setPrevLinkedNode(node2);
	
	// Test node
	LinkedNode * test = node1;
	
	// Print
	while(test->hasNextLinkedNode())
	{
		std::cout << test->getData() << "->";
		test = test->getNextLinkedNode();
	}
	
	// Print test data, node 2 previous and next linked nodes
	std::cout << test->getData() << std::endl;
	std::cout << "Next: " << node2->getNextLinkedNode()->getData() << std::endl;
	std::cout << "Prev: " << node2->getPrevLinkedNode()->getData() << std::endl;
	
	// Delete head
	delete node1;
	*/
	// Phase IV
	/*
	// New double linked list
	DoubleLinkedList * doubleLinkedList = new DoubleLinkedList();
	
	// Insert Values to double linked list
	doubleLinkedList->insertLinkedNode(doubleLinkedList->getTail(), 15);
	
	std::cout << "Inserting 15..." << std::endl;
	
	doubleLinkedList->insertLinkedNode(doubleLinkedList->getTail(), 7);
	
	std::cout << "Inserting 7..." << std::endl;
	
	doubleLinkedList->insertLinkedNode(doubleLinkedList->getTail(), 10);
	
	std::cout << "Inserting 10..." << std::endl;
	
	// Print that list and length
	doubleLinkedList->printList();
	std::cout << "Length: " << doubleLinkedList->getLength() << std::endl;
	
	// Insert testing
	doubleLinkedList->insertAfterLinkedNode(doubleLinkedList->getTail()->getPrevLinkedNode(), 12);
	
	// Print list
	doubleLinkedList->printList();
	
	// Insert testing
	doubleLinkedList->insertBeforeLinkedNode(doubleLinkedList->getHead(), 13);
	
	// Print list
	doubleLinkedList->printList();
	//std::cout << "Next: " << linkedList->getData() << std::endl;
	//std::cout << "Prev: " << linkedList->getPrevLinkedNode().getData() << std::endl;
	
	// Delete the linked list
	delete doubleLinkedList;
	*/
	
	// Phase V
	
	// New double linked list for data.txt and sorted.txt
	DoubleLinkedList * dataDoubleLinked = new DoubleLinkedList();
	DoubleLinkedList * sortedDoubleLinked = new DoubleLinkedList();
	
	// Variables
	int dataVal = 0;	// Text file data
	int sortedVal = 0;	// Text file data
	int insertVal = 0;	// Insserts file data
	
	int tailHops = 0;	// Total tail hops
	int headHops = 0;	// total head hops
	
	int totalSorted = 0;	// Total sorted hops
	int totalData = 0;		// Total data hops
	
	// Open data.txt
	std::ifstream input;
	input.open("data.txt");
	
	// Load data.txt
	if(input.is_open())
	{
		// Loops for the length of the file.
		while(!input.eof())
		{
			// read in inputs
			input >> dataVal;
			
			// Insert the nodes to the double linked list
			dataDoubleLinked->insertLinkedNode(dataDoubleLinked->getTail(), dataVal);
			
		}
		// Close and clear file.
		input.close();
		input.clear();
	}
	else
	{
		// File is unable to open.
		std::cout << "Cannot open file." << std::endl;
	}
	
	// Print data to show current list
	dataDoubleLinked->printList();
	
	//	**DATA**
	
	// Open inserts.txt
	input.open("inserts.txt");
	
	// New data head and data tail linked nodes
	LinkedNode * dataHead = dataDoubleLinked->LinkedList::getHead();
	LinkedNode * dataTail = dataDoubleLinked->LinkedList::getTail();
	
	// If the stream is open
	if(input.is_open())
	{
		// Loops for the length of the file.
		while(!input.eof())
		{
			// Read in inserts to insert val
			input >> insertVal;
			
			// Reset tail and head hops to 0 each run
			tailHops = 0;
			headHops = 0;
			
			// Set tail and head hops to hops calculated in funcitons
			tailHops = checkTailInsert(dataDoubleLinked, dataHead, dataTail, insertVal, tailHops);
			headHops = checkHeadInsert(dataDoubleLinked, dataHead, dataTail, insertVal, headHops);
			
			// If the tail hops is less than head hops
			if(tailHops < headHops)
			{
				// if the insert value is the data head's value
				if(insertVal == dataHead->getData())
				{
					// Insert after the head
					dataDoubleLinked->insertAfterLinkedNode(dataHead, insertVal);
					
					// Increase data hops
					totalData = totalData + tailHops + 1; 
				}
				
				// Insert after the tail
				dataDoubleLinked->insertAfterLinkedNode(dataTail, insertVal);
				
				// Increase data hops
				totalData = totalData + tailHops;
			}
			else if(headHops < tailHops)
			{
				// If the insert value is the data heads value
				if(insertVal == dataHead->getData())
				{
					// Inserts after head
					dataDoubleLinked->insertAfterLinkedNode(dataHead, insertVal);
					
					// Increment data total
					totalData = totalData + headHops + 1; 
				}
				else
				{
					// Inserts before head
					dataDoubleLinked->insertBeforeLinkedNode(dataHead, insertVal);
					
					// Increment total data
					totalData = totalData + headHops;
				}
			}
			else
			{
				// Default to inserting after the tail
				dataDoubleLinked->insertAfterLinkedNode(dataTail, insertVal);
				
				// increment total data
				totalData = totalData + tailHops;
			}
			
			// Update head and tail poniters
			dataTail = dataDoubleLinked->getTail();
			dataHead = dataDoubleLinked->getHead();
		}
		// Close file.
		input.close();
		input.clear();
	}
	else
	{
		// File is unable to open.
		std::cout << "Cannot open file." << std::endl;
	}
	
	
	// Print Data list
	dataDoubleLinked->printList();
	
	// Open sorted.txt
	
	input.open("sorted.txt");
	
	// Load sorted.txt
	if(input.is_open())
	{
		// Loops for the length of the file.
		while(!input.eof())
		{
			input >> sortedVal;
			//LinkedNode * newNode;
			sortedDoubleLinked->insertLinkedNode(sortedDoubleLinked->getTail(), sortedVal);
			//std::cout << dataVal << " ";
		}
		// Close file.
		input.close();
		input.clear();
	}
	else
	{
		// File is unable to open.
		std::cout << "Cannot open file." << std::endl;
	}
	
	// Print sorted List
	sortedDoubleLinked->printList();
	
	// Open inserts.txt
	input.open("inserts.txt");
	
	//	**SORTED**
	
	// Set head and tail to to the double link lists head and tail
	LinkedNode * sortedHead = sortedDoubleLinked->LinkedList::getHead();
	LinkedNode * sortedTail = sortedDoubleLinked->LinkedList::getTail();
	
	// If the input file is open
	if(input.is_open())
	{
		// Loops for the length of the file.
		while(!input.eof())
		{
			// Read in inserts to insertVal
			input >> insertVal;
			
			// Reset tail and headhops each loop
			tailHops = 0;
			headHops = 0;
			
			// Set tail and head hops to the counts found from the helper functions
			tailHops = checkTailInsert(sortedDoubleLinked, sortedHead, sortedTail, insertVal, tailHops);
			headHops = checkHeadInsert(sortedDoubleLinked, sortedHead, sortedTail, insertVal, headHops);
			
			// If the tailhops are less than head hops
			if(tailHops < headHops)
			{
				// If the inserted value equals the head of the sorted
				if(insertVal == sortedHead->getData())
				{
					// Insert after the head
					sortedDoubleLinked->insertAfterLinkedNode(sortedHead, insertVal);
					
					// Increment sorted total
					totalSorted = totalSorted + tailHops + 1; 
				}
				
				// Insert after the tail
				sortedDoubleLinked->insertAfterLinkedNode(sortedTail, insertVal);
				
				// Increment sorted total
				totalSorted = totalSorted + tailHops;
			}
			else if(headHops < tailHops)
			{
				// If the inserted value is equal to the sorted head data
				if(insertVal == sortedHead->getData())
				{
					// Insert after the head
					sortedDoubleLinked->insertAfterLinkedNode(sortedHead, insertVal);
					
					// Increment total
					totalSorted = totalSorted + headHops + 1; 
				}
				else
				{
					// Insert before the head
					sortedDoubleLinked->insertBeforeLinkedNode(sortedHead, insertVal);
					
					// Increment total
					totalSorted = totalSorted + headHops;
				}
			}
			else
			{
				// Insert after tail 
				sortedDoubleLinked->insertAfterLinkedNode(sortedTail, insertVal);
				
				// Increment total
				totalSorted = totalSorted + tailHops;
			}
			
			// Update head and tail pointers
			sortedTail = sortedDoubleLinked->getTail();
			sortedHead = sortedDoubleLinked->getHead();
			
		}
		// Close file.
		input.close();
		input.clear();
	}
	else
	{
		// File is unable to open.
		std::cout << "Cannot open file." << std::endl;
	}
	
	std::cout << std::endl;
	
	// Print Sorted with inserts
	sortedDoubleLinked->printList();
	
	// Write to a file
	std::ofstream outputFile;
	outputFile.open("output.txt");
	
	// If list is not empty
	if(dataDoubleLinked->getLength() != 0)
	{
		// Get the head first for the print node
		LinkedNode * printNode = dataDoubleLinked->getHead();
		
		// Then write that to the file
		outputFile << printNode->getData();
		
		// While there is a node after the print node
		while(printNode->hasNextLinkedNode())
		{
			// Cycle through each node in the linked list
			printNode = printNode->getNextLinkedNode();
			
			// Writes to file with correct formatting
			outputFile << "<-->" << printNode->getData();
		}
		
		// Adds space
		outputFile << std::endl;
	}
	else
	{
		// Prints the linked list is empty
		outputFile << "The Linked List is empty." << std::endl;
	}
	
	// Close output stream
	outputFile.close();
	outputFile.clear();
	
	
	
	// Write to a file
	outputFile.open("sortedOutput.txt");
	
	// If list is not empty
	if(sortedDoubleLinked->getLength() != 0)
	{
		// Get the head first for the print node
		LinkedNode * printNode = sortedDoubleLinked->getHead();
		
		// Then write that to the file
		outputFile << printNode->getData();
		
		// While there is a node after the print node
		while(printNode->hasNextLinkedNode())
		{
			// Cycle through each node in the linked list
			printNode = printNode->getNextLinkedNode();
			
			// Writes to file with correct formatting
			outputFile << "<-->" << printNode->getData();
		}
		
		// Adds space
		outputFile << std::endl;
	}
	else
	{
		// Linked list is empty
		outputFile << "The Linked List is empty." << std::endl;
	}
	// Close file
	outputFile.close();
	outputFile.clear();
	
	// Open output for README
	outputFile.open("README.txt");
	
	// Write number of Big Dog Hops for data.txt and sorted.txt to the README
	outputFile << "Total number of Big Dog Hops in data.txt: " << totalData << std::endl;
	outputFile << "Total number of Big Dog Hops in sorted.txt: " << totalSorted << std::endl;
	
	// Close file
	outputFile.close();
	outputFile.clear();
	
	// Delete both linked lists
	delete sortedDoubleLinked;
	delete dataDoubleLinked;
	
	// Return 0
	return 0;
}