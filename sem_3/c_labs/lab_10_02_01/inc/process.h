#ifndef _PROCESS_H_
#define _PROCESS_H_

#include <stdio.h>

#include "funcs.h"
#include "struct.h"
#include "io.h"

#define INCORRECT_INPUT -1
#define EMPTY_POLYNOM -2

int process_count_val();
int process_find_ddx();
int process_sum();
int process_split_to_odd_even();

#endif