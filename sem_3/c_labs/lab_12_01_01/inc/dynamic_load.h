#ifndef _DYNAMIC_LOAD_H_
#define _DYNAMIC_LOAD_H_

#include "dynamic_utils.h"
#include "dynamic_key.h"
#include "dynamic_sort.h"
#include <windows.h>

typedef int(ARR_DECL *fn_allocate_arr_t)(int **arr_beg, int n);
typedef void(ARR_DECL *fn_free_arr_t)(int **arr_beg, int **arr_end);

typedef int(ARR_DECL *fn_get_count_elements_t)(FILE *f, int *count);
typedef int(ARR_DECL *fn_read_array_t)(FILE *f, int *arr, size_t n);
typedef int(ARR_DECL *fn_create_array_t)(FILE *f, int **arr, size_t *n);

typedef void(ARR_DECL *fn_fprint_t)(FILE *f, const int *arr_beg, const int *arr_end);

typedef void(ARR_DECL *fn_swap_t)(void *elem_1, void *elem_2, size_t size);
typedef void(ARR_DECL *fn_mysort_t)(void *base, size_t n, size_t size, int (*cmp)(const void *, const void *));

typedef int(ARR_DECL *fn_find_arr_size_after_key_t)(const int *pb_src, const int *pe_src);
typedef int(ARR_DECL *fn_key_t)(const int *pb_src, const int *pe_src, int *pb_dst, int *pe_dst);

typedef void(ARR_DECL *fn_key_swap_t)(int **f, int **s);
typedef int(ARR_DECL *fn_comparator_t)(const void *elem_1, const void *elem_2);

int lib_allocate_and_free(HMODULE hlib, fn_allocate_arr_t *allocate_arr, fn_free_arr_t *free_arr);
int lib_io_and_create(HMODULE hlib, fn_get_count_elements_t *get_count, fn_create_array_t *create,
                                        fn_read_array_t *read, fn_fprint_t *print);
int lib_key_and_sort(HMODULE hlib, fn_swap_t *swap, fn_mysort_t *mysort,
                               fn_find_arr_size_after_key_t *get_count, fn_key_t *key, fn_key_swap_t *key_swap, fn_comparator_t *comparator);

#endif