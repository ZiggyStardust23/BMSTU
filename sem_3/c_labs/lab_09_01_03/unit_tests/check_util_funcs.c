#include "../inc/check_main.h"

int tests_char_is_num()
{
    int test_pos = 2;
    int pos_count = 0;

    char ch = '2';
    if (if_char_is_num(ch) != 1)
        pos_count++;
    
    ch = 'b';
    if (if_char_is_num(ch) != 0)
        pos_count++;

    printf("===%s:", __func__);
    printf("\n -Позитивные тесты: %d of %d - %s", test_pos - pos_count, test_pos, pos_count ? "FAILED" : "SUCCESS\n");
    
    return pos_count;
}

int tests_str_is_num()
{
    int test_pos = 2;
    int pos_count = 0;

    char *str = "123";
    if (check_if_str_is_num(str) != 0)
        pos_count++;
    
    char *str_not = "abc";
    if (check_if_str_is_num(str_not) != NOT_NUM)
        pos_count++;

    printf("===%s:", __func__);
    printf("\n -Позитивные тесты: %d of %d - %s", test_pos - pos_count, test_pos, pos_count ? "FAILED" : "SUCCESS\n");
    
    return pos_count;
}