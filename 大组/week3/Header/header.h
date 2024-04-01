#ifndef HEADER
#define HEADER

#include <stdio.h>
#include <stdlib.h>

#define SMALL_DATA_ARRAY 1000 // 小数据量的数组长度
#define LARGE_DATA_ARRAY 1000000 // 大数据量的数组长度


typedef enum Status {
    SUCCESS = 1,
    ERROR = 0
} Status;

typedef enum Order {
    ASC = 1, // 升序
    DESC = 0  // 降序
} Order;

/* 函数原型 */
Status Sort_Checker(double ArrayToSort[], Order ORDER, int ArrayLength);
Status InsertSort(double ArrayToSort[], int ArrayLength);
Status MergeSort(double ArrayToSort[], int ArrayLength);
void MergeSort_Main(double ArrayToSort[], double temp_array[], int left, int right);
void MergeSort_Merge(double ArrayToSort[], double temp_array[], int left, int mid, int right);
Status QuickSort(double ArrayToSort[], int ArrayLength, int left, int right);
Status CountSort(double ArrayToSort[], int ArrayLength);
Status RadixCountSort(double ArrayToSort[], int ArrayLength);
double * get_small_data(double temp_array[SMALL_DATA_ARRAY], int * length);
double * get_large_data(double temp_array[], int * length);
double get_sort_much_small_data_time(int algorithm_choice,double temp_array[SMALL_DATA_ARRAY]);
Status get_sort_much_small_data_time_used(int algorithm_choice);
int choose_sort_algorithm();
double get_sort_large_data_time(int algorithm_choice, double temp_test_array[LARGE_DATA_ARRAY]);

#endif
