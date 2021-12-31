#ifndef _KEY_H_
#define _KEY_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SRC_ARR_IS_EMPTY    -2
#define DST_ARR_IS_EMPTY    -6
#define NO_ELEMENTS_BETWEEN -7
#define INCORRECT_PARAMS    -9
#define MEMORY_ERROR        -13
#define FILE_ERROR          -10
#define AVR_ERR             -8
#define LIB_ERROR           -11

int find_arr_size_after_key(const int *pb_src, const int *pe_src);
int key(const int *pb_src, const int *pe_src, int *pb_dst, int *pe_dst);
void key_swap(int **f, int **s);

#endif