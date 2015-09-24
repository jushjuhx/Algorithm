/*********************************************************************************
1.�Ѷ�Ԫ������(Binary search tree)ת��������˫������
��Ŀ��
����һ�ö�Ԫ�����������ö�Ԫ������ת����һ�������˫������
Ҫ���ܴ����κ��µĽ�㣬ֻ����ָ���ָ��

   10
   / \
 6    14
/ \   / \
4  8 12 16

ת����˫������
4 = 6 = 8 = 10 = 12 = 14 = 16��


�������Ƕ���Ķ�Ԫ������ �ڵ�����ݽṹ���£�
struct BSTreeNode
{
	int m_nValue; // value of node
	BSTreeNode *m_pLeft; // left child of node
	BSTreeNode *m_pRight; // right child of node
};

*********************************************************************************/

#include <iostream>
#include "bstree.h"
using namespace std;

int main()
{
	BSTreeNode * pHead = NULL;
	BSTreeNode * pListIndex = NULL;
	BSTree* pRoot = new BSTree();
	pRoot->addBSTreeNode(10);
	pRoot->addBSTreeNode(4);
	pRoot->addBSTreeNode(12);
	pRoot->addBSTreeNode(14);
	pRoot->addBSTreeNode(15);
	pRoot->addBSTreeNode(6);
	pRoot->addBSTreeNode(8);
	pRoot->addBSTreeNode(16);
	pRoot->showTree(); // ������״
	pRoot->ergodicBSTree();
	return 0;
}


/////////////////////////////////////////////////
//4
//6
//8
//10
//12
//14
//15
//16
//Press any key to continue
////////////////////////////////////////////////