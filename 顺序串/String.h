#pragma once
#ifndef STRING_H
#define STRING_H
#include <iostream>
#include <vector>
//ch[0]不存数据

class String;
std::vector<int> getNext(const String& T);

class String
{
private:
	char* ch;
	int length;
public:
	String()
		:length(0)
	{
		ch = new char[1];
	}

	String(const char* other)
	{
		length = 0;

		while (other[length] != '\0')
		{
			length++;
		}

		ch = new char[length + 1];

		for (int i = 0; i < length; i++)
			ch[i + 1] = other[i];
	}

	bool isEmpty() const
	{
		return length == 0;
	}

	int getLength() const
	{
		return length;
	}

	String substring(int pos, int len)
	{
		String result;

		if (pos<1 || pos>getLength() || len <= 0)
			return result;

		if (pos + len - 1 > getLength())
			len = length - pos + 1;

		result.length = len;

		delete[] result.ch;
		result.ch = new char[len + 1];

		for (int i = 0; i < result.length; i++)
			result.ch[i + 1] = ch[pos + i];

		return result;
	}

	String concat(String& other)
	{
		String result;

		result.length = length + other.length;

		delete[] result.ch;
		result.ch = new char[result.length + 1];

		for (int i = 0; i < length; i++)
			result.ch[i + 1] = ch[i + 1];

		for (int i = 0; i < other.length; i++)
			result.ch[length + i + 1] = other.ch[i + 1];

		return result;
	}

	int index_BF(const String& T) const
	{
		int i = 1;
		int j = 1;

		while (i <= length && j <= T.length)
		{
			if (ch[i] == T.ch[j])
			{
				i++;
				j++;
			}

			else
			{
				i = i - j + 2;
				j = 1;
			}
		}

		if (j > T.length)
			return i - T.length;

		return 0;
	}

	int index_KMP(const String& T) const
	{
		std::vector<int> next = getNext(T);

		int i = 1;
		int j = 1;

		while (i <= length && j <= T.length)
		{
			if (ch[i] == T.ch[j])
			{
				i++;
				j++;
			}
			else if(j > 1)
			{
				j = next[j];
			}
			else
			{
				i++;
			}
		}

		if (j > T.length)
			return i - T.length;

		return 0;
	}

	void clear()
	{
		length = 0;
	}

	void print() const
	{
		for (int i = 0; i < getLength(); i++)
			std::cout << ch[i + 1];

		std::cout << std::endl;
	}

	char operator[](int index) const
	{
		return ch[index];
	}

	char& operator[](int index)
	{
		return ch[index];
	}

	~String()
	{
		delete[] ch;
	}
};

std::vector<int> getNext(const String& T)
{
	int size = T.getLength();
	std::vector<int> next(size + 1);

	int current = 3;
	int compare = 1;

	next[1] = 0;
	next[2] = 1;

	while (current <= T.getLength())
	{
		if (T[compare] == T[current - 1])
		{
			next[current] = compare + 1;
			current++;
			compare++;
		}
		else if (compare > 1)//compare可以回退
			compare = next[compare];
		else//compare不能回退
			next[current++] = 1;
	}

	return next;
}

#endif // !STRING_H
