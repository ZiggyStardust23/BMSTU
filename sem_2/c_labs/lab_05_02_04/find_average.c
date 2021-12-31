#include <stdio.h>
#include "find_average.h"

#define INCORRECT_INPUT -1

int find_average(FILE *f, float *result)
{
    int total_count;
    float max, min, cur;
    int max_i, min_i;
    
    if (fscanf(f, "%f", &cur) == 1)
    {
        total_count = 1;
        max = cur;
        min = cur;
        max_i = 0;
        min_i = 0;
    }
    else
        return INCORRECT_INPUT;

    while (fscanf(f, "%f", &cur) == 1)
    {
        if (cur > max)
        {
            max = cur;
            max_i = total_count;
        }

        if (cur < min)
        {
            min = cur;
            min_i = total_count;
        }

        total_count++;
    }

    fseek(f, 0L, SEEK_SET);
    int i = 0;
    float sum = 0;

    while (fscanf(f, "%f", &cur) == 1)
    {
        if (i > min_i && i < max_i)
            sum += cur;

        i++;
    }

    int num_of_nums_between = max_i - min_i - 1;
    *result = sum / num_of_nums_between;

    return 0;
}