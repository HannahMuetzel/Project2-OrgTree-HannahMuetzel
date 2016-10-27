#include "stdafx.h"
#include "OrgTree.h"
#include <iostream>

OrgTree::OrgTree()
{
	root = TREENULLPTR;
	size = 0;
}

OrgTree::~OrgTree()
{
	deleteHelper(root);
}

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

unsigned int OrgTree::getSize()
{
	return size;
}

TREENODEPTR OrgTree::getRoot()
{
	return root;
}

//TODO: test this
TREENODEPTR OrgTree::leftmostChild(TREENODEPTR node)
{
	if (node->getLC() == TREENULLPTR) {
		return TREENULLPTR;
	}
	else {
		return node->getLC();
	}
}

//TODO: test this
TREENODEPTR OrgTree::rightSibling(TREENODEPTR node)
{
	if (node->getRS() == TREENULLPTR) {
		return TREENULLPTR;
	}
	else {
		return node->getLC();
	}
}

//TODO: test this
void OrgTree::hire(TREENODEPTR ptr, std::string newTitle, std::string newName)
{
	if (ptr->getLC() == TREENULLPTR) {
		TreeNode* newEmployee = new TreeNode(newName, newTitle, TREENULLPTR, TREENULLPTR, ptr);
		ptr->lc = newEmployee;
	}
	else {
		TREENODEPTR rightmostSibling = rightmostSiblingFinder(ptr);
		TreeNode* newEmployee = new TreeNode(newName, newTitle, TREENULLPTR, rightmostSibling, ptr);
		rightmostSibling->rs = newEmployee;
	}
	
	size++;
}

//TODO: test this
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

	if (fireThem->getLC() != TREENULLPTR) {
		while ((fireThem->getLC())->getRS() != TREENULLPTR) {
			rightmostSiblingFinder(fireThem->getLC())->par = fireThem->getPar();
		}
		(fireThem->getLC())->par = fireThem->getPar();
		size--;
		return true;
	}

	delete fireThem;

	return false;
	//find(formerTitle)
	//delete that guy by setting his children's parents to his parent
	//change their rs if needed
	//remove him from the tree by deleting his node

	//size --- -!!! !!
}


void OrgTree::printSubTree(TREENODEPTR subTreeRoot)
{
	printHelper(subTreeRoot);
	//make this recursive somehow?
	//if there's a root, print it, then set the lc of root to currRoot
	//err no, print all the rs of that lc first, then set the lc to currRoot
	//print currRoot, rinse and repeat
	//except don't do this because it messes up the order of the children
	//does that even matter?
	//idk lol
	//how do i print a tab omg

	//currNode = root (start here)
	//print currNode
	//call printHelper(currNode->LC) if currNode->LC exists
	//print tab
	//print currNode->LC
	//check if currNode->LC->RS exists
	//if it does, print that with an "and" and blah blah
	//go through all children of currNode
	//if child of currNode has a child, print that child, move down, etc, etc
	//print some dang tabs
	//inorder traversal?? with tab printing?

}

/*
bool OrgTree::read(std::string filename)
{
	return false;
}

void OrgTree::write(std::string filename)
{
}

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

//TODO: test this
TREENODEPTR OrgTree::findHelper(TREENODEPTR currNode, std::string findTitle) {
	TREENODEPTR travNode = currNode;
	if (currNode->getLC() != TREENULLPTR) {
		travNode = findHelper(currNode->getLC(), findTitle);
		if (travNode != TREENULLPTR) {
			currNode = travNode;
		}
	}
	if (currNode->getRS() != TREENULLPTR) {
		currNode = findHelper(currNode->getRS(), findTitle);
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

//TODO: test this
TREENODEPTR OrgTree::rightmostSiblingFinder(TREENODEPTR currNode) {
	if (currNode->getRS() != TREENULLPTR) {
		rightmostSiblingFinder(currNode->getRS());
	}
	return currNode;
}

//TODO: make this not break the program lol
void OrgTree::printHelper(TREENODEPTR currNode) {
	std::cout << currNode->getTitle() << ": " << currNode->getName() << std::endl;
	if (currNode->getLC() != TREENULLPTR) {
		std::cout << "     ";
		printHelper(currNode->getLC());
		//print a tab here probs?
	}
	if (currNode->getRS() != TREENULLPTR) {
		std::cout << " and ";
		printHelper(currNode->getRS());
	}
	std::cout << std::endl;
}