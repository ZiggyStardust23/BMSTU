#include <stdio.h>
#include <string.h>
#include "find_words.h"

int main()
{
    char str1[MAX_STR_LEN + 1];
    char str2[MAX_STR_LEN + 1];
    int len1, len2 = 0; 

    char words_arr_1[MAX_WORDS_IN_STR][MAX_WORD_LEN + 1];
    char words_arr_2[MAX_WORDS_IN_STR][MAX_WORD_LEN + 1];

    if (read_string(str1, MAX_STR_LEN + 1) == 0 || read_string(str2, MAX_STR_LEN + 1) == 0)
        return STRING_IS_EMPTY;

    len1 = find_words(str1, words_arr_1);
    len2 = find_words(str2, words_arr_2);

    if (len1 == 0 || len2 == 0)
        return NO_WORDS_IN_STRINGS;
        
    char new_word_arr[2 * MAX_WORDS_IN_STR][MAX_WORD_LEN + 1];
    int new_arr_len = 0;

    printf("Result: ");

    for (int i = 0; i < len1; i++)
    {
        int has_clone = 0;
        for (int j = 0; j < len1; j++)
            if (j != i && strcmp(words_arr_1[i], words_arr_1[j]) == 0)
                has_clone = 1;
        
        if (has_clone == 0)
            for (int j = 0; j < len2; j++)
                if (strcmp(words_arr_1[i], words_arr_2[j]) == 0)
                    has_clone = 1;

        if (has_clone == 0)
            not_clone(new_word_arr, &new_arr_len, words_arr_1, i);
    } 

    for (int i = 0; i < len2; i++)
    {
        int has_clone = 0;
        for (int j = 0; j < len1; j++)
            if (strcmp(words_arr_2[i], words_arr_1[j]) == 0)
                has_clone = 1;
        
        if (has_clone == 0)
            for (int j = 0; j < len2; j++)
                if (i != j && strcmp(words_arr_2[i], words_arr_2[j]) == 0)
                    has_clone = 1;

        if (has_clone == 0)
            not_clone(new_word_arr, &new_arr_len, words_arr_2, i);
    } 
    
    print_new_arr(new_word_arr, new_arr_len);

    return 0;
}
