#include "../inc/check_main.h"

int main()
{
    SRunner *runner = srunner_create(comparator_suite());
    srunner_add_suite(runner, key_suite());
    srunner_add_suite(runner, mysort_suite());

    srunner_run_all(runner, CK_VERBOSE);
    int num_of_fails = srunner_ntests_failed(runner);
    srunner_free(runner);
    
    if (num_of_fails == 0)
        return 0;
    else
        return -1;
}
