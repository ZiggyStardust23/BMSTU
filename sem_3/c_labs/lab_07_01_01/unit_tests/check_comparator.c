#include "../inc/check_main.h"

START_TEST(tests_compare_lower)
{
    int first = 1;
    int second = 5;

    int *p_first = &first;
    int *p_second = &second;

    int result = comparator(p_first, p_second);
    ck_assert_int_eq(result, -1);
}
END_TEST

START_TEST(tests_compare_equal)
{
    int first = 5;
    int second = 5;

    int *p_first = &first;
    int *p_second = &second;

    int result = comparator(p_first, p_second);
    ck_assert_int_eq(result, -1);
}
END_TEST

START_TEST(tests_compare_bigger)
{
    int first = 5;
    int second = 1;

    int *p_first = &first;
    int *p_second = &second;

    int result = comparator(p_first, p_second);
    ck_assert_int_eq(result, 1);
}
END_TEST

Suite *comparator_suite(void)
{
    Suite *s = suite_create("comparator");
    TCase *tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, tests_compare_lower);
    tcase_add_test(tc_pos, tests_compare_equal);
    tcase_add_test(tc_pos, tests_compare_bigger);
    suite_add_tcase(s, tc_pos);

    return s;
}