// MSEx4.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <vector>
#include <iostream>


typedef int DATA;        // ��������������

// �������ṹ��
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

// ���нṹ��
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

// ȫ�ֱ���
CQType *queHead = NULL;
CQType *queTail = NULL;            // ����ͷ�Ͷ���β

// �����
void pushQueue(CBSType *treeNode)
{
	if (NULL == queHead && NULL == queTail)         // ����Ϊ��
	{// ��ʼ������

		queHead = new CQType();
		queTail = new CQType();
		queHead = queTail;
	}

	CQType *newQueNode = new CQType();
	newQueNode->elem = treeNode;
	queTail->next = newQueNode;
	queTail = newQueNode;
}

// ������
CBSType *pullQueue()
{
	CBSType *node;
	if (NULL == queHead && NULL == queTail)         // ����Ϊ��
	{
		std::cout << "����Ϊ��\n";
		return NULL;
	}
	else
	{
		node = queHead->next->elem;
		queHead = queHead->next;
	}

	return node;
}

// ��ն���
void clearQueue()
{
	queTail = NULL;
	queHead = queTail;
}

// �ж϶����Ƿ�Ϊ��
bool isEmpty()
{
	if (queHead == queTail)
		return true;
	else
		return false;
}

// ����һ��������, ���������һ���������飬���ظ��ڵ�ָ��
// ǰ�����
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

			// �����������������������
			if (NULL == node->lchild)
				node->lchild = new CBSType();
			if (NULL == node->rchild)
				node->rchild = new CBSType();

			pushQueue(node->lchild);
			pushQueue(node->rchild);
		}
		else
		{
			std::cout << "�����ѿ�\n";
			break;
		}
	}

	return root;
}


// �����Ԫ������,�������Ϊ����������ĸ��ڵ�ָ��
void mirrorBiTree(CBSType *root)
{
	CBSType *node;
	pushQueue(root);
	while (!isEmpty())
	{
		node = pullQueue();
		CBSType *tmpNode;
		if (NULL != node->lchild || NULL != node->rchild)           // ����������һ����Ϊ��
		{// ������������
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

