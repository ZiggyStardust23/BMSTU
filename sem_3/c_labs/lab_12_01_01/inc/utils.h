#ifndef _UTILS_H_
#define _UTILS_H_

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

int allocate_arr(int **arr_beg, int n);
void free_arr(int **arr_beg, int **arr_end);
int find_num_of_elems(FILE *f, int *count);
int read_arr(FILE *f_in, int *arr, size_t size);
int create_arr(FILE *f_in, int **arr, size_t *n_size);
void fprint(FILE *f_in, const int *pb, const int *pe);

#endif