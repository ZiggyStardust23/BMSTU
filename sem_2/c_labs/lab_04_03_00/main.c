#include <string.h>
#include <stdio.h>
#include "fill_arr.h"

int main()
{
    char word_arr[MAX_NUM_OF_WORDS_IN_STR][MAX_WORD_LEN + 1];
    char new_word_arr[MAX_NUM_OF_WORDS_IN_STR][MAX_WORD_LEN + 1];
    char str[MAX_STR_LEN + 1];
    char new_str[MAX_STR_LEN + 1];

    if (read_string(str, MAX_STR_LEN + 1) == 0)
        return STRING_IS_EMPTY;

    int num_of_words = fill_arr(str, word_arr);
    
    int cur_new_arr_len = delete_same_letters(word_arr, new_word_arr, num_of_words);
    
    if (cur_new_arr_len == 0)
        return NEW_STR_IS_EMPTY;
    
    make_new_str(new_word_arr, new_str, cur_new_arr_len);

    printf("Result: %s\n ", new_str);

    return 0;
}
