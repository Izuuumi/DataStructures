#pragma once
#ifndef DOUBLELIST_H
#define DOUBLELIST_H
#include "ListNode.h"

template <typename T>
class DoubleList
{
private:
	ListNode<T>* headPtr;
public:
	DoubleList()
	{
		headPtr = new ListNode<T>();//创造头结点
	}

	bool isEmpty() const
	{
		return headPtr->nextPtr == nullptr;
	}

	void insertAtFront(const T& value)
	{
		ListNode<T>* newNode = new ListNode<T>(value);

		newNode->nextPtr = headPtr->nextPtr;
		newNode->priorPtr = headPtr;

		if (headPtr->nextPtr != nullptr)
			headPtr->nextPtr->priorPtr = newNode;//如果不是空，就让原本的第一个结点指向newNode

		headPtr->nextPtr = newNode;//一定是在判空之后再指向newNode
	}

	void insertAtBack(const T& value)
	{
		ListNode<T>* newNode = new ListNode<T>(value);
		ListNode<T>* currentPtr = headPtr;

		while (currentPtr->nextPtr != nullptr)//找到最后一个结点
		{
			currentPtr = currentPtr->nextPtr;
		}

		currentPtr->nextPtr = newNode;
		newNode->priorPtr = currentPtr;
	}

	bool insert(int pos, const T& value)
	{
		if (pos < 1)
			return false;

		if (pos == 1)
		{
			insertAtFront(value);
			return true;
		}

		if (pos == getLength() + 1)
		{
			insertAtBack(value);
			return true;
		}

		ListNode<T>* newNode = new ListNode<T>(value);
		ListNode<T>* currentPtr = headPtr;

		for (int i = 0; i < pos; i++)//找到第pos个结点
		{
			if (currentPtr->nextPtr == nullptr)
				return false;

			currentPtr = currentPtr->nextPtr;
		}

		currentPtr->priorPtr->nextPtr = newNode;
		newNode->priorPtr = currentPtr->priorPtr;
		currentPtr->priorPtr = newNode;
		newNode->nextPtr = currentPtr;

		return true;
	}

	bool remove(int pos)
	{
		if (pos < 1 || pos > getLength())
			return false;

		ListNode<T>* currentPtr = headPtr;

		for (int i = 0; i < pos; i++)//找到第pos个结点
		{
			if (currentPtr->nextPtr == nullptr)
				return false;

			currentPtr = currentPtr->nextPtr;
		}

		currentPtr->priorPtr->nextPtr = currentPtr->nextPtr;
		currentPtr->nextPtr->priorPtr = currentPtr->priorPtr;

		delete currentPtr;

		return true;
	}

	int getLength() const
	{
		int length = 0;

		if (isEmpty())
			return length;

		ListNode<T>* currentPtr = headPtr;

		while (currentPtr->nextPtr != nullptr)
		{
			currentPtr = currentPtr->nextPtr;
			length++;
		}

		return length;
	}

	void print() const
	{
		ListNode<T>* currentPtr = headPtr->nextPtr;

		for (int i = 0; i < getLength(); i++)
		{
			std::cout << currentPtr->data << " ";
			currentPtr = currentPtr->nextPtr;
		}

		std::cout << std::endl;
	}

	~DoubleList()
	{
		while (headPtr != nullptr)
		{
			ListNode<T>* currentPtr = headPtr;
			headPtr = headPtr->nextPtr;
			delete currentPtr;
		}
	}
};
#endif // !DOUBLELIST_H
