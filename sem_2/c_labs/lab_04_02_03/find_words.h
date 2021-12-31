#ifndef _FIND_WORDS_H_
#define _FIND_WORDS_H_

#define MAX_STR_LEN 256
#define MAX_WORD_LEN 16
#define MAX_WORDS_IN_STR 127 

#define STRING_IS_EMPTY -1
#define NO_WORDS_IN_STRINGS -2

int find_words(char *str, char words_arr[][MAX_WORD_LEN + 1]);

void print_new_arr(char new_arr[][MAX_WORD_LEN + 1], int len);

void not_clone(char new_arr[][MAX_WORD_LEN + 1], int *new_len, char cpy_arr[][MAX_WORD_LEN + 1], int cpy_pos);

int read_string(char *str, int n);

#endif 
