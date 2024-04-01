#ifndef MUCH_SMALL_DATA
#define MUCH_SMALL_DATA

#include <stdio.h> 
#include <stdlib.h>
#include <time.h> // 需要用到clock_t

#include "../Header/header.h"
#include "./sort_algorithm.c"

// 读取大量小数据进行排序
double get_sort_much_small_data_time(int algorithm_choice,double temp_array[SMALL_DATA_ARRAY])
{
    // 创建一个文件指针
    FILE *get_much_small_data = NULL;
    // 用于写入排序后的数据
    FILE *write_much_small_data = NULL;
    // 创建检测文件的指针
    FILE *check_much_small_data = NULL;
    // 打开需要排序的文件
    get_much_small_data = fopen("./data/sort_small_data.txt", "r+");
    // 打开排序后需要写入的文件
    write_much_small_data = fopen("./data/sorted_much_small_data.txt", "a+");
    // 打开检查文件
    check_much_small_data = fopen("./data/sort_small_data.txt", "r+");
    // 检查是否打开文件成功
    if (get_much_small_data == NULL || write_much_small_data == NULL || check_much_small_data == NULL)
    {
        perror("文件打开失败！\n");
        exit(0);
    }    
    // 跳过文件的第一行
    char temp[100];
    fgets(temp, 100, get_much_small_data);
    // 跳过换行符
    fgetc(get_much_small_data);
    
    // 读取数据（利用循环）
    int i = 0;
    int j = 0;
    double time_used = 0;

    // 获取当前文件指针的位置
    long int current_pos = ftell(get_much_small_data);
    // 将另一个文件指针移动到相同的位置
    fseek(check_much_small_data, current_pos, SEEK_SET);

    // 开始计时
    clock_t start, end;
    start = clock();

    while (fgetc(check_much_small_data) != EOF)
    {
        // 获取当前文件指针的位置
        current_pos = ftell(get_much_small_data);
        // 将另一个文件指针移动到相同的位置
        fseek(check_much_small_data, current_pos, SEEK_SET);

        // 读取每一行的数据
        if (fgetc(check_much_small_data) != '\n')
        {
            fscanf(get_much_small_data, "%lf", &temp_array[i]);
            i++;

            // 获取当前文件指针的位置
            current_pos = ftell(get_much_small_data);
            // 将另一个文件指针移动到相同的位置
            fseek(check_much_small_data, current_pos, SEEK_SET);

        }

        // 更新检查文件的指针
        // 获取当前文件指针的位置
        current_pos = ftell(get_much_small_data);
        // 将另一个文件指针移动到相同的位置
        fseek(check_much_small_data, current_pos, SEEK_SET);

        // 如果整一行读完了，就进行排序然后换下一行直到每一行排序完
        // 进行排序
        // 插入排序
        if (fgetc(check_much_small_data) == '\n')
        {
            // 进行排序
            switch (algorithm_choice)
            {
            case 1:
                InsertSort(temp_array, i);
                break;
            case 2:
                MergeSort(temp_array, i);
                break;
            case 3:
                QuickSort(temp_array, i, 0, i - 1);
                break;
            case 4:
                CountSort(temp_array, i);
                break;
            case 5:
                RadixCountSort(temp_array, i);
                break;    

            default:
                break;
            }

            // 将排序后的数据写入另一个文件
            for (j = 0; j < i; j++)
            {
                fprintf(write_much_small_data, "%lf ", temp_array[j]);
            }
            fprintf(write_much_small_data, "\n"); // 换行

            // 重置i
            i = 0;

            // 将文件指针移到下一行(跳过换行符)
            fgetc(get_much_small_data);
        }

        // 更新检查文件的指针
        // 获取当前文件指针的位置
        current_pos = ftell(get_much_small_data);
        // 将另一个文件指针移动到相同的位置
        fseek(check_much_small_data, current_pos, SEEK_SET);

    }

    // 结束计时
    end = clock();
    time_used = (double)(end - start) / CLOCKS_PER_SEC;


    // 关闭文件
    fclose(get_much_small_data);
    fclose(write_much_small_data);

    // printf("%lf\n", time_used);
    return time_used;
}



#endif