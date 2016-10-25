#include "stdafx.h"
#include "OrgTree.h"
#include <iostream>
//#define TREENODEPTR TreeNode*
//#define TREENULLPTR NULL


OrgTree::OrgTree()
{
	root = TREENULLPTR;
	size = 0;
}

void OrgTree::deleteHelper(TreeNode* currNode) {
	if (currNode->getLC() != TREENULLPTR) {
		deleteHelper(currNode->getLC());
	}
	if (currNode->getRS() != TREENULLPTR) {
		deleteHelper(currNode->getRS());
	}
	
	delete currNode;
}

//TODO: test this just like freakin' everything else in this program
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

//TODO: test this
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

void OrgTree::hire(TREENODEPTR ptr, std::string newTitle, std::string newName)
{
	//check to see if the ptr has a kid,
	//if they don't, then just hire newEmp as lc of ptr
	//if they do, then go through all of the rs of ptr's lc
	//then add newEmp as a rs of the most rightest sibling
	//don't forget to set newEmp's par to ptr, lc to NULL, and rs to NULL
}

TREENODEPTR OrgTree::find(std::string title)
{
	//traverse tree
	//somehow figure out how to do that ^
	//if node's title == passed title then return that ptr
	return TREENULLPTR;
}

bool OrgTree::fire(std::string formerTitle)
{
	//find(formerTitle)
	//delete that guy by setting his children's parents to his parent
	//change their rs if needed
	//remove him from the tree by deleting his node
	return false;
}

void OrgTree::printSubTree(TREENODEPTR subTreeRoot)
{
	//make this recursive somehow?
	//if there's a root, print it, then set the lc of root to currRoot
	//err no, print all the rs of that lc first, then set the lc to currRoot
	//print currRoot, rinse and repeat
	//except don't do this because it messes up the order of the children
	//does that even matter?
	//idk lol
	//how do i print a tab omg
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