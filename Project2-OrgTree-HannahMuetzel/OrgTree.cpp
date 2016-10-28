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

TREENODEPTR OrgTree::leftmostChild(TREENODEPTR node)
{
	if (node->getLC() == TREENULLPTR) {
		return TREENULLPTR;
	}
	else {
		return node->getLC();
	}
}

TREENODEPTR OrgTree::rightSibling(TREENODEPTR node)
{
	if (node->getRS() == TREENULLPTR) {
		return TREENULLPTR;
	}
	else {
		return node->getRS();
	}
}

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

	//Handle if fireThem is a right sibling to another node
	TREENODEPTR travNode = fireThem->getPar()->getLC();
	while (travNode != fireThem) {
		if (travNode->getRS() == fireThem) {
			travNode = travNode->getRS();
			travNode->rs = fireThem->getRS();
		}
		else {
			travNode = travNode->getRS();
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

TREENODEPTR OrgTree::rightmostSiblingFinder(TREENODEPTR currNode) {
	if (currNode->getRS() == TREENULLPTR) {
		return currNode;
	} else {
		return rightmostSiblingFinder(currNode->getRS());
	}
}