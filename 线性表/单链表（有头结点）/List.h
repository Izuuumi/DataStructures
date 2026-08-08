#pragma once
#ifndef  LIST_H
#define LIST_H
#include "ListNode.h"
#include<iostream>

template <typename T>
class List
{
private:
	ListNode<T>* headPtr;
public:
	List()
	{
		headPtr = new ListNode<T>();
	}

	bool isEmpty() const
	{
		return headPtr->nextPtr == nullptr;
	}

	void clear()//清空链表
	{
		ListNode<T>* currentPtr = headPtr->nextPtr;//首元节点

		while (currentPtr != nullptr)
		{
			ListNode<T>* tempPtr = currentPtr;
			currentPtr = currentPtr->nextPtr;
			delete tempPtr;
		}

		headPtr->nextPtr = nullptr;//防止头结点的nextPtr成为悬空指针
	}

	int getLength() const//获取表长
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

	void insertAtFront(const T& value)
	{
		ListNode<T>* newNode = new ListNode<T>(value);

		newNode->nextPtr = headPtr->nextPtr;
		headPtr->nextPtr = newNode;
	}

	void insertAtBack(const T& value)
	{
		ListNode<T>* newNode = new ListNode<T>(value);

		ListNode<T>* currentPtr = headPtr;

		while (currentPtr->nextPtr != nullptr)
			currentPtr = currentPtr->nextPtr;

		currentPtr->nextPtr = newNode;
	}

	bool insert(int pos, const T& value)//将某个元素插在第pos个位置上
	{
		if (pos <1 || pos>getLength() + 1)
			return false;

		if (pos == getLength() + 1)
		{
			insertAtBack(value);
			return true;
		}
			
		ListNode<T>* currentPtr = headPtr;
		ListNode<T>* newNode = new ListNode(value);

		for (int i = 1; i < pos; i++)//找到pos-1的结点
		{
			currentPtr = currentPtr->nextPtr;
		}

		newNode->nextPtr = currentPtr->nextPtr;
		currentPtr->nextPtr = newNode;

		return true;
	}

	bool removeFront()
	{
		if (isEmpty())
			return false;

		ListNode<T>* temp = headPtr->nextPtr;//首元节点

		headPtr->nextPtr = temp->nextPtr;
		delete temp;

		return true;
	}

	bool remove(int pos)
	{
		if (isEmpty() || pos < 1)
			return false;

		ListNode<T>* currentPtr = headPtr->nextPtr;

		int currentPos = 1;

		while (currentPos < pos - 1)//找到第pos-1个节点
		{
			if (currentPtr->nextPtr == nullptr)//说明pos越界了
				return false;


			currentPtr = currentPtr->nextPtr;
			currentPos++;
		}

		ListNode<T>* tempPtr = currentPtr->nextPtr;//要删除的节点

		currentPtr->nextPtr = tempPtr->nextPtr;

		delete tempPtr;
		return true;
	}

	bool get(int pos, T& value)//取值
	{
		if (pos < 1)
			return false;

		ListNode<T>* currentPtr = headPtr->nextPtr;

		for (int i = 0; i < pos; i++)//直接找到第pos个节点
		{
			if (currentPtr == nullptr)
				return false;

			currentPtr = currentPtr->nextPtr;
		}

		if (currentPtr == nullptr)
			return false;

		value = currentPtr->data;

		return true;
	}

	ListNode<T>* searchLoc(const T& value) const//按值查找，返回节点地址
	{
		ListNode<T>* currentPtr = headPtr->nextPtr;

		while (currentPtr != nullptr)
		{
			if (currentPtr->data == value)
				return currentPtr;

			currentPtr = currentPtr->nextPtr;
		}

		return nullptr;
	}

	int searchPos(const T& value) const//按值查找，返回目标值在表中的位置
	{
		ListNode<T>* currentPtr = headPtr->nextPtr;
		int pos = 1;

		while (currentPtr != nullptr)
		{
			if (currentPtr->data == value)
				return pos;

			currentPtr = currentPtr->nextPtr;
			pos++;
		}

		return -1;
	}

	void print() const
	{
		ListNode<T>* currentPtr = headPtr->nextPtr;

		while (currentPtr != nullptr)
		{
			std::cout << currentPtr->data << ' ';
			currentPtr = currentPtr->nextPtr;
		}

		std::cout << std::endl;
	}

	List<T> merge(List<T>& other)//有序表合并
	{
		List<T> result;

		ListNode<T>* a_ptr = headPtr->nextPtr;
		ListNode<T>* b_ptr = other.headPtr->nextPtr;

		ListNode<T>* c_ptr = result.headPtr;

		while (a_ptr != nullptr && b_ptr != nullptr)
		{
			if (a_ptr->data <= b_ptr->data)
			{
				c_ptr->nextPtr = a_ptr;
				a_ptr = a_ptr->nextPtr;
			}
			else
			{
				c_ptr->nextPtr = b_ptr;
				b_ptr = b_ptr->nextPtr;
			}

			c_ptr = c_ptr->nextPtr;
		}

		c_ptr->nextPtr = a_ptr ? a_ptr : b_ptr;

		headPtr->nextPtr = nullptr;
		other.headPtr->nextPtr = nullptr;
		/* 原有的两个链表结构被破坏，原链表头结点的 nextPtr 与 result 头结点的 nextPtr 指向同一组数据节点，
		   导致多个链表同时拥有这些节点的管理权。析构时会重复释放同一片内存，造成程序崩溃。*/
        // 因此需要将原有两个链表头结点的 nextPtr 置为空指针，使其放弃对这些节点的管理。

		return result;
	}

	~List()//销毁链表，连头结点也要销毁
	{
		while (headPtr != nullptr)
		{
			ListNode<T>* tempPtr = headPtr;
			headPtr = headPtr->nextPtr;
			delete tempPtr;
		}
	}
};
#endif // ! LIST_H
