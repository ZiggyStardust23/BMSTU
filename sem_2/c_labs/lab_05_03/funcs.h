#ifndef _FUNCS_H_
#define _FUNCS_H_

int get_number_by_pos(FILE *f, int pos, int *val);

int put_number_by_pos(FILE *f, int pos, int val);

int print_file(FILE *f);

int make_file(char *str, int num);

int sort(FILE *f);

int check_correct_int(char *num);

#endif