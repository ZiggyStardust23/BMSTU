#ifndef _UTIL_FUNCS_H_
#define _UTIL_FUNCS_H_

#define FILE_IS_EMPTY -1
#define INCORRECT_NUM_OF_STRUCTS -2
#define NOT_NUM -5

#include <stdio.h>
#include "goods.h"

int check_if_str_is_num(char *str);

int if_char_is_num(char ch);

int find_num_of_structs(FILE *f, int *structs_in_file);

void free_all(struct goods *struct_arr, struct goods *new_arr, int structs_in_file);

#endif