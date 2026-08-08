#pragma once
#ifndef NODE_H
#define NODE_H

template <typename T> class BinarySortTree;

template <typename T>
class Node
{
	friend class BinarySortTree<T>;

private:
	Node<T>* lchild;
	Node<T>* rchild;
	T data;
public:
	Node()
		:lchild(nullptr), rchild(nullptr)
	{

	}

	Node(const T& d)
		:data(d), lchild(nullptr), rchild(nullptr)
	{

	}
};
#endif // !NODE_H
