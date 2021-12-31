#include "check_main.h"

START_TEST(char_check_yes)
{
    char ch = '8';

    int result = if_char_is_num(ch);

    ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(char_check_no)
{
    char ch = 'a';

    int result = if_char_is_num(ch);

    ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(str_check_yes)
{
    char *str = "123";

    int result = check_if_str_is_num(str);

    ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(str_check_no)
{
    char *str = "1s3";

    int result = check_if_str_is_num(str);

    ck_assert_int_eq(result, NOT_NUM);
}
END_TEST

Suite *util_funcs_suite(void)
{
    Suite *s = suite_create("check_util_funcs");
    TCase *tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, char_check_yes);
    tcase_add_test(tc_pos, char_check_no);
    tcase_add_test(tc_pos, str_check_yes);
    tcase_add_test(tc_pos, str_check_no);
    suite_add_tcase(s, tc_pos);
    return s;
}