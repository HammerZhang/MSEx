// MSEx2.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>


// ջԪ�ؽṹ
typedef int DATA;
struct  CStackType
{
	DATA data;
	CStackType *next;
	CStackType()
	{
		this->next = NULL;
	}
};

// ȫ�ֱ���
CStackType *stackTop;           // ջ��

// ��ջ��������
// ��������ʼ��ջ
void InitStack()
{
	stackTop = new CStackType();
}

// ��ջ
void push(DATA d)
{
	CStackType *elem = new CStackType();
	elem->data = d;
	elem->next = stackTop;
	stackTop = elem;
}

// ��ջ
CStackType *pull()
{
	CStackType *node = stackTop;
	stackTop = stackTop->next;

	return node;
}

DATA min()
{
	CStackType *node = stackTop;
	DATA min = stackTop->data;

	while (NULL != node->next)
	{
		if (min > node->data)
			min = node->data;

		node = node->next;
	}

	return min;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int a[10] = { 0, 3, -2, 7, 22, 41, -6, -13, 10, 18 };
	InitStack();
	for (int i = 0; i < 10; i++)
	{
		push(a[i]);
	}

	DATA minElem = min();
	std::cout << "ջ�������СԪ��Ϊ��"<<minElem<<std::endl;

	return 0;
}

