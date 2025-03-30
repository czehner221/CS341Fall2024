// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// czehner

#include "RedBlackTree.h"

// Defauly constructor
RedBlackTree::RedBlackTree() : BinarySearchTree()
{
	
}

// Destructor
RedBlackTree::~RedBlackTree()
{
	
}

// Inserts data
void RedBlackTree::insert(int data)
{
	// New node with the passed data integer
	TreeNode * newNode = new TreeNode(data);
	
	// New nodes are red
	newNode->setColor(RED);
	
	// Insert the new node and set the root
	BinarySearchTree::setRoot(BinarySearchTree::insertNode(BinarySearchTree::getRoot(), newNode));
	
	// Make root node set equal to BST root
	TreeNode * rootNode = BinarySearchTree::getRoot();
	
	// Balance the color
	balanceColor(rootNode, newNode);
}

// Rotates tree left
void RedBlackTree::rotateLeft(TreeNode *& root, TreeNode *& newNode)
{
	// New tree node representing right child. Set to the passed newNode's right child.
	TreeNode * rightChild = newNode->getRightChild();
	
	// New node's right child is set to the right child's left child
	newNode->setRightChild(rightChild->getLeftChild());
	
	// If the new node's right child is not a nullptr
	if(newNode->getRightChild() != nullptr)
	{
		// The rightChild's parent becomes the newNode
		newNode->getRightChild()->setParent(newNode);
	}
	
	// The rightChild's parent is set to the newNode's parent
	rightChild->setParent(newNode->getParent());
	
	// If the newNode's parent is a nullptr
	if(newNode->getParent() == nullptr)
	{
		// The root becomes the right child
		root = rightChild;
		
		// Set the root to the right child
		BinarySearchTree::setRoot(rightChild);
	}
	else if(newNode == newNode->getParent()->getLeftChild()) // If the new node equals its parents left node
	{
		// Set the left child to the rightChild
		newNode->getParent()->setLeftChild(rightChild);
	}
	else
	{
		// Parent's right child is set to right child
		newNode->getParent()->setRightChild(rightChild);
	}
	
	// Right child's left child becomes newNode
	rightChild->setLeftChild(newNode);
	
	// New node's parent becomes the rightChild
	newNode->setParent(rightChild);
}

// Rotates tree right
void RedBlackTree::rotateRight(TreeNode *& root, TreeNode *& newNode)
{
	// New TreeNode representing leftChild set to the newNode's left child
	TreeNode * leftChild = newNode->getLeftChild();
	
	// New nodes left child is set to the left child's right child
	newNode->setLeftChild(leftChild->getRightChild());
	
	// If the new node's left child is not a nullptr
	if(newNode->getLeftChild() != nullptr)
	{
		// The leftChild's parent beccomes the newNode
		newNode->getLeftChild()->setParent(newNode);
	}
	
	// The leftChild's parent is set to the newNode's parent
	leftChild->setParent(newNode->getParent());
	
	// If the newNode's parent is a nullptr
	if(newNode->getParent() == nullptr)
	{
		// Root becomes leftChild
		root = leftChild;
		
		// Sets root to left child
		BinarySearchTree::setRoot(leftChild);	// IF DOESNT WORK MOVE ABOVE 
	}
	else if(newNode == newNode->getParent()->getLeftChild()) // If the new node equals its parents right node
	{
		// Set parent's left child to left child.
		newNode->getParent()->setLeftChild(leftChild);
	}
	else
	{
		// Parent's right child becomes left child
		newNode->getParent()->setRightChild(leftChild);
	}
	
	// Left Childs right child becomes new node
	leftChild->setRightChild(newNode);
	
	// New node's parent becomes the left child
	newNode->setParent(leftChild);
}

