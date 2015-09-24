#pragma once
struct BSTreeNode
{
	int value;          // value of node
	BSTreeNode *left;   // left child of node
	BSTreeNode *right;  // right child of node
	//BSTreeNode() { left = NULL; right = NULL;};
	BSTreeNode(int val) { value = val; left = NULL; right = NULL; };
};