#include <string.h>
#include <stdio.h>

#include "my_str_funcs.h"

#define NOT_SAME_RESULT -1

int main()
{
    char test_str[] = "test";
    if (my_strchr(test_str, 't') != strchr(test_str, 't'))
        return NOT_SAME_RESULT; 
    return 0;
}
