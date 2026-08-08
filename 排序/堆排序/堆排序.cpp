// 堆排序.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

void heapAdjust(int* arr, int s, int m)//从arr[s]开始，到arr[m]，将其调整为小根堆（s之后的元素已经是小根堆了）
{
    int tar = arr[s];//待调整的数

    for (int i = s * 2; i <= m; i *= 2)
    {
        if (i < m && arr[i + 1] < arr[i])//防止m+1越界
            i++;//保证arr[i]是arr[s]的最小孩子

        if (tar < arr[i])//说明已经是一个小根堆了
            break;

        arr[s] = arr[i];
        s = i;
    }

    arr[s] = tar;
}

void heapSort(int* arr, const int length)
{
    for (int i = length / 2; i >= 1; i--)//将序列调整为小根堆
        heapAdjust(arr, i, length);

    for (int i = length; i > 1; i--)//n个元素共需调整n-1次
    {
        swap(arr[i], arr[1]);//将待排序的最后一个元素放到堆顶，上一次排序的最小放到最后
        heapAdjust(arr, 1, i - 1);//再进行堆调整
    }//第一次将最小的移到最后，第二次将次小的移到倒数第二个，所以排序之后其实是按从大到小的顺序
}

int main()
{
    const int length = 6;
    int arr[length + 1] = { 0,51,426,54,2,5,25 };

    heapSort(arr, length);

    for (int i = length; i >= 1; i--)
        std::cout << arr[i] << " ";
}
