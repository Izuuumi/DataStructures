// 链栈.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "Stack.h"

int main()
{
    Stack<int> stack;

    stack.push(1);
    stack.push(3);
    stack.push(5);
    stack.push(7);
    stack.push(9);

    std::cout << "当前的Stack: \n";
    stack.print();
    std::cout << "Stack的长度: " << stack.getLength() << std::endl;

    for (int i = 0; i < 3; i++)
    {
        int value = 0;
        stack.pop(value);
        std::cout << "弹出: " << value << std::endl;
        std::cout << "当前的Stack: ";
        stack.print();
    }
}
