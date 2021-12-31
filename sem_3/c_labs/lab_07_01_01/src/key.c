#include "../inc/key.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void key_swap(int **f, int **s)
{
    int *temp = NULL;
    temp = *f;
    *f = *s;
    *s = temp;
}

int key(int *pb_src, int *pe_src, int **pb_dst, int **pe_dst)
{   
    int error_code = 0;
    int *min = NULL;
    int *max = NULL;

    *pb_dst = NULL;
    *pe_dst = NULL;

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
            int len = end - begin;
            *pb_dst = malloc(len * sizeof(int));
            if (*pb_dst == NULL)
                error_code = MEMORY_ERROR;
            if (error_code == 0)
            {
                *pe_dst = *pb_dst + len;
                memcpy(*pb_dst, begin, len * sizeof(int));
            }
        }
    }
    return error_code;
}
