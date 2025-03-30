// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// czehner

#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H

#include "BinarySearchTree.h"

class RedBlackTree : public BinarySearchTree
{
	public:
		// Default Constructor
		RedBlackTree();
		
		// Red Black Tree Destructor
		virtual ~RedBlackTree();
		
		// Insert into the RBT
		virtual void insert(int data);
		
		// Prints the red nodes
		void printRedNodes(TreeNode * root);
		
		// Prints the black nodes
		void printBlackNodes(TreeNode * root);
		
		
	private:
		// Rotates RBT left
		void rotateLeft(TreeNode *& root, TreeNode *& newNode);
		
		// Rotates RBT right
		void rotateRight(TreeNode *& root, TreeNode *& newNode);
		
		// Balances the RBT
		void balanceColor(TreeNode *& root, TreeNode *& newNode);
};

#endif