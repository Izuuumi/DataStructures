#pragma once
#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>

constexpr int QUEUE_MAX_SIZE = 5;

template <typename T>
class Queue
{
private:
	int front;
	int rear;//指向队尾元素的下一个空间
	int length;
	T data[QUEUE_MAX_SIZE];
public:
	Queue()
		:front(0), rear(0), length(0)
	{

	}

	bool isEmpty() const
	{
		return front == rear;
	}

	bool isFull() const//牺牲一个存储空间
	{
		return front == (rear + 1) % QUEUE_MAX_SIZE;
	}

	bool enQueue(const T& value)
	{
		if (isFull())
			return false;

		data[rear] = value;
		rear = (rear + 1) % QUEUE_MAX_SIZE;

		return true;
	}

	bool deQueue(T& value)
	{
		if (isEmpty())
			return false;

		value = data[front];
		front = (front + 1) % QUEUE_MAX_SIZE;

		return true;
	}

	void print() const
	{
		int index = front;

		while (index != rear)
		{
			std::cout << data[index] << " ";
			index = (index + 1) % QUEUE_MAX_SIZE;
		}

		std::cout << std::endl;
	}
};
#endif // !QUEUE_H
