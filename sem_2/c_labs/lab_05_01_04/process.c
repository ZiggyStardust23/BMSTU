#include <stdio.h>
#include "process.h"

#define INCORRECT_INPUT -1

int process(FILE *f, int *result)
{
    int left, mid, right;
    int cur;
    int res = 0;

    if (fscanf(f, "%d", &left) != 1)
        return INCORRECT_INPUT;
    if (fscanf(f, "%d", &mid) != 1)
        return INCORRECT_INPUT;
    if (fscanf(f, "%d", &right) != 1)
        return INCORRECT_INPUT;
    
    if (mid > left && mid > right)
        (*result)++;

    while (fscanf(f, "%d", &cur) == 1)
    {
        left = mid;
        mid = right;
        right = cur;

        if (mid > left && mid > right)
            res++;
    }
    *result = res;

    return 0;
}