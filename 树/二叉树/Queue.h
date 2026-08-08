#pragma once
#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>

const int maxSize = 100;

template <typename T>
class Queue
{
private:
	int front;
	int rear;
	int length;
	T data[maxSize];
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
		return front == (rear + 1) % maxSize;
	}

	bool enQueue(const T& value)
	{
		if (isFull())
			return false;

		data[rear] = value;
		rear = (rear + 1) % maxSize;

		return true;
	}

	bool deQueue(T& value)
	{
		if (isEmpty())
			return false;

		value = data[front];
		front = (front + 1) % maxSize;

		return true;
	}

	void print() const
	{
		int index = front;

		while (index != rear)
		{
			std::cout << data[index] << " ";
			index = (index + 1) % maxSize;
		}

		std::cout << std::endl;
	}
};
#endif // !QUEUE_H
