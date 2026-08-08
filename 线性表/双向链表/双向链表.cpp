// 双向链表.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "DoubleList.h"

using namespace std;

int main()
{
	DoubleList<int> list;
	list.insertAtFront(40);
	list.insertAtFront(30);
	list.insertAtFront(20);
	list.insertAtFront(10);

	list.print();

	list.remove(2);
	list.remove(2);

	list.print();

	list.insert(2, 1000);

	list.print();
}
