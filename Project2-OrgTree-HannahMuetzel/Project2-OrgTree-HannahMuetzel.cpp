#pragma once
#include "stdafx.h"
//#include <stdlib.h>
#include "OrgTree.h"
//#include "TreeNode.h"
#include <iostream>
#define TREENODEPTR TreeNode*
#define TREENULLPTR NULL

void testfucn() {
	//Test making an OrgTree

	//OrgTree* testTree = new OrgTree();
	OrgTree testTree;
	//Make a TreeNode
	//TreeNode* testNode = new TreeNode("Tom Root", "Root-Man", TREENULLPTR, TREENULLPTR, TREENULLPTR);
	//std::cout << testNode->getName() << testNode->getTitle() << testNode->getLC() << testNode->getRS() << testNode->getPar() << std::endl;

	//Add a root
	testTree.addRoot("Things: ", "1");
	//Get root
	TreeNode* currRoot = testTree.getRoot();
	//std::cout << currRoot->getName() << currRoot->getTitle() << currRoot->getLC() << currRoot->getRS() << currRoot->getPar() << std::endl;
	//Add root when there already exists a root
	std::cout << testTree.getSize() << std::endl;

	testTree.addRoot("Things:: ", "2");
	currRoot = testTree.getRoot();
	std::cout << testTree.getSize() << std::endl;

	testTree.addRoot("Things::: ", "3");
	std::cout << testTree.getSize() << std::endl;

	//std::cout << currRoot->getName() << currRoot->getTitle() << currRoot->getLC() << currRoot->getRS() << currRoot->getPar() << std::endl;
	//delete testTree;
}

int main()
{
	for (int i = 0; i < 1; i++) {
		//testfucn();
	}

	OrgTree test;
	test.addRoot("Test Root Title", "Root");
	test.hire(test.getRoot(), "Fire me!", "I'm a horrible employee!");
	test.hire(test.find("Fire me!"), "RS of Fire me", "RS 1");
	test.hire(test.find("Fire me!"), "LC of Fire me", "LC 1");
	
	//std::cout << test.find("Fire me!") << std::endl;
	//std::cout << test.find("Test Root Title") << std::endl;
	//std::cout << test.find("I will not be found") << std::endl;
	
	test.printSubTree(test.getRoot());

	/*
	for (int i = 0; i < 10; i++) {
		test.hire(test.getRoot(), "Title", "Name");
		std::cout << test.getSize() << std::endl;
		test.printSubTree(test.getRoot());
//		bool isFired = test.fire("Fire me!");
	//	std::cout << "Did we fire? " << isFired << std::endl;
		std::cout << test.getSize() << std::endl;
	}
	*/

	system("pause");
    return 0;
}

