#pragma once
#ifndef STRING2_H
#define STRING2_H
#include <iostream>
#include <vector>
//ch[0]存数据
//大致一样，KMP的关键步骤也一样

class String2;
std::vector<int> getNext(const String2&);

class String2
{
private:
	char* ch;
	int length;
public:
	String2()
		:length(0)
	{
		ch = new char[1];
	}

	String2(const char* other)
	{
		length = 0;

		while (other[length] != '\0')
		{
			length++;
		}

		delete[] ch;

		ch = new char[length];

		for (int i = 0; i < length; i++)
		{
			ch[i] = other[i];
		}
	}

	bool isEmpty() const
	{
		return length == 0;
	}

	int getLength() const
	{
		return length;
	}

	String2 getSubString(int pos, int len)
	{
		String2 result;

		if (pos<1 || pos>length || len < 1)
			return result;

		if (len > length - pos + 1)
			len = length - pos + 1;

		result.length = len;

		delete[] result.ch;

		result.ch = new char[len];

		for (int i = 0; i < len; i++)
		{
			result.ch[i] = ch[pos - 1 + i];
		}

		return result;
	}

	String2 concat(const String2& other) const
	{
		String2 result;
		result.length = length + other.length;
		delete[] result.ch;
		result.ch = new char[result.length];

		for (int i = 0; i < length; i++)
			result.ch[i] = ch[i];

		for (int i = 0; i < other.length; i++)
			result.ch[length + i] = other.ch[i];

		return result;
	}

	int index_BF(const String2& sub) const
	{
		int i = 0;
		int j = 0;

		while (i < length && j < sub.length)
		{
			if (ch[i] == sub.ch[j])
			{
				i++;
				j++;
			}
			else
			{
				i = i - j + 1;//不同
				j = 0;
			}
		}

		if (j >= sub.length)
			return i - sub.length + 1;//不同

		return -1;
	}

	int index_KMP(const String2& other) const
	{
		std::vector<int> next = getNext(other);

		int i = 0;//从零开始
		int j = 0;

		while (i < length && j < other.length)
		{
			if (ch[i] == other.ch[j])
			{
				i++;
				j++;
			}
			else if(j > 0)
			{
				j = next[j];
			}
			else//j == 0 && ch[i] != other.ch[j], 此时i移到下一位
			{
				i++;
			}
		}

		if (j >= other.length)
			return i - other.length + 1;

		return -1;
	}

	char operator[](int index) const
	{
		return ch[index];
	}

	char& operator[](int index)
	{
		return ch[index];
	}

	void print() const
	{
		for (int i = 0; i < length; i++)
			std::cout << ch[i];

		std::cout << std::endl;
	}

	~String2()
	{
		delete[] ch;
	}
};

std::vector<int> getNext(const String2& sub)
{
	int size = sub.getLength();

	std::vector<int> next(size);

	next[0] = 0;
	next[1] = 0;//不同

	int compare = 0;
	int current = 2;

	while (current < size)
	{
		if (sub[current - 1] == sub[compare])
		{
			next[current] = compare + 1;
			current++;
			compare++;
		}
		else if(compare > 0)
		{
			compare = next[compare];
		}
		else
		{
			next[current++] = 0;//不同
		}
	}

	return next;
}

#endif // !STRING2_H
