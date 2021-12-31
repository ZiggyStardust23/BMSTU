#include "../inc/check_main.h"

int main()
{
    int num_of_errors = 0;

    num_of_errors += check_ddx();

    return num_of_errors;
}