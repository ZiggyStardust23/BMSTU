#include "../inc/check_main.h"

int main()
{
    int num_of_errors = 0;

    num_of_errors += check_find_arr_len();
    num_of_errors += check_which_once_are_cheaper();

    num_of_errors += tests_char_is_num();
    num_of_errors += tests_str_is_num();

    return num_of_errors;
}