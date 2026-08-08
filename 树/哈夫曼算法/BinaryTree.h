#pragma once
#ifndef BINARYTREE_H
#define BINARYTREE_H
#include "Node.h"
#include <iostream>

class BinaryTree
{
private:
	Node* data;
	int nodeCount;
	int leafCount;

	void find(int& s1, int& s2)
	{
		int min1 = INT_MAX;//用来存放最小的权值
		int min2 = INT_MAX;//用来存放第二小的权值

		s1 = s2 = -1;

		for (int i = 1; i < nodeCount + 1; i++)
		{
			if (data[i].parent == 0)//已经有双亲的结点不考虑
			{
				if (data[i].getWeight() < min1)//找到了新的最小
				{
					min2 = min1;//让原本的最小成为第二小
					s2 = s1;

					min1 = data[i].getWeight();//更新最小
					s1 = i;
				}
				else if (data[i].getWeight() < min2)//说明介于最小和第二小之间
				{
					min2 = data[i].getWeight();//更新第二小
					s2 = i;
				}
			}
			else
				continue;
		}
	}

public:
	BinaryTree(const int num)
		:nodeCount(num), leafCount(num)
	{
		data = new Node[2 * nodeCount];

		for (int i = 1; i <= nodeCount; i++)
		{
			int weight = 0;
			std::cout << "请输入结点权值: \n";
			std::cin >> weight;
			data[i].setWeight(weight);
		}
	}

	void createHuffmanTree()
	{
		int n = nodeCount;

		for (int i = n + 1; i < 2 * n; i++)
		{
			int s1 = 0;
			int s2 = 0;

			find(s1, s2);

			data[i].weight = data[s1].weight + data[s2].weight;
			data[i].lchild = s1;
			data[i].rchild = s2;

			data[s1].parent = data[s2].parent = i;

			nodeCount++;
		}
	}

	void createHuffmanCode(char**& HuffmanCode)
	{
		HuffmanCode = new char* [leafCount + 1];
		char* code = new char[leafCount];

		code[leafCount - 1] = '\0';

		for (int i = 1; i <= leafCount; i++)
		{
			int start = leafCount - 1;
			int current = i;
			int p = data[i].parent;

			while (p != 0)
			{
				start--;

				if (data[p].lchild == current)
					code[start] = '0';
				else
					code[start] = '1';

				current = p;
				p = data[p].parent;
			}

			HuffmanCode[i] = new char[leafCount - start];

			strcpy(HuffmanCode[i], &code[start]);
		}

		delete[] code;
	}

	void print() const
	{
		std::cout << "index\tweight\tparent\tlchild\trchild" << std::endl;

		for (int i = 1; i <= nodeCount; i++)
		{
			std::cout << i << "\t" << data[i].weight << "\t" << data[i].parent << "\t" << data[i].lchild << "\t" << data[i].rchild << std::endl;
		}
	}

	~BinaryTree()
	{
		delete[] data;
	}
};

#endif // !BINARYTREE_H

