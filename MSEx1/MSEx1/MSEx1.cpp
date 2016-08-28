// MSEx1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <vector>



typedef int DATA;          // define data type in tree
struct CBTType
{
	DATA data;             // Ԫ������
	CBTType *leftTree;     // ָ��������ָ��
	CBTType *rightTree;    // ָ��������ָ��

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

// ����
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

//ȫ�ֱ���
CBTType *listHead = NULL;
CBTType *listTail = NULL;

// ȫ�ֺ���
void Tree2BiList(CBTType *node);

// ��ʼ��������
CBTType * InitCBT()
{
	CBTType *Node;
	if (Node = new CBTType)
	{
		std::cout << "������ڵ�Ԫ��:\n";
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


// ����һ��������������������������ұ���,���ظ��ڵ�ָ��
// ������Ԫ��ֵ���ݸ���һά����
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
				// �����
				Node->leftTree = new CBTType(*it);
				sq->elem[sq->tail++] = Node->leftTree;
			}
			else
			{
				if (Node->rightTree == NULL)
				{
					// �����
					Node->rightTree = new CBTType(*it);
					sq->elem[sq->tail++] = Node->rightTree;

					// ������
					Node = sq->elem[sq->head++];
				}
			}
		}
	}
	return root;
}

// ��Ԫ�����������������������Ƕ������ĸ��ڵ�
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

// ��������ת������˫������, �����Ƕ������ĸ��ڵ�
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

