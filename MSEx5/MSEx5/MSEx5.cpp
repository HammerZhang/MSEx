// MSEx5.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

#define INF 1000
typedef int DATA;

struct GENode
{
	DATA adjvex;
	DATA weight;
	GENode* nextNode;

	GENode(DATA adjv = -1, DATA weight = -1000)
	{
		this->adjvex = adjv;
		this->weight = weight;
		this->nextNode = NULL;
	}

	bool empty()
	{
		if (this->adjvex == -1 && this->weight == -1000
			&& this->nextNode == NULL)
			return true;
		else
			return false;
	}
};

struct GVNode
{
	DATA vertex;
	GENode* link;
	GENode* tail;

	GVNode(DATA v = -1)
	{
		this->vertex = v;
		this->tail = new GENode();
		this->link = tail;
	}

	void AddENode(GENode* node)
	{
		tail->adjvex = node->adjvex;
		tail->nextNode = new GENode();
		tail = tail->nextNode;
	}
};

/*
* Create adjacency list of a graph using given adjacency matrix
* @param DATA** adjMatrix: adjancency matrix
* @param DATA* vertexs: vector stores vertex
* @return the vertex list adress 
*/
GVNode** BuildAdjList(DATA* adjMatrix, DATA* vertexs, int len)
{
	GVNode** vertexList = new GVNode*[len];

	//push element values into vertex list
	for (int i = 0; i < len; i++)
	{
		vertexList[i] = new GVNode(*(vertexs+i));
	}

	// add adjMatrix element into adjancency lists
	for (int j = 0; j < len; j++)
	{
		for (int k = 0; k < len; k++)
		{
			if (0 != *(adjMatrix + j*len + k) && INF != *(adjMatrix + j*len + k))
			{
				GENode* newNode = new GENode(k + 1, *(adjMatrix + j*len + k));
				vertexList[j]->AddENode(newNode);
			}
		}
	}

	return vertexList;
}

/*
* display each routine in graph
* @param GVNode** list: the adress of a poniter array which store adresses of vertex
*/
void DisplayAdjList(GVNode** list, int len)
{
	for (int i = 0; i < len;i++)
	{
		DATA d = list[i]->vertex;
		std::cout << d << "-->";

		GENode* tmpNode = list[i]->link;		
		while (!tmpNode->empty())
		{
			d = tmpNode->adjvex;
			std::cout << d << "-->";

			tmpNode = tmpNode->nextNode;
		}
		std::cout << "end\n";
	}
}


int _tmain(int argc, _TCHAR* argv[])
{
	DATA vertexs[3] = { 1, 2, 3 };
	DATA adjMatrix[3][3] = { 0, 1, INF , 4, 0, 2 , 3, INF, 0 };
	GVNode** vertexList = BuildAdjList(&adjMatrix[0][0], vertexs, 3);
	DisplayAdjList(vertexList,3);
	return 0;
}

