// 链队.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "Queue.h"

int main()
{
	Queue<int> queue;

	queue.enQueue(1);
	queue.enQueue(2);
	queue.enQueue(3);
	queue.enQueue(4);
	queue.enQueue(5);

	std::cout << "当前队列: ";
	queue.print();
	std::cout << "长度为: " << queue.getLength() << std::endl;

	for (int i = 0; i < 3; i++)
	{
		int value = 0;
		queue.deQueue(value);
		std::cout << "删除" << value << std::endl;
		queue.print();
	}

	return 0;
}