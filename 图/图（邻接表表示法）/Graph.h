#pragma once
#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include "Queue.h"

template <typename T>
class Graph
{
private:
	struct ArcNode
	{
		int adjvex;//邻接节点
		ArcNode* nextarc;//指向下一条边
		int weight;
		ArcNode(int adj, int w)
			:adjvex(adj), nextarc(nullptr), weight(w)
		{
			
		}
	};
	struct VNode
	{
		T data;
		ArcNode* firstarc;
		VNode()
			:firstarc(nullptr)
		{

		}
	};
	VNode* vertices;//存头结点的数组
	int vexnum;
	int arcnum;

	void DFS_help(bool* visit, int v) const
	{
		std::cout << vertices[v].data << " ";
		visit[v] = 1;

		ArcNode* currentPtr = vertices[v].firstarc;

		while (currentPtr != nullptr)
		{
			if (visit[currentPtr->adjvex] == 0)
				DFS_help(visit, currentPtr->adjvex);

			currentPtr = currentPtr->nextarc;
		}
	}

public:
	Graph(int vnum, int anum)
		:vexnum(vnum), arcnum(anum)
	{
		vertices = new VNode[vexnum]();

		std::cout << "-------构建顶点-------\n";
		for (int i = 0; i < vexnum; i++)
		{
			std::cout << "请输入顶点信息: \n";
			std::cin >> vertices[i].data;
		}

		std::cout << "\n-------构建边-------\n";
		for (int i = 0; i < arcnum; i++)
		{
			int v1;
			int v2;
			int w;
			std::cout << "输入: \n";
			std::cin >> v1 >> v2 >> w;

			ArcNode* newArc1 = new ArcNode(v2, w);
			ArcNode* newArc2 = new ArcNode(v1, w);

			newArc1->nextarc = vertices[v1].firstarc;
			vertices[v1].firstarc = newArc1;

			newArc2->nextarc = vertices[v2].firstarc;
			vertices[v2].firstarc = newArc2;
		}
	}

	void DFS() const
	{
		bool* visit = new bool[vexnum] {0};

		for (int i = 0; i < vexnum; i++)//保证非联连通图也能够完成遍历
		{
			if (visit[i] == 0)
				DFS_help(visit, i);
		}

		delete[] visit;
	}

	void BFS() const
	{
		bool* visit = new bool[vexnum] {0};
		Queue<int> queue;

		for (int i = 0; i < vexnum; i++)
		{
			if (visit[i] == 0)//保证非连通图也可以完成遍历
			{
				std::cout << vertices[i].data << " ";

				queue.enQueue(i);
				visit[i] = 1;

				while (!queue.isEmpty())
				{
					int value = 0;//保存出队顶点的编号
					queue.deQueue(value);

					for (ArcNode* currentPtr = vertices[value].firstarc; currentPtr != nullptr; currentPtr = currentPtr->nextarc)//遍历出队顶点的单链表
					{
						if (visit[currentPtr->adjvex] == 0)//如果链表中的某个顶点还未被访问
						{
							std::cout << vertices[currentPtr->adjvex].data << " ";
							visit[currentPtr->adjvex] = 1;
							queue.enQueue(currentPtr->adjvex);
						}
					}
				}
				
			}
		}

		delete[] visit;
	}

	void print() const
	{
		std::cout << "\n-------邻接表-------\n";

		for (int i = 0; i < vexnum; i++)
		{
			std::cout << vertices[i].data << " : ";

			ArcNode* p = vertices[i].firstarc;

			while (p != nullptr)
			{
				std::cout << " -> "
					<< vertices[p->adjvex].data
					<< "(" << p->weight << ")";

				p = p->nextarc;
			}

			std::cout << std::endl;
		}

		std::cout << std::endl;
	}

	~Graph()
	{
		for (int i = 0; i < vexnum; i++)
		{
			while (vertices[i].firstarc != nullptr)
			{
				ArcNode* temp = vertices[i].firstarc;
				vertices[i].firstarc = temp->nextarc;
				delete temp;
			}
		}

		delete[] vertices;
	}
};
#endif // !GRAPH_H
