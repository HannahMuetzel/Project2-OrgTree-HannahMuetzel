#pragma once
#include "stdafx.h"
//#include <stdlib.h>
#include "OrgTree.h"
//#include "TreeNode.h"
#include <iostream>
#define TREENODEPTR TreeNode*
#define TREENULLPTR NULL

int main()
{
	OrgTree testDaRoot;
	testDaRoot.addRoot("TEST", "root!!");
	testDaRoot.printSubTree(testDaRoot.getRoot());

	int expSize = 0;
	OrgTree test;
	test.addRoot("Test Root Title", "Root");
	expSize++;
	test.hire(test.getRoot(), "LC", "Root LC");

	for (int i = 1; i < 10; i++) {
		expSize++;
		test.hire(test.getRoot(), "RS" + std::to_string(i), "Root LC RS" + std::to_string(i));

		//TODO: test fire omg

		//test.fire("RS" + std::to_string(i));
		//expSize--;
	}

	for (int i = 1; i < 5; i++) {
		test.hire(test.find("RS1"), "RS1" + std::to_string(i), "Root LC RS1" + std::to_string(i));
		expSize++;
	}
	for (int i = 1; i < 9; i++) {
		test.hire(test.find("RS5"), "RS5" + std::to_string(i), "Root LC RS5" + std::to_string(i));
		expSize++;
	}

	test.hire(test.getRoot(), "Fire me!", "I take fifteen breaks an hour!");
	expSize++;

	test.fire("Fire me!");
	expSize--;

	//std::cout << "Found Fire me?: " << test.find("Fire me!") << std::endl;
	//std::cout << "Found root?: " << test.find("Test Root Title") << std::endl;
	//std::cout << "Found unfindable guy?: " << test.find("I will not be found") << std::endl;

	test.printSubTree(test.getRoot());

	std::cout << std::endl << "Expected size: " << expSize << std::endl;
	std::cout << "Size: " << test.getSize() << std::endl;

	system("pause");
	return 0;
}

