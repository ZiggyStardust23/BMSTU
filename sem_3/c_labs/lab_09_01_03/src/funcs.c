#include "../inc/funcs.h"
#include "../inc/goods.h"

int find_size_of_name(FILE *f)
{
    int size_of_name = 0;
    char ch = 0;

    long cur_pos = ftell(f);
    while (fscanf(f, "%c", &ch) == 1 && ch != '\n')
    {
        size_of_name++;
    }

    fseek(f, cur_pos, 0);
    
    return size_of_name;
}

int read_structs(FILE *f, struct goods *struct_arr, int num_of_structs)
{
    int error_code = 0;

    int structs_in_file = num_of_structs;
    
    char *cur_name;
    int cur_price;
    if (error_code == 0)
    {
        for (int i = 0; i < structs_in_file; i++)
        {
            if (error_code == 0)
            {
                int cur_len = find_size_of_name(f);

                cur_name = malloc(cur_len + 1);
                fgets(cur_name, cur_len + 1, f);
                if (cur_name == NULL)
                    error_code = TOO_LONG_NAME;
                if (error_code == 0 && cur_len == 0)
                    error_code = INCORRECT_NAME;
                if (error_code == 0 && fscanf(f, "%d\n", &cur_price) != 1)
                    error_code = READ_ERROR;
                if (error_code == 0 && cur_price <= 0)
                    error_code = INCORRECT_PRICE;

                if (error_code != 0)
                    free(cur_name);
                
                if (error_code == 0)
                {
                    struct_arr[i].name = cur_name;
                    struct_arr[i].price = cur_price;
                }
            }
        }
    }

    return error_code;
}

int find_new_arr_len(struct goods *struct_arr, int structs_num, int top_price)
{
    int new_arr_len = 0;
    for (int i = 0; i < structs_num; i++)
    {
        if (struct_arr[i].price < top_price)
        {
            new_arr_len++;
        }
    }

    return new_arr_len;
}

void which_ones_are_cheaper(struct goods *struct_arr, int structs_num, struct goods *new_arr, float top_price)
{
    int new_arr_len = 0;

    for (int i = 0; i < structs_num; i++)
    {
        if (struct_arr[i].price < top_price)
        {
            new_arr[new_arr_len].name = struct_arr[i].name;
            new_arr[new_arr_len].price = struct_arr[i].price;
            new_arr_len++;
        }
    }
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
