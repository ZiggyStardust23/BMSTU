#include "../inc/matrix_math.h"
#include "../inc/matrix_math.h"

void matrix_pow(int **matrix, int pow, int size)
{
    int **temp_matrix = malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++)
    {
        temp_matrix[i] = malloc(size * sizeof(int));
    }

    copy_square_matrix(temp_matrix, matrix, size);

    for (int n = 0; n < pow - 1; n++)
    {
        matrix_multy(matrix, temp_matrix, size);
    }
    
    for (int i = 0; i < size; i++)
    {
        free(temp_matrix[i]);
    }
    free(temp_matrix);
}

void matrix_multy(int **matrix_a, int **matrix_b, int size)
{
    int **result_matrix = malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++)
        result_matrix[i] = malloc(size * sizeof(int));

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            int cur_elem = 0;
            for (int k = 0; k < size; k++)
            {
                cur_elem += matrix_a[i][k] * matrix_b[k][j];
            }
            result_matrix[i][j] = cur_elem;
        }
    }

    copy_square_matrix(matrix_a, result_matrix, size);

    free_one(result_matrix, size);
}

int pow_and_multy_matrices(int ***matrix_a, int ***matrix_b, int size)
{
    int a_pow = 0;
    int b_pow = 0;

    int error_code = 0;

    error_code = enter_two_int(&a_pow, &b_pow);

    if (error_code == 0 && (a_pow < 0 || b_pow < 0))
        error_code = INCORRECT_NUM_OF_MULTY;

    if (error_code == 0)
    {
        if (a_pow != 0)
            matrix_pow(*matrix_a, a_pow, size);
        else
            make_identity_matrix(*matrix_a, size);
        
        if (b_pow != 0)
            matrix_pow(*matrix_b, b_pow, size);
        else
            make_identity_matrix(*matrix_b, size);
        matrix_multy(*matrix_a, *matrix_b, size);
    }

    return error_code;
}