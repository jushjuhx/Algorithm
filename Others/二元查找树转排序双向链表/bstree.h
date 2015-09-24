#pragma once
#include <iostream>
#include "bstreenode.h"
using namespace std;
class BSTree
{
public:
	BSTree();
	~BSTree();

	void addBSTreeNode(int) ;
	void addAsChild(BSTreeNode * &, int);
	void convertToDoubleList(BSTreeNode * );
	void BSTree::ergodicBSTree();
	void BSTree::ergodicBSTree(BSTreeNode *);
	void showTree();
	void BSTree::showTree(BSTreeNode *,int);
private:
	BSTreeNode * pTreeIndex;
	BSTreeNode * pListIndex;
	BSTreeNode * pHead;
};

BSTree::BSTree()
{
	pTreeIndex = NULL;
}

BSTree::~BSTree()
{

}

void BSTree::addBSTreeNode(int value)
{
	if (NULL == pTreeIndex)
	{
		BSTreeNode * pBSTreeNode = new BSTreeNode(value);
		pTreeIndex = pBSTreeNode;
	}
	else
	{
		if ((pTreeIndex->value) != value)
		{
			addAsChild(pTreeIndex, value);
		}
		else
		{
			cout<<"�ظ�����ڵ�"<<endl;
		}
	}
}
void BSTree::addAsChild(BSTreeNode * &parent, int value)
{
	if (NULL == parent)
	{
		BSTreeNode * pBSTreeNode = new BSTreeNode(value);
		parent = pBSTreeNode;
		return;
	}
	if (parent->value > value) {
		if (NULL == parent->left) {
			parent->left = new BSTreeNode(value);
		}
		else
		{
			addAsChild(parent->left, value);
		}
	}
	if (parent->value < value) {
		if (NULL == parent->right) {
			parent->right = new BSTreeNode(value);
		}
		else
		{
			addAsChild(parent->right, value);
		}
	}
}

void BSTree::ergodicBSTree() {
	ergodicBSTree(pTreeIndex);
}
// ������Ԫ������  ����
void BSTree::ergodicBSTree(BSTreeNode * pCurrent)
{
	if (NULL == pCurrent)
	{
		return;
	}
	if (NULL != pCurrent->left)
	{
		ergodicBSTree(pCurrent->left);
	}

	// �ڵ�ӵ�����β��
	convertToDoubleList(pCurrent);
	// ������Ϊ��
	if (NULL != pCurrent->right)
	{
		ergodicBSTree(pCurrent->right);
	}
}

// ������ת����list
void BSTree::convertToDoubleList(BSTreeNode * pCurrent)
{
	pCurrent->left = pListIndex;
	if (NULL != pListIndex)
	{
		pListIndex->right = pCurrent;
	}
	else
	{
		pHead = pCurrent;
	}
	pListIndex = pCurrent;
	cout << pCurrent->value << endl;
}
void BSTree::showTree()
{
	showTree(pTreeIndex ,0);
}
void BSTree::showTree(BSTreeNode * pCurrent, int level)
{
	if (NULL == pCurrent) { return; }
	cout << level <<":" << pCurrent->value <<endl;
	level++;
	showTree(pCurrent->left, level);
	showTree(pCurrent->right,level);
}