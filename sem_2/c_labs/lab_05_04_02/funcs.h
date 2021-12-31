#ifndef _FUNCS_H_
#define _FUNCS_H_

#include <stdio.h>
#include <string.h>

#define FILE_ERROR          -1
#define INCORRECT_INPUT     -2
#define NO_STRUCTS_TO_PRINT -3
#define NOT_FILE_OF_STRUCTS -4
#define FILE_IS_EMPTY       -5
#define ACCESS_ERROR        -6
#define INCORRECT_PARAMS     53

struct goods
{
    char name[31];
    char author[16];
    unsigned int price;
    unsigned int amount;
};

int sort(char *in_fname, char *out_fname);

int print_goods(char *fname, char *substr);

int add_new(char *fname);

void print_struct(struct goods good);

int enter_struct(struct goods *good);

int put_number_by_pos(FILE *f, int pos, struct goods val);

int get_number_by_pos(FILE *f, int pos, struct goods *val);

#endif