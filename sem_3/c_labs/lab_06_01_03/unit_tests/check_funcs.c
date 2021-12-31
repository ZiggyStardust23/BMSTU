#include "check_main.h"
#include <string.h>

START_TEST(test_cheaper)
{
    struct goods struct_arr[3];

    struct goods s_1, s_2, s_3;

    strcpy(s_1.name, "a");
    strcpy(s_2.name, "b");
    strcpy(s_3.name, "c");

    s_1.price = 10;
    s_2.price = 20;
    s_3.price = 30;

    struct_arr[0] = s_1;
    struct_arr[1] = s_2;
    struct_arr[2] = s_3;

    int structs_num = 3;

    struct goods new_arr[2];

    int new_len = which_ones_are_cheaper(struct_arr, structs_num, new_arr, 21);

    ck_assert_int_eq(new_len, 2);
    ck_assert_int_eq(new_arr[0].price, 10);
    ck_assert_int_eq(new_arr[1].price, 20);
}

END_TEST

START_TEST(test_cheaper_empty)
{
    struct goods struct_arr[3];

    struct goods s_1, s_2, s_3;

    strcpy(s_1.name, "a");
    strcpy(s_2.name, "b");
    strcpy(s_3.name, "c");

    s_1.price = 10;
    s_2.price = 20;
    s_3.price = 30;

    struct_arr[0] = s_1;
    struct_arr[1] = s_2;
    struct_arr[2] = s_3;

    int structs_num = 3;

    struct goods new_arr[3];

    int new_len = which_ones_are_cheaper(struct_arr, structs_num, new_arr, 9);

    ck_assert_int_eq(new_len, 0);
}

END_TEST

Suite *funcs_suite(void)
{
    Suite *s = suite_create("check_funcs");
    TCase *tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_cheaper);
    tcase_add_test(tc_pos, test_cheaper_empty);
    suite_add_tcase(s, tc_pos);
    return s;
}