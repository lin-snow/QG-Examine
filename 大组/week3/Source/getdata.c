#ifndef GETDATA
#define GETDATA

#include <stdio.h>
#include <stdlib.h>
#include "../Header/header.h"

/* 获取数据 */


/* 数据获取说明 */
/* 功能：从txt文件中获取数据，并应用于排序算法
   注意：txt文件中存储浮点数或非浮点数 */

// 读取小数据
double * get_small_data(double temp_array[SMALL_DATA_ARRAY], int * length)
{   
    /* 打开数据文件 */
    FILE *fp;
    if ((fp = fopen("./data/sort_small_data.txt", "r+")) == NULL)
    {
        printf("文件打开失败！\n");
        exit(0);
    }

    // 跳过文件的第一行
    char temp[100];
    fgets(temp, 100, fp);
    // 跳过换行符
    fgetc(fp);


    // 读取数据
    int i = 0; // 计数器
    while (fscanf(fp, "%lf", &temp_array[i]) != EOF)
    {
        i++;

        if (i == SMALL_DATA_ARRAY)
        {
            break;
        }
    }
    /* 更新获取到的数据的量 */
    *length = i;

    /* 关闭文件 */
    fclose(fp);

    return temp_array;
}

// // 读取多个小数据
// File * 

// // 读取大数据(用于外部排序)
// double * get_large_data(double temp_array[], int * length)
// {
//     /* 打开数据文件 */
//     FILE *fp;
//     if ((fp = fopen("./data/sort_large_data.txt", "r+")) == NULL)
//     {
//         printf("文件打开失败！\n");
//         exit(0);
//     }

//     // 跳过文件的第一行
//     char temp[100];
//     fgets(temp, 100, fp);
//     // 跳过换行符
//     fgetc(fp);

//     // 读取数据（先读一小部分）
//     int i = 0; // 计数器
//     while (fscanf(fp, "%lf", &temp_array[i]) != EOF)
//     {
//         i++;

//         if (i == SMALL_DATA_ARRAY)
//         {
//             break;
//         }
//     }

//     /* 更新获取到的数据的量 */
//     *length = i;

   

// }

#endif