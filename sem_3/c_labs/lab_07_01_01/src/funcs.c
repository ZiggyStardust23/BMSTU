#include "../inc/funcs.h"

int count_nums_in_file(FILE *in_file, int *nums_in_file)
{
    int read_code = 0;
    int error_code = 0;

    int nums_read = 0;
    int cur_num;

    fseek(in_file, 0, SEEK_END);
    long pos = ftell(in_file);
    if (pos <= 0)
        error_code = READ_ERROR;
    fseek(in_file, 0, 0);

    while ((read_code = fscanf(in_file, "%d", &cur_num)) != EOF && error_code == 0)
    {
        if (error_code == 0)
        {
            if (read_code == 1)
                nums_read++;
            else if (read_code == 0)
                error_code = READ_ERROR;
        }
    }

    if (nums_read == 0 && error_code == EOF)
        error_code = READ_ERROR;

    if (error_code == 0)
        *nums_in_file = nums_read;

    fseek(in_file, 0L, SEEK_SET);

    return error_code;
}

int read_from_file_to_arr(FILE *in_file, int *pb, int *pe)
{
    int error_code = 0;
    int cur_num;
    for (int *i = pb; i != pe; i++)
    {
        if (error_code == 0)
        {
            if (fscanf(in_file, "%d", &cur_num) != 1)
                error_code = READ_ERROR;
            if (error_code == 0)
            {
                *i = cur_num;
            }
        }
    }

    return error_code;
}

int write_array_to_file(FILE *out_file, int *pb, int *pe)
{
    int error_code = 0;

    if (out_file == NULL)
        error_code = INCORRECT_FILE_POINTER;

    if (error_code == 0)
        for (int *i = pb; i != pe; i++)
            fprintf(out_file, "%d ", *i);

    return error_code;
}

int check_if_nums_are_same(int *int_array, int nums)
{
    int same_flag = 1;
    for (int i = 0; i < nums; i++)
        for (int j = 0; j < nums; j++)
            if (int_array[i] != int_array[j])
                same_flag = 0;
    
    return same_flag;
}