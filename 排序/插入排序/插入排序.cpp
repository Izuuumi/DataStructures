// 插入排序.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

void shellSort(int* arr, int dk, int length);

void insertSort1(int* arr, int length)//直接查找法
{
    int j;

    for (int i = 2; i <= length; i++)//从第二个开始比较
    {
        if (arr[i] < arr[i - 1])//如果待排元素比上一个已排元素小（否则待排元素不动）
        {
            arr[0] = arr[i];//复制为哨兵

            for (j = i - 1; arr[j] > arr[0]; j--)//后移
                arr[j + 1] = arr[j];

            arr[j + 1] = arr[0];
        }
    }
}

void insertSort2(int* arr, int length)//二分查找法
{
    for (int i = 2; i <= length; i++)
    {
        if (arr[i] < arr[i - 1])
        {
            arr[0] = arr[i];

            int low = 1;
            int high = i - 1;
            int mid = 0;

            while (low <= high)
            {
                mid = (low + high) / 2;

                if (arr[0] < arr[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            }

            for (int j = i - 1; j > high; j--)
                arr[j + 1] = arr[j];

            arr[high + 1] = arr[0];
        }
    }
}

void insertSort3(int* arr, int* dlta, int t, int length)//dlta[]是增量序列，按照增量dlta[t]进行排序
{
    for (int j = 0; j < t; j++)
        shellSort(arr, dlta[j], length);
}

void shellSort(int* arr, int dk, int length)//dk为步长
{
    int j;

    for (int i = dk + 1; i <= length; i++)//以dk间隔进行直接插入排序
    {
        if (arr[i] < arr[i - dk])
        {
            arr[0] = arr[i];

            for (j = i - dk; j > 0 && arr[0] < arr[j]; j -= dk)
                arr[j + dk] = arr[j];

            arr[j + dk] = arr[0];
        }
    }
}

int main()
{
    const int length = 10;

    int arr[length + 1] = { 0,10,51,42,67573,35,72,43,3,5,1 };
    int dlta[4] = { 1,3,5,7 };

    insertSort1(arr, length);
    for (int i = 1; i <= length; i++)
        std::cout << arr[i] << " ";

    std::cout << std::endl;

    insertSort2(arr, length);
    for (int i = 1; i <= length; i++)
        std::cout << arr[i] << " ";

    std::cout << std::endl;

    insertSort3(arr, dlta, 3, length);
    for (int i = 1; i <= length; i++)
        std::cout << arr[i] << " ";
}
