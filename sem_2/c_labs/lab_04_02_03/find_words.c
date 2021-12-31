#include "find_words.h"
#include <stdio.h>
#include <string.h>

int find_words(char *str, char words_arr[][17])
{
    int i = 0;
    char *check_arr = ",;:-.!?";
    int num_of_symbols_to_check = 7;
    int num_of_words = 0;
    int cur_word_i = 0;
    int last_sym_is_punctuation = 1;

    while (str[i] != '\0')
    {
        int is_punctuation = 0;
        for (int j = 0; j < num_of_symbols_to_check; j++)
            if (str[i] == check_arr[j])
                is_punctuation = 1;
        
        if (str[i] == ' ')
            is_punctuation = 1;
        
        if (is_punctuation == 0 && str[i] != ' ')
        {
            words_arr[num_of_words][cur_word_i] = str[i];
            if (str[i + 1] == '\0')
            {
                words_arr[num_of_words][cur_word_i + 1] = '\0';
                num_of_words++;
            }
            cur_word_i++;
        }
        else if (last_sym_is_punctuation == 0)
        {
            words_arr[num_of_words][cur_word_i] = '\0';
            num_of_words++;
            cur_word_i = 0;
        }

        i++;
        last_sym_is_punctuation = is_punctuation;
    }

    return num_of_words;
}

int read_string(char *str, int n)
{
    int cur_ch, i = 0;

    while ((cur_ch = getchar()) != '\n' && cur_ch != EOF)
        if (i < n - 1)
            str[i++] = cur_ch;

    str[i] = '\0';

    return i;
}

void not_clone(char new_arr[][MAX_WORD_LEN + 1], int *new_len, char cpy_arr[][MAX_WORD_LEN + 1], int cpy_pos)
{
    strcpy(new_arr[*new_len], cpy_arr[cpy_pos]);
    (*new_len)++;
}

void print_new_arr(char new_arr[][MAX_WORD_LEN + 1], int len)
{
    printf("Result: ");
    for (int i = 0; i < len; i++)
    {
        printf("%s", new_arr[i]);
        if (i != len - 1)
            printf("%c", ' ');
    }    
} 
