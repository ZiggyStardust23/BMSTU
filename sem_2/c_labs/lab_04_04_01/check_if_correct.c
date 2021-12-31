#include <stdio.h>
#include <string.h>

#include "check_if_correct.h"

#define MAX_STR_LEN 256

#define YES 1
#define NO 0

int fill_arr(char str[MAX_STR_LEN], char (*arr)[MAX_STR_LEN + 1])
{
    char *cur = strtok(str, " \n\r\t");
    int i = 0;

    while (cur != NULL)
    {
        strcpy(arr[i], cur);
        cur = strtok(NULL, " \n\r\t");
        i++;
    }

    return i;
}

int check_if_correct(char in_str[MAX_STR_LEN + 1], int str_len)
{
    char str_arr[MAX_STR_LEN + 1][MAX_STR_LEN + 1];

    if (str_len == STRING_IS_TOO_LONG)
        return STRING_IS_TOO_LONG;
    
    int new_arr_len;

    new_arr_len = fill_arr(in_str, str_arr);

    if (new_arr_len != 1)
        return NO;
    
    char str[MAX_STR_LEN + 1];
    strcpy(str, str_arr[0]);
        
    char num_str[] = "0123456789";
    int i = 0;

    if (str[i] == '+' || str[i] == '-')
        i++;

    if (str[i] != '\0' && strchr(num_str, str[i]) != NULL)
    {
        int next_i = i + 1;
        for (int j = next_i; str[j] != '\0' && strchr(num_str, str[j]) != NULL; j++)
            i++;
        i++;
        if (str[i] == '.')
        {
            i++;

            if (str[i] == '\0')
                return YES;

            if (str[i] != '\0' && strchr(num_str, str[i]) != NULL)
            {
                next_i = i + 1;
                for (int j = next_i; str[j] != '\0' && strchr(num_str, str[j]) != NULL; j++)
                    i++;
                i++;
            }
            
            if (str[i] == 'e' || str[i] == 'E')
            {
                i++;
                
                if (str[i] == '+' || str[i] == '-')                
                    i++;
                
                if (str[i] != '\0' && strchr(num_str, str[i]) != NULL)
                {             
                    next_i = i + 1;
                    
                    for (int j = next_i; str[j] != '\0' && strchr(num_str, str[j]) != NULL; j++)
                        i++;
                        
                    i++;
                }
                
                else
                    return NO;
            }
        }
        
        else if (str[i] == 'e' || str[i] == 'E')
        {
            i++;
            
            if (str[i] == '+' || str[i] == '-')
            i++;

            if (str[i] != '\0' && strchr(num_str, str[i]) != NULL)
            {
                next_i = i + 1;
                for (int j = next_i; str[j] != '\0' && strchr(num_str, str[j]) != NULL; j++)
                {
                    i++;
                }
                i++;
            }
            
            else
                return NO;
        }

        if ((str[i]) != '\0')
            return NO;
    }
    
    else if (str[i] == '.')
    {
        i++;
        
        if (str[i] != '\0' && strchr(num_str, str[i]) != NULL)
        {
            int next_i = i + 1;
            
            for (int j = next_i; str[j] != '\0' && strchr(num_str, str[j]) != NULL; j++)
                i++;
                
            i++;

            if (str[i] == '\0')
                return YES;

            if (str[i] == 'e' || str[i] == 'E')
            {
                i++;
                if (str[i] == '+' || str[i] == '-')
                    i++;
                    
                if (str[i] != '\0' && strchr(num_str, str[i]) != NULL)
                {
                    next_i = i + 1;
                    
                    for (int j = next_i; str[j] != '\0' && strchr(num_str, str[j]) != NULL; j++)
                        i++;
                        
                    i++;
                }
                
                else
                    return NO;
            }
            
            else if (str[i] == '+' || str[i] == '-')
            {
                int next_i = i + 1;
                
                for (int j = next_i; str[j] != '\0' && strchr(num_str, str[j]) != NULL; j++)
                    i++;
                    
                i++;
            }
            
            else
                return NO;
                    
            if ((str[i]) != '\0')
                return NO;
        }
        
        else
            return NO;
    }
    
    else
        return NO;
        
    return YES;
}

int read_str(char str[MAX_STR_LEN])
{
    char ch;
    int i = 0;
    
    while ((ch = getchar()) != '\n' && ch != EOF)
    {
        str[i] = ch;
        if (i + 1 > MAX_STR_LEN)
            return STRING_IS_TOO_LONG;
        i++;
    }
    
    str[i] = '\0';
    
    return i;
}
