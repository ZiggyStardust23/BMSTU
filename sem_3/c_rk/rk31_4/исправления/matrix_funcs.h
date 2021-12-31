#ifndef _MATRIX_FUNCS_H_
#define _MATRIX_FUNCS_H_

#include "util.h"

#include <stdio.h>
#include <stdlib.h>

#define READ_ERROR -3
#define SIZE_ERROR -4

int find_size_of_matrix(FILE *f_in, int *size);

int read_sort_and_write_to_matrix(FILE *f_in, int **matrix, int size);

int find_max_len_of_num(int **matrix, int size);

void print_matrix(int **matrix, int size);

void free_matrix(int **matrix);

#endif