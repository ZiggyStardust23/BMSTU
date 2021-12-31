#include <string.h>
#include <stdio.h>
#include "fill_arr.h"

int fill_arr(char *str, char arr[][MAX_WORD_LEN + 1])
{
    char *delim = ",;:-.!? \n";
    char *cur_word = strtok(str, delim);
    int num_of_words = 0;

    while (cur_word != NULL)
    {
        strcpy(arr[num_of_words], cur_word);
        num_of_words++;
        cur_word = strtok(NULL, delim);
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

void make_new_str(char word_arr[][MAX_WORD_LEN + 1], char str[MAX_STR_LEN + 1], int cur_new_arr_len)
{
    int cur_new_str_len = 0;
    
    for (int i = cur_new_arr_len - 1; i >= 0; i--)
    {
        unsigned int word_len = strlen(word_arr[i]);
        for (unsigned int j = 0; j < word_len; j++)
        {
            str[cur_new_str_len] = word_arr[i][j];
            cur_new_str_len++;
        }

        if (i == 0)
            str[cur_new_str_len] = '\0';
        else
            str[cur_new_str_len] = ' ';
        cur_new_str_len++;
    }
}

int delete_same_letters(char word_arr[][MAX_WORD_LEN + 1], char new_word_arr[][MAX_WORD_LEN + 1], int num_of_words)
{
    int cur_new_arr_len = 0;
        
    for (int i = 0; i < num_of_words; i++)
    {
        if (strcmp(word_arr[i], word_arr[num_of_words - 1]) != 0)
        {
            int j = 0;
            char word[MAX_WORD_LEN + 1];
            char first_symbol = word_arr[i][0];
            int cur_word_len = 0;

            while (word_arr[i][j] != '\0')
            {
                if (word_arr[i][j] != first_symbol || j == 0)
                {
                    word[cur_word_len] = word_arr[i][j];
                    cur_word_len++;
                }
                
                j++;
            }   

            word[cur_word_len] = '\0';
            strcpy(new_word_arr[cur_new_arr_len], word);
            cur_new_arr_len++;
        }
    }        
    return cur_new_arr_len;
}
