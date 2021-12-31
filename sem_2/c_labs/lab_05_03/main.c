#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "funcs.h"

#define INCORRECT_COMMAND     -1
#define INCORRECT_NUM         -2
#define INCORRECT_FILE_NAME   -3
#define INCORRECT_NUM_OF_ARGS -4
#define FILE_NOT_FOUND        -5
#define ACCESS_ERROR          -6
#define FILE_IS_EMPTY         -7

int main(int argc, char **argv)
{
    if (argc == 4)
    {
        if (argv[1][0] != 'c')
            return INCORRECT_COMMAND;
        
        int checked_num = check_correct_int(argv[2]);
        if (checked_num == INCORRECT_NUM)
            return INCORRECT_NUM;
        
        if (make_file(argv[3], checked_num) != 0)
            return INCORRECT_FILE_NAME;
    }

    if (argc == 3)
    {
        if (argv[1][0] == 'p')
        {
            FILE *f = fopen(argv[2], "r");
            if (f == NULL)
                return FILE_NOT_FOUND;
            if (print_file(f) != 0)
                return FILE_IS_EMPTY;

            fclose(f);
        }
        else if (argv[1][0] == 's')
        {
            FILE *f = fopen(argv[2], "r+");
            if (f == NULL)
                return FILE_NOT_FOUND;
            if (sort(f) != 0)
                return ACCESS_ERROR;

            fclose(f);
        }
        else
            return INCORRECT_COMMAND;
    }
    else
        return INCORRECT_NUM_OF_ARGS;

    return 0;
}