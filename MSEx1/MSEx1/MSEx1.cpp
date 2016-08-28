// MSEx1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>



typedef int DATA;          // define data type in tree
struct CBTType
{
	DATA data;             // 元素数据
	CBTType *leftTree;     // 指向左子树指针
	CBTType *rightTree;    // 指向右子树指针

	CBTType(int x = 0)
	{
		this->data = x;
		this->leftTree = NULL;
		this->rightTree = NULL;
	}
};

struct  ListType
{
	CBTType *elem;
	ListType *next;
	ListType *prev;

	ListType()
	{
		this->elem = NULL;
		this->next = NULL;
		this->prev = NULL;
	}
};

// 队列
struct  SQType
{
	CBTType *elem[10];
	int head;
	int tail;

	SQType()
	{
		head = 0;
		tail = 0;
	}
};

//全局变量
CBTType *listHead = NULL;
CBTType *listTail = NULL;

// 全局函数
void Tree2BiList(CBTType *node);

// 初始化二叉树
CBTType * InitCBT()
{
	CBTType *Node;
	if (Node = new CBTType)
	{
		std::cout << "请输入节点元素:\n";
		std::cin >> Node->data;
		Node->leftTree = NULL;
		Node->rightTree = NULL;
	}
	if (Node != NULL)
		return Node;
	else
		return NULL;

	return NULL;
}


// 创建一个二叉树，按层遍历，从左向右遍历,返回根节点指针
// 二叉树元素值根据给定一维容器
CBTType *CreateCBT(std::vector<int> vec)
{
	CBTType *Node = NULL; CBTType *root = NULL;
	SQType *sq = new SQType();
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		if (Node == NULL)
		{
			Node = new CBTType(*it);
			root = Node;
		}
		else
		{
			if (Node->leftTree == NULL)
			{
				// 入队列
				Node->leftTree = new CBTType(*it);
				sq->elem[sq->tail++] = Node->leftTree;
			}
			else
			{
				if (Node->rightTree == NULL)
				{
					// 入队列
					Node->rightTree = new CBTType(*it);
					sq->elem[sq->tail++] = Node->rightTree;

					// 出队列
					Node = sq->elem[sq->head++];
				}
			}
		}
	}
	return root;
}

// 二元查找树中序遍历，输入参数是二叉树的根节点
void inOrderBiTree(CBTType *root)
{
	if (NULL != root)
	{
		inOrderBiTree(root->leftTree);
		Tree2BiList(root);
		inOrderBiTree(root->rightTree);
	}
	else
	{
		return;
	}
}

// 将二叉树转成排序双向链表, 参数是二叉树的根节点
void Tree2BiList(CBTType *node)
{
	if (NULL == listHead && NULL == listTail)
	{
		listHead = new CBTType();
		listTail = new CBTType();
		listHead->rightTree = listTail;
		listTail->leftTree = listHead;
	}

	node->leftTree = listTail->leftTree;
	listTail->leftTree->rightTree = node;
	node->rightTree = listTail;
	listTail->leftTree = node;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int arr[7] = {10,6,14,4,8,12,16};
	std::vector<int> vec;
	for (int i = 0; i < 7; i++)
	{
		vec.push_back(arr[i]);
	}

	CBTType *root;
	root = CreateCBT(vec);
	inOrderBiTree(root);

	CBTType *node;
	node = listHead->rightTree;
	while (NULL != node->rightTree)
	{
		std::cout << node->data << "    \n";
	}
	return 0;
}

