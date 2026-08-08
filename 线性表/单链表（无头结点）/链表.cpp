// 链表.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "List.h"

using namespace std;

int main()
{
	List<int> list;

	cout << "现在你可以添5个数: \n";
	for (int i = 0; i < 5; i++)
	{
		int num;
		cout << '?';
		cin >> num;
		list.insertAtFront(num);
	}

	list.print();

	int pos = 0;
	int value;

	cout << "您可以随意添加：";
	cin >> pos >> value;
	list.insert(pos, value);

	cout << "完成:\n";
	list.print();

	system("pause");
}
/*void instruction()
{
	cout << "Enter onr of the following:\n"
		<< "1 to insert at beginning of the list\n"
		<< "2 to insert at the end of the list\n"
		<< "3 to delete from beginning of the list\n"
		<< "4 to delete from end of the list\n"
		<< "5 to end list processing\n";
}

template<typename T>
void testlist(List<T>& listobject, const string& typeName)
{
	cout << "Testing a list of " << typeName << " values\n";
	instruction();

	int choice;
	T value;

	do
	{
		cout << '?';
		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "Enter " << typeName << " : ";
			cin >> value;
			listobject.insertAtFront(value);
			listobject.print();
			break;
		case 2:
			cout << "Enter " << typeName << " : ";
			cin >> value;
			listobject.insertAtBack(value);
			listobject.print();
			break;
		case 3:
			if (listobject.removeFromFront(value))
				cout << value << " removed from list\n";
			listobject.print();
			break;
		case 4:
			if (listobject.removeFromBack(value))
				cout << value << " removed from list\n";
			listobject.print();
			break;
		}
	} while (choice < 5);

	cout << "End list test\n";
}

int main()
{
	List<int> integerList;
	testlist(integerList, "integer");

	return 0;
}*/