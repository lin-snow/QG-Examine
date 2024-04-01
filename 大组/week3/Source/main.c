#include <stdio.h>
#include <stdlib.h>
#include "../Header/header.h"
#include "./getdata.c"
#include "./gendata.c"
#include "./sort_algorithm.c"
#include "./much_small_data.c"
#include "./large_data.c" 



int main() 
{
    system("cls"); // 清屏
    // double temp_array[SMALL_DATA_ARRAY]; // 临时数组
    // int length; // 数组长度
    // get_small_data(temp_array, &length); // 获取小数据

    // /* 开始测试函数 */
    // double temp_array[SMALL_DATA_ARRAY]; // 临时数组
    // int length; // 数组长度
    // get_small_data(temp_array, &length); // 获取小数据

    // // InsertSort
    // InsertSort(temp_array, length);
    // printf("InsertSort: \n");
    // Show_Sorted_Array(temp_array, length);

    // // MergeSort
    // get_small_data(temp_array, &length); // 重新获取数据
    // MergeSort(temp_array, length);
    // printf("MergeSort: \n");
    // Show_Sorted_Array(temp_array, length);

    // // QuickSort
    // get_small_data(temp_array, &length); // 重新获取数据
    // QuickSort(temp_array, length, 0, length - 1);
    // printf("QuickSort: \n");
    // Show_Sorted_Array(temp_array, length);

    // // CountSort
    // get_small_data(temp_array, &length); // 重新获取数据
    // CountSort(temp_array, length);
    // printf("CountSort: \n");
    // Show_Sorted_Array(temp_array, length);

    // // RadixCountSort
    // get_small_data(temp_array, &length); // 重新获取数据
    // RadixCountSort(temp_array, length);
    // printf("RadixCountSort: \n");
    // Show_Sorted_Array(temp_array, length);

    /* 测试完毕，各个排序函数使用正常 */

    printf("开始测试排序算法！\n");
    printf("大量小数据排序测试开始！\n");
    while(1)
    {
        // 获取大量小数据并排序
        if(get_sort_much_small_data_time_used(choose_sort_algorithm()) == ERROR)
        {
            break;
        }
    }
    printf("大数据量排序测试开始！\n");
    while (1)
    {
        // 获取大数据并排序
        if(get_sort_large_data_time_used(choose_sort_algorithm()) == ERROR)
        {
            break;
        }
    }
    

    

    
    system("pause");
    return 0;
}