// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// czehner

#include "HashTable.h"
#include "HashTableArray.h"
#include "HashTableChaining.h"
#include "HashTableCuckoo.h"

#include <fstream>

int main()
{
	// Variables
	int probeChoice = 0;
	int tableChoice = 0;
	int inputKey = 0;
	int searchOutput = 0;
	int key = 0;
	int value = 0;
	int hashSize = 0;
	int numValues = 0;
	
	// Welcome message
	std::cout << std::endl;
	std::cout << "Welcome to Blue IV's Can of Who Hash!" << std::endl;
	std::cout << std::endl;
	
	// While the user's choice isn't 5, the program runs
	while(probeChoice != 5)
	{
		// Reset table choice to 0
		tableChoice = 0;
		
		// Display options
		std::cout << "1) Linear Probing" << std::endl;
		std::cout << "2) Quadratic Probing" << std::endl;
		std::cout << "3) Separate Chaining" << std::endl;
		std::cout << "4) Cuckoo Hashing" << std::endl;
		std::cout << "5) Quit Program" << std::endl;
		
		std::cout << std::endl;
		
		// Ask user for their probing choice
		std::cout << "Please enter your choice: ";
		std::cin >> probeChoice;
		
		std::cout << std::endl;
		
		// Linear Probing
		if(probeChoice == 1)
		{
			// Reset hash size
			hashSize = 0;
			
			std::cout << "Linear Probing" << std::endl;
			
			// Ask user for hash size. This loop prevents them from entering 0
			while(hashSize == 0)
			{
				std::cout << std::endl << "Please enter the size of the Hash Table you wish to create: ";
				std::cin >> hashSize;
				
				if(hashSize == 0)
				{
					std::cout << std::endl;
					std::cout << "Do not enter ZERO." << std::endl;
				}
			}
			
			// Create new hash table for linear probing
			HashTableArray * linearHash = new HashTableArray(hashSize, LINEAR);
			
			// File work
			std::ifstream inputFile;
			inputFile.open("data.txt");
			
			// If the file is open
			if(inputFile.is_open())
			{
				// While its not the end of the file
				while(!inputFile.eof())
				{
					// Read in the data from the file
					inputFile >> key >> value;
					
					// Load the hash table
					linearHash->insert(key, value);
					
				}
			}
			else
			{
				std::cout << "Cannot open file." << std::endl;
			}
			
			// Reset numValues
			numValues = 0;
			
			// Close file
			inputFile.close();
			inputFile.clear();
			
			// Print the table
			linearHash->print();
			
			// While table choice isn't four provide options for the table
			while(tableChoice != 4)
			{
				// Display table options
				std::cout << "1) Search For Entry" << std::endl;
				std::cout << "2) Remove Entry" << std::endl;
				std::cout << "3) Print Hash Table" << std::endl;
				std::cout << "4) Return to Main Menu" << std::endl;
			
				std::cout << std::endl;
				
				// Ask user for their choice
				std::cout << "Please enter your choice: ";
				std::cin >> tableChoice;
				
				// Search
				if(tableChoice == 1)
				{
					// Ask for key
					std::cout << std::endl;
					std::cout << "Search (Please enter a key): ";
					std::cin >> inputKey;
					
					searchOutput = linearHash->search(inputKey);
					
					// If search output is -1
					if(searchOutput == -1)
					{
						// It is an invalid key
						std::cout << std::endl;
						std::cout << "Invalid Key! Key " << inputKey << " not found in table!" << std::endl;
						std::cout << std::endl;
					}
					else
					{
						// Print the key and value
						std::cout << std::endl;
						std::cout << "Key: " << inputKey << "\tValue: " << searchOutput << std::endl;
						std::cout << std::endl;
					}
					
				}
				else if(tableChoice == 2) // Remove Entry
				{
					// Ask for key to remove
					std::cout << std::endl;
					std::cout << "Remove (Please enter a key): ";
					std::cin >> inputKey;
					std::cout << std::endl;
					
					// Remove the key
					linearHash->remove(inputKey);
				}
				else if(tableChoice == 3) // Print
				{
					linearHash->print();
				}
				else if(tableChoice == 4) // Return to main menu
				{
					// Leaves the loop. This is required so it doesn't think 4 is an else case, keeping you in the loop.
				}
				else
				{
					std::cout << std::endl;
					// If the user enters something else
					std::cout << "Please enter a number corresponding to the given options!" << std::endl;
					std::cout << std::endl;
				}
			}
			
			// Delete the hash table when finished
			delete linearHash;
		}
		else if(probeChoice == 2) // Quadratic Probing
		{
			// Reset hash size
			hashSize = 0;
			
			std::cout << "Quadratic Probing" << std::endl;
			
			// Ask user to enter the hash size. Loop prevents entering 0
			while(hashSize == 0)
			{
				std::cout << std::endl << "Please enter the size of the Hash Table you wish to create: ";
				std::cin >> hashSize;
				
				if(hashSize == 0)
				{
					std::cout << std::endl;
					std::cout << "Do not enter ZERO." << std::endl;
				}
			}
			
			// Create hash table for quadratic probing
			HashTableArray * quadHash = new HashTableArray(hashSize, QUADRATIC);
			
			// File work
			std::ifstream inputFile;
			inputFile.open("data.txt");
			
			// If the file is open
			if(inputFile.is_open())
			{
				// While its not the end of the file
				while(!inputFile.eof())
				{
					// Read in the data from the file
					inputFile >> key >> value;
					
					// Insert values into quadratic table
					quadHash->insert(key, value);
					
				}
			}
			else
			{
				std::cout << "Cannot open file." << std::endl;
			}
			
			// Close file
			inputFile.close();
			inputFile.clear();
			
			// Print the table
			quadHash->print();
			
			// If choice is not 4
			while(tableChoice != 4)
			{
				// Print options
				std::cout << "1) Search For Entry" << std::endl;
				std::cout << "2) Remove Entry" << std::endl;
				std::cout << "3) Print Hash Table" << std::endl;
				std::cout << "4) Return to Main Menu" << std::endl;
				
				std::cout << std::endl;
				
				// Ask for table choice
				std::cout << "Please enter your choice: ";
				std::cin >> tableChoice;
				
				if(tableChoice == 1) // Search
				{
					std::cout << std::endl;
					
					// Ask for key to search for 
					std::cout << "Search (Please enter a key): ";
					std::cin >> inputKey;
					
					std::cout << std::endl;
					
					searchOutput = quadHash->search(inputKey);
					
					// If search output is -1, key doesn't exist
					if(searchOutput == -1)
					{
						// Send message to user
						std::cout << "Invalid Key! Key " << inputKey << " not found in table!" << std::endl;
						std::cout << std::endl;
					}
					else
					{
						// Print key and value
						std::cout << "Key: " << inputKey << "\tValue: " << searchOutput << std::endl;
						std::cout << std::endl;
					}
					
				}
				else if(tableChoice == 2) // Remove key
				{
					std::cout << std::endl;
					
					// Ask for key to remove
					std::cout << "Remove (Please enter a key): ";
					std::cin >> inputKey;
					
					// Remove the key
					quadHash->remove(inputKey);
				}
				else if(tableChoice == 3) // Print
				{
					quadHash->print();
				}
				else if(tableChoice == 4) // Return to main menu
				{
					// Leaves the loop. This is required so it doesn't think 4 is an else case, keeping you in the loop.
				}
				else
				{
					std::cout << std::endl;
					// Error message
					std::cout << "Please enter a number corresponding to the given options!" << std::endl;
					std::cout << std::endl;
				}
			}
			
			// Delete quadratic probing table
			delete quadHash;
		}
		else if(probeChoice == 3) // Separate Chaining
		{
			// Reset hash size
			hashSize = 0;
			
			std::cout << "Separate Chaining" << std::endl;
			
			// Ask user for hash size. Loop prevents entering 0
			while(hashSize == 0)
			{
				std::cout << std::endl << "Please enter the size of the Hash Table you wish to create: ";
				std::cin >> hashSize;
				
				if(hashSize == 0)
				{
					std::cout << std::endl;
					std::cout << "Do not enter ZERO." << std::endl;
				}
			}
			
			// Create Hash table chaining
			HashTableChaining * chainHash = new HashTableChaining(hashSize);
			
			// File work
			std::ifstream inputFile;
			inputFile.open("data.txt");
			
			// If the file is open
			if(inputFile.is_open())
			{
				// While its not the end of the file
				while(!inputFile.eof())
				{
					// Read in the data from the file
					inputFile >> key >> value;
					
					// Insert values
					chainHash->insert(key, value);
					
				}
			}
			else
			{
				std::cout << "Cannot open file." << std::endl;
			}
			
			// Close file
			inputFile.close();
			inputFile.clear();
			
			// Print the table
			chainHash->print();
			
			// While the user doesn't return to main menu
			while(tableChoice != 4)
			{
				// Display options
				std::cout << "1) Search For Entry" << std::endl;
				std::cout << "2) Remove Entry" << std::endl;
				std::cout << "3) Print Hash Table" << std::endl;
				std::cout << "4) Return to Main Menu" << std::endl;
				
				std::cout << std::endl;
			
				// Ask for table choice
				std::cout << "Please enter your choice: ";
				std::cin >> tableChoice;
				
				std::cout << std::endl;
				
				// Search
				if(tableChoice == 1)
				{
					inputKey = 0;
					searchOutput = 0;
					
					// Ask for key
					std::cout << "Search (Please enter a key): ";
					std::cin >> inputKey;
					
					std::cout << std::endl;
					
					searchOutput = chainHash->search(inputKey);
					
					// If output is -1, it is not found
					if(searchOutput == -1)
					{
						// Display message
						std::cout << "Invalid Key! Key " << inputKey << " not found in table!" << std::endl;
						std::cout << std::endl;
					}
					else
					{
						// Key is found. Message shows key and value
						std::cout << "Key: " << inputKey << "\tValue: " << searchOutput << std::endl;
						std::cout << std::endl;
					}
				}
				else if(tableChoice == 2) // Remove key
				{
					// Ask for key to remove
					std::cout << "Remove (Please enter a key): ";
					std::cin >> inputKey;
					
					std::cout << std::endl;
					
					// Remove key from table
					chainHash->remove(inputKey);
					
					std::cout << std::endl;
				}
				else if(tableChoice == 3) // Print table
				{
					chainHash->print();
				}
				else if(tableChoice == 4) // Return to main menu
				{
					// Leaves the loop. This is required so it doesn't think 4 is an else case, keeping you in the loop.
				}
				else
				{
					std::cout << std::endl;
					// Message if user enters something else
					std::cout << "Please enter a number corresponding to the given options!" << std::endl;
					std::cout << std::endl;
				}
			}
			
			// Delete table
			delete chainHash;
		}
		else if(probeChoice == 4) // Cuckoo Hashing
		{
			// Reset hash size to 0
			hashSize = 0;
			
			std::cout << "Cuckoo Hashing" << std::endl;
			
			// Ask user for hash size. Loop prevents entering 0
			while(hashSize == 0)
			{
				std::cout << std::endl << "Please enter the size of the Hash Table you wish to create: ";
				std::cin >> hashSize;
				
				if(hashSize == 0)
				{
					std::cout << std::endl;
					std::cout << "Do not enter ZERO." << std::endl;
				}
			}
			
			// Create new cuckoo hashing table
			HashTableCuckoo * cuckooHash = new HashTableCuckoo(hashSize);
			
			// File work
			std::ifstream inputFile;
			inputFile.open("data.txt");
			
			// If the file is open
			if(inputFile.is_open())
			{
				// While its not the end of the file
				while(!inputFile.eof())
				{
					// Read in the data from the file
					inputFile >> key >> value;
					
					// Increase number of values
					numValues++;
					
					// If the number of values hits 50%, it is an insufficient table size. (Cuckoo Hash rule)
					// It could be just >, but that would include 50%, allowing for more cycles. 
					//So for the project, I'm allowing it to get up to 50% capacity, not including 50%.
					if(numValues >= (hashSize))
					{
						cuckooHash->setCycle(false);
						
						// It is an insufficient table size
						std::cout << std::endl;
						std::cout << "<<<--- Insufficient Hash Table Size! Re-hash! --->>>" << std::endl;
						std::cout << std::endl;
						
						// Leave loop, table can't be made
						break;
					}
					
					// Insert the key and value
					cuckooHash->insert(key, value);
					
					// If there is a cycle
					if(cuckooHash->getCycle())
					{
						// Leave the loop
						break;
					}
				}
			}
			else
			{
				std::cout << "Cannot open file." << std::endl;
			}
			
		
			// Close file
			inputFile.close();
			inputFile.clear();
			
			// If there is not a cycle, and the size is valid
			// For the condition numValues < hashSize, this accounts for the number of values being below 50% not including 50%. 
			// However, it can be <=, but this will allow for full 50% capacity, which has a better chance of having a cycle.
			// For the project I'm not including 50%
			if(!cuckooHash->getCycle() && numValues < (hashSize))
			{
				// Print
				cuckooHash->print();
			}
			else // If it is invalid
			{
				// Table is deleted
				delete cuckooHash;
				
				// Number of values is reset
				numValues = 0;
				
				// Returns to the main menu
				continue;
			}
			
			// Reset numValues 
			numValues = 0;
			
			// If the table choice isn't 4
			while(tableChoice != 4)
			{
				// Display options
				std::cout << "1) Search For Entry" << std::endl;
				std::cout << "2) Remove Entry" << std::endl;
				std::cout << "3) Print Hash Table" << std::endl;
				std::cout << "4) Return to Main Menu" << std::endl;
				
				std::cout << std::endl;
			
				// Asks for table choice 
				std::cout << "Please enter your choice: ";
				std::cin >> tableChoice;
				
				std::cout << std::endl;
				
				// Search
				if(tableChoice == 1)
				{
					inputKey = 0;
					searchOutput = 0;
					
					// Ask user for key
					std::cout << "Search (Please enter a key): ";
					std::cin >> inputKey;
					
					std::cout << std::endl;
					
					// Determine search output
					searchOutput = cuckooHash->search(inputKey);
					
					// If it is -1, it is invalid
					if(searchOutput == -1)
					{
						// Print message
						std::cout << "Invalid Key! Key " << inputKey << " not found in table!" << std::endl;
						std::cout << std::endl;
					}
					else
					{
						// Print key and value
						std::cout << "Key: " << inputKey << "\tValue: " << searchOutput << std::endl;
						std::cout << std::endl;
					}
					
				}
				else if(tableChoice == 2) // Remove key
				{
					// Ask for a key to remove
					std::cout << "Remove (Please enter a key): ";
					std::cin >> inputKey;
					
					std::cout << std::endl;
					
					// Remove the key
					cuckooHash->remove(inputKey);
					
					std::cout << std::endl;
				}
				else if(tableChoice == 3) // Print
				{
					cuckooHash->print();
				}
				else if(tableChoice == 4) // Return to main menu
				{
					// Leaves the loop. This is required so it doesn't think 4 is an else case, keeping you in the loop.
				}
				else
				{
					std::cout << std::endl;
					// Error message
					std::cout << "Please enter a number corresponding to the given options!" << std::endl;
					std::cout << std::endl;
				}
			}
			
			// Delete cuckoo hash table
			delete cuckooHash;
		}
		else if(probeChoice == 5) // Exits the program
		{
			std::cout << "Thank you for using Blue IV's program - Goodbye!" << std::endl;
		}
		else
		{
			// User must enter given options
			std::cout << "Please enter a number corresponding to the given options!" << std::endl;
		}
		
		std::cout << std::endl;
	}// End of Loop
	
	return 0;
}