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
	explicit ListNode(const T& info)
		:data(info),nextPtr(nullptr)
	{

	}

	T getData() const
	{
		return data;
	}
};
#endif // !LISTNOED_H
