#ifndef _FUNCS_H_
#define _FUNCS_H_

#include "struct.h"
#include <stdio.h>
#include <stdlib.h>

#define DATA_ERROR -1
#define INCORRECT_ARGC -2
#define FILE_NOT_FOUND -3


node_t *find(node_t *head, const void *data, int (*comparator)(const void*, const void *));

void *pop_front(node_t **head);

int copy(node_t *head, node_t **new_head);

void sorted_insert(node_t **head, node_t *element, int(*comparator)(const void*, const void*));

node_t *sort(node_t *head, int (*comparator)(const void *, const void*));

void free_list(node_t *head);

int comparator(const void *a, const void *b);

void add_elem(node_t **head);

int copy_circle(node_t **new_head, node_t **cur_head);

#endif