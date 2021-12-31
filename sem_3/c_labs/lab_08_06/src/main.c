#include <stdio.h>
#include <stdlib.h>

#include "../inc/matrix_utils.h"
#include "../inc/matrix_math.h"
#include "../inc/utils.h"

int main(int argc, char **argv)
{
    int **matrix_a = NULL;
    int **matrix_b = NULL;

    int a_n = 0;
    int a_m = 0;
    int b_n = 0;
    int b_m = 0;

    setbuf(stdout, NULL);

    int error_code = 0;

    error_code = create_and_input_matrix(&matrix_a, &a_n, &a_m);

    if (error_code == 0)
        error_code = create_and_input_matrix(&matrix_b, &b_n, &b_m);

    int size_a = 0;
    int size_b = 0;
    int size = 0;

    if (error_code == 0)
    {
        find_size_and_make_square(&matrix_a, a_n, a_m, &size_a);
        find_size_and_make_square(&matrix_b, b_n, b_m, &size_b);

        choice_matrix_and_form_it(&matrix_a, &matrix_b, size_a, size_b, &size);

        error_code = pow_and_multy_matrices(&matrix_a, &matrix_b, size);
    }

    if (error_code == 0)
        print_matrix(matrix_a, size);

    free_all(matrix_a, matrix_b, a_n, b_n, size_a, size_b, size);

    return error_code;
}