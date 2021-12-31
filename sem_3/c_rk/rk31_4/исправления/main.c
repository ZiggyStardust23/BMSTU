#include <stdio.h>
#include <stdlib.h>

#define FILE_NOT_FOUND -1
#define DATA_ERROR -2
#define READ_ERROR -3
#define SIZE_ERROR -4
#define ARGS_ERROR -5

#include "matrix_funcs.h"
#include "snake.h"
#include "util.h"

int main(int argc, char **argv)
{
    int error_code = 0;

    if (argc != 2)
        error_code = ARGS_ERROR;

    FILE *f_in = NULL;
    
    if (error_code == 0)
    {
        f_in = fopen(argv[1], "r");
        if (f_in == NULL)
            error_code = FILE_NOT_FOUND;
    }
    
    int size = 0;
    if (error_code == 0)
        error_code = find_size_of_matrix(f_in, &size);

    int **matrix = NULL;
    int *data = NULL;

    if (error_code == 0)
    {
        matrix = malloc(size * sizeof(int*));
        if (matrix == NULL)
            error_code = DATA_ERROR;

        if (error_code == 0)
	        data = malloc(size * size * sizeof(int));
        if (data == NULL)
            error_code = DATA_ERROR;

        if (error_code == 0)
            for (int i = 0; i < size; i++)
		        matrix[i] = data + i * size;


        if (error_code == 0)
            error_code = read_sort_and_write_to_matrix(f_in, matrix, size);
    }

    if (f_in != NULL)
        fclose(f_in);
    
    if (error_code == 0)
    {
        snake_sort(matrix, size);
        print_matrix(matrix, size);
    }

    free_matrix(matrix);

    return error_code;
}