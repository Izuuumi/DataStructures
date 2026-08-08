#pragma once
#ifndef SEQLIST_H
#define SEQLIST_H

#include <iostream>
#include <stdexcept>
using namespace std;

const int maxSize = 100;

template <typename T>
class SeqList
{
private:
	T elem[maxSize];
	int length;
public:
	SeqList()
	{
		length = 0;
	}
	int getLength() const
	{
		return length;
	}
	void clear()
	{
		length = 0;
	}
	bool isEmpty() const
	{
		return length == 0;
	}
	T get(int pos) const
	{
		if (pos > length || pos < 1)
		{
			throw out_of_range("位置非法");
		}
		
		return elem[pos - 1];
	}
	int locate(T tar) const
	{
		for (int i = 0; i < length; i++)
		{
			if (elem[i] == tar)
				return i + 1;
		}

		return -1;
	}
	bool insert(int pos, T value)
	{
		if (pos > length + 1 || pos < 1)
			return false;

		for (int i = length; i>=pos; i--)
		{
			elem[i] = elem[i - 1];
		}

		elem[pos - 1] = value;
		length++;

		return true;
	}
	bool remove(int pos)
	{
		if (pos > length || pos < 1)
			return false;

		for (int i = pos - 1; i < length - 1; i++)
			elem[i] = elem[i + 1];

		length--;
		return true;
	}
	SeqList<T> merge(const SeqList<T>& other)//有序表合并
	{
		SeqList<T> result;

		int i = 0;
		int j = 0;

		while (i < getLength() && j < other.getLength())
		{
			if (elem[i] <= other.elem[j])
				result.elem[result.length++] = elem[i++];
			else
				result.elem[result.length++] = other.elem[j++];
		}

		while (i < getLength())
		{
			result.elem[result.length++] = elem[i++];
		}

		while (j < other.getLength())
		{
			result.elem[result.length++] = other.elem[j++];
		}

		return result;
	}
	void print() const
	{
		for (int i = 0; i < length; i++)
		{
			cout << elem[i]<<" ";
		}
		cout << endl;
	}
};
#endif // !SEQLIST_H
