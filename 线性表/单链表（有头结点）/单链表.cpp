// 单链表.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "List.h"

int main()
{
    List<int> list1;
    List<int> list2;

    list1.insertAtBack(10);
    list1.insertAtBack(20);
    list1.insertAtBack(30);

    list2.insertAtBack(5);
    list2.insertAtBack(10);
    list2.insertAtBack(14);
    list2.insertAtBack(59);

    std::cout << "List1: \n";
    list1.print();

    std::cout << "List2: \n";
    list2.print();

    List<int> list3 = list1.merge(list2);

    std::cout << "合并后: \n";
    list3.print();

    return 0;
}