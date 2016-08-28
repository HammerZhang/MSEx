// MSEx2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>


// 栈元素结构
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

// 全局变量
CStackType *stackTop;           // 栈顶

// 堆栈操作函数
// 创建并初始化栈
void InitStack()
{
	stackTop = new CStackType();
}

// 入栈
void push(DATA d)
{
	CStackType *elem = new CStackType();
	elem->data = d;
	elem->next = stackTop;
	stackTop = elem;
}

// 出栈
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
	std::cout << "栈里面的最小元素为："<<minElem<<std::endl;

	return 0;
}

