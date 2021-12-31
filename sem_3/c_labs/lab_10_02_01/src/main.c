#include <stdio.h>

#include "../inc/funcs.h"
#include "../inc/struct.h"
#include "../inc/process.h"

#define EMPTY_POLYNOM -2

int main()
{
    int error_code = 0;
    int choice = -1;

    error_code = read_choice(&choice);

    if (error_code == 0)
    {
        if (choice == 0)
            error_code = process_count_val();
        else if (choice == 1)
            error_code = process_find_ddx();
        else if (choice == 2)
            error_code = process_sum();
        else if (choice == 3)
            error_code = process_split_to_odd_even();
    }

    return error_code;
}