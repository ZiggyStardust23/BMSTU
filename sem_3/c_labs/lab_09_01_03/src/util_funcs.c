#include "../inc/util_funcs.h"

#include <string.h>
#include <stdlib.h>

int if_char_is_num(char ch)
{
    return '0' <= ch && ch <= '9' ? 1 : 0;
}

int check_if_str_is_num(char *str)
{
    int error_code = 0;

    int str_len = strlen(str);
    int num_of_points = 0;
    for (int i = 0; i < str_len; i++)
    {
        if (error_code == 0)
        {
            if (str[i] == '.')
                num_of_points++;
            else if (!if_char_is_num(str[i]))
                error_code = NOT_NUM;
        }
    }
    if (error_code == 0 && num_of_points > 1)
        error_code = NOT_NUM;
    return error_code;
}

int find_num_of_structs(FILE *f, int *structs_in_file)
{
    int error_code = 0;
    if (error_code == 0 && fscanf(f, "%d\n", structs_in_file) != 1)
        error_code = FILE_IS_EMPTY;

    if (error_code == 0 && *structs_in_file <= 0)
        error_code = INCORRECT_NUM_OF_STRUCTS;

    return error_code;
}

void free_all(struct goods *struct_arr, struct goods *new_arr, int structs_in_file)
{
    if (struct_arr != NULL)
    {
        for (int i = 0; i < structs_in_file; i++)
            if (struct_arr[i].name != NULL)
                free(struct_arr[i].name);
        free(struct_arr);
    }

    if (new_arr != NULL)
    {
        free(new_arr);
    }
}