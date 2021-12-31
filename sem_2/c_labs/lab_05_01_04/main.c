#include <stdio.h>
#include "process.h"

#define INCORRECT_INPUT -1

int main()
{
    int result;
    
    if (process(stdin, &result) != 0)
        return INCORRECT_INPUT;

    printf("%d", result);

    return 0;       
}