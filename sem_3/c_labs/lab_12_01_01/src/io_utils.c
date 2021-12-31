#include "../inc/utils.h"
int allocate_arr(int **arr_beg, int n)
{
    int *p = NULL;
    int error_code = 0;
    p = malloc(n * sizeof(int));
    if (!p)
        error_code = MEMORY_ERROR;
    else
        *arr_beg = p;
    return error_code;
}

void free_arr(int **arr_beg, int **arr_end)
{
    free(*arr_beg);
    *arr_beg = NULL;
    *arr_end = NULL;
}

int find_num_of_elems(FILE *f, int *count)
{
    int error_code = 0, i = 0, buff;
    while ((error_code = fscanf(f, "%d", &buff)) == 1)
        i++;
    if (error_code == 0)
        error_code = FILE_ERROR;
    else if (i == 0)
        error_code = FILE_ERROR;
    else
    {
        *count = i;
        error_code = 0;
    }
    return error_code;
}

int read_arr(FILE *f_in, int *arr, size_t size)
{
    int error_code = 0;

    if (arr == NULL || f_in == NULL ||  size <= 0)
        error_code = INCORRECT_PARAMS;
    else
    {
        for (size_t n_size = 0; n_size < size && error_code == 0; n_size++)
        {
            if (fscanf(f_in, "%d", arr + n_size) != 1)
                error_code = EXIT_FAILURE;
        }
    }
    return error_code;
}

void fprint(FILE *f_in, const int *pb, const int *pe)
{
    for (size_t i = 0; i < pe - pb; i++)
        fprintf(f_in, "%d ", *(pb + i));
}


int create_arr(FILE *f_in, int **arr, size_t *n_size)
{
    int error_code = 0;
    if (f_in == NULL)
        error_code = INCORRECT_PARAMS;
    else
    {
        int *init_p = NULL;
        int count_size = 0;
        error_code = find_num_of_elems(f_in, &count_size);
        if (error_code == 0)
            error_code = allocate_arr(&init_p, count_size);
        if (error_code == 0)
        {
            rewind(f_in);
            error_code = read_arr(f_in, init_p, count_size);
        }
        if (error_code == 0)
        {
            *arr = init_p;
            *n_size = count_size;
        }
        else
        {
            free(init_p);
            init_p = NULL;
        }
    }
    return error_code;
}