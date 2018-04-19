//Tellon Smith
//CMPS 3013 - Program 4
//AVLTree.h
//This file declares an AVL tree to store numbers (integers)

#pragma once

#include <iostream>

using namespace std;

struct AVLNode
{
	int value;
	int height;
	int depth;
	int balanceFactor;
	AVLNode *leftNode;
	AVLNode *rightNode;

	//default constructor
	AVLNode()
	{
		value = NULL;
		height = 0;
		depth = 0;
		balanceFactor = 0;
		leftNode = NULL;
		rightNode = NULL;
	}

	//parameterized constructor
	AVLNode(int newValue)
	{
		value = newValue;
		height = 0;
		depth = 0;
		balanceFactor = 0;
		leftNode = NULL;
		rightNode = NULL;
	}
};


class AVLTree
{
public:
	//default constructor
	AVLTree();

	//parameterized constructor
	AVLTree(int newValue);

	//destructor
	~AVLTree();

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

	//Purpose: calculates the depth each node
	//Requires: none
	//Returns: tree with calculated depths
	void calculateDepth();

private:
	//Purpose: recursively inserts values into the tree
	//Requires: root, value to insert
	//Returns: root with new value inserted into the tree
	void insertNode(AVLNode *& ptr, int newValue);
	
	//Purpose: recursively calculate the depth of each node
	//Requires: root
	//Returns: each node with its calculated depth
	void calculateNodeDepth(AVLNode *& ptr);
	
	//Purpose: recursively calculate the height of each node
	//Requires: root
	//Returns: each node with its calculated height
	void calculateNodeHeight(AVLNode *& ptr);

	//Purpose: recursively calculates the balance factor fo each node
	//Requires: root
	//Returns: each node with its calculated balance factor
	void calculateBalanceFactor(AVLNode *& ptr);

	//Purpose: performs a left rotation on a subtree
	//Requires: ptr (subtree)
	//Returns: tree with nodes rotated
	void rotateLeft(AVLNode *& ptr);

	//Purpose: performs a right rotation on a subtree
	//Requires: ptr (subtree)
	//Returns: tree with nodes rotated 
	void rotateRight(AVLNode *& ptr);

	//Purpose: recursively rebalances the tree if not balanced
	//Requires: root
	//Returns: balanced tree 
	void rebalanceTree(AVLNode *& ptr);

	//Purpose: recursively adds the depth of all nodes
	//Requires: root
	//Returns: sum of the depth of all nodes
	int sumNodeDepth(AVLNode *& ptr);

	//Purpose: recursively adds the height of all nodes
	//Requires: root
	//Returns: sum of the height of all nodes 
	int sumNodeHeight(AVLNode *& ptr);
	
	//Purpose: recursively deletes all nodes in the tree
	//Requires: root node
	//Returns: empty tree 
	void destroySubtree(AVLNode *& ptr);	

	AVLNode *root;
	int numberOfNodes;
};
