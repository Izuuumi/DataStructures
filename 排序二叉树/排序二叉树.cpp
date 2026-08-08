// 排序二叉树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "BinarySortTree.h"

int main()
{
    BinarySortTree<int> tree(0);


    std::cout << "\n当前二叉树（中序）: ";
    tree.inTraverse();

    std::cout << "\n输入想要移除的数据: ";
    int value;
    std::cin >> value;

    if (tree.remove(value))
    {
        std::cout << "成功移除." << std::endl;
        std::cout << "当前二叉树: ";
        tree.inTraverse();
    }
    else
        std::cout << "移除失败." << std::endl;

    return 0;
}
