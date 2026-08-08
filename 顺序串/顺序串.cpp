// 顺序串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "String.h"
#include "String2.h"

int main()
{
	String2 S("abbbcabcacbab");
	String2 T("abcac");

	std::cout << S.index_BF(T);
}

