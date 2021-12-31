#include "../inc/check_my_snprintf.h"

int main(void)
{
    int failed_tests = 0;

    failed_tests += test_snprintf_c();
    failed_tests += test_snprintf_s();
    failed_tests += test_snprintf_d();
    failed_tests += test_snprintf_o();

    return failed_tests;
}
