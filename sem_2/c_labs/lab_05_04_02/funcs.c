#include "funcs.h"

void print_struct(struct goods good)
{
    printf("%s\n", good.name);
    printf("%s\n", good.author);
    printf("%u\n%u", good.price, good.amount);
}

int enter_struct(struct goods *good)
{
    char name[31];
    char author[16];
    unsigned int price;
    unsigned int amount;

    if (scanf("%s", name) != 1)
        return INCORRECT_INPUT;
    if (scanf("%s", author) != 1)
        return INCORRECT_INPUT;
    if (scanf("%u", &price) != 1)
        return INCORRECT_INPUT;
    if (scanf("%u", &amount) != 1)
        return INCORRECT_INPUT;

    strcpy(good->name, name);
    strcpy(good->author, author);
    good->price = price;
    good->amount = amount;

    return 0;
}

int get_number_by_pos(FILE *f, int pos, struct goods *val)
{
    fseek(f, pos * sizeof(struct goods), SEEK_SET);

    if (fread(val, sizeof(struct goods), 1, f) != 1)
        return ACCESS_ERROR;

    return 0;
}

int put_number_by_pos(FILE *f, int pos, struct goods val)
{
    fseek(f, pos * sizeof(struct goods), SEEK_SET);

    if (fwrite(&val, sizeof(struct goods), 1, f) != 1)
        return ACCESS_ERROR;

    return 0;
}

int sort(char *in_fname, char *out_fname) 
{
    FILE *f = fopen(in_fname, "rb");
    FILE *out_file = fopen(out_fname, "wb+");

    if (f == NULL || out_file == NULL)
        return FILE_ERROR;

    fseek(f, 0, SEEK_END);
    if (ftell(f) % sizeof(struct goods) != 0)
    {
        fclose(f);
        fclose(out_file);
        return NOT_FILE_OF_STRUCTS;
    }
       
    int structs_in_file = ftell(f) / sizeof(struct goods);

    if (structs_in_file == 0)
    {
        fclose(f);
        fclose(out_file);
        return FILE_IS_EMPTY;
    }
    fseek(f, 0, SEEK_SET);

    for (int i = 0; i < structs_in_file; i++)
    {
        struct goods cur_struct;
        memset(&cur_struct, 0, sizeof(cur_struct));
        fread(&cur_struct, sizeof(struct goods), 1, f);
        fwrite(&cur_struct, sizeof(struct goods), 1, out_file);
    }

    for (int i = 0; i < structs_in_file; i++)
    {
        for (int j = i + 1; j < structs_in_file; j++)
        {
            struct goods struct_1;
            struct goods struct_2;
            memset(&struct_1, 0, sizeof(struct goods));
            memset(&struct_2, 0, sizeof(struct goods));

            if (get_number_by_pos(out_file, i, &struct_1) == 0 && get_number_by_pos(out_file, j, &struct_2) == 0)
            {
                if (struct_1.price < struct_2.price)
                {
                    if (put_number_by_pos(out_file, i, struct_2) != 0 || put_number_by_pos(out_file, j, struct_1) != 0)
                        return ACCESS_ERROR;
                }
                else if (struct_1.price == struct_2.price)
                {
                    if (struct_1.amount < struct_2.amount)
                    {
                        if (put_number_by_pos(out_file, i, struct_2) != 0 || put_number_by_pos(out_file, j, struct_1) != 0)
                        return ACCESS_ERROR;
                    }
                }
            }
        }
    }

    fclose(out_file);
    fclose(f);

    return 0;
}

int print_goods(char *fname, char *substr)
{
    FILE *f = fopen(fname, "rb");

    fseek(f, 0, SEEK_END);
    if (ftell(f) % sizeof(struct goods) != 0)
    {
        fclose(f);
        return NOT_FILE_OF_STRUCTS;
    }
       
    int structs_in_file = ftell(f) / sizeof(struct goods);

    if (structs_in_file == 0)
    {
        fclose(f);
        return FILE_IS_EMPTY;
    }
    fseek(f, 0, SEEK_SET);

    int num_of_printed = 0;
    
    for (int i = 0; i < structs_in_file; i++)
    {
        struct goods cur_struct;
        memset(&cur_struct, 0, sizeof(struct goods));
        fread(&cur_struct, sizeof(cur_struct), 1, f);

        int str_len = strlen(cur_struct.name);
        int sub_len = strlen(substr);

        if (str_len >= sub_len)
        {   
            int same_flag = 1;

            for (unsigned int j = 0; j < strlen(substr); j++)
                if (cur_struct.name[str_len - j - 1] != substr[sub_len - j - 1])
                    same_flag = 0;

            if (same_flag == 1)
            {
                num_of_printed++;
                print_struct(cur_struct);
                
                if (i != structs_in_file - 1)
                    printf("%c", '\n');
            }
        }
    }
    
    fclose(f);

    if (num_of_printed == 0)
        return NO_STRUCTS_TO_PRINT;
    return 0;
}

int add_new(char *fname)
{
    struct goods in_struct;
    memset(&in_struct, 0, sizeof(struct goods));
    if (enter_struct(&in_struct) != 0)
        return INCORRECT_INPUT;

    FILE *f = fopen(fname, "rb+");
    if (f == NULL)
        return FILE_ERROR;
            
    fseek(f, 0, SEEK_END);
    if (ftell(f) % sizeof(struct goods) != 0)
    {
        fclose(f);
        return NOT_FILE_OF_STRUCTS;
    }
       
    int structs_in_file = ftell(f) / sizeof(struct goods);

    if (structs_in_file == 0)
    {
        fclose(f);
        return FILE_IS_EMPTY;
    }
    fseek(f, 0, SEEK_SET);


    int struct_pos = 0;
    int flag_is_lower = 1;

    while (flag_is_lower && struct_pos < structs_in_file)
    {
        struct goods cur_struct;
        memset(&cur_struct, 0, sizeof(struct goods));
        fread(&cur_struct, sizeof(struct goods), 1, f);
        if (cur_struct.price == in_struct.price)
            if (cur_struct.amount < in_struct.amount)
                flag_is_lower = 0;
        if (cur_struct.price < in_struct.price)
            flag_is_lower = 0;
        
        if (flag_is_lower)
            struct_pos++;
    }

    int structs_to_move = structs_in_file;

    while (structs_to_move >= struct_pos)
    {
        struct goods cur_struct;
        memset(&cur_struct, 0, sizeof(struct goods));

        if (structs_to_move == structs_in_file)
        {
            fseek(f, structs_to_move * sizeof(struct goods), SEEK_SET);
            fread(&cur_struct, sizeof(struct goods), 1, f);
            fseek(f, 0, SEEK_END);
            fwrite(&cur_struct, sizeof(struct goods), 1, f);
        }
        else
        {
            fseek(f, structs_to_move * sizeof(struct goods), SEEK_SET);
            fread(&cur_struct, sizeof(struct goods), 1, f);
            fseek(f, (structs_to_move + 1) * sizeof(struct goods) , SEEK_SET);
            fwrite(&cur_struct, sizeof(struct goods), 1, f);
        }

        structs_to_move--;
    }

    fseek(f, struct_pos * sizeof(struct goods), SEEK_SET);
    fwrite(&in_struct, sizeof(struct goods), 1, f);
    
    fclose(f);

    return 0;
}