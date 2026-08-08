#pragma once
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

const int maxSize = 100;

template <typename T>
class Queue
{
private:
	T data[maxSize];
	int front;
	int back;
	int length;
public:
	Queue()
		:front(0), back(0), length(0)
	{

	}

	bool isEmpty() const
	{
		return front == back;
	}

	bool isFull() const
	{
		return front == maxSize;
	}

	int getLength() const
	{
		return front - back;
	}

	bool getHead(T& value) const
	{
		if (isEmpty())
			return false;

		value = data[front - 1];

		return true;
	}

	bool enQueue(const T& value)
	{
		if (isFull())
			return false;

		for (int i = front; i > 0; i--)
			data[i] = data[i - 1];

		front++;

		data[back] = value;

		return true;
	}

	bool deQueue(T& value)
	{
		if (isEmpty())
			return false;

		value = data[front - 1];
		front--;

		return true;
	}

	void print() const
	{
		for (int i = 0; i < getLength(); i++)
			std::cout << data[i] << " ";

		std::cout << std::endl;
	}

	void clear()
	{
		front = 0;
	}
};
#endif // !QUEUE_H
