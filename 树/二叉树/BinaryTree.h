#pragma once
#ifndef BINAEYTREE_H
#define BINARYTREE_H
#include <iostream>
#include "Node.h"
#include "Stack.h"
#include "Queue.h"

template <typename T>
class BinaryTree
{
public:
	BinaryTree(const T& empty)
	{
		tPtr = create(empty);
	}

	BinaryTree(const BinaryTree& other)
	{
		tPtr = new Node<T>(other.tPtr->data);

		tPtr = copyHelp(other.tPtr);
	}

	int getDepth() const
	{
		if (tPtr == nullptr)
			return 0;

		return depthHelp(tPtr);
	}

	int getNodeCount() const
	{
		if (tPtr == nullptr)
			return 0;

		return countHelp(tPtr);
	}

	int getLeafCount() const
	{
		if (tPtr == nullptr)
			return 0;

		return leafHelp(tPtr);
	}

	void preTraverse() const
	{
		preOrder(tPtr);
		std::cout << std::endl;
	}

	void inTraverse() const
	{
		inOrder(tPtr);
		std::cout << std::endl;
	}

	void inTraverse_stack() const//无需递归，借助栈
	{
		Stack<Node<T>*> stack;

		Node<T>* p = tPtr;//指向现在的结点
		Node<T>* q = nullptr;//用来存弹出的结点

		while (p || !stack.isEmpty())
		{
			if (p)//不空就入栈
			{
				stack.push(p);
				p = p->lchild;
			}
			else
			{
				stack.pop(q);
				std::cout << q->data << " ";
				p = q->rchild;
			}
		}

		std::cout << std::endl;
	}

	void postTraverse() const
	{
		postOrder(tPtr);
		std::cout << std::endl;
	}

	void levelOrder() const
	{
		Queue<Node<T>*> queue;
		Node<T>* ptr;

		queue.enQueue(tPtr);

		while (!queue.isEmpty())
		{
			queue.deQueue(ptr);
			std::cout << ptr->data << " ";

			if (ptr->lchild)
				queue.enQueue(ptr->lchild);

			if (ptr->rchild)
				queue.enQueue(ptr->rchild);
		}

		std::cout << std::endl;
	}

	Node<T>* searchBST(T key) const//二叉排序树查找
	{
		return BTShelp(tPtr, key);
	}

	~BinaryTree()
	{
		destory(tPtr);
	}

private:
	Node<T>* tPtr;

	Node<T>* create(const T& empty)//先序创建
	{
		T value;

		std::cout << "输入结点值: " << std::endl;
		std::cin >> value;

		if (value == empty)
			return nullptr;

		else
		{
			Node<T>* newNode = new Node<T>(value);

			newNode->lchild = create(empty);
			newNode->rchild = create(empty);

			return newNode;
		}
	}

	Node<T>* copyHelp(Node<T>* other)
	{
		if (other == nullptr)
			return nullptr;

		Node<T>* newNode = new Node<T>(other->data);
		
		newNode->lchild = copyHelp(other->lchild);
		newNode->rchild = copyHelp(other->rchild);

		return newNode;
	}

	int depthHelp(Node<T>* p) const
	{
		if (p == nullptr)
			return 0;

		int m = depthHelp(p->lchild);
		int n = depthHelp(p->rchild);

		if (m > n)
			return m + 1;
		else
			return n + 1;
	}

	int countHelp(Node<T>* p) const
	{
		if (p == nullptr)
			return 0;

		return countHelp(p->lchild) + countHelp(p->rchild) + 1;
	}

	int leafHelp(Node<T>* p) const
	{
		if (p == nullptr)
			return 0;

		if (p->lchild == nullptr && p->rchild == nullptr)
			return 1;

		else
			return leafHelp(p->lchild) + leafHelp(p->rchild);
	}

	void preOrder(const Node<T>* ptr) const//先序遍历
	{
		if (ptr == nullptr)
			return;

		std::cout << ptr->data << " ";
		preOrder(ptr->lchild);
		preOrder(ptr->rchild);
	}

	void inOrder(const Node<T>* ptr) const//中序遍历
	{
		if (ptr == nullptr)
			return;

		inOrder(ptr->lchild);
		std::cout << ptr->data << " ";
		inOrder(ptr->rchild);
	}

	void postOrder(const Node<T>* ptr) const//后序遍历
	{
		if (ptr == nullptr)
			return;

		postOrder(ptr->lchild);
		postOrder(ptr->rchild);
		std::cout << ptr->data << " ";
	}

	Node<T>* BTShelp(Node<T>* ptr, T key) const
	{
		if (ptr == nullptr)
			return nullptr;

		if (ptr->data == key)
			return ptr;

		if (key < ptr->data)
			return BTShelp(ptr->lchild, key);
		else if (key >= ptr->data)
			return BTShelp(ptr->rchild, key);
	}

	void destory(Node<T>* ptr)//后序删除
	{
		if (ptr == nullptr)
			return;

		destory(ptr->lchild);
		destory(ptr->rchild);

		delete ptr;
	}
};
#endif // !BINAEYTREE_H
