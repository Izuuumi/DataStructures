// 顺序栈.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "Stack.h"

int main()
{
    Stack<int> stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);

    std::cout << "stack共有" << stack.getLength() << "个元素\n";
    stack.print();

    for (int i = 0; i < 3; i++)
    {
        int value = 0;

        stack.pop(value);

        std::cout << "\n弹出" << value << std::endl;
        stack.print();
    }
}