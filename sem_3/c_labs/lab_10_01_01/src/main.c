#include <stdio.h>
#include <stdlib.h>

#include "../inc/funcs.h"
#include "../inc/struct.h"
#include "../inc/io.h"
#include "../inc/process.h"

int main(int argc, char **argv)
{
    int error_code = 0;
    if (argc != 3)
        error_code = INCORRECT_ARGC;

    if (error_code == 0)
        error_code = process(argv[1], argv[2]);
    
    return error_code;
}