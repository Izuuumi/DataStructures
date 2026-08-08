#pragma once
#ifndef SNODE_H
#define SNODE_H

template <typename T> class Stack;

template <typename T>
class SNode
{
	friend class Stack<T>;

private:
	SNode<T>* nextPtr;
	T data;
public:
	SNode(T value)
		:data(value), nextPtr(nullptr)
	{

	}
};
#endif // !SNODE_H
