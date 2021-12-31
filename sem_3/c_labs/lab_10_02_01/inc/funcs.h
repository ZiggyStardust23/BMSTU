#ifndef _FUNCS_H_
#define _FUNCS_H_

#define INCORRECT_INPUT -1
#define EMPTY_POLYNOM -2

#include "struct.h"

void split_to_odd_and_even(node_t *head, node_t **head_even, node_t **head_odd);

void sum_polynom(node_t *head_a, node_t *head_b, node_t **result);

void print_polynom(node_t *head);

void find_ddx(node_t *head, node_t **new_head);

int count_val(node_t *head, int *result);

int read_polynom(node_t **head);

int read_choice(int *choice);

void free_polynom(node_t *head);

void init_node(node_t *new_cur_node, node_t *cur_node);

void sum_node(node_t ***result, node_t **cur_result, node_t **cur_node, int *init_flag);

void sum_nodes(node_t ***result, node_t **cur_result, node_t **cur_node_a, node_t **cur_node_b, int *init_flag);

void add_node_to_ode_or_even_list(node_t ***head_even_or_ode, node_t *cur_head, node_t **cur_odd_or_even, int *init_flag);

void copy_node(node_t *new_cur_node, node_t *cur_node);

#endif