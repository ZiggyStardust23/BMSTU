#ifndef _PROCESS_H_
#define _PROCESS_H_

#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "io.h"
#include "funcs.h"

#define DATA_ERROR -1
#define INCORRECT_ARGC -2
#define FILE_NOT_FOUND -3

int process(char *in_fname, char *out_fname);

#endif