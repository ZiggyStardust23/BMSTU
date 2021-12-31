#include "../inc/check_main.h"

int main()
{
    int num_of_errors = 0;

    num_of_errors += check_find();
    num_of_errors += check_sort();
    num_of_errors += check_comparator();
    num_of_errors += check_pop_front();

    return num_of_errors;
}