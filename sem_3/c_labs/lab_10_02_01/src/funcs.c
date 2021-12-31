#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "../inc/funcs.h"

#define INCORRECT_INPUT -1

int count_val(node_t *head, int *result)
{
    int error_code = 0;
    float a;

    if (scanf("%f", &a) != 1)
        error_code = INCORRECT_INPUT;

    if (error_code == 0)
    {
        *result = 0;
        node_t *cur_elem = head;

        while (cur_elem != NULL)
        {
            *result += cur_elem->elem.coef * pow(a, cur_elem->elem.pow);
            cur_elem = cur_elem->next;
        }
    }

    return error_code;
}

void init_node(node_t *new_cur_node, node_t *cur_node)
{
    new_cur_node->elem.coef = cur_node->elem.coef * cur_node->elem.pow;
    new_cur_node->elem.pow = cur_node->elem.pow - 1;
    new_cur_node->next = NULL;
}

void copy_node(node_t *new_cur_node, node_t *cur_node)
{
    new_cur_node->elem.pow = cur_node->elem.pow;
    new_cur_node->elem.coef = cur_node->elem.coef;
    new_cur_node->next = NULL;
}

void find_ddx(node_t *head, node_t **new_head)
{
    node_t *cur_node = head;
    node_t *new_cur_node;
    *new_head = NULL;
    int first_iter_flag = 1;

    while (cur_node != NULL)
    {
        if (cur_node->elem.pow != 0)
        {
            if (first_iter_flag == 1)
            {
                *new_head = malloc(sizeof(node_t));
                new_cur_node = *new_head;
                init_node(new_cur_node, cur_node);
                first_iter_flag = 0;
            }
            else
            {
                new_cur_node->next = malloc(sizeof(node_t));
                new_cur_node = new_cur_node->next;
                init_node(new_cur_node, cur_node);
            }
        }

        cur_node = cur_node->next; 
    }
}

void sum_node(node_t ***result, node_t **cur_result, node_t **cur_node, int *init_flag)
{
    if (*init_flag == 0)
    {
        **result = malloc(sizeof(node_t));
        *cur_result = **result;
        *init_flag = 1;
    }
    else
    {
        (*cur_result)->next = malloc(sizeof(node_t));
        *cur_result = (*cur_result)->next;
    }
    (*cur_result)->elem.pow = (*cur_node)->elem.pow;
    (*cur_result)->elem.coef = (*cur_node)->elem.coef;
    (*cur_result)->next = NULL;
    *cur_node = (*cur_node)->next;
}

void sum_nodes(node_t ***result, node_t **cur_result, node_t **cur_node_a, node_t **cur_node_b, int *init_flag)
{
    if (*init_flag == 0)
    {
        **result = malloc(sizeof(node_t));
        *cur_result = **result;
        *init_flag = 1;
    }
    else
    {
        (*cur_result)->next = malloc(sizeof(node_t));
        *cur_result = (*cur_result)->next;
    }

    (*cur_result)->elem.pow = (*cur_node_b)->elem.pow;
    (*cur_result)->elem.coef = (*cur_node_a)->elem.coef + (*cur_node_b)->elem.coef;
    (*cur_result)->next = NULL;
    (*cur_node_a) = (*cur_node_a)->next;
    (*cur_node_b) = (*cur_node_b)->next;
}

void sum_polynom(node_t *head_a, node_t *head_b, node_t **result)
{
    node_t *cur_a = head_a;
    node_t *cur_b = head_b;
    node_t *cur_result;

    int init_flag = 0;

    while (cur_a != NULL || cur_b != NULL)
    {
        if (cur_a != NULL && cur_b != NULL)
        {
            if (cur_a->elem.pow > cur_b->elem.pow)
            {
                sum_node(&result, &cur_result, &cur_a, &init_flag);
            }
            else if (cur_a->elem.pow < cur_b->elem.pow)
            {
                sum_node(&result, &cur_result, &cur_b, &init_flag);
            }
            else if (cur_a->elem.pow == cur_b->elem.pow)
            {
                sum_nodes(&result, &cur_result, &cur_a, &cur_b, &init_flag);
            }
        }
        else if (cur_a != NULL)
        {
            sum_node(&result, &cur_result, &cur_a, &init_flag);
        }
        else if (cur_b != NULL)
        {
            sum_node(&result, &cur_result, &cur_b, &init_flag);
        }
    }
}

void add_node_to_ode_or_even_list(node_t ***head_even_or_ode, node_t *cur_head, node_t **cur_odd_or_even, int *init_flag)
{
    if (*init_flag == 0)
    {
        **head_even_or_ode = malloc(sizeof(node_t));
        copy_node(**head_even_or_ode, cur_head);
        *init_flag = 1;

        *cur_odd_or_even = **head_even_or_ode;
    }
    else
    {
        (*cur_odd_or_even)->next = malloc(sizeof(node_t));
        (*cur_odd_or_even) = (*cur_odd_or_even)->next;
        copy_node(*cur_odd_or_even, cur_head);
    }
}

void split_to_odd_and_even(node_t *head, node_t **head_even, node_t **head_odd)
{
    int init_even_flag = 0;
    int init_odd_flag = 0;
    node_t *cur_head = head; 

    node_t *cur_even;
    node_t *cur_odd;

    while (cur_head != NULL)
    {
        if (cur_head->elem.pow % 2 == 0)
        {
            add_node_to_ode_or_even_list(&head_even, cur_head, &cur_even, &init_even_flag);
        }
        else
        {
            add_node_to_ode_or_even_list(&head_odd, cur_head, &cur_odd, &init_odd_flag);
        }
        cur_head = cur_head->next;
    }
}

void free_polynom(node_t *head)
{
    node_t *next_node;

    for (; head; head = next_node)
    {
        next_node = head->next;
        free(head);
    }
}