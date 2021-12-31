#ifndef _DYNAMIC_UTILS_H_
#define _DYNAMIC_UTILS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dynamic.h"

#define SRC_ARR_IS_EMPTY    -2
#define DST_ARR_IS_EMPTY    -6
#define NO_ELEMENTS_BETWEEN -7
#define INCORRECT_PARAMS    -9
#define MEMORY_ERROR        -13
#define FILE_ERROR          -10
#define AVR_ERR             -8
#define LIB_ERROR           -11

ARR_DLL int ARR_DECL allocate_arr(int **arr_beg, int n);
ARR_DLL void ARR_DECL free_arr(int **arr_beg, int **arr_end);
ARR_DLL int ARR_DECL find_num_of_elems(FILE *f, int *count);
ARR_DLL int ARR_DECL read_arr(FILE *f_in, int *arr, size_t size);
ARR_DLL int ARR_DECL create_arr(FILE *f_in, int **arr, size_t *n_size);
ARR_DLL void ARR_DECL fprint(FILE *f_in, const int *pb, const int *pe);

#endif