// Balance the colors of the tree
void RedBlackTree::balanceColor(TreeNode *& root, TreeNode *& newNode)
{
	// New parent and grandparent nodes
	TreeNode * parent = nullptr;
	TreeNode * grandParent = nullptr;
	
	// Loops while the new node is not the root, the new node's color isn't black, and the newnode's parent's color is red
	while(newNode != root && newNode->getColor() != BLACK && newNode->getParent()->getColor() == RED)
	{
		// Set parent to newnode's parent
		parent = newNode->getParent();
		
		// Set grandparent to the newnode's parent's parent
		grandParent = newNode->getParent()->getParent();
		
		// If the parent is the Grandparent's left child
		if(parent == grandParent->getLeftChild())
		{
			// New aunt node that is the right child of the grandparent
			TreeNode * aunt = grandParent->getRightChild();
			
			// If the aunt is not nullptr and it's color is red
			if(aunt != nullptr && aunt->getColor() == RED)
			{
				// Recolor
				// Grandparent becomes red
				grandParent->setColor(RED);
				
				// Parent becomes black
				parent->setColor(BLACK);
				
				// Aunt becomes black
				aunt->setColor(BLACK);
				
				// The newnode becomes the grandparent
				newNode = grandParent;
			}
			else
			{
				// If the node is a right child
				if(newNode == parent->getRightChild())
				{
					// Do a left rotation
					rotateLeft(root, parent);
					
					// New node becomes the parent
					newNode = parent;
					
					// Parent becomes teh newNodes parent
					parent = newNode->getParent();
				}
				else // Node is left child
				{
					// Do a right rotation
					rotateRight(root, grandParent);
					
					// New temporary color set to the parents color
					Color tempColor = parent->getColor();
					
					// Parents color is set to the grandparent's color
					parent->setColor(grandParent->getColor());
					
					// Grandparents color becomes the temporary color, the parent's color from earlier
					grandParent->setColor(tempColor);
					
					// Newnode becomes the parent
					newNode = parent;
				}
			}
		}
		else // Parent is grandparent's right child
		{
			// New aunt node set to the grandparents left child
			TreeNode * aunt = grandParent->getLeftChild();
			
			// If the aunt is not nullptr and the color is red
			if(aunt != nullptr && aunt->getColor() == RED)
			{
				// Grandparent becomes red
				grandParent->setColor(RED);
				
				// Parent becomes black
				parent->setColor(BLACK);
				
				// Aunts color becomes black
				aunt->setColor(BLACK);
				
				// New node becomes the grandparent
				newNode = grandParent;
			}
			else
			{
				// If the new node is the parent's left child
				if(newNode == parent->getLeftChild())
				{
					// Do a right rotation
					rotateRight(root, parent);
					
					// New node becomes parent
					newNode = parent;
					
					// Parent becomes the newnode's parent
					parent = newNode->getParent();
				}
				else // parent's right child
				{
					// Do a left rotation
					rotateLeft(root, grandParent);
					
					// Temporary color set to the parent's current color
					Color tempColor = parent->getColor();
					
					// Parent color is set to the grandparent's color
					parent->setColor(grandParent->getColor());
					
					// Set the grandparent's color to the temp color
					grandParent->setColor(tempColor);
					
					// New node becomes the parent
					newNode = parent;
				}
			}
		}
	}
	
	// Set the root to Black
	root->setColor(BLACK);
}

// Print the red nodes
void RedBlackTree::printRedNodes(TreeNode * root)
{
	// If the root is not nullptr
	if(root != nullptr)
	{
		// Inorder Traversal logic
		
		// Left Node
		printRedNodes(root->getLeftChild());
		
		// Root
		if(root->getColor() == RED)
		{
			std::cout << root->getData() << " ";
		}
		
		// Right Node
		printRedNodes(root->getRightChild());
	}
}

// Print the black nodes
void RedBlackTree::printBlackNodes(TreeNode * root)
{
	// If the root is not nullptr
	if(root != nullptr)
	{
		// Preorder Traversal logic
		
		// Root
		if(root->getColor() == BLACK)
		{
			std::cout << root->getData() << " ";
		}
		
		// Left Node
		printBlackNodes(root->getLeftChild());
		
		// Right Node
		printBlackNodes(root->getRightChild());
	}
}