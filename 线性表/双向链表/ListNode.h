#pragma once
#ifndef LISTNODE_H
#define LISTNODE_H

template <typename T> class DoubleList;

template <typename T>
class ListNode
{
	friend class DoubleList<T>;

private:
	T data;
	ListNode<T>* priorPtr;
	ListNode<T>* nextPtr;
public:
	ListNode()
	{
		priorPtr = nullptr;
		nextPtr = nullptr;
	}

	ListNode(const T& value)
	{
		data = value;
		priorPtr = nullptr;
		nextPtr = nullptr;
	}
};
#endif // !LISTNODE_H
