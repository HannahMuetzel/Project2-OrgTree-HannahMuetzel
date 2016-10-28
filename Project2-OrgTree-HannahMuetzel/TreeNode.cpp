#include "stdafx.h"
#include "TreeNode.h"
#define TREENODEPTR TreeNode*
#define TREENULLPTR NULL

//default constructor
TreeNode::TreeNode()
{
	title = "";
	name = "";
	lc = TREENULLPTR;
	rs = TREENULLPTR;
	par = TREENULLPTR;
}

//paramitarized constructor
TreeNode::TreeNode(const std::string name_, const std::string title_, TREENODEPTR lc_, TREENODEPTR rs_, TREENODEPTR par_)
{
	title = title_;
	name = name_;
	lc = lc_;
	rs = rs_;
	par = par_;
}

TreeNode::~TreeNode(){}

std::string TreeNode::getName() {
	return name;
}

std::string TreeNode::getTitle() {
	return title;
}

TREENODEPTR TreeNode::getLC() {
	return lc;
}

TREENODEPTR TreeNode::getRS() {
	return rs;
}

TREENODEPTR TreeNode::getPar() {
	return par;
}