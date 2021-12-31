#include "../inc/check_sort.h"

static int unsorted[] = {-10, 3, -4, 37};
static int sorted[] =    {-10, -4, 3, 37};
static int same_nums[] =  {10, 10};
static int temp_same_nums[] =  {10, 10};

START_TEST(sort_unsorted_array)
{
    mysort(unsorted, sizeof(unsorted) / sizeof(int), sizeof(int), comparator);
    ck_assert_mem_eq(sorted, unsorted, sizeof(sorted) / sizeof(sorted[0]));
}
END_TEST

START_TEST(sort_sorted_array)
{
    mysort(same_nums, sizeof(same_nums) / sizeof(same_nums[0]), sizeof(same_nums[0]), comparator);
    ck_assert_mem_eq(temp_same_nums, same_nums, sizeof(temp_same_nums) / sizeof(temp_same_nums[0]));
}
END_TEST

START_TEST(comparator_pos_nums)
{
    int first = 100;
    int second = 10;
    int result = comparator(&first, &second);
    ck_assert(result > 0);
}
END_TEST

START_TEST(comparator_neg_nums)
{
    int first = 3;
    int second = 14;
    int result = comparator(&first, &second);
    ck_assert(result < 0);
}
END_TEST

Suite *sort_suite(void)
{
    Suite *st_sort;
    TCase *tc_pos;

    st_sort = suite_create("_MYSORT_");

    tc_pos = tcase_create("_POS_TEST_");
    tcase_add_test(tc_pos, sort_unsorted_array);
    tcase_add_test(tc_pos, sort_sorted_array);
    suite_add_tcase(st_sort, tc_pos);
    return st_sort;
}

Suite *comparator_suite(void)
{
    Suite *st_cmp;
    TCase *tc_pos;

    st_cmp = suite_create("_COMPARATOR_");

    tc_pos = tcase_create("_POS_TEST_");
    tcase_add_test(tc_pos, comparator_pos_nums);
    tcase_add_test(tc_pos, comparator_neg_nums);
    suite_add_tcase(st_cmp, tc_pos);
    return st_cmp;
}