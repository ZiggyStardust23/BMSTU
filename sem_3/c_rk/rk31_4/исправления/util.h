#ifndef _UTIL_H_
#define _UTIL_H_

#include <stdio.h>

#define READ_ERROR -3

int find_max_len_of_num(int **matrix, int size);

void swap(int *el_1, int *el_2);

void bubble_sort(int *arr, int arr_size);

int read_from_file_to_arr(FILE *f_in, int *read_array, int num_to_read);

int find_len_of_num(int num);

#endif