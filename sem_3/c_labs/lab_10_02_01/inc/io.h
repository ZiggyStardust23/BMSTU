#ifndef _IO_H_
#define _IO_H_

#define INCORRECT_INPUT -1
#define EMPTY_POLYNOM -2

#include "struct.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int read_choice(int *choice);

int read_polynom(node_t **head);

void print_polynom(node_t *head);

#endif