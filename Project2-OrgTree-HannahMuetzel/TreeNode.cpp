#include "stdafx.h"
#include "TreeNode.h"
#define TREENODEPTR TreeNode*
#define TREENULLPTR NULL

//default constructor
//Time complexity: theta(1)
TreeNode::TreeNode()
{
	title = "";
	name = "";
	lc = TREENULLPTR;
	rs = TREENULLPTR;
	par = TREENULLPTR;
}

//paramitarized constructor
//Time complexity: theta(1)
TreeNode::TreeNode(const std::string name_, const std::string title_, TREENODEPTR lc_, TREENODEPTR rs_, TREENODEPTR par_)
{
	title = title_;
	name = name_;
	lc = lc_;
	rs = rs_;
	par = par_;
}

TreeNode::~TreeNode(){}

//returns name of node
//Time complexity: theta(1)
std::string TreeNode::getName() {
	return name;
}

//returns title of node
//Time complexity: theta(1)
std::string TreeNode::getTitle() {
	return title;
}

//returns left child of node
//Time complexity: theta(1)
TREENODEPTR TreeNode::getLC() {
	return lc;
}

//returns right sibling of node
//Time complexity: theta(1)
TREENODEPTR TreeNode::getRS() {
	return rs;
}

//returns parent of node
//Time complexity: theta(1)
TREENODEPTR TreeNode::getPar() {
	return par;
}