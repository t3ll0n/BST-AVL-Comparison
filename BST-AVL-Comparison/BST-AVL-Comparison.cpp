//-----------------------------------------------------------------------------------------------------
//
// Name: Tellon Smith
//
// Course: CS 3013 - Advanced Structures and Algorithms, Spring 16, Dr. Johnson
//
// Program Assignment : #4
//
// Due Date: Thursday, Apr. 14, 2016, 2PM
//
// Purpose: This program inserts 2000 randomly generated intergers into a BST and an AVL tree and then 
//          calculates the node height, the average node height and depth.
//
//-----------------------------------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <string>
#include "time.h"
#include "BST.h"
#include "AVLTree.h"

using namespace std;

const int MAXINT = 2000;

//Purpose: opens an output stream
//Requires: outfile
//Returns: an opened output stream
void openOutputFile(ofstream & outfile);

//Purpose: prints headings
//Requires: opened output stream
//Returns: outfile with headings appended to it
void printHeading(ofstream & outfile);

//Purpose: prints a welcome message
//Requires: opened output stream
//Returns: outfile with welcome message appended to it
void printWelcomeMessage(ofstream & outfile);

//Purpose: prints an exit message
//Requires: opened output stream
//Returns: outfile with exit message appended to it
void printExitMessage(ofstream & outfile);

//Purpose: inserts MAXINT random numbers into two binary search trees
//Requires: BST, AVL tree
//Returns: BST, AVL tree with MAXINT random numbers interted
void insertRandomNumbers(BST & bst, AVLTree & avltree);

//Purpose: calculates the average node depth of a binary search tree
//Requires: binary search tree with "getSumOfNodeDepth()" and "getNumberOfNodes()" functions 
//Returns: double, average node depth
template <class ItemType>
double calulateAverageNodeDepth(ItemType & tree);

//Purpose: calculates the average node height of a binary search tree
//Requires: binary search tree with "getSumOfNodeHeight()" and "getNumberOfNodes()" functions 
//Returns: double, average node height
template <class ItemType>
double calulateAverageNodeHeight(ItemType & tree);

//Purpose: prints a comparison of the height, average node depth and height 
//Requires: BST, AVL tree, opened output stream
//Returns: outfile with results appended to it
void printResults(BST & bst, AVLTree & avltree, ofstream & outfile);

void main()
{
	//variable declarations
	ofstream outfile;
	BST bst;
	AVLTree avltree;

	//begin process
	openOutputFile(outfile);
	printHeading(outfile);
	printWelcomeMessage(outfile);
	insertRandomNumbers(bst, avltree);
	printResults(bst, avltree, outfile);
	printExitMessage(outfile);

	//close file
	outfile.close();

	system("pause");
}

void openOutputFile(ofstream & outfile)
{
	char outFileName[40];

	//open output stream
	cout << "Enter the output file name: ";
	cin >> outFileName;
	outfile.open(outFileName);
}

void printHeading(ofstream & outfile)
{
	outfile << "\nName: Tellon Smith" << endl;
	outfile << "Course: CS 3013 - Advanced Structures and Algorithms, Spring 16, Dr. Johnson" << endl;
	outfile << "Program Assignment: #4" << endl;
	outfile << "Due Date: Thursday, Apr. 14, 2016, 2PM" << endl;
	outfile << "Purpose: This program inserts 2000 randomly generated intergers into a BST" << endl;
	outfile << "and an AVL tree and then calculates the node height, the average node height" << endl;
	outfile << "and depth." << endl;
}

void printWelcomeMessage(ofstream & outfile)
{
	outfile << "\nWelcome to the Binary Search Tree Comparison Program!" << endl;
	outfile << "\n----------------------------------------------------------------------" << endl;
	outfile << "                 Binary Search Tree Comparison Program" << endl;
	outfile << "----------------------------------------------------------------------" << endl;
}

void printExitMessage(ofstream & outfile)
{
	outfile << "\nThank you for using the Binary Search Tree Comparison Program... Goodbye!" << endl;
}

void insertRandomNumbers(BST & bst, AVLTree & avltree)
{
	int num;

	for (int i = 0; i < MAXINT; i++)
	{
		srand(time(NULL)); //seed with time
		num = rand();
		//insert values into trees
		bst.insertValue(num);
		avltree.insertValue(num);
	}
	//recalculate tree values
	//NB: due to the program taking upwards of 10mins to run due to the rapid insertion of 2000
	//    integers and the calculations being performed after each insert (which would be done in
	//    normal circumstances), some of the calculation will only be performed after the 2000 
	//    integers have been inserted which reduces the run time to roughly 5 seconds :)
	bst.calculateDepth();
	bst.calculateHeight();
	avltree.calculateDepth();
}

template <class ItemType>
double calulateAverageNodeDepth(ItemType & tree)
{
	return (tree.getSumOfNodeDepth() / tree.getNumberOfNodes());
}

template <class ItemType>
double calulateAverageNodeHeight(ItemType & tree)
{
	return (tree.getSumOfNodeHeight() / tree.getNumberOfNodes());
}

void printResults(BST & bst, AVLTree & avltree, ofstream & outfile)
{
	outfile << "Height of BST: ";
	outfile << bst.getTreeHeight() << endl;
	outfile << "Height of AVL tree: ";
	outfile << avltree.getTreeHeight() << endl;
	outfile << "Average node depth of BST: ";
	outfile << calulateAverageNodeDepth(bst) << endl;;
	outfile << "Average node depth of AVL tree: ";
	outfile << calulateAverageNodeDepth(avltree) << endl;
	outfile << "Average node height of BST: ";
	outfile << calulateAverageNodeHeight(bst) << endl;
	outfile << "Average node height of AVL tree: ";
	outfile << calulateAverageNodeHeight(avltree) << endl;
}

