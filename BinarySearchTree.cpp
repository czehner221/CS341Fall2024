// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// czehner

#include "BinarySearchTree.h"

// Default constructor
BinarySearchTree::BinarySearchTree() : root_(nullptr)
{
	
}

// Copy Constructor
BinarySearchTree::BinarySearchTree(const BinarySearchTree & tree) : root_(nullptr)
{
	
	// Copying the root recursively
	if(tree.root_ != nullptr)
	{
		root_ = new TreeNode(* tree.root_);
	}
}

// Destructor
BinarySearchTree::~BinarySearchTree()
{
	// If the root is not a nullptr, it is deleted
	if(root_ != nullptr)
	{
		delete root_;
	}
}

// Sets the root of the tree
void BinarySearchTree::setRoot(TreeNode * root)
{
	root_ = root;
}

// Gets the root of the BST
TreeNode * BinarySearchTree::getRoot()
{
	return root_;
}

// Insert value into tree
void BinarySearchTree::insert(int num)
{
	TreeNode * newNode = new TreeNode(num);
	
	root_ = insertNode(root_, newNode);
	
	// Balance and color
}

// Helper to inserting the value into the tree
TreeNode * BinarySearchTree::insertNode(TreeNode * root, TreeNode * node)
{
	// If the root is nullptr, just return the node
	if(root == nullptr)
	{
		return node;
	}
	else 
	{
		// If the node's data is less than the root's data, it'll be in the left subtree
		if(node->getData() < root->getData())
		{
			// Left Subtree
			
			// Sets the left child of the root recursively
			root->setLeftChild(insertNode(root->getLeftChild(), node));
			
			// Set that child's parent to the root
			root->getLeftChild()->setParent(root);
		}
		else if(node->getData() > root->getData()) // Node's data is greater than the root's data, so right subtree
		{
			// Right Subtree
			
			// Sets the right child of the root, recursively
			root->setRightChild(insertNode(root->getRightChild(), node));
			
			// Set that child's parent to the root
			root->getRightChild()->setParent(root);
		}
		else // equal to
		{
			// Not needed for assignment
		}
		
		// Return the root
		return root;
	}
}

// Print the BST
void BinarySearchTree::print(TreeNode * root)
{
	// If the root is nullptr, nothing will be printed
	if(root == nullptr)
	{
		
	}
	else // If it's not nullptr, prints the nodes in Inorder traversal using recursion 
	{
		// Prints left node recursively
		print(root->getLeftChild());
		
		// Prints root's data
		std::cout << root->getData() << " ";
		
		// Prints right node recursively
		print(root->getRightChild());
	}
		
}