#pragma once
#ifndef QUEUE_H
#define QUEUE_H
#include "Node.h"
#include <iostream>

template<typename T>
class Queue
{
private:
	Node<T>* front;
	Node<T>* rear;
	int length;
public:
	Queue()
		:length(0)
	{
		front = new Node<T>();
		rear = front;
	}

	bool isEmpty() const
	{
		return rear == front;
	}

	void enQueue(const T& value)
	{
		Node<T>* newNode = new Node<T>(value);

		rear->nextPtr = newNode;
		rear = newNode;

		length++;
	}

	bool deQueue(T& value)
	{
		if (isEmpty())
			return false;

		value = front->nextPtr->data;
		Node<T>* tempPtr = front->nextPtr;
		front->nextPtr = tempPtr->nextPtr;

		if (rear == tempPtr)//防止删除tempPtr后rear变成悬空指针
			rear = front;

		delete tempPtr;
		length--;

		return true;
	}

	int getLength() const
	{
		return length;
	}

	void print() const
	{
		Node<T>* currentPtr = front->nextPtr;

		for (int i = 0; i < getLength(); i++)
		{
			std::cout << currentPtr->data << " ";
			currentPtr = currentPtr->nextPtr;
		}

		std::cout << std::endl;
	}

	~Queue()
	{
		while (front != nullptr)
		{
			Node<T>* tempPtr = front;
			front = front->nextPtr;
			delete tempPtr;
		}
	}
};
#endif // !QUEUE_H
