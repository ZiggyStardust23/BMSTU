#include "../inc/utils.h"

int enter_two_int(int *a, int *b)
{
    int error_code = 0;

    if (scanf("%d", a) != 1)
        error_code = READ_ERROR;
    if (error_code == 0 && scanf("%d", b) != 1)
        error_code = READ_ERROR;
    
    return error_code;    
}