#include "../inc/funcs.h"
#include "../inc/goods.h"
#include "../inc/util_funcs.h"

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

    struct goods *struct_arr = NULL;
    int structs_in_file = 0;
    int new_arr_len = 0;

    if (error_code == 0)
    {
        error_code = find_num_of_structs(f, &structs_in_file);

        if (error_code == 0)
        {
            struct_arr = malloc(structs_in_file * sizeof(struct goods));
            for (int i = 0; i < structs_in_file; i++)
                struct_arr[i].name = NULL;

            error_code = read_structs(f, struct_arr, structs_in_file);
        }
    }

    if (error_code == 0 && check_if_str_is_num(argv[2]) == NOT_NUM)
        error_code = NOT_NUM;

    struct goods *new_arr = NULL;
    if (error_code == 0)
    {
        float top_price = strtof(argv[2], NULL);
        new_arr_len = find_new_arr_len(struct_arr, structs_in_file, top_price);

        if (new_arr_len > 0)
        {
            new_arr = malloc(new_arr_len * sizeof(struct goods));
            which_ones_are_cheaper(struct_arr, structs_in_file, new_arr, top_price);

            print_goods_arr(new_arr, new_arr_len);
        }
    }
    
    if (f != NULL)
        fclose(f);

    free_all(struct_arr, new_arr, structs_in_file);
    
    return error_code;
}
