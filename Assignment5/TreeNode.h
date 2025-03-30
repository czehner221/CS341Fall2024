// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// czehner

#ifndef TREENODE_H
#define TREENODE_H

#include "Node.h"

// Enum to keep track of the color of the RBT Nodes
enum Color
{
	// NONE - 0, RED - 1, BLACK - 2
	NONE, RED, BLACK
};

class TreeNode : public Node
{

	public:
		// TreeNode default constructor
		TreeNode(int data); // int data = -1;
		
		// TreeNode copy constructor
		TreeNode(const TreeNode & treeNode);
		
		// TreeNode destructor
		virtual ~TreeNode();
		
		// Gets the left child of the node
		TreeNode * getLeftChild();
		
		// Gets the right child of the node
		TreeNode * getRightChild();
		
		// Gets the parent of the node
		TreeNode * getParent();
		
		// Sets the left child of the node
		void setLeftChild(TreeNode * child);
		
		// Sets the right child of the node
		void setRightChild(TreeNode * child);
		
		// Sets the parent of the node
		void setParent(TreeNode * parent);
		
		// Gets the color of the node
		Color getColor();
		
		// Sets the color of the node
		void setColor(Color color);
	
	private:
		TreeNode * leftChild_;		// Left child treenode
		TreeNode * rightChild_;		// Right Child treenode
		TreeNode * parent_;			// Parent node
		Color color_;				// Color of the node
};

#endif