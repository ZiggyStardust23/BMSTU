#ifndef _MATRIX_MATH_H_
#define _MATRIX_MATH_H_

#include <stdlib.h>
#include <stdio.h>

#include "matrix_utils.h"
#include "utils.h"

void matrix_pow(int **matrix, int pow, int size);

void matrix_multy(int **matrix_a, int **matrix_b, int size);

int pow_and_multy_matrices(int ***matrix_a, int ***matrix_b, int size);

#endif