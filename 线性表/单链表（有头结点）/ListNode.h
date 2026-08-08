#pragma once
#ifndef LISTNODE_H
#define LISTNODE_H

template <typename T> class List;

template <typename T>
class ListNode
{
	friend class List<T>;

private:
	T data;
	ListNode<T>* nextPtr;
public:
	ListNode()
	{
		nextPtr = nullptr;
	}
	ListNode(const T& value)
		: data(value), nextPtr(nullptr)
	{
	}
};
#endif // !LISTNODE_H
