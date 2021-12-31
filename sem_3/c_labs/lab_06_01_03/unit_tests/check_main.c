#include "check_main.h"

int main()
{
    SRunner *runner = srunner_create(util_funcs_suite());
    srunner_add_suite(runner, funcs_suite());

    srunner_run_all(runner, CK_VERBOSE);
    int num_of_fails = srunner_ntests_failed(runner);
    srunner_free(runner);
    
    if (num_of_fails == 0)
        return 0;
    else
        return -1;
}