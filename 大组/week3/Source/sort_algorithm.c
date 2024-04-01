#ifndef SORT_ALGORITHM
#define SORT_ALGORITHM

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Header/header.h"

// Sorted_Checker (判断是否已完成排序)
Status Sort_Checker(double ArrayToSort[], Order ORDER, int ArrayLength)
{   
    // 升序
    if (ORDER == ASC)
    {
        for (int i = 0; i < ArrayLength - 1; i++)
        {
            if (ArrayToSort[i] > ArrayToSort[i + 1])
            {
                return ERROR;
            }
        }
        return SUCCESS;
    }
    // 降序
    else if (ORDER == DESC)
    {
        for (int i = 0; i < ArrayLength - 1; i++)
        {
            if (ArrayToSort[i] < ArrayToSort[i + 1])
            {
                return ERROR;
            }
        }
        return SUCCESS;
    }
    // 错误
    else
    {
        return ERROR;
    }
}

/* SMALL DATA SORT */
// InsertSort
Status InsertSort(double ArrayToSort[], int ArrayLength)
{
    /* 检查数据是否已经排好序 */
    if (Sort_Checker(ArrayToSort, ASC, ArrayLength) == SUCCESS)
    {
        return SUCCESS;
    }

    // 插入排序(升序)
    for (int i = 1; i < ArrayLength; i++)
    {
        double temp = ArrayToSort[i];
        int j = i - 1;
        while (j >= 0 && ArrayToSort[j] > temp)
        {
            ArrayToSort[j + 1] = ArrayToSort[j];
            j--;
        }
        ArrayToSort[j + 1] = temp;
    }

    /* 检查数据是否已经排好序 */
    if (Sort_Checker(ArrayToSort, ASC, ArrayLength) == SUCCESS)
    {
        return SUCCESS;
    }
    else
    {
        return ERROR;
    }
}
// MergeSort

// 归并排序(升序)

Status MergeSort(double ArrayToSort[], int ArrayLength) // 入口函数
{
    /* 检查是否已经排好序 */
    if (Sort_Checker(ArrayToSort, ASC, ArrayLength) == SUCCESS)
    {
        return SUCCESS;
    }

    /* 创建辅助数组 */
    double * temp_array = (double *)malloc(sizeof(double) * ArrayLength);
    if (temp_array == NULL)
    {
        return ERROR;
    }

    /* 开始排序 */
    MergeSort_Main(ArrayToSort, temp_array, 0, ArrayLength - 1);  
}

// 归并排序主要排序函数
void MergeSort_Main(double ArrayToSort[], double temp_array[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        MergeSort_Main(ArrayToSort, temp_array, left, mid);
        MergeSort_Main(ArrayToSort, temp_array, mid + 1, right);
        MergeSort_Merge(ArrayToSort, temp_array, left, mid, right);
    }
}

// 归并排序合并函数
void MergeSort_Merge(double ArrayToSort[], double temp_array[], int left, int mid, int right)
{
    int i = left;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= right)
    {
        if (ArrayToSort[i] <= ArrayToSort[j])
        {
            temp_array[k++] = ArrayToSort[i++];
        }
        else
        {
            temp_array[k++] = ArrayToSort[j++];
        }
    }

    while (i <= mid)
    {
        temp_array[k++] = ArrayToSort[i++];
    }

    while (j <= right)
    {
        temp_array[k++] = ArrayToSort[j++];
    }

    for (int i = 0; i < k; i++)
    {
        ArrayToSort[left + i] = temp_array[i];
    }
}


