//Tellon Smith
//CMPS 3013 - Program 3
//AVLTree.cpp
//Implements AVLTree class in AVLTree.h

#include "AVLTree.h"


AVLTree::AVLTree()
{
	root = NULL;
	numberOfNodes = 0;
}

AVLTree::AVLTree(int newValue)
{
	root = new AVLNode(newValue);
	numberOfNodes = 1;
}

AVLTree::~AVLTree()
{
	destroySubtree(root);
	numberOfNodes = 0;
}

void AVLTree::insertValue(int newValue)
{
	insertNode(root, newValue);
	numberOfNodes++;
}

double AVLTree::getSumOfNodeDepth()
{
	return sumNodeDepth(root);
}

double AVLTree::getSumOfNodeHeight()
{
	return sumNodeHeight(root);
}

int AVLTree::getTreeHeight()
{
	return root->height;
}

int AVLTree::getNumberOfNodes()
{
	return numberOfNodes;
}

void AVLTree::calculateDepth()
{
	calculateNodeDepth(root);
}

void AVLTree::insertNode(AVLNode *& ptr, int newValue)
{
	//if ptr is null
	if (ptr == NULL)
	{
		ptr = new AVLNode(newValue); //create new node with value inserted
	}
	//if value to be inserted is less than or equal to to the ptr's value
	else if (newValue <= ptr->value)
	{
		insertNode(ptr->leftNode, newValue); //insert on the left side of subtree
	}
	//if value to be inserted is greater than the ptr's value
	else
	{
		insertNode(ptr->rightNode, newValue); //insert on the right side of subtree
	}
	//recalculate height, balance factor and rebalance tree 
	calculateNodeHeight(root);
	calculateBalanceFactor(root);
	rebalanceTree(root);
}

void AVLTree::calculateNodeDepth(AVLNode *& ptr)
{
	//if ptr is equal to root
	if (ptr == root)
	{
		ptr->depth = 0; //set to zero (top of tree)
	}
	//if left node is not null
	if (ptr->leftNode)
	{
		ptr->leftNode->depth = ptr->depth + 1; //set depth
		calculateNodeDepth(ptr->leftNode); //continue down left side
	}
	//if right node is not null
	if (ptr->rightNode)
	{
		ptr->rightNode->depth = ptr->depth + 1; //set depth
		calculateNodeDepth(ptr->rightNode); //continue down right side
	}
}

void AVLTree::calculateNodeHeight(AVLNode *& ptr)
{
	int left = 0;
	int right = 0;

	//if left node is not null
	if (ptr->leftNode)
	{
		calculateNodeHeight(ptr->leftNode); //continue down left side
		left = (ptr->leftNode->height + 1);
	}
	//if right node is not null
	if (ptr->rightNode)
	{
		calculateNodeHeight(ptr->rightNode); //continue down right side
		right = (ptr->rightNode->height + 1);
	}

	//if left height greater than or equal to right height
	if (left >= right)
	{
		ptr->height = left;
	}
	//if left height less than right height
	else
	{
		ptr->height = right;
	}
}

void AVLTree::calculateBalanceFactor(AVLNode *& ptr)
{
	//if node is a leaf
	if (!ptr->leftNode && !ptr->rightNode)
	{
		ptr->balanceFactor = 0;
	}
	//if right node is null
	else if (ptr->leftNode && !ptr->rightNode)
	{
		calculateBalanceFactor(ptr->leftNode); //continue down left side
		ptr->balanceFactor = (ptr->leftNode->height + 1); //set balance factor
	}
	//if left node is null
	else if (!ptr->leftNode && ptr->rightNode)
	{
		calculateBalanceFactor(ptr->rightNode); //continue down right side
		ptr->balanceFactor = (0 - (ptr->rightNode->height + 1)); //set balance factor
	}
	//if both left and right nodes are not null (has two children)
	else
	{
		calculateBalanceFactor(ptr->leftNode); //continue down left side
		calculateBalanceFactor(ptr->rightNode); //continue down right side
		ptr->balanceFactor = (ptr->leftNode->height - ptr->rightNode->height); //set balance factor
	}
}

void AVLTree::rotateLeft(AVLNode *& ptr)
{
	//if right node is left heavy
	if (ptr->rightNode->balanceFactor > 0)
	{
		rotateRight(ptr->rightNode);
	}

	//peform rotation
	AVLNode *temp;
	temp = ptr->rightNode;
	ptr->rightNode = temp->leftNode;
	temp->leftNode = ptr;
	ptr = temp;

	//delete temp node
	temp = NULL;
	delete temp;

	//recalculate height and balance factor
	calculateNodeHeight(root);
	calculateBalanceFactor(root);
}

void AVLTree::rotateRight(AVLNode *& ptr)
{
	//if left node is right heavy
	if (ptr->leftNode->balanceFactor < 0)
	{
		rotateLeft(ptr->leftNode);
	}

	//perform rotation
	AVLNode *temp;
	temp = ptr->leftNode;
	ptr->leftNode = temp->rightNode;
	temp->rightNode = ptr;
	ptr = temp;

	//delete temp node
	temp = NULL;
	delete temp;

	//recalculate height and balance factor
	calculateNodeHeight(root);
	calculateBalanceFactor(root);
}

void AVLTree::rebalanceTree(AVLNode *& ptr)
{
	//if left node is not null
	if (ptr->leftNode)
	{
		rebalanceTree(ptr->leftNode); //continue down left side
	}

	//if right node is not null
	if (ptr->rightNode)
	{
		rebalanceTree(ptr->rightNode); //continue down right side
	}

	//rotate right if out of balance with positive value 
	if (ptr->balanceFactor > 1)
	{
		rotateRight(ptr);
	}
	//rotate left if out of balance with negative value
	else if (ptr->balanceFactor < -1)
	{
		rotateLeft(ptr);
	}
}

int AVLTree::sumNodeDepth(AVLNode *& ptr)
{
	int sum = 0;

	//if prt is null
	if (!ptr)
	{
		return 0;
	}
	else
	{
		sum += sumNodeDepth(ptr->leftNode); //continue down left side
		sum += sumNodeDepth(ptr->rightNode); //continue down right side
		sum += ptr->depth; //add to sum
		return sum;
	}
}

int AVLTree::sumNodeHeight(AVLNode *& ptr)
{
	int sum = 0;

	//if prt is null
	if (!ptr)
	{
		return 0;
	}
	else
	{
		sum += sumNodeHeight(ptr->leftNode); //continue down left side
		sum += sumNodeHeight(ptr->rightNode); //continue down right side
		sum += ptr->height; //add to sum
		return sum;
	}
}

void AVLTree::destroySubtree(AVLNode *& ptr)
{
	//if node is not empty
	if (ptr)
	{
		destroySubtree(ptr->leftNode); //left substree
		destroySubtree(ptr->rightNode); //right substree
		delete ptr;
		ptr = NULL;
	}
}