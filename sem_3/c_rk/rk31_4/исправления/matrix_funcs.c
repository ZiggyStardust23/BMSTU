#include "matrix_funcs.h"

int find_size_of_matrix(FILE *f_in, int *size)
{
    int error_code = 0;
    fscanf(f_in, "%d", size);
    if (*size <= 0 || *size > 100)
        error_code = SIZE_ERROR;
    return error_code;
}

int read_sort_and_write_to_matrix(FILE *f_in, int **matrix, int size)
{
    int error_code = 0;

    int *read_array = malloc(size * size * sizeof(int));

    error_code = read_from_file_to_arr(f_in, read_array, size * size);

    if (error_code == 0)
        bubble_sort(read_array, size * size);

    int array_index = 0;
    if (error_code == 0)
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
            {
                matrix[i][j] = read_array[array_index];
                array_index++;
            }

    return error_code;
}

void print_matrix(int **matrix, int size)
{
    int biggest_len = find_max_len_of_num(matrix, size);

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%d", matrix[i][j]);
            int cur_num_len = find_len_of_num(matrix[i][j]);
            if (j != size - 1)
                for (int i = 0; i < (biggest_len - cur_num_len + 1); i++)
                    printf(" ");
        }
        
        if (i != size - 1)
            printf("\n");
    }
}

void free_matrix(int **matrix)
{
    if (matrix[0] != NULL)
        free(matrix[0]);
    if (matrix != NULL)
        free(matrix);
}