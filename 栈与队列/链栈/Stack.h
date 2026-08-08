#pragma once
#ifndef STACK_H
#define STACK_H
#include "Node.h"
#include <iostream>

template <typename T>
class Stack
{
private:
	Node<T>* headPtr;
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
		Node<T>* currentPtr = headPtr;

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
		Node<T>* newNode = new Node<T>(value);

		newNode->nextPtr = headPtr;
		headPtr = newNode;
	}

	bool pop(T& value)
	{
		if (isEmpty())
			return false;

		Node<T>* tempPtr = headPtr;

		value = headPtr->data;
		headPtr = headPtr->nextPtr;

		delete tempPtr;

		return true;
	}

	void print() const
	{
		Node<T>* currentPtr = headPtr;

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
			Node<T>* tempPtr = headPtr;
			headPtr = headPtr->nextPtr;
			delete tempPtr;
		}
	}
};
#endif // ! STACK_H
