#include "dynamic_load.h"

int lib_io_and_create(HMODULE hlib, fn_get_count_elements_t *get_count, fn_create_array_t *create,
                                        fn_read_array_t *read, fn_fprint_t *print)
{
    int error_code = 0;
    
    *get_count = (fn_get_count_elements_t)GetProcAddress(hlib, "find_num_of_elems");
    if (!*get_count)
        error_code = LIB_ERROR;

    if (error_code == 0)
    {
        *read = (fn_read_array_t)GetProcAddress(hlib, "read_arr");
         if (!*read)
            error_code = LIB_ERROR;
    }
    
    if (error_code == 0)
    {
        *create = (fn_create_array_t)GetProcAddress(hlib, "create_arr");
        if (!*create)
            error_code = LIB_ERROR;
    }
    
    if (error_code == 0)
    {
        *print = (fn_fprint_t)GetProcAddress(hlib, "fprint");
        if (!*print)
            error_code = LIB_ERROR;
    }

    return error_code;
}

int lib_allocate_and_free(HMODULE hlib, fn_allocate_arr_t *allocate_arr, fn_free_arr_t *free_arr)
{
    int error_code = 0;
    
    *allocate_arr = (fn_allocate_arr_t)GetProcAddress(hlib, "allocate_arr");
    if (!*allocate_arr)
        error_code = LIB_ERROR;
    
    if (error_code == 0)
    {
        *free_arr = (fn_free_arr_t)GetProcAddress(hlib, "free_arr");
        if (!*free_arr)
            error_code = LIB_ERROR;
    }
    
    return error_code;
}

int lib_key_and_sort(HMODULE hlib, fn_swap_t *swap, fn_mysort_t *mysort,
                               fn_find_arr_size_after_key_t *find_arr_size_after_key, fn_key_t *key, fn_key_swap_t *key_swap, fn_comparator_t *comparator)
{
    int error_code = 0;
    
    *swap = (fn_swap_t)GetProcAddress(hlib, "swap");
    if (!*swap)
        error_code = LIB_ERROR;

    if (error_code == 0)
    {
        *mysort = (fn_mysort_t)GetProcAddress(hlib, "mysort");
        if (!*mysort)
            error_code = LIB_ERROR;
    }
    
    if (error_code == 0)
    {
        *find_arr_size_after_key = (fn_find_arr_size_after_key_t)GetProcAddress(hlib, "find_arr_size_after_key");
        if (!*find_arr_size_after_key)
            error_code = LIB_ERROR;
    }

    if (error_code == 0)
    {
        *comparator = (fn_comparator_t)GetProcAddress(hlib, "comparator");
        if (!*comparator)
            error_code = LIB_ERROR;
    }
     
    if (error_code == 0)
    {
        *key = (fn_key_t)GetProcAddress(hlib, "key");
        if (!*key)
            error_code = LIB_ERROR;
    }

    if (error_code == 0)
    {
        *key_swap = (fn_key_swap_t)GetProcAddress(hlib, "key_swap");
        if (!*key_swap)
            error_code = LIB_ERROR;
    }

    return error_code;
}