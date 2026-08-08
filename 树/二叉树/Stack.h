#pragma once
#ifndef STACK_H
#define STACK_H
#include "SNode.h"
#include <iostream>

template <typename T>
class Stack
{
private:
	SNode<T>* headPtr;
public:
	Stack()
		: headPtr(nullptr)
	{

	}

	bool isEmpty() const
	{
		return headPtr == nullptr;
	}

	int getLength() const
	{
		SNode<T>* currentPtr = headPtr;

		int length = 0;

		if (isEmpty())
			return length;

		while (currentPtr != nullptr)
		{
			currentPtr = currentPtr->nextPtr;
			length++;
		}

		return length;
	}

	void push(const T& value)
	{
		SNode<T>* newNode = new SNode<T>(value);

		newNode->nextPtr = headPtr;
		headPtr = newNode;
	}

	bool pop(T& value)
	{
		if (isEmpty())
			return false;

		SNode<T>* tempPtr = headPtr;

		value = headPtr->data;
		headPtr = headPtr->nextPtr;

		delete tempPtr;

		return true;
	}

	void print() const
	{
		SNode<T>* currentPtr = headPtr;

		for (int i = 0; i < getLength(); i++)
		{
			std::cout << currentPtr->data << " ";
			currentPtr = currentPtr->nextPtr;
		}

		std::cout << std::endl;
	}

	~Stack()
	{
		while (headPtr != nullptr)
		{
			SNode<T>* tempPtr = headPtr;
			headPtr = headPtr->nextPtr;
			delete tempPtr;
		}
	}
};
#endif // ! STACK_H