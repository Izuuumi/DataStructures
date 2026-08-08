// 选择排序.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

void selectSort(int* arr, const int length)
{
    for (int i = 0; i < length - 1; i++)
    {
        int k = i;//最小

        for (int j = i + 1; j < length; j++)
        {
            if (arr[j] < arr[k])
                k = j;
        }

        swap(arr[i], arr[k]);
    }
}

int main()
{
    const int length = 6;
    int arr[length] = { 51,2627,125,5742,4,74 };

    selectSort(arr, length);

    for (int i = 0; i < length; i++)
        std::cout << arr[i] << " ";

    
}
