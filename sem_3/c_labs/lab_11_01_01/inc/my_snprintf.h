#ifndef _MY_SNPRINTF_H_
#define _MY_SNPRINTF_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int my_snprintf(char *restrict buf, size_t num, const char *restrict format, ...);

void snprintf_char(const char *restrict format, char *buf, va_list args, int *cur_format_len, int *cur_buf_len, size_t num, char cur_ch);

void snprintf_string(const char *restrict format, char *buf, va_list args, int *cur_format_len, int *cur_buf_len, size_t num, char *cur_str);

void snprintf_d(const char *restrict format, char *buf, va_list args, int *cur_format_len, int *cur_buf_len, size_t num, int cur_int);

void snprintf_o(const char *restrict format, char *buf, va_list args, int *cur_format_len, int *cur_buf_len, size_t num, unsigned long int cur_int);

void write_o_num_to_buf(char *buf, unsigned long int cur_int, int *cur_buf_len, int *cur_format_len, size_t num);

int find_len_of_o_num(unsigned long int cur_int);

void write_zero_to_buf(char *buf, int *cur_buf_len, int *cur_format_len, size_t num);

void write_num_to_buf(char *buf, int cur_int, int *cur_buf_len, int *cur_format_len, size_t num);

int find_len_of_num(int num);

void write_null_string(char *buf, int *cur_format_len, int *cur_buf_len, size_t num);

#endif