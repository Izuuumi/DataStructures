#pragma once
#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "ListNode.h"

template<typename T>
class List
{
private:
	ListNode<T>* firstPtr;
	ListNode<T>* lastPtr;

	ListNode<T>* getNewNode(const T& value)
	{
		return new ListNode<T>(value);
	}

	void printBackwardHelper(ListNode<T>* currentPtr)
	{
		if (currentPtr == nullptr)
			return;

		printBackwardHelper(currentPtr->nextPtr);
		std::cout << currentPtr->data << ' ';
	}

	ListNode<T>* searchHelper(ListNode<T>* currentPtr, T& value)
	{
		if (currentPtr == nullptr)
			return nullptr;

		if (currentPtr->data == value)
			return currentPtr;

		return searchHelper(currentPtr->nextPtr, value);
	}

public:
	List()
		:firstPtr(nullptr), lastPtr(nullptr)
	{

	}
	void insertAtFront(const T& value)
	{
		ListNode<T>* newPtr = getNewNode(value);

		if (isEmpty())
		{
			firstPtr = lastPtr = newPtr;
		}
		else
		{
			newPtr->nextPtr = firstPtr;//让新创建的节点指向旧的第一个节点, 即添在最前面
			firstPtr = newPtr;//新节点成为新的第一个节点
		}
	}
	void insertAtBack(const T& value)
	{
		ListNode<T>* newPtr = getNewNode(value);

		if (isEmpty())
		{
			firstPtr = lastPtr = newPtr;
		}
		else
		{
			lastPtr->nextPtr = newPtr;
			lastPtr = newPtr;
		}
	}
	bool removeFromFront(T& value)//传地址是为了能够保存被删除的元素
	{
		if (isEmpty())//如果是空的，则删除失败
		{
			return false;
		}
		else
		{
			ListNode<T>* tempPtr = firstPtr;//先把原本链表头的地址记录下来

			if (firstPtr == lastPtr)
				firstPtr = lastPtr = nullptr;//就一个元素，删完就空了
			else
				firstPtr = firstPtr->nextPtr;//链表头的指针指向原本的第二个，成为了新的第一个

			value = tempPtr->data;//保存被删除的元素
			delete tempPtr;
			return true;
		}
	}
	bool removeFromBack(T& value)
	{
		ListNode<T>* tempPtr = lastPtr;

		if (isEmpty())
		{
			return false;
		}
		else
		{
			if (firstPtr == lastPtr)
				firstPtr = lastPtr = nullptr;
			else
			{
				ListNode<T>* currentPtr = firstPtr;//从链表头开始遍历，直到找到倒数第二个节点
				while (currentPtr->nextPtr != lastPtr)
				{
					currentPtr = currentPtr->nextPtr;
				}

				lastPtr = currentPtr;
				currentPtr->nextPtr = nullptr;//成为新的链表尾
			}

			value = tempPtr->data;
			delete tempPtr;
			return true;
		}
	}
	bool isEmpty() const
	{
		return firstPtr == nullptr;
	}
	void print() const
	{
		if (isEmpty())
		{
			std::cout << "The list is empty.\n";
			return;
		}
		
		ListNode<T>* currentPtr = firstPtr;

		std::cout << "The list is: ";

		while (currentPtr != nullptr)
		{
			std::cout << currentPtr->data << ' ';
			currentPtr = currentPtr->nextPtr;
		}

		std::cout << "\n\n";
	}
	void printListBackward() const//逆向打印
	{
		printBackwardHelper(firstPtr);
		std::cout << std::endl;
	}
	ListNode<T>* searchList(T& value) //寻找特定值
	{
		return searchHelper(firstPtr, value);
	}
	void insert(int pos, T& value)//在任意位置插入，其中pos从0开始，即firstPtr的pos是0
	{
		ListNode<T>* newNode = getNewNode(value);

		if (pos == 0)
		{
			insertAtFront(value);
		}

		ListNode<T>* currentPtr = firstPtr;
		int index = 0;

		while (currentPtr->nextPtr != nullptr && index < pos - 1)//找到目标位置的前一个节点
		{
			currentPtr = currentPtr->nextPtr;
			index++;
		}

		newNode->nextPtr = currentPtr->nextPtr;
		currentPtr->nextPtr = newNode;

		if (newNode->nextPtr == nullptr)
			lastPtr = newNode;
	}
	void remove(int pos, T& value)
	{
		if (pos == 0)
		{
			removeFromFront(value);
		}

		ListNode<T>* currentPtr = firstPtr;
		int index = 0;

		while (currentPtr->nextPtr != nullptr && index < pos - 1)//找到目标位置的前一个节点
		{
			currentPtr = currentPtr->nextPtr;
			index++;
		}

		ListNode<T>* removeNode = currentPtr->nextPtr;
		value = removeNode->data;
		currentPtr->nextPtr = removeNode->nextPtr;

		if (removeNode->nextPtr == nullptr)
			lastPtr = currentPtr;

		delete removeNode;
	}
	~List()
	{
		if (!isEmpty())
		{
			std::cout << "Destorying nodes ...\n";

			ListNode<T>* currentPtr = firstPtr;
			ListNode<T>* tempPtr = nullptr;

			while (currentPtr != nullptr)
			{
				tempPtr = currentPtr;
				std::cout << tempPtr->data << '\n';
				currentPtr = currentPtr->nextPtr;
				delete tempPtr;
			}
		}

		std::cout << "All nodes destroyed\n\n";
	}
};

#endif // !LIST_H