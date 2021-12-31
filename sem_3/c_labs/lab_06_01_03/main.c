#include "funcs.h"
#include "goods.h"
#include "util_funcs.h"

#include <stdio.h>

int main(int argc, char **argv)
{
    int error_code = 0;
    
    if (argc != 3)
        error_code = INCORRECT_ARGS;
    
    FILE *f = NULL;

    if (error_code == 0)
    {
        f = fopen(argv[1], "r");
        if (f == NULL)
            error_code = FILE_ERROR;
    }

    struct goods struct_arr[MAX_STRUCTS_IN_FILE];
    int structs_in_file;

    if (error_code == 0)
    {
        error_code = read_structs(f, struct_arr, &structs_in_file);
    }

    if (error_code == 0 && check_if_str_is_num(argv[2]) == NOT_NUM)
        error_code = NOT_NUM;

    if (error_code == 0)
    {
        float top_price = strtof(argv[2], NULL);

        struct goods new_arr[MAX_STRUCTS_IN_FILE];
        int new_arr_len = which_ones_are_cheaper(struct_arr, structs_in_file, new_arr, top_price);

        print_goods_arr(new_arr, new_arr_len);
    }
    
    if (f != NULL)
        fclose(f);
    
    return error_code;
}