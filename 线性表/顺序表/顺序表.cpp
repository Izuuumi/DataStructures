// 顺序表.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "SeqList.h"

int main()
{
    SeqList<int> list1;
    SeqList<int> list2;

    list1.insert(1, 1);
    list1.insert(2, 3); 
    list1.insert(3, 7);
    list1.insert(4, 67);

    list2.insert(1, 2);
    list2.insert(2, 3);
    list2.insert(3, 10);


    std::cout << "List1: \n";
    list1.print();

    std::cout << "List2: \n";
    list2.print();

    SeqList<int> list3 = list1.merge(list2);

    std::cout << "\n合并后: \n";
    list3.print();

    return 0;
}
