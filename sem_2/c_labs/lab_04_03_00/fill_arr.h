#ifndef _FILL_ARR_H_
#define _FILL_ARR_H_

#define MAX_STR_LEN 256
#define MAX_WORD_LEN 16
#define MAX_NUM_OF_WORDS_IN_STR 127 

#define STRING_IS_EMPTY -1
#define NEW_STR_IS_EMPTY -2

int fill_arr(char *str, char arr[][MAX_WORD_LEN + 1]);

void make_new_str(char word_arr[][MAX_WORD_LEN + 1], char str[MAX_STR_LEN + 1], int cur_new_arr_len);

int read_string(char *str, int n);

int delete_same_letters(char word_arr[][MAX_WORD_LEN + 1], char new_word_arr[][MAX_WORD_LEN + 1], int num_of_words);

#endif
