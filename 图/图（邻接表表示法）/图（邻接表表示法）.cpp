// 图（邻接表表示法）.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "Graph.h"
using namespace std;

int main()
{
	Graph<char> graph(8, 9);

	graph.print();

	std::cout << "DFS遍历结果: ";
	graph.DFS();

	std::cout << "\nBFS遍历结果: ";
	graph.BFS();

	return 0;
}
