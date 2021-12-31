#include "util_funcs.h"

#include <string.h>

int if_char_is_num(char ch)
{
    return '0' <= ch && ch <= '9' ? 1 : 0;
}

int check_if_str_is_num(char *str)
{
    int error_code = 0;

    int str_len = strlen(str);
    int num_of_points = 0;
    for (int i = 0; i < str_len; i++)
    {
        if (error_code == 0)
        {
            if (str[i] == '.')
                num_of_points++;
            else if (!if_char_is_num(str[i]))
                error_code = NOT_NUM;
        }
    }
    if (error_code == 0 && num_of_points > 1)
        error_code = NOT_NUM;
    return error_code;
}