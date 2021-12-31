#ifndef _KEY_H_
#define _KEY_H_

#define NO_ELEMENTS_BETWEEN -7
#define MEMORY_ERROR -13

#include <stdlib.h>

int key(int *pb_src, int *pe_src, int **pb_dst, int **pe_dst);

void key_swap(int **f, int **s);

#endif