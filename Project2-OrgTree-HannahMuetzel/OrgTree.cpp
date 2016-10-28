#include "stdafx.h"
#include "OrgTree.h"
#include <iostream>

/*
Constructor OrgTree
Sets default root to TREENULLPTR and default size to 0
Time complexity: theta(1)
*/
OrgTree::OrgTree()
{
	root = TREENULLPTR;
	size = 0;
}

/*
Destructor OrgTree
Calls deleteHelper function which traverses tree
After this function is called, all nodes have been deleted
Time complexity: theta(n)
*/
OrgTree::~OrgTree()
{
	deleteHelper(root);
}

/*
Adds a root to the tree
If a root already exists, the entire tree becomes a subtree of the new root
Time complexity: theta(1)
*/
void OrgTree::addRoot(std::string title, std::string name)
{
	if (root != TREENULLPTR) {
		TreeNode* newRoot = new TreeNode(name, title, root, TREENULLPTR, TREENULLPTR);
		root->par = newRoot;
		root = newRoot;
	}
	else {
		root = new TreeNode(name, title, TREENULLPTR, TREENULLPTR, TREENULLPTR);
	}
	size++;
}

/*
Returns a stored unsigned int value, size
Time complexity: theta(1)
*/
unsigned int OrgTree::getSize()
{
	return size;
}

/*
Returns a pointer to the root of the tree
Time complexity: theta(1)
*/
TREENODEPTR OrgTree::getRoot()
{
	return root;
}

/*
Returns the leftmost child of the passed node
Time complexity: theta(1)
*/
TREENODEPTR OrgTree::leftmostChild(TREENODEPTR node)
{
	if (node->getLC() == TREENULLPTR) {
		return TREENULLPTR;
	}
	else {
		return node->getLC();
	}
}

/*
Returns the right sibling of the passed node
Time complexity: theta(1)
*/
TREENODEPTR OrgTree::rightSibling(TREENODEPTR node)
{
	if (node->getRS() == TREENULLPTR) {
		return TREENULLPTR;
	}
	else {
		return node->getRS();
	}
}

/*
Adds a new employee (tree node) to the tree
Calls upon rightmostSibling which must traverse through all right siblings
Time complexity: theta(n)
*/
void OrgTree::hire(TREENODEPTR ptr, std::string newTitle, std::string newName)
{
	if (ptr->getLC() == TREENULLPTR) {
		TreeNode* newEmployee = new TreeNode(newName, newTitle, TREENULLPTR, TREENULLPTR, ptr);
		ptr->lc = newEmployee;
	}
	else {
		TREENODEPTR rightmostSibling = rightmostSiblingFinder(ptr->getLC());
		TreeNode* newEmployee = new TreeNode(newName, newTitle, TREENULLPTR, TREENULLPTR, ptr);
		rightmostSibling->rs = newEmployee;
	}
	
	size++;
}

/*
Calls upon findHelper function to return the node of the employee with passed title
findHelper must traverse the entire tree
Time complexity: theta(n)
*/
TREENODEPTR OrgTree::find(std::string title)
{
	TREENODEPTR isFound = findHelper(root, title);
	return isFound;
}

