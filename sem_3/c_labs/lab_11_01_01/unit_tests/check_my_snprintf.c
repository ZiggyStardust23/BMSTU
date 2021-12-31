#include "../inc/check_my_snprintf.h"
#include <string.h>

#define SIZE 100

int cmp_two_str(const char *a, const char *b)
{
    int not_same_flag = 0;
    int i = 0;
    if (my_strlen(a) != my_strlen(b))
        not_same_flag = 1;
    else
    {
        while (a[i] != '\0' && !not_same_flag)
        {
            if (a[i] != b[i])
                not_same_flag = 1;
            i++;
        }
    }
    
    return not_same_flag;
}

int my_strlen(const char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return i;
}

int test_snprintf_c(void)
{
    int pos_cnt = 0, test_pos = 3;

    int len1 = 0, len2 = 0;
    char str1[SIZE] = { '\0' };
    char str2[SIZE] = { '\0' };


    len1 = my_snprintf(str1, 10, "%c %c %c", 'a', 'b', 'c');
    len2 = snprintf(str2, 10, "%c %c %c", 'a', 'b', 'c');

    if (len1 != len2 || cmp_two_str(str1, str2) != 0)
        pos_cnt++;

    len1 = my_snprintf(str1, 40, "%c: and %c: and %c: and", 'a', 'b', 'c');
    len2 = snprintf(str2, 40, "%c: and %c: and %c: and", 'a', 'b', 'c');

    if (len1 != len2 || cmp_two_str(str1, str2) != 0)
        pos_cnt++;

    len1 = my_snprintf(str1, 100, "%c: and %c: and %c: and", 'a', 'b', 'c');
    len2 = snprintf(str2, 100, "%c: and %c: and %c: and", 'a', 'b', 'c');

    if (len1 != len2 || strcmp(str1, str2) != 0)
        pos_cnt++;

    printf("%s: %d of %d - %s\n", __func__, test_pos - pos_cnt, test_pos, pos_cnt ? "FAILED" : "SUCCESS");

    return pos_cnt;
}

int test_snprintf_s(void)
{
    int pos_cnt = 0, test_pos = 3;

    int len1 = 0, len2 = 0;

    char str1[SIZE] = { '\0' };
    char str2[SIZE] = { '\0' };


    len1 = my_snprintf(str1, 40, "%s%s%s", "test1", " ", "test2");
    len2 = snprintf(str2, 40, "%s%s%s", "test1", " ", "test2");

    if (len1 != len2 || cmp_two_str(str1, str2) != 0)
        pos_cnt++;

    len1 = my_snprintf(str1, 30, "%s: and %s: and %s: and", "a", "b", "c");
    len2 = snprintf(str2, 30, "%s: and %s: and %s: and", "a", "b", "c");

    if (len1 != len2 || cmp_two_str(str1, str2) != 0)
        pos_cnt++;

    len1 = my_snprintf(str1, 100, "%s: and %s: and %s: and", "a", "b", "c");
    len2 = snprintf(str2, 100, "%s: and %s: and %s: and", "a", "b", "c");

    if (len1 != len2 || cmp_two_str(str1, str2) != 0)
        pos_cnt++;

    printf("%s: %d of %d - %s\n", __func__, test_pos - pos_cnt, test_pos, pos_cnt ? "FAILED" : "SUCCESS");

    return pos_cnt;
}

int test_snprintf_d(void)
{
    int pos_cnt = 0, test_pos = 3;

    int len1 = 0, len2 = 0;
    char str1[SIZE] = { '\0' };
    char str2[SIZE] = { '\0' };

    len1 = my_snprintf(str1, 30, "%d %d %d", 100, -100, 0);
    len2 = snprintf(str2, 30, "%d %d %d", 100, -100, 0);

    if (len1 != len2 || cmp_two_str(str1, str2) != 0)
        pos_cnt++;

    len1 = my_snprintf(str1, 40, "%d: hi %d: hello %d: hallo", 1, 2, 3);
    len2 = snprintf(str2, 40, "%d: hi %d: hello %d: hallo", 1, 2, 3);

    if (len1 != len2 || cmp_two_str(str1, str2) != 0)
        pos_cnt++;

    len1 = my_snprintf(str1, 100, "%d: hi %d: hello %d: hallo", 1, 2, 3);
    len2 = snprintf(str2, 100, "%d: hi %d: hello %d: hallo", 1, 2, 3);

    if (len1 != len2 || cmp_two_str(str1, str2) != 0)
        pos_cnt++;

    printf("%s: %d of %d - %s\n", __func__, test_pos - pos_cnt, test_pos, pos_cnt ? "FAILED" : "SUCCESS");

    return pos_cnt;
}

int test_snprintf_o(void)
{
    int pos_cnt = 0, test_pos = 3;

    int len1 = 0, len2 = 0;
    char str1[SIZE] = { '\0' };
    char str2[SIZE] = { '\0' };

    len1 = my_snprintf(str1, 30, "%o %o %o", 100, -100, 0);
    len2 = snprintf(str2, 30, "%o %o %o", 100, -100, 0);

    if (len1 != len2 || cmp_two_str(str1, str2) != 0)
        pos_cnt++;

    len1 = my_snprintf(str1, 40, "%o: and %o: and %o: and", 1212, -2000, 3411);
    len2 = snprintf(str2, 40, "%o: and %o: and %o: and", 1212, -2000, 3411);

    if (len1 != len2 || cmp_two_str(str1, str2) != 0)
        pos_cnt++;

    len1 = my_snprintf(str1, 100, "%o: and %o: and %o: and", 1212, -2000, 3411);
    len2 = snprintf(str2, 100, "%o: and %o: and %o: and", 1212, -2000, 3411);

    if (len1 != len2 || cmp_two_str(str1, str2) != 0)
        pos_cnt++;

    printf("%s: %d of %d - %s\n", __func__, test_pos - pos_cnt, test_pos, pos_cnt ? "FAILED" : "SUCCESS");

    return pos_cnt;
}