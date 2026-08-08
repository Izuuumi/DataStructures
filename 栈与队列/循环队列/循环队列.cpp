// 循环队列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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

    queue.print();

    if (!queue.isFull())
        queue.enQueue(5);

    queue.print();

    int value = 0;
    queue.deQueue(value);

    queue.enQueue(5);
    queue.print();
}
