#include "check_sort.h"
#include "check_key.h"

#include <check.h>

int main(void)
{
    int fails = 0;
    SRunner *run_func = NULL;

    run_func = srunner_create(sort_suite());
    srunner_run_all(run_func, CK_VERBOSE);
    fails += srunner_ntests_failed(run_func);
    srunner_free(run_func);
    run_func = NULL;

    run_func = srunner_create(key_suite());
    srunner_run_all(run_func, CK_VERBOSE);
    fails += srunner_ntests_failed(run_func);
    srunner_free(run_func);
    run_func = NULL;

    run_func = srunner_create(comparator_suite());
    srunner_run_all(run_func, CK_VERBOSE);
    fails += srunner_ntests_failed(run_func);
    srunner_free(run_func);
    run_func = NULL;

    return (fails == 0) ? 0 : -1;
}