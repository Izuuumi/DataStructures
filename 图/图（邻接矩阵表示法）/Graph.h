#pragma once
#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include "Queue.h"

constexpr int GRAPH_MAX_SIZE = 10;

template <typename T>
class Graph
{
private:
	T vexs[GRAPH_MAX_SIZE];
	int arcs[GRAPH_MAX_SIZE][GRAPH_MAX_SIZE];
	int vexnum;//顶点数
	int arcnum;//边数

	void DFS_help(int* visit, int v) const
	{
		std::cout << vexs[v] << " ";
		visit[v] = 1;

		for (int i = 0; i < vexnum; i++)
		{
			if (arcs[v][i] != 0 && visit[i] == 0)
				DFS_help(visit, i);
		}
	}

public:
	Graph(int vnum, int anum)
		:vexnum(vnum), arcnum(anum)
	{
		std::cout << "-------构建点-------\n";
		for (int i = 0; i < vexnum; i++)
		{
			std::cout << "输入顶点信息: \n";
			std::cin >> vexs[i];
		}

		for (int i = 0; i < GRAPH_MAX_SIZE; i++)
		{
			for (int j = 0; j < GRAPH_MAX_SIZE; j++)
			{
				arcs[i][j] = 0;
			}
		}

		std::cout << "-------构建边-------\n";
		for (int i = 0; i < arcnum; i++)
		{
			int j = 0;
			int k = 0;
			int weight = 0;

			std::cout << "输入: \n";
			std::cin >> j >> k >> weight;

			if (j >= GRAPH_MAX_SIZE || k > GRAPH_MAX_SIZE)
				std::cerr << "位置非法";

			arcs[k][j] = weight;
			arcs[j][k] = weight;
		}
	}

	int locateVex(const T& v) const
	{
		int index = 0;

		while (vexs[index] != v && index < GRAPH_MAX_SIZE)
		{
			index++;
		}

		if (index == GRAPH_MAX_SIZE)
			return -1;

		return index;
	}

	void DFS() const
	{
		int* visit = new int[vexnum] {0};

		for (int i = 0; i < vexnum; i++)//保证非连通图也能够完成遍历
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

		for (int i = 0; i < vexnum; i++)//保证非连通图也能够完成遍历
		{
			if (visit[i] == 0)
			{
				std::cout << vexs[i] << " ";
				queue.enQueue(i);
				visit[i] = 1;

				while (!queue.isEmpty())
				{
					int value = 0;
					queue.deQueue(value);

					for (int j = 0; j < vexnum; j++)//遍历二维数组里出队顶点的这一行
					{
						if (visit[j] == 0 && arcs[value][j] != 0)//未被访问，且与出队顶点邻接
						{
							std::cout << vexs[j] << " ";
							queue.enQueue(j);
							visit[j] = 1;
						}
					}
				}
			}
		}

		delete[] visit;
	}

	void print() const
	{
		std::cout << "-------邻接矩阵-------\n";

		std::cout << "   ";
		for (int i = 0; i < vexnum; i++)
		{
			std::cout << vexs[i] << " ";
		}
		std::cout << std::endl;


		// 打印矩阵
		for (int i = 0; i < vexnum; i++)
		{
			// 打印行标题
			std::cout << vexs[i] << "  ";


			for (int j = 0; j < vexnum; j++)
			{
				std::cout << arcs[i][j] << " ";
			}

			std::cout << std::endl;
		}
	}
};
#endif // !GRAPH_H
