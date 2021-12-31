#include "../inc/dynamic_utils.h"

ARR_DLL int ARR_DECL allocate_arr(int **arr_beg, int n)
{
    int error_code = 0;
    int *arr_p = NULL;

    arr_p = malloc(n * sizeof(int));

    if (!arr_p)
        error_code = MEMORY_ERROR;
    else
        *arr_beg = arr_p;

    return error_code;
}

ARR_DLL void ARR_DECL free_arr(int **arr_beg, int **arr_end)
{
    free(*arr_beg);

    *arr_beg = NULL;
    *arr_end = NULL;
}

ARR_DLL int ARR_DECL find_num_of_elems(FILE *f, int *count)
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

ARR_DLL int ARR_DECL read_arr(FILE *f_in, int *arr, size_t size)
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

ARR_DLL void ARR_DECL fprint(FILE *f_in, const int *pb, const int *pe)
{
    for (size_t i = 0; i < pe - pb; i++)
        fprintf(f_in, "%d ", *(pb + i));
}

ARR_DLL int ARR_DECL create_arr(FILE *f_in, int **arr, size_t *n_size)
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
