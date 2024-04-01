#ifndef GENDATA
#define GENDATA

// #include <time.h>
#include "../Header/header.h"

// 选择要使用的排序算法
int choose_sort_algorithm()
{
    printf("请选择要使用的排序算法: \n");
    printf("1. 插入排序\n");
    printf("2. 归并排序\n");
    printf("3. 快速排序\n");
    printf("4. 计数排序\n");
    printf("5. 基数排序\n");
    printf("6. 退出\n");

    int choice = 0;
    printf("请输入: ");
    scanf("%d", &choice);
    // 检查输入是否合法
    while (choice < 1 || choice > 6)
    {
        // 输入不合法
        printf("输入不合法，请重新输入: \n");
        scanf("%d", &choice);

        // 清空输入缓冲区
        while (getchar() != '\n')
            continue;

    }

    return choice;
}

Status get_sort_much_small_data_time_used(int algorithm_choice)
{
    if (algorithm_choice == 6)
    {
        return ERROR;
    }
    /* 测试数据生成 */
    /* 大量小数据情况总共用时 */
    double temp_test_array[SMALL_DATA_ARRAY]; // 临时数组
    double time_used = 0.0; // 用于存储时间
    
    /* 获取时间 */
    time_used = get_sort_much_small_data_time(algorithm_choice, temp_test_array); // 获取大量小数据并排序
    // printf("大量小数据排序总共用时: %lf\n", time_used);

    FILE *write_time = NULL;
    write_time = fopen("./data/test_time_data.txt", "a+");
    if (write_time == NULL)
    {
        perror("文件打开失败！\n");
        exit(0);
    }

    switch(algorithm_choice)
    {
        case 1:
            printf("插入排序用时: %lf\n", time_used);
            fprintf(write_time, "插入排序用时: %lf\n", time_used);
            break;
        case 2:
            printf("归并排序用时: %lf\n", time_used);
            fprintf(write_time, "归并排序用时: %lf\n", time_used);
            break;
        case 3:
            printf("快速排序用时: %lf\n", time_used);
            fprintf(write_time, "快速排序用时: %lf\n", time_used);
            break;
        case 4:
            printf("计数排序用时: %lf\n", time_used);
            fprintf(write_time, "计数排序用时: %lf\n", time_used);
            break;
        case 5:
            printf("基数排序用时: %lf\n", time_used);
            fprintf(write_time, "基数排序用时: %lf\n", time_used);
            break;

        default:
            break;            
    }
    return SUCCESS;
}

Status get_sort_large_data_time_used(int algorithm_choice)
{
    if (algorithm_choice == 6)
    {
        return ERROR;
    }
    /* 测试数据生成 */
    /* 大数据量情况总共用时 */
    double* temp_test_array = (double*)malloc(LARGE_DATA_ARRAY * sizeof(double));
    if (temp_test_array == NULL) {
        printf("内存分配失败\n");
        exit(1);
    } // 临时数组
    double time_used = 0.0; // 用于存储时间

    /* 获取时间 */
    time_used = get_sort_large_data_time(algorithm_choice, temp_test_array); // 获取大数据并排序
    // printf("大数据排序总共用时: %lf\n", time_used);

    FILE *write_time = NULL;
    write_time = fopen("./data/test_time_data.txt", "a+");
    if (write_time == NULL)
    {
        perror("文件打开失败！\n");
        exit(0);
    }

    switch(algorithm_choice)
    {
        case 1:
            printf("大数据量插入排序用时: %lf\n", time_used);
            fprintf(write_time, "大数据量插入排序用时: %lf\n", time_used);
            break;
        case 2:
            printf("大数据量归并排序用时: %lf\n", time_used);
            fprintf(write_time, "大数据量归并排序用时: %lf\n", time_used);
            break;
        case 3:
            printf("大数据量快速排序用时: %lf\n", time_used);
            fprintf(write_time, "大数据量快速排序用时: %lf\n", time_used);
            break;
        case 4:
            printf("大数据量计数排序用时: %lf\n", time_used);
            fprintf(write_time, "大数据量计数排序用时: %lf\n", time_used);
            break;
        case 5:
            printf("大数据量基数排序用时: %lf\n", time_used);
            fprintf(write_time, "大数据量基数排序用时: %lf\n", time_used);
            break;

        default:
            break;            
    }
    return SUCCESS;
}


#endif