// QuickSort(递归版)
Status QuickSort(double ArrayToSort[], int ArrayLength, int left, int right)
{
    /* 检查是否已经排序好 */
    if (Sort_Checker(ArrayToSort, ASC, ArrayLength) == SUCCESS)
    {
        return SUCCESS;
    }

    /* 开始排序 */
    int i = left;
    int j = right;
    double temp = ArrayToSort[left];

    if (i > j)
    {
        return ERROR;
    }

    while (i != j)
    {
        while (ArrayToSort[j] >= temp && i < j)
        {
            j--;
        }

        while (ArrayToSort[i] <= temp && i < j)
        {
            i++;
        }

        if (i < j)
        {
            double t = ArrayToSort[i];
            ArrayToSort[i] = ArrayToSort[j];
            ArrayToSort[j] = t;
        }
    }

    ArrayToSort[left] = ArrayToSort[i];
    ArrayToSort[i] = temp;

    QuickSort(ArrayToSort, ArrayLength, left, i - 1);
    QuickSort(ArrayToSort, ArrayLength, i + 1, right);

    /* 检查是否已经排序好 */
    if (Sort_Checker(ArrayToSort, ASC, ArrayLength) == SUCCESS)
    {
        return SUCCESS;
    }
    else
    {
        return ERROR;
    }

}


// CountSort
Status CountSort(double ArrayToSort[], int ArrayLength)
{
    /* 检查是否已经排序好 */
    if (Sort_Checker(ArrayToSort, ASC, ArrayLength) == SUCCESS)
    {
        return SUCCESS;
    }

    /* 开始排序 */
    double max = ArrayToSort[0];
    double min = ArrayToSort[0];

    for (int i = 1; i < ArrayLength; i++)
    {
        if (ArrayToSort[i] > max)
        {
            max = ArrayToSort[i];
        }
        if (ArrayToSort[i] < min)
        {
            min = ArrayToSort[i];
        }
    }

    int range = max - min + 1;
    int * count = (int *)malloc(sizeof(int) * range);
    if (count == NULL)
    {
        return ERROR;
    }

    memset(count, 0, sizeof(int) * range);

    for (int i = 0; i < ArrayLength; i++)
    {
        count[(int)(ArrayToSort[i] - min)]++;
    }

    int k = 0;
    for (int i = 0; i < range; i++)
    {
        while (count[i] > 0)
        {
            ArrayToSort[k] = i + min;
            k++;
            count[i]--;
        }
    }

    /* 检查是否已经排序好 */
    if (Sort_Checker(ArrayToSort, ASC, ArrayLength) == SUCCESS)
    {
        return SUCCESS;
    }
    else
    {
        return ERROR;
    }
}

// RadixCountSort
Status RadixCountSort(double ArrayToSort[], int ArrayLength)
{
    /* 检查是否已经排序好 */
    if (Sort_Checker(ArrayToSort, ASC, ArrayLength) == SUCCESS)
    {
        return SUCCESS;
    }

    /* 开始排序 */
    double max = ArrayToSort[0];
    double min = ArrayToSort[0];

    for (int i = 1; i < ArrayLength; i++)
    {
        if (ArrayToSort[i] > max)
        {
            max = ArrayToSort[i];
        }
        if (ArrayToSort[i] < min)
        {
            min = ArrayToSort[i];
        }
    }

    int range = max - min + 1;
    int * count = (int *)malloc(sizeof(int) * range);
    if (count == NULL)
    {
        return ERROR;
    }

    memset(count, 0, sizeof(int) * range);

    for (int i = 0; i < ArrayLength; i++)
    {
        count[(int)(ArrayToSort[i] - min)]++;
    }

    int k = 0;
    for (int i = 0; i < range; i++)
    {
        while (count[i] > 0)
        {
            ArrayToSort[k] = i + min;
            k++;
            count[i]--;
        }
    }

    /* 检查是否已经排序好 */
    if (Sort_Checker(ArrayToSort, ASC, ArrayLength) == SUCCESS)
    {
        return SUCCESS;
    }
    else
    {
        return ERROR;
    }
}

// 查看排序后的数组
void Show_Sorted_Array(double ArrayToSort[], int ArrayLength)
{
    for (int i = 0; i < ArrayLength; i++)
    {
        printf("%lf ", ArrayToSort[i]);
    }
    printf("\n");
}

/* BIG DATA SORT */
// 外部排序
/* 思路： 对于大数据量的情况下， 将大数据的量分成若干分SMALL_DATA_ARRAY长度的数组
    利用上面写好的各种小数据排序函数进行排序，排序完之后存储到一个临时文件中
   再对排好的多个数组进行类似于归并排序的操作 */

/*  */
#endif