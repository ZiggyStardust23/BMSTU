#ifndef _CHECK_STR_H_
#define _CHECK_STR_H_

#define MAX_STR_LEN 256
#define MAX_WORD_LEN 16

#define STRING_IS_TOO_LONG -1

int check_if_correct(char in_str[MAX_STR_LEN + 1], int str_len);

int read_str(char str[MAX_STR_LEN]);

int fill_arr(char str[MAX_STR_LEN], char (*arr)[MAX_STR_LEN + 1]);

#endif
