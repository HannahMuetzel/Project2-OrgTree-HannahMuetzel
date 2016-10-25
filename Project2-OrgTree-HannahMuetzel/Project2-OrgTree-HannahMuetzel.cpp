#pragma once
#include "stdafx.h"
//#include <stdlib.h>
#include "OrgTree.h"
//#include "TreeNode.h"
#include <iostream>
#define TREENODEPTR TreeNode*
#define TREENULLPTR NULL

void testfuc() {
	//Test making an OrgTree

	//OrgTree* testTree = new OrgTree();
	OrgTree testTree;
	//Make a TreeNode
	//TreeNode* testNode = new TreeNode("Tom Root", "Root-Man", TREENULLPTR, TREENULLPTR, TREENULLPTR);
	//std::cout << testNode->getName() << testNode->getTitle() << testNode->getLC() << testNode->getRS() << testNode->getPar() << std::endl;

	//Add a root
	testTree.addRoot("Test title", "Test name");
	//Get root
	TreeNode* currRoot = testTree.getRoot();
	//std::cout << currRoot->getName() << currRoot->getTitle() << currRoot->getLC() << currRoot->getRS() << currRoot->getPar() << std::endl;
	//Add root when there already exists a root

	testTree.addRoot("Replace title", "Replace name");
	currRoot = testTree.getRoot();
	//std::cout << currRoot->getName() << currRoot->getTitle() << currRoot->getLC() << currRoot->getRS() << currRoot->getPar() << std::endl;
	//delete testTree;
}

int main()
{
	for (int i = 0; i < 100000; i++) {
		testfuc();
	}
	//Test making an OrgTree

	//OrgTree* testTree = new OrgTree();
	
	//Make a TreeNode
	//TreeNode* testNode = new TreeNode("Tom Root", "Root-Man", TREENULLPTR, TREENULLPTR, TREENULLPTR);
	//std::cout << testNode->getName() << testNode->getTitle() << testNode->getLC() << testNode->getRS() << testNode->getPar() << std::endl;
	/*
	//Add a root
	testTree->addRoot("Test title", "Test name");
	//Get root
	TreeNode* currRoot = testTree->getRoot();
	std::cout << currRoot->getName() << currRoot->getTitle() << currRoot->getLC() << currRoot->getRS() << currRoot->getPar() << std::endl;
	//Add root when there already exists a root
	
	testTree->addRoot("Replace title", "Replace name");
	currRoot = testTree->getRoot();
	std::cout << currRoot->getName() << currRoot->getTitle() << currRoot->getLC() << currRoot->getRS() << currRoot->getPar() << std::endl;

	*/
	system("pause");
    return 0;
}

