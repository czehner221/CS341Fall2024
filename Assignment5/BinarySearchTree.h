// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// czehner

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "TreeNode.h"

class BinarySearchTree
{
	public:
		// Binary Search tree Default Constructor
		BinarySearchTree();
		
		// BST Copy Constructor
		BinarySearchTree(const BinarySearchTree & tree);
		
		// BST Destructor
		virtual ~BinarySearchTree();
		
		// Insert value into BST
		void insert(int num);
		
		// Gets the root of the BST
		TreeNode * getRoot();
		
		// Sets the root of the BST
		void setRoot(TreeNode * root);
		
		// Prints the BST
		void print(TreeNode * root);
		
		// Insert helper function
		TreeNode * insertNode(TreeNode * root, TreeNode * node);
	
	private:
		TreeNode * root_;	// Root of the tree
};

#endif