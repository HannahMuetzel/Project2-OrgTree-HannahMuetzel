#pragma once
#include <string>
#define TREENODEPTR TreeNode*
#define TREENULLPTR NULL

class TreeNode
{
public:
	TreeNode();
	TreeNode(std::string name, std::string title, TREENODEPTR lc, TREENODEPTR rs, TREENODEPTR par);
	~TreeNode();

	std::string getName();
	std::string getTitle();
	TREENODEPTR getLC();
	TREENODEPTR getRS();
	TREENODEPTR getPar();

	std::string title;
	std::string name;
	TREENODEPTR lc;
	TREENODEPTR rs;
	TREENODEPTR par;
};
