#include <stdio.h>
#include "find_average.h"

#define INCORRECT_INPUT       -1
#define INCORRECT_NUM_OF_ARGS -2
#define FILE_NOT_FOUND        -3

int main(int argc, char **argv)
{
    if (argc != 2)
        return INCORRECT_NUM_OF_ARGS;

    FILE *f = fopen(argv[1], "r");

    if (f == NULL)
        return FILE_NOT_FOUND;
         
    float result = 0;
    
    int result_code = find_average(f, &result);
    fclose(f);

    if (result_code != 0)
        return result_code;
    else 
        printf("%f", result);
    return 0;
}