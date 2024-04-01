#ifndef LARGE_DATA
#define LARGE_DATA

#include <time.h>
#include "../Header/header.h"

/* 大数据量测试 */
double get_sort_large_data_time(int algorithm_choice, double temp_test_array[LARGE_DATA_ARRAY])
{
    // 创建一个文件指针
    FILE *get_large_data = NULL;
    // 打开需要排序的文件
    get_large_data = fopen("./data/sort_large_data.txt", "r+");

    // 检查是否打开文件成功
    if (get_large_data == NULL)
    {
        perror("文件打开失败！\n");
        exit(0);
    }

    // 跳过文件的第一行（2000000数据量）
    char temp[100];
    fgets(temp, 100, get_large_data);
    // 跳过换行符
    fgetc(get_large_data);

    // 读取数据（利用循环）
    int i = 0;
    while (fscanf(get_large_data, "%lf", &temp_test_array[i]) != EOF)
    {
        i++;
        if (i == LARGE_DATA_ARRAY)
        {
            break;
        }
    }

    // 开始排序
    clock_t start, end;
    start = clock();

    switch (algorithm_choice)
    {
    case 1:
        InsertSort(temp_test_array, i);
        break;
    case 2:
        MergeSort(temp_test_array, i);
        break;
    case 3:
        QuickSort(temp_test_array, i, 0, i - 1);
        break;    
    case 4:
        CountSort(temp_test_array, i);
        break;
    case 5:
        RadixCountSort(temp_test_array, i);
        break;
    default:
        break;
    }

    end = clock();

    // 计算时间
    double time_used = (double)(end - start) / CLOCKS_PER_SEC;

    // 写入文件
    FILE *write_sorted_data = NULL;
    write_sorted_data = fopen("./data/sorted_large_data.txt", "a+");

    if (write_sorted_data == NULL)
    {
        perror("文件打开失败！\n");
        exit(0);
    }

    // 写入排序后的数据
    for (int j = 0; j < i; j++)
    {
        fprintf(write_sorted_data, "%lf ", temp_test_array[j]);
    }

    // 关闭文件
    fclose(get_large_data);

    return time_used;
}
#endif