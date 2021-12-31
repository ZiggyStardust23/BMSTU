#ifndef _FUNCS_H_
#define _FUNCS_H_

#include "goods.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STRUCTS_IN_FILE 15
#define MAX_SYMBOLS_IN_NAME 25

#define FILE_IS_EMPTY -1
#define INCORRECT_NUM_OF_STRUCTS -2
#define FILE_ERROR -3
#define INCORRECT_ARGS -4
#define NOT_NUM -5
#define INCORRECT_PRICE -6
#define TOO_LONG_NAME -7
#define READ_ERROR -8
#define INCORRECT_NAME -9

int read_structs(FILE *f, struct goods *struct_arr, int num_of_structs);

void which_ones_are_cheaper(struct goods *struct_arr, int structs_num, struct goods *new_arr, float top_price);

void print_goods(struct goods *cur_struct);

void print_goods_arr(struct goods *struct_arr, int structs_num);

int find_size_of_name(FILE *f);

int find_new_arr_len(struct goods *struct_arr, int structs_num, int top_price);



#endif