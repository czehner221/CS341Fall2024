// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// czehner

#include <iostream>
#include <cstring>
#include <fstream>

#include "bitarray.h"
#include "dictionary.h"
#include "set.h"

void PhaseI();
void PhaseII();
void PhaseIII();
void PhaseIV();
void PhaseV();

int main()
{
	// Call Each Phase
	//PhaseI();
	//PhaseII();
	//PhaseIII();
	PhaseIV();
	//PhaseV();
	
	return 0;
}

void PhaseI()
{
	//Phase 1
	// New bit array
	BitArray bitArray;
	
	// New word array
	char word[] = "byte";
	
	// Initialize the bit array with the word array and length of the word
	bitArray.initialize(word, strlen(word));
	
	//bitArray.get(4);
	
	// Print number of bits in bit array
	std::cout << "Number of Bits: " << bitArray.length() << std::endl;
	
	// Print the bit array
	bitArray.print();
}

void PhaseII()
{
	// New bit array
	BitArray bitArray;
	
	// New word array
	char word[] = "byte";
	
	// Initialize the bit array with the word array and length of the word
	bitArray.initialize(word, strlen(word));
	
	//bitArray.get(4);
	
	// Print the bit array
	bitArray.print();
	
	std::cout << std::endl;
	
	// Show what the 0th and 10th bit are set to
	std::cout << "0th Bit Set: " << bitArray.get(0) << std::endl;
	std::cout << "10th Bit Set: " << bitArray.get(10) << std::endl;
	
	std::cout << std::endl;
	
	// Set position 0 to 1
	std::cout << "Setting 0th position to 1..." << std::endl;
	bitArray.set(0, 1);
	bitArray.print();
	
	std::cout << std::endl;
	
	// Set position 10 to 0
	std::cout << "Setting 10th position to 0..." << std::endl;
	bitArray.set(10, 0);
	bitArray.print();
	
	std::cout << std::endl;
	
	// Compliment Function
	std::cout << "Complement:" << std::endl;
	bitArray.complement();
	bitArray.print();
	
	std::cout << std::endl;
	
	// Clear Function
	std::cout << "Clear:" << std::endl;
	bitArray.clear();
	bitArray.print();
	
	std::cout << std::endl;
}

void PhaseIII()
{
	// Cardinality variable
	int cardinality = 0;
	
	// Two new word char arrays
	char wordA[] = "byte";
	char wordB[] = "rock";
	
	// Two new bit arrays
	BitArray bitArrayA;
	BitArray bitArrayB;
	
	// Initialize both bit arrays with the 2 char array words
	bitArrayA.initialize(wordA, strlen(wordA));
	bitArrayB.initialize(wordB, strlen(wordB));
	
	// Print the two bit arrays
	bitArrayA.print();
	bitArrayB.print();
	
	// Two new sets
	Set setA;
	Set setB;
	
	// Initialize sets with the 2 char array words
	setA.initialize(wordA, strlen(wordA));
	setB.initialize(wordB, strlen(wordB));
	
	std::cout << std::endl;
	
	// Set cardinality
	cardinality = setA.getCardinality();
	
	// Display cardinality
	std::cout << "Cardinality: " << cardinality << std::endl << std::endl;
	
	// Set union A with B
	setA.setUnion(setB);
	
	// Display the unioned sets
	std::cout << "Set Union (A U B): " << std::endl;
	setA.getData().print();
	
	// Re-initialize setA and setB for intersection
	setA.initialize(wordA, strlen(wordA));
	setB.initialize(wordB, strlen(wordB));
	
	std::cout << std::endl;
	
	// Set intersection set B and set A
	setA.setIntersection(setB);
	
	// Display the set after intersection
	std::cout << "Set Intersection (A X B): " << std::endl;
	setA.getData().print();
	
	std::cout << std::endl;
}

void PhaseIV()
{
	// New char array word
	char word[] = "byte";
	
	// New bit array
	BitArray bitArray;
	
	// Initialize new bit array
	bitArray.initialize(word, strlen(word));
	
	// Print bit array
	bitArray.print();
	
	// New dictionary
	Dictionary dictionary;
	
	// Initialize new dictionary with word
	dictionary.initialize(word, strlen(word));
	
	// Display Rank, Rank Range, Select, and Select Range
	std::cout << "Rank: " << dictionary.rank(strlen(word) * BIT_IN_BYTE) << std::endl;
	std::cout << "Rank Range (15-31): " << dictionary.rank_range(15, 31, 1) << std::endl;
	std::cout << "Select (5,1): " << dictionary.select(5, 1) << std::endl;
	std::cout << "Select Range (0,15,2,1): " << dictionary.select_range(0, 15, 2, 1) << std::endl;
}


void PhaseV()
{
	// New word char array
	char word[] = "byte";
	
	// Create and initialize new bit array
	BitArray bitArray;
	bitArray.initialize(word, strlen(word));
	
	// Print bit Array
	bitArray.print();
	
	// Create and initialize new dictionary object
	Dictionary dict;
	dict.initialize(word, strlen(word));
	
	std::cout << std::endl;
	
	// Display Rank and Select
	std::cout << "Rank: " << dict.rank(strlen(word) * BIT_IN_BYTE) << std::endl;
	std::cout << "Select(4, 1): " << dict.select(4, 1) << std::endl;
	
	std::cout << std::endl;
	
	std::cout << "Printing Lookup Table to file... "<< std::endl;
	// Write the lookup table to a file
	std::ofstream outputFile("LookupTableOutput.txt");
	dict.printLookupTable(outputFile);
	
	// Close the file
	outputFile.close();
}