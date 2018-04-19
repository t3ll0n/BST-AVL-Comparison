//Tellon Smith
//CMPS 3013 - Program 4
//BST.cpp
//Implements the BST class in BST.h

#include "BST.h"
#include <iostream>

using namespace std;

BST::BST()
{
	root = NULL;
	numberOfNodes = 0;
}

BST::BST(int newValue)
{
	root = new BSTNode(newValue);
	numberOfNodes = 1;
}

BST::~BST()
{
	destroySubtree(root);
	numberOfNodes = 0;
}

void BST::insertValue(int newValue)
{
	insertNode(root, newValue);
	numberOfNodes++;
}

double BST::getSumOfNodeDepth()
{
	return sumNodeDepth(root);
}

double BST::getSumOfNodeHeight()
{
	return sumNodeHeight(root);
}

int BST::getTreeHeight()
{
	return root->height;
}

int BST::getNumberOfNodes()
{
	return numberOfNodes;
}

void BST::calculateDepth()
{
	calculateNodeDepth(root);
}

void BST::calculateHeight()
{
	calculateNodeHeight(root);
}
void BST::insertNode(BSTNode *& ptr, int newValue)
{
	//if ptr is null 
	if (!ptr)
	{
		ptr = new BSTNode(newValue); //create new node with value inserted
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
}

void BST::calculateNodeDepth(BSTNode *& ptr)
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

void BST::calculateNodeHeight(BSTNode *& ptr)
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

int BST::sumNodeDepth(BSTNode *& ptr)
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

int BST::sumNodeHeight(BSTNode *& ptr)
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

void BST::destroySubtree(BSTNode *& ptr)
{
	//if node is not empty
	if (ptr != NULL)
	{
		destroySubtree(ptr->leftNode); //left substree
		destroySubtree(ptr->rightNode); //right substree
		delete ptr;
		ptr = NULL;
	}
}