#ifndef _FUNCS_H_
#define _FUNCS_H_

#include <stdio.h>
#include <stdlib.h>

#define INCORRECT_ARG_COUNT -1
#define FILE_NOT_FOUND -2
#define INIT_ERROR -3
#define INCORRECT_ARG -4
#define READ_ERROR -5
#define INCORRECT_FILE_POINTER -6

int count_nums_in_file(FILE *in_file, int *nums_in_file);
int read_from_file_to_arr(FILE *in_file, int *pb, int *pe);
int write_array_to_file(FILE *out_file, int *pb, int *pe);
int check_if_nums_are_same(int *int_array, int nums);

#endif