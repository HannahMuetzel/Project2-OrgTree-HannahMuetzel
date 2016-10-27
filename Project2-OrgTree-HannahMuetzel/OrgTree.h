#pragma once
#include <string>
#include "TreeNode.h"

class OrgTree
{
public:
	OrgTree();
	~OrgTree();

	void addRoot(std::string title, std::string name);
	unsigned int getSize();
	TREENODEPTR getRoot();
	
	TREENODEPTR leftmostChild(TREENODEPTR node);
	TREENODEPTR rightSibling(TREENODEPTR node);
	
	void printSubTree(TREENODEPTR subTreeRoot);
	TREENODEPTR find(std::string title);
	bool read(std::string filename);
	void write(std::string filename);
	void hire(TREENODEPTR ptr, std::string newTitle, std::string newName);
	bool fire(std::string formerTitle);
	

private:
	TREENODEPTR root;
	unsigned int size;

	void deleteHelper(TREENODEPTR);
	TREENODEPTR findHelper(TREENODEPTR, std::string);
	TREENODEPTR rightmostSiblingFinder(TREENODEPTR);
	void printHelper(TREENODEPTR);

};

