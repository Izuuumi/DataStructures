// 交换排序.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

int partition(int* arr, int low, int high);

void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

void bubbleSort(int* arr, const int length)//冒泡排序
{
    for (int i = 1; i < length; i++)//n个数共需n-1趟
    {
        for (int j = 1; j <= length - i; j++)//第m趟需要n-m-1次比较
        {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}

void advancedBubble(int* arr, const int length)//改进的冒泡排序
{
    bool swapped = true;//用来标记是否进行了交换

    for (int i = 1; i < length; i++)
    {
        swapped = false;

        for (int j = 1; j <= length - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        if (!swapped)//如果没交换，说明排序已经完成，直接退出循环
            break;
    }
}

void quickSort(int* arr, int low, int high)//快速排序
{
    if (low < high)//如果子表不只一个元素
    {
        int pivot = partition(arr, low, high);

        quickSort(arr, low, pivot - 1);//左子表排序
        quickSort(arr, pivot + 1, high);//右子表排序
    }
}

int partition(int* arr, int low, int high)//确定分割子表的位置
{
    arr[0] = arr[low];//pivot
    
    while (low < high)
    {
        while (low < high && arr[high] >= arr[0])//直到找到比pivot小的元素
            high--;

        arr[low] = arr[high];//交换

        while (low < high && arr[low] <= arr[0])//直到找到比pivot大的元素
            low++;

        arr[high] = arr[low];//交换
    }

    arr[low] = arr[0];//low==high的位置

    return low;//返回pivot的位置，作为分割子表的位置
}

int main()
{
    const int length = 6;
    int arr1[length + 1] = { 0,41,52,63,12,425,31 };

    bubbleSort(arr1, length);
    for (int i = 1; i <= length; i++)
        std::cout << arr1[i] << " ";

    std::cout << std::endl;

    int arr2[length + 1] = { 0,41,52,63,12,425,31 };
    advancedBubble(arr2, length);
    for (int i = 1; i <= length; i++)
        std::cout << arr2[i] << " ";

    std::cout << std::endl;

    int arr3[length + 1] = { 0,41,52,63,12,425,31 };
    quickSort(arr3, 1, length);
    for (int i = 1; i <= length; i++)
        std::cout << arr3[i] << " ";
}