// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// czehner

#include "RedBlackTree.h"

#include <fstream>

int main()
{
	// Phase I & II
	/*
	// New BST
	BinarySearchTree * testTree = new BinarySearchTree();
	
	// Data value from file
	int dataVal = 0;
	
	// Open file
	std::ifstream inputFile;
	inputFile.open("data.txt");
	
	// If the file is open
	if(inputFile.is_open())
	{
		// Loops while the file is not over
		while(!inputFile.eof())
		{
			// Read in data from file
			inputFile >> dataVal;
			
			// Insert the values into the test tree
			testTree->insert(dataVal);
		}
	}
	else
	{
		std::cout << "Cannot open file." << std::endl;
	}
	
	// Close file
	inputFile.close();
	
	// Print the BST
	testTree->print(testTree->getRoot());
	
	std::cout << std::endl;
	
	// Display root
	std::cout << "Root: " << testTree->getRoot()->getData() << std::endl;
	// Delete the tree
	delete testTree;*/
	
	// Phase III - V
	
	// New Red Black Tree
	RedBlackTree * testTree = new RedBlackTree();
	
	// Data value from file
	int dataVal = 0;
	
	// Open file to read in from
	std::ifstream inputFile;
	inputFile.open("data.txt");
	
	// If the file is open
	if(inputFile.is_open())
	{
		// While its not the end of the file
		while(!inputFile.eof())
		{
			// Read in the data from the file
			inputFile >> dataVal;
			
			// Insert the data into the tree
			testTree->insert(dataVal);
		}
	}
	else
	{
		std::cout << "Cannot open file." << std::endl;
	}
	
	// Close file
	inputFile.close();
	
	// Print the tree
	testTree->print(testTree->getRoot());
	
	std::cout << std::endl;
	
	// Display root and color of the root
	std::cout << "Root: " << testTree->getRoot()->getData() << std::endl;
	std::cout << "Color: " << testTree->getRoot()->getColor() << std::endl;
	
	// Display red nodes
	std::cout << "Red Nodes: ";
	testTree->printRedNodes(testTree->getRoot());
	std::cout << std::endl;
	
	// Display black nodes
	std::cout << "Black Nodes: ";
	testTree->printBlackNodes(testTree->getRoot());
	std::cout << std::endl;
	
	// Delete test tree
	delete testTree;
	
	return 0;
}