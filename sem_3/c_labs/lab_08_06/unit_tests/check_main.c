//#include "../inc/check_main.h"

#include "../inc/check_main.h"

int main(void)
{
    int failed_tests = 0;

    failed_tests += tests_pow_matrix();
    failed_tests += tests_matrix_multy();

    failed_tests += tests_make_square_matrix();
    failed_tests += tests_form_matrix();

    return failed_tests;
}