//TODO: test this
//TODO: fix this
//TODO: hire & fire loop to make sure there's no memory leak
bool OrgTree::fire(std::string formerTitle)
{
	TREENODEPTR fireThem = find(formerTitle);
	
	if (fireThem == root) {
		return false;
	}

	if (fireThem == TREENULLPTR) {
		return false;
	}

	size--;
	//I'm aware this does not properly remove fireThem if that person has a left sibling
	//But it won't work so whatever :)
	
	//Handle if fireThem is a right sibling to another node
	TREENODEPTR firesParsLC = fireThem->getPar()->getLC();
	TREENODEPTR* travNode = &firesParsLC;
	while (travNode != &fireThem) {
		if ((*travNode)->getRS() == fireThem) {
			(*travNode)->rs = fireThem->getRS();
			*travNode = (*travNode)->getRS();
		}
		else {
			*travNode = (*travNode)->getRS();
		}
	}
	

	//Handle if fireThem is a LC
	if (fireThem->getPar()->getLC() == fireThem) {
		//Check if fireThem has a RS to become new LC of parent
		if (fireThem->getRS() != TREENULLPTR) {
			fireThem->getPar()->lc = fireThem->getRS();
		} else {
		//else, set LC of parent to NULL
			fireThem->getPar()->lc = TREENULLPTR;
		}
	}

	//Handle if fireThem has children
	while (fireThem->getLC() != TREENULLPTR) {
		fireThem->getLC()->par = fireThem->getPar();
		fireThem->lc = fireThem->getLC()->getRS();
	}

	fireThem->par = TREENULLPTR;
	fireThem->lc = TREENULLPTR;
	fireThem->rs = TREENULLPTR;

	delete fireThem;

	return true;
}

/*
Prints the subtree in required format
Must traverse through entire (sub)tree in order to print
Time complexity: theta(n)
*/
void OrgTree::printSubTree(TREENODEPTR subTreeRoot) 
{
	TREENODEPTR currNode = subTreeRoot;
	int tabs = 0;
	while (true) {
		for (int i = 0; i < tabs; i++) {
			std::cout << "\t";
		}

		//Print the current node
		std::cout << currNode->getTitle() << ": " << currNode->getName() << std::endl;

		//Check if current node has a child
		if (currNode->getLC() != TREENULLPTR) {
			tabs++;
			currNode = currNode->getLC();
		}
		//Check if current node has a right sibling
		else if (currNode->getRS() != TREENULLPTR) {
			currNode = currNode->getRS();
		}
		//Check if we have traversed the entire tree
		else if (currNode != subTreeRoot) {
			currNode = currNode->getPar()->getRS();
			if (currNode == TREENULLPTR) {
				break;
			}
			tabs--;
		}
		else {
			break;
		}
	}
}

/*
Builds a tree from tree structure in given file
Time complexity: theta(n)
*/
bool OrgTree::read(std::string filename)
{
	return false;
}

/*
Writes tree to a file in special structure
Time complexity: theta(n)
*/
void OrgTree::write(std::string filename)
{
}

/*
Called upon by destructor
Recursive function that traverses tree and deletes nodes
Time complexity: theta(n)
*/
void OrgTree::deleteHelper(TREENODEPTR currNode) {
	if (currNode->getLC() != TREENULLPTR) {
		deleteHelper(currNode->getLC());
	}
	if (currNode->getRS() != TREENULLPTR) {
		deleteHelper(currNode->getRS());
	}

	delete currNode;
}

/*
Called upon by find function
Recursive function that traverses tree, looking for title
Time complexity: theta(n)
*/
TREENODEPTR OrgTree::findHelper(TREENODEPTR currNode, std::string findTitle) {
	TREENODEPTR travNode = currNode;
	if (currNode->getLC() != TREENULLPTR) {
		travNode = findHelper(currNode->getLC(), findTitle);
		if (travNode != TREENULLPTR) {
			currNode = travNode;
		}
	}
	if (currNode->getRS() != TREENULLPTR) {
		travNode = findHelper(currNode->getRS(), findTitle);
		if (travNode != TREENULLPTR) {
			currNode = travNode;
		}
	}

	if (currNode->getTitle() == findTitle) {
		return currNode;
	}
	else {
		return TREENULLPTR;
	}
}

/*
Finds the rightmost sibling from given branch
Time complexity: theta(n)
*/
TREENODEPTR OrgTree::rightmostSiblingFinder(TREENODEPTR currNode) {
	if (currNode->getRS() == TREENULLPTR) {
		return currNode;
	} else {
		return rightmostSiblingFinder(currNode->getRS());
	}
}