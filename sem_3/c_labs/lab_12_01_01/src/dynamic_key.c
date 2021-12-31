#include "../inc/dynamic_key.h"

ARR_DLL void ARR_DECL key_swap(int **f, int **s)
{
    int *temp = NULL;
    temp = *f;
    *f = *s;
    *s = temp;
}

ARR_DLL int ARR_DECL find_arr_size_after_key(const int *pb_src, const int *pe_src)
{
    int *min = pb_src;
    int *max = pb_src;
    for (int *i = pb_src + 1; i < pe_src; i++)
    {
        if (*i < *min)
        {
            min = i;
        }
        if (*i > *max)
        {
            max = i;
        }
    }

    int *begin = min;
    int *end = max;

    if (end < begin)
    {
        key_swap(&begin, &end);
    }
    begin++;

    return end - begin;
}

ARR_DLL int ARR_DECL key(const int *pb_src, const int *pe_src, int *pb_dst, int *pe_dst)
{
   int error_code = 0;
    int *min = NULL;
    int *max = NULL;

    if (pb_src == pe_src)
        error_code = NO_ELEMENTS_BETWEEN;

    if (pb_src == NULL || pe_src == NULL)
        error_code = MEMORY_ERROR;
    
    if (error_code == 0)
    {
        min = pb_src;
        max = pb_src;
        for (int *i = pb_src + 1; i < pe_src; i++)
        {
            if (*i < *min)
            {
                min = i;
            }
            if (*i > *max)
            {
                max = i;
            }
        }

        int *begin = min;
        int *end = max;

        if (end < begin)
        {
            key_swap(&begin, &end);
        }
        begin++;

        if (begin - end >= 0)
            error_code = NO_ELEMENTS_BETWEEN;

        if (error_code == 0)
        {
            int dst_len = end - begin;
            if (pb_dst == NULL)
                error_code = MEMORY_ERROR;

            memcpy(pb_dst, begin, dst_len * sizeof(int));
        }
    }
    return error_code;
}