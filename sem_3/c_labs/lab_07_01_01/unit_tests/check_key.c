#include "../inc/check_main.h"

START_TEST(tests_key_empty_array)
{
    int *pb_src, *pe_src, *pb_dst, *pe_dst;
    int array[] = {0};

    pb_src = array;
    pe_src = array;

    int result = key(pb_src, pe_src, &pb_dst, &pe_dst);
    ck_assert_int_eq(result, NO_ELEMENTS_BETWEEN);
    ck_assert_ptr_null(pb_dst);
}
END_TEST

START_TEST(tests_key_same_array)
{
    int *pb_src, *pe_src, *pb_dst, *pe_dst;
    int array[3] = {3, 3, 3};

    pb_src = array;
    pe_src = array + 3;

    int result = key(pb_src, pe_src, &pb_dst, &pe_dst);
    ck_assert_int_eq(result, NO_ELEMENTS_BETWEEN);
    ck_assert_ptr_null(pb_dst);
}
END_TEST

START_TEST(tests_key_two_elems)
{
    int *pb_src, *pe_src, *pb_dst, *pe_dst;
    int array[2] = {1, 3};

    pb_src = array;
    pe_src = array + 1;

    int result = key(pb_src, pe_src, &pb_dst, &pe_dst);
    ck_assert_int_eq(result, NO_ELEMENTS_BETWEEN);
    ck_assert_ptr_null(pb_dst);
}
END_TEST

START_TEST(tests_key_two_near_in_arr)
{
    int *pb_src, *pe_src, *pb_dst, *pe_dst;
    int array[4] = {5, 1, 3, 4};

    pb_src = array;
    pe_src = array + 3;

    int result = key(pb_src, pe_src, &pb_dst, &pe_dst);
    ck_assert_int_eq(result, NO_ELEMENTS_BETWEEN);
    ck_assert_ptr_null(pb_dst);
}
END_TEST

START_TEST(tests_key_normal)
{
    int *pb_src, *pe_src, *pb_dst, *pe_dst;
    int array[5] = {5, 1, 6, 9, 4};

    pb_src = array;
    pe_src = array + 4;

    int result = key(pb_src, pe_src, &pb_dst, &pe_dst);
    ck_assert_int_eq(result, 0);
    ck_assert_ptr_nonnull(pb_dst);
    free(pb_dst);
}
END_TEST

START_TEST(tests_key_normal_2)
{
    int *pb_src, *pe_src, *pb_dst, *pe_dst;
    int array[6] = {5, 1, 6, 7, 9, 4};

    pb_src = array;
    pe_src = array + 5;

    int result = key(pb_src, pe_src, &pb_dst, &pe_dst);
    ck_assert_int_eq(result, 0);
    ck_assert_ptr_nonnull(pb_dst);
    free(pb_dst);
}
END_TEST

START_TEST(tests_key_normal_reverse)
{
    int *pb_src, *pe_src, *pb_dst, *pe_dst;
    int array[6] = {5, 9, 6, 7, 1, 4};

    pb_src = array;
    pe_src = array + 5;

    int result = key(pb_src, pe_src, &pb_dst, &pe_dst);
    ck_assert_int_eq(result, 0);
    ck_assert_ptr_nonnull(pb_dst);
    free(pb_dst);
}
END_TEST

Suite *key_suite(void)
{
    Suite *s = suite_create("key");
    TCase *tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, tests_key_empty_array);
    tcase_add_test(tc_pos, tests_key_same_array);
    tcase_add_test(tc_pos, tests_key_two_elems);
    tcase_add_test(tc_pos, tests_key_two_near_in_arr);
    tcase_add_test(tc_pos, tests_key_normal);
    tcase_add_test(tc_pos, tests_key_normal_2);
    tcase_add_test(tc_pos, tests_key_normal_reverse);
    suite_add_tcase(s, tc_pos);

    return s;
}