// MSEx4.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <iostream>


typedef int DATA;        // 二叉树数据类型

// 二叉树结构体
struct  CBSType
{
	DATA data;
	CBSType *lchild;
	CBSType *rchild;

	CBSType()
	{
		this->lchild = NULL;
		this->rchild = NULL;
	}
};

// 队列结构体
struct CQType
{
	CBSType *elem;
	CQType *next;

	CQType()
	{
		this->elem = NULL;
		this->next = NULL;
	}
};

// 全局变量
CQType *queHead = NULL;
CQType *queTail = NULL;            // 队列头和队列尾

// 入队列
void pushQueue(CBSType *treeNode)
{
	if (NULL == queHead && NULL == queTail)         // 队列为空
	{// 初始化队列

		queHead = new CQType();
		queTail = new CQType();
		queHead = queTail;
	}

	CQType *newQueNode = new CQType();
	newQueNode->elem = treeNode;
	queTail->next = newQueNode;
	queTail = newQueNode;
}

// 出队列
CBSType *pullQueue()
{
	CBSType *node;
	if (NULL == queHead && NULL == queTail)         // 队列为空
	{
		std::cout << "队列为空\n";
		return NULL;
	}
	else
	{
		node = queHead->next->elem;
		queHead = queHead->next;
	}

	return node;
}

// 清空队列
void clearQueue()
{
	queTail = NULL;
	queHead = queTail;
}

// 判断队列是否为空
bool isEmpty()
{
	if (queHead == queTail)
		return true;
	else
		return false;
}

// 创建一个二叉树, 输入参数是一个整形数组，返回根节点指针
// 前序遍历
void preOrderTraverse(CBSType *node, void(*operation)(CBSType *curr_node))
{
	if (NULL != node)
	{
		preOrderTraverse(node->lchild, operation);
		operation(node);
		preOrderTraverse(node->rchild, operation);
	}
	else
	{
		return;
	}
}

CBSType *CreateBiTree(std::vector<int> vec)
{
	CBSType *root = new CBSType(); 
	CBSType *node = new CBSType();
	pushQueue(root);
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end();it++)
	{
		if (!isEmpty())
		{
			node = pullQueue();
			node->data = *it;

			// 将左子树和右子树放入队列
			if (NULL == node->lchild)
				node->lchild = new CBSType();
			if (NULL == node->rchild)
				node->rchild = new CBSType();

			pushQueue(node->lchild);
			pushQueue(node->rchild);
		}
		else
		{
			std::cout << "队列已空\n";
			break;
		}
	}

	return root;
}


// 镜像二元查找树,输入参数为被镜像的树的根节点指针
void mirrorBiTree(CBSType *root)
{
	CBSType *node;
	pushQueue(root);
	while (!isEmpty())
	{
		node = pullQueue();
		CBSType *tmpNode;
		if (NULL != node->lchild || NULL != node->rchild)           // 左右子树有一个不为空
		{// 交换左右子树
			tmpNode = node->lchild;
			node->lchild = node->rchild;
			node->rchild = tmpNode;
		}

		if (NULL != node->lchild)
			pushQueue(node->lchild);

		if (NULL != node->rchild)
			pushQueue(node->rchild);
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int arr[7] = { 8, 6, 10, 5, 7, 9, 11 };
	std::vector<int> vec;
	for (int i = 0; i < 7; i++)
	{
		vec.push_back(arr[i]);
	}

	CBSType *root;
	root = CreateBiTree(vec);
	clearQueue();
	mirrorBiTree(root);
	return 0;
}

