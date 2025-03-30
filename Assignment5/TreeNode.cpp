// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// czehner

#include "TreeNode.h"

// Linked Node default constructor
TreeNode::TreeNode(int data) : Node(data), leftChild_(nullptr), rightChild_(nullptr), parent_(nullptr), color_(NONE)
{
	
}

// Linked Node Copy Constructor
TreeNode::TreeNode(const TreeNode & treeNode) : Node(treeNode.getData()), leftChild_(nullptr), rightChild_(nullptr), parent_(nullptr), color_(NONE)
{
	
	color_ = treeNode.color_;
	// If the left child is not nullptr
	if(treeNode.leftChild_ != nullptr)
	{
		// Left children are copied recursively
		leftChild_ = new TreeNode(*treeNode.leftChild_);
		leftChild_->setParent(this);
	}
	
	// If the right child is not nullptr
	if(treeNode.rightChild_ != nullptr)
	{
		// right children are copied recursively
		rightChild_ = new TreeNode(*treeNode.rightChild_);
		rightChild_->setParent(this);
	}
	
}

// Linked Node destructor
TreeNode::~TreeNode()
{
	// Delete left Child
	if(leftChild_ != nullptr)
	{
		delete leftChild_;
	}
	
	// Delete the right child
	if(rightChild_ != nullptr)
	{
		delete rightChild_;
	}
}

// Gets the parent
TreeNode * TreeNode::getParent()
{
	return parent_;
}

// Gets the left child
TreeNode * TreeNode::getLeftChild()
{
	return leftChild_;
}

// Gets the right child
TreeNode * TreeNode::getRightChild()
{
	return rightChild_;
}

// Sets the parent
void TreeNode::setParent(TreeNode * parent)
{
	parent_ = parent;
}

// Sets the left child
void TreeNode::setLeftChild(TreeNode * leftChild)
{
	leftChild_ = leftChild;
}

// Sets teh right child
void TreeNode::setRightChild(TreeNode * rightChild)
{
	rightChild_ = rightChild;
}

// Gets the color
Color TreeNode::getColor()
{
	return color_;
}

// Sets the color
void TreeNode::setColor(Color color)
{
	color_ = color;
}
