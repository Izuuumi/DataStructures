#pragma once
#ifndef NODE_H
#define NODE_H

template <typename T> class Queue;

template <typename T>
class Node
{
	friend class Queue<T>;

private:
	Node<T>* nextPtr;
	T data;
public:
	Node()
		:nextPtr(nullptr)
	{

	}

	Node(const T& value)
		:data(value), nextPtr(nullptr)
	{

	}
};
#endif // !NODE_H
