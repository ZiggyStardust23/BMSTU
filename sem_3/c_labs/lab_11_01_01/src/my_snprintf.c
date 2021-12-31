#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <math.h>

#define INCORRECT_SPEC -1

#define O_BASE 8

void snprintf_char(const char *restrict format, char *buf, va_list args, int *cur_format_len, int *cur_buf_len, size_t num, char cur_ch)
{
    if (*cur_buf_len < (int)num)
    {
        buf[*cur_buf_len] = cur_ch;
    }
    (*cur_buf_len)++;
    (*cur_format_len)++;
    (*cur_format_len)++;
}

void write_null_string(char *buf, int *cur_format_len, int *cur_buf_len, size_t num)
{
    char null_word[6] = "(null)";
    for (int i = 0; i < 6; i++)
    {
        if (*cur_buf_len < (int)num)
            buf[*cur_buf_len] = null_word[i];
        (*cur_buf_len)++;
    }

    (*cur_format_len)++;
    (*cur_format_len)++;
}

void snprintf_string(const char *restrict format, char *buf, va_list args, int *cur_format_len, int *cur_buf_len, size_t num, char *cur_str)
{
    if (cur_str != NULL)
    {
        int cur_str_len = 0;
        while (cur_str[cur_str_len] != '\0')
        {
            if (*cur_buf_len < (int)num)
            {
                buf[*cur_buf_len] = cur_str[cur_str_len];
            }
            (*cur_buf_len)++;
            cur_str_len++;
        }

        (*cur_format_len)++;
        (*cur_format_len)++;
    }
    else
    {
        write_null_string(buf, cur_format_len, cur_buf_len, num);
    }
}

int find_len_of_num(int num)
{
    int len = 0;
    if (num == 0)
        len = 1;
    else
        while (num != 0)
        {
            len++;
            num /= 10;
        }

    return len;
}

void write_num_to_buf(char *buf, int cur_int, int *cur_buf_len, int *cur_format_len, size_t num)
{
    int int_len = find_len_of_num(cur_int);
    int save_buf_len = *cur_buf_len;

    for (int i = save_buf_len + int_len - 1; i >= save_buf_len; i--)
    {
        if (*cur_buf_len < (int)num)
        {
            buf[i] = abs(cur_int % 10) + '0';
            cur_int /= 10;
        }
        (*cur_buf_len)++;
    }

    (*cur_format_len)++;
    (*cur_format_len)++;
}

void write_zero_to_buf(char *buf, int *cur_buf_len, int *cur_format_len, size_t num)
{
    if (*cur_buf_len < (int)num)
        buf[*cur_buf_len] = '0';
    (*cur_buf_len)++;

    (*cur_format_len)++;
    (*cur_format_len)++;
}

void snprintf_d(const char *restrict format, char *buf, va_list args, int *cur_format_len, int *cur_buf_len, size_t num, int cur_int)
{
    if (cur_int < 0)
    {
        if (*cur_buf_len < (int)num)
            buf[*cur_buf_len] = '-';
        (*cur_buf_len)++;
    }

    if (cur_int != 0)
        write_num_to_buf(buf, cur_int, cur_buf_len, cur_format_len, num);
    else
        write_zero_to_buf(buf, cur_buf_len, cur_format_len, num);
}

int find_len_of_o_num(unsigned long int cur_int)
{
    int len = 0;
    if (cur_int == 0)
        len = 1;
    else
        while (cur_int != 0)
        {
            len++;
            cur_int /= O_BASE;
        }

    return len;
}

void write_o_num_to_buf(char *buf, unsigned long int cur_int, int *cur_buf_len, int *cur_format_len, size_t num)
{
    int len = find_len_of_o_num(cur_int);

    int save_cur_buf_len = *cur_buf_len;

    for (int j = save_cur_buf_len + len - 1; j >= save_cur_buf_len; j--)
    {
        if (*cur_buf_len < (int)num)
        {
            buf[j] = cur_int % O_BASE + '0';
            cur_int /= O_BASE;
        }
        (*cur_buf_len)++;
    }

    (*cur_format_len)++;
    (*cur_format_len)++;
}

void snprintf_o(const char *restrict format, char *buf, va_list args, int *cur_format_len, int *cur_buf_len, size_t num, unsigned long int cur_int)
{
    if (cur_int != 0)
        write_o_num_to_buf(buf, cur_int, cur_buf_len, cur_format_len, num);
    else
        write_zero_to_buf(buf, cur_buf_len, cur_format_len, num);
}

int my_snprintf(char *restrict buf, size_t num, const char *restrict format, ...)
{
    int result = 0;

    if (format == NULL)
    {
        if (buf != NULL)
            buf[0] = '\0';
        result = -1;
    }
    else if (buf == NULL)
    {
        int ret_nums = 0;
        while (format[ret_nums] != '\0')
            ret_nums++;
            
        result = ret_nums;
    }
    else
    {
        va_list args;
        va_start(args, format);

        if ((int)num < 0)
            num = 0x7fffffff;
        if ((int)num != 0)
            num = num - 1;
        
        int cur_buf_len = 0;
        int cur_format_len = 0;
        int stop_flag = 0;
        while (format[cur_format_len] != '\0' && stop_flag == 0)
        {
            if (format[cur_format_len] == '%' && format[cur_format_len + 1] != '\0')
            {
                if (format[cur_format_len + 1] == 'c')
                {
                    char cur_ch = (char)va_arg(args, int);
                    snprintf_char(format, buf, args, &cur_format_len, &cur_buf_len, num, cur_ch);
                }
                else if (format[cur_format_len + 1] == 's')
                {
                    char *cur_str = va_arg(args, char*);
                    snprintf_string(format, buf, args, &cur_format_len, &cur_buf_len, num, cur_str);
                }
                else if (format[cur_format_len + 1] == 'd')
                {
                    int cur_int = va_arg(args, int);
                    snprintf_d(format, buf, args, &cur_format_len, &cur_buf_len, num, cur_int);
                }
                else if (format[cur_format_len + 1] == 'o')
                {
                    unsigned long int cur_int = va_arg(args, unsigned long int);
                    snprintf_o(format, buf, args, &cur_format_len, &cur_buf_len, num, cur_int);
                }
                else if (format[cur_format_len] != '\0')
                {
                    stop_flag = 1;
                }
            }
            else
            {
                if (format[cur_format_len] == '%')
                    stop_flag = 1;
                else
                {
                    if (cur_buf_len < (int)num)
                        buf[cur_buf_len] = format[cur_format_len];
                    cur_buf_len++;
                    cur_format_len++;
                }
            }
        }

        if (cur_buf_len > num)
            buf[num] = '\0';
        else
            buf[cur_buf_len] = '\0';

        if (stop_flag == 1)
            result = -1;
        else
            result = cur_buf_len;
    }

    return result;
}