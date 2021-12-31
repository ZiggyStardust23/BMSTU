#ifndef _IO_H_
#define _IO_H_

#include <stdio.h>
#include <stdlib.h>
#include "struct.h"

void read_from_file_to_list(FILE *f, node_t *head);

void print_list(node_t *head);

void write_to_file(FILE *f, node_t *head);

void print_menu();

#endif