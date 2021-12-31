#include <string.h>

#include "../inc/funcs.h"
#include "../inc/key.h"
#include "../inc/mysort.h"

#define ONLY_ONE_NUM_IN_FILE -10
#define ALL_NUMS_ARE_SAME -11

int main(int argc, char **argv)
{
    int error_code = 0;
    if (argc < 3 || argc > 4)
        error_code = INCORRECT_ARG_COUNT;

    FILE *in_file = NULL;
    if (error_code == 0)
    {
        in_file = fopen(argv[1], "r");
        if (in_file == NULL)
            error_code = FILE_NOT_FOUND;
    }

    int nums_in_file = 0;
    if (error_code == 0)
        error_code = count_nums_in_file(in_file, &nums_in_file);

    int *int_array = NULL;
    if (error_code == 0)
    {
        int_array = (int*)calloc(nums_in_file, sizeof(int));
        if (int_array == NULL)
            error_code = INIT_ERROR;
        else 
            error_code = read_from_file_to_arr(in_file, int_array, int_array + nums_in_file);
    }
    
    int *new_arr_b = NULL;
    int *new_arr_e = NULL;
    if (error_code == 0)
    {
        if (argc == 4)
        {
            if (strcmp(argv[3], "f") == 0)
            {
                if (nums_in_file == 1)
                    error_code = ONLY_ONE_NUM_IN_FILE;
                
                int same_flag = check_if_nums_are_same(int_array, nums_in_file);

                if (same_flag == 1)
                    error_code = ALL_NUMS_ARE_SAME;

                if (error_code == 0)
                    error_code = key(&(int_array[0]), &(int_array[0]) + nums_in_file, &new_arr_b, &new_arr_e);
            }
            else
                error_code = INCORRECT_ARG;
        }
    }

    if (error_code == 0)
    {
        FILE *out_file = fopen(argv[2], "w");
        if (new_arr_b != NULL && new_arr_e != NULL)
        {
            int new_len = 0;
            for (int *i = new_arr_b; i != new_arr_e; i++)
                new_len++;
            mysort(new_arr_b, new_len, sizeof(int), comparator);
            write_array_to_file(out_file, new_arr_b, new_arr_e);
        }
        else
        {
            mysort(int_array, nums_in_file, sizeof(int), comparator);
            write_array_to_file(out_file, int_array, int_array + nums_in_file);
        }
        
        fclose(out_file);
    }
    if (in_file != NULL)
        fclose(in_file);

    if (int_array != NULL)
        free(int_array);
    if (new_arr_b != NULL)
        free(new_arr_b);

    return error_code;
}













