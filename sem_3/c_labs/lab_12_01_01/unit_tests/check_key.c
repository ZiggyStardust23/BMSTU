#include "../inc/check_key.h"

static int not_filtered[] = {-10, 30, 40, 70};
static int filtered[] = {30, 40};
static int same_nums[] =  {10, 10};

START_TEST(key_incorrect_params)
{
    int error_code;
    int *filter_begin = NULL, *filter_end = NULL;
    int *arr_beg = not_filtered;
    int *arr_end = arr_beg + 4;

    error_code = key(NULL, arr_end, filter_begin, filter_end);
    ck_assert_int_eq(error_code, MEMORY_ERROR);
    free(filter_begin);
    filter_begin = NULL;
    filter_end = NULL;

    error_code = key(arr_beg, NULL, filter_begin, filter_end);
    ck_assert_int_eq(error_code, MEMORY_ERROR);
    free(filter_begin);
    filter_begin = NULL;
    filter_end = NULL;
}
END_TEST

START_TEST(key_empty_arr)
{
    int error_code;
    int *filter_begin = NULL, *filter_end = NULL;
    int *arr_beg = not_filtered;
    int *arr_end = arr_beg;
    
    filter_begin = malloc(4 * sizeof(int));
    filter_end = filter_begin + 4;
    
    error_code = key(arr_beg, arr_end, filter_begin, filter_end);
    ck_assert_int_eq(error_code, NO_ELEMENTS_BETWEEN);
    
    free(filter_begin);
    filter_begin = NULL;
    filter_end = NULL;
}
END_TEST

START_TEST(key_not_filtered_arr)
{
    int error_code;
    int *filter_begin = NULL, *filter_end = NULL;
    int *arr_beg = not_filtered;
    int *arr_end = (arr_beg + 4);
    
    filter_begin = malloc(2 * sizeof(int));
    filter_end = filter_begin + 2;
    
    error_code = key(arr_beg, arr_end, filter_begin, filter_end);
    
    ck_assert_int_eq(error_code, 0);
    ck_assert_mem_eq(filtered, filter_begin, (filter_end - filter_begin) * sizeof(int));
    
    free(filter_begin);
    filter_begin = NULL;
    filter_end = NULL;
}
END_TEST

Suite *key_suite(void)
{
    Suite *st_filter;
    TCase *tc_neg;
    TCase *tc_pos;

    st_filter = suite_create("_KEY_");

    tc_neg = tcase_create("_NEG_TEST_");
    tcase_add_test(tc_neg, key_incorrect_params);
    tcase_add_test(tc_neg, key_empty_arr);
    suite_add_tcase(st_filter, tc_neg);

    tc_pos = tcase_create("_POS_TEST_");
    tcase_add_test(tc_pos, key_not_filtered_arr);
    suite_add_tcase(st_filter, tc_pos);

    return st_filter;
}