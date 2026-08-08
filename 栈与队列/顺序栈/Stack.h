#pragma once
#ifndef STACK_H
#define STACK_H
#include <iostream>

const int maxSize = 100;

template <typename T>
class Stack
{
private:
	T data[maxSize];
	int top;
	int base;
	int stackSize;
public:
	Stack()
		:top(0), base(0), stackSize(0)
	{

	}

	bool isEmpty() const
	{
		return top == base;
	}

	bool isFull() const
	{
		return top - base == maxSize;
	}

	int getLength() const
	{
		return top - base;
	}

	T get() const
	{
		return data[top];
	}

	bool push(const T& value)
	{
		if (isFull())
			return false;

		data[top++] = value;
		
		return true;
	}

	bool pop(T& value)
	{
		if (isEmpty())
			return false;

		value = data[top - 1];
		top--;

		return true;
	}

	void clear()
	{
		top = 0;
	}

	void print() const
	{
		for (int i = 0; i < top; i++)
			std::cout << data[i] << " ";

		std::cout << std::endl;
	}

};
#endif // !STACK_H
