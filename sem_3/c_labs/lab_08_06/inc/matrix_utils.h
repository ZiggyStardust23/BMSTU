#ifndef _MATRIX_UTILS_H_
#define _MATRIX_UTILS_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "utils.h"

#define READ_ERROR -1
#define MEMORY_ERROR -2
#define INTORRECT_SIZE -3
#define INCORRECT_NUM_OF_MULTY -4

int **allocate_matrix(int n, int m);

int input_matrix(int **matrix, int *n, int *m);

int **make_square_matrix(int **matrix, int n, int m, int *size);

int **form_matrix(int **matrix, int new_size, int old_size);

void print_matrix(int **matrix, int size);

void free_all(int **matrix_a, int **matrix_b, int a_n, int b_n, int size_a, int size_b, int size);

void make_identity_matrix(int **matrix, int size);

int **delete_strings(int n, int m, int **matrix, int size);

int **delete_columns(int n, int m, int **matrix, int size);

void find_min_elems_for_columns(int column_to_delete, int *column_index, int **matrix, int n, int m);

void write_without_deleted_columns(int column_to_delete, int *column_index, int **matrix, int **new_matrix, int n, int m);

float average_geom(float write_elem, int pow_elems);

void add_strings(int **matrix, int **new_matrix, int old_size, int new_size);

void add_columns(int **matrix, int **new_matrix, int old_size, int new_size);

void free_one(int **matrix, int n);

void copy_square_matrix(int **matrix_a, int **matrix_b, int size);

int create_and_input_matrix(int ***matrix, int *n, int *m);

void find_size_and_make_square(int ***matrix, int n, int m, int *size);

void choice_matrix_and_form_it(int ***matrix_a, int ***matrix_b, int size_a, int size_b, int *size);

#endif