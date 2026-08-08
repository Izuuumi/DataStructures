// 哈夫曼.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "BinaryTree.h"

int main()
{
    int num;

    std::cout << "请输入节点数: ";
    std::cin >> num;

    BinaryTree tree(num);

    tree.createHuffmanTree();

    tree.print();


    char** huffmanCode = nullptr;
    tree.createHuffmanCode(huffmanCode);

    for (int i = 1; i <= num; i++)
    { 
        std::cout << huffmanCode[i] << std::endl;
    }

    for (int i = 1; i <= num; i++)
    {
        delete[] huffmanCode[i];
    }

    delete[] huffmanCode;
}
