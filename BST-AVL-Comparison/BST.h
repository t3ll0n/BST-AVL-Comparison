//Tellon Smith
//CMPS 3013 - Program 4
//BST.h
//This file declares a binary search tree to store numbers (integers)

#pragma once

#include <iostream>

using namespace std;

struct BSTNode
{
	int value;
	int height;
	int depth;
	BSTNode *leftNode;
	BSTNode *rightNode;

	//default constructor
	BSTNode()
	{
		value = NULL;
		height = 0;
		depth = 0;
		leftNode = NULL;
		rightNode = NULL;
	}

	//parameterized constructor
	BSTNode(int newValue)
	{
		value = newValue;
		height = 0;
		depth = 0;
		leftNode = NULL;
		rightNode = NULL;
	}
};

class BST
{
public:
	//default constructor
	BST();

	//parameterized constructor
	BST(int newValue);

	//destructor
	~BST();

	//Purpose: inserts a value into the tree
	//Requires: value to insert (int)
	//Returns: tree with new value inserted
	void insertValue(int newValue);

	//Purpose: returns the sum of all node depths 
	//Requires: none
	//Returns: sum of all node depths
	double getSumOfNodeDepth();

	//Purpose: returns the sum of all node heights 
	//Requires: none
	//Returns: sum of all node heights
	double getSumOfNodeHeight();

	//Purpose: returns the height of the tree
	//Requires: none
	//Returns: height of the tree
	int getTreeHeight();

	//Purpose: returns the number of nodes in the tre
	//Requires: none
	//Returns: number of nodes in the tree
	int getNumberOfNodes();

	//Purpose: calculate the depth of each node
	//Requires: none
	//Returns: tree with calculated depths
	void calculateDepth();

	//Purpose: calculate the height of each node
	//Requires: none
	//Returns: tree with calculated heights
	void calculateHeight();

private:
	//Purpose: recursively inserts values into the tree
	//Requires: root, value to insert
	//Returns: root with new value inserted into the tree
	void insertNode(BSTNode *& ptr, int newValue);

	//Purpose: recursively calculate the depth of each node
	//Requires: root
	//Returns: each node with its calculated depth
	void calculateNodeDepth(BSTNode *& ptr);

	//Purpose: recursively calculate the height of each node
	//Requires: root
	//Returns: each node with its calculated height
	void calculateNodeHeight(BSTNode *& ptr);

	//Purpose: recursively adds the depth of all nodes
	//Requires: root
	//Returns: sum of the depth of all nodes 
	int sumNodeDepth(BSTNode *& ptr);

	//Purpose: recursively adds the height of all nodes
	//Requires: root
	//Returns: sum of the height of all nodes 
	int sumNodeHeight(BSTNode *& ptr);

	//Purpose: recursively deletes all nodes in the tree
	//Requires: root node
	//Returns: empty tree 
	void destroySubtree(BSTNode *& ptr);

	BSTNode *root;
	int numberOfNodes;
};

