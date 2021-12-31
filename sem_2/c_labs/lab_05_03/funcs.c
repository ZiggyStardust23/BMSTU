#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "funcs.h"

#define INCORRECT_COMMAND     -1
#define INCORRECT_NUM         -2
#define INCORRECT_FILE_NAME   -3
#define INCORRECT_NUM_OF_ARGS -4
#define FILE_NOT_FOUND        -5
#define ACCESS_ERROR          -6
#define FILE_IS_EMPTY         -7

#define MAX_RAND_INT           100

int print_file(FILE *f)
{
    int cur_num;
    int amount_of_nums = 0;
    
    while (fread(&cur_num, sizeof(int), 1, f) == 1)
    {
        printf("%d ", cur_num);
        amount_of_nums++;
    }
    
    if (amount_of_nums == 0)
        return FILE_IS_EMPTY;
    
    return 0;
}

int get_number_by_pos(FILE *f, int pos, int *val)
{
    fseek(f, pos * sizeof(int), SEEK_SET);

    if (fread(val, sizeof(int), 1, f) != 1)
        return ACCESS_ERROR;

    return 0;
}

int put_number_by_pos(FILE *f, int pos, int val)
{
    fseek(f, pos * sizeof(int), SEEK_SET);

    if (fwrite(&val, sizeof(int), 1, f) != 1)
        return ACCESS_ERROR;

    return 0;
}

int make_file(char *str, int num)
{
    FILE *f = fopen(str, "w");
    if (f == NULL)
        return ACCESS_ERROR;
    
    srand(time(0));
    for (int i = 0; i < num; i++)
    {
        int cur_num;
        cur_num = rand() % MAX_RAND_INT;

        fwrite(&cur_num, sizeof(int), 1, f);
    }

    fclose(f);
    return 0;
}

int sort(FILE *f)
{
    fseek(f, 0, SEEK_END);

    int nums_in_file = ftell(f) / sizeof(int);

    fseek(f, 0, SEEK_CUR);

    for (int i = 0; i < nums_in_file; i++)
    {
        for (int j = i + 1; j < nums_in_file; j++)
        {
            int num_1;
            int num_2;

            if (get_number_by_pos(f, i, &num_1) == 0 && get_number_by_pos(f, j, &num_2) == 0)
            {
                if (num_1 > num_2)
                {
                    if (put_number_by_pos(f, i, num_2) != 0 || put_number_by_pos(f, j, num_1) != 0)
                        return ACCESS_ERROR;
                }
            }
        }
    }

    return 0;
}

int check_correct_int(char *num)
{
    int i = 0;
    char all_nums[] = "0123456789";

    while (num[i] != '\0')
    {
        if (strchr(all_nums, num[i]) == NULL)
            return INCORRECT_NUM;
        
        i++;
    }

    if (i == 0)
        return INCORRECT_NUM;
    if (num[0] == '0')
        return INCORRECT_NUM; 

    int result = atoi(num);

    return result;
}