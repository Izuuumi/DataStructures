#pragma once
#ifndef BINARYSORTTREE_H
#define BINARYSORTTREE_H
#include <iostream>
#include "Node.h"

template <typename T>
class BinarySortTree
{
private:
	Node<T>* tPtr;

	void inOrder(const Node<T>* ptr) const
	{
		if (ptr == nullptr)
			return;

		inOrder(ptr->lchild);
		std::cout << ptr->data << " ";
		inOrder(ptr->rchild);
	}

	Node<T>* searchHelp(Node<T>* ptr, T key) const
	{
		if (ptr == nullptr)
			return nullptr;

		if (ptr->data == key)
			return ptr;

		if (key < ptr->data)
			return searchHelp(ptr->lchild, key);
		else if (key > ptr->data)
			return searchHelp(ptr->rchild, key);
	}

	Node<T>* removeHelp(Node<T>* ptr, T key)
	{
		if (ptr == nullptr)
			return nullptr;

		if (key < ptr->data)
			ptr->lchild = removeHelp(ptr->lchild, key);
		else if (key > ptr->data)
			ptr->rchild = removeHelp(ptr->rchild, key);
		else//找到了
		{
			if (ptr->lchild == nullptr && ptr->rchild == nullptr)//是叶子结点
			{
				delete ptr;
				return nullptr;
			}
			else if (ptr->lchild == nullptr)//只有右子树
			{
				Node<T>* temp = ptr->rchild;
				delete ptr;
				return temp;
			}
			else if (ptr->rchild == nullptr)//只有左子树
			{
				Node<T>* temp = ptr->lchild;
				delete ptr;
				return temp;
			}
			else//左右子树都不为空
			{
				Node<T>* successor = ptr->rchild;//successor是ptr的后继结点，即序列中比ptr->data大的后一个结点

				while (successor->lchild)
					successor = successor->lchild;//找到ptr的右子树中最小的结点，所以要一直朝左找

				ptr->data = successor->data;//直接替换值

				ptr->rchild = removeHelp(ptr->rchild, successor->data);//找到并删除ptr的后继结点
			}
		}

		return ptr;
	}

	void destroy(Node<T>* ptr)
	{
		if (ptr == nullptr)
			return;

		destroy(ptr->lchild);
		destroy(ptr->rchild);

		delete ptr;
	}

public:
	BinarySortTree(const T& end)
		:tPtr(nullptr)
	{
		T info;

		while (true)
		{
			std::cout << "输入数据: \n";
			std::cin >> info;

			if (info == end)
				break;

			insert(info);
		}
	}

	bool insert(T data)
	{
		Node<T>* newNode = new Node<T>(data);

		if (isEmpty())
		{
			tPtr = newNode;
			return true;
		}	
		
		Node<T>* parent = nullptr;
		Node<T>* currentPtr = tPtr;

		while (currentPtr)
		{
			parent = currentPtr;

			if (data < currentPtr->data)
				currentPtr = currentPtr->lchild;
			else if (data > currentPtr->data)
				currentPtr = currentPtr->rchild;
			else
			{
				delete newNode;
				return false;
			}
		}

		if (data < parent->data)
			parent->lchild = newNode;
		else
			parent->rchild = newNode;

		return true;
	}

	bool remove(T key)
	{
		if (!search(key))
			return false;

		tPtr = removeHelp(tPtr, key);

		return true;
	}

	Node<T>* search(T key) const
	{
		return searchHelp(tPtr, key);
	}

	bool isEmpty() const
	{
		return tPtr == nullptr;
	}

	void inTraverse() const
	{
		inOrder(tPtr);
		std::cout << std::endl;
	}

	~BinarySortTree()
	{
		destroy(tPtr);
	}
};
#endif // !BINARYSORTTREE_H
