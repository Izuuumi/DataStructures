// 二叉树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "BinaryTree.h"

int main()
{
	BinaryTree<int> BiTree(0);

	std::cout << "\n初始化后的二叉树(中序): ";
	BiTree.inTraverse();

	std::cout << "\n输入要查找的数据: ";
	int key = 0;
	std::cin >> key;

	Node<int>* position = BiTree.searchBST(key);
	
	if (position)
		std::cout << "\n所找元素的位置为: " << position <<std::endl;
	else
		std::cout << "\n未找到元素." << std::endl;

	return 0;
}
