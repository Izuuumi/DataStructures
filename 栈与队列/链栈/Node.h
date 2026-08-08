#pragma once
#ifndef NODE_H
#define NODE_H

template <typename T> class Stack;

template <typename T>
class Node
{
	friend class Stack<T>;

private:
	Node<T>* nextPtr;
	T data;
public:
	Node(T value)
		:data(value),nextPtr(nullptr)
	{
		
	}
};
#endif // !NODE_H
