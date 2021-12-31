#include "funcs.h"
#include "goods.h"

int read_structs(FILE *f, struct goods *struct_arr, int *num_of_structs)
{
    int error_code = 0;

    int structs_in_file = 0;

    if (error_code == 0 && fscanf(f, "%d\n", &structs_in_file) != 1)
        error_code = FILE_IS_EMPTY;
    
    if (error_code == 0 && structs_in_file > MAX_STRUCTS_IN_FILE)
        error_code = INCORRECT_NUM_OF_STRUCTS;
    
    char cur_name[MAX_SYMBOLS_IN_NAME + 1];
    int cur_price;
    if (error_code == 0)
    {
        for (int i = 0; i < structs_in_file; i++)
        {
            if (error_code == 0)
            {
                fgets(cur_name, MAX_SYMBOLS_IN_NAME + 1, f);
                int cur_len = strlen(cur_name);
                if (cur_name[cur_len - 1] == '\n')
                    cur_name[cur_len - 1] = '\0';
                if (cur_name == NULL)
                    error_code = TOO_LONG_NAME;
                if (error_code == 0 && strlen(cur_name) == 0)
                    error_code = INCORRECT_NAME;
                if (error_code == 0 && fscanf(f, "%d\n", &cur_price) != 1)
                    error_code = READ_ERROR;
                if (error_code == 0 && cur_price <= 0)
                    error_code = INCORRECT_PRICE;
                
                if (error_code == 0)
                {
                    strcpy(struct_arr[i].name, cur_name);
                    struct_arr[i].price = cur_price;
                }
            }
        }
    
        if (error_code == 0)
            *num_of_structs = structs_in_file; 
    }

    return error_code;
}

int which_ones_are_cheaper(struct goods *struct_arr, int structs_num, struct goods *new_arr, float top_price)
{
    int new_arr_len = 0;
    for (int i = 0; i < structs_num; i++)
    {
        if (struct_arr[i].price < top_price)
        {
            strcpy(new_arr[new_arr_len].name, struct_arr[i].name);
            new_arr[new_arr_len].price = struct_arr[i].price;

            new_arr_len++;
        }
    }

    return new_arr_len;
}

void print_goods(struct goods *cur_struct)
{
    printf("%s\n%d", cur_struct->name, cur_struct->price);
}

void print_goods_arr(struct goods *struct_arr, int structs_num)
{
    for (int i = 0; i < structs_num; i++)
    {
        print_goods(&(struct_arr[i]));
        printf("\n");
    }
}
