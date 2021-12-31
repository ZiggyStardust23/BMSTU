#include "../inc/io.h"

int read_choice(int *choice)
{
    int error_code = 0;
    char str_choice[3];

    if (scanf("%s", str_choice) != 1)
        error_code = INCORRECT_INPUT;

    if (error_code == 0)
    {
        if (strcmp(str_choice, "val") == 0)
            *choice = 0;
        else if (strcmp(str_choice, "ddx") == 0)
            *choice = 1;
        else if (strcmp(str_choice, "sum") == 0)
            *choice = 2;
        else if (strcmp(str_choice, "dvd") == 0)
            *choice = 3;
        else
            error_code = INCORRECT_INPUT;
    }

    return error_code;
}

int read_polynom(node_t **head)
{
    node_t *cur_node = NULL;
    int error_code = 0;
    int stop_code = 0;

    int cur_coef = 0;
    int cur_pow = 0;
    char cur_ch;

    int first_iter_flag = 1;

    while (stop_code == 0)
    {
        if (scanf("%d", &cur_coef) != 1)
        {
            stop_code = 1;
        }   

        if (scanf("%d", &cur_pow) != 1)
        {
            stop_code = 1;
            error_code = INCORRECT_INPUT;
        }

        if (stop_code == 0)
        {
            if (first_iter_flag == 1)
            {
                *head = malloc(sizeof(node_t));
                cur_node = *head;
                cur_node->elem.coef = cur_coef;
                cur_node->elem.pow = cur_pow;
                cur_node->next = NULL;
                first_iter_flag = 0;
            }   
            else
            {
                cur_node->next = malloc(sizeof(node_t));
                cur_node = cur_node->next;
                cur_node->elem.coef = cur_coef;
                cur_node->elem.pow = cur_pow;
                cur_node->next = NULL;
            }
        }

        cur_ch = getchar();
        if (cur_ch == '\n')
            stop_code = 1;
    }

    return error_code;
}

void print_polynom(node_t *head)
{
    node_t *cur_node = head;

    while (cur_node != NULL)
    {
        printf("%d %d ", cur_node->elem.coef, cur_node->elem.pow);
        cur_node = cur_node->next;
    }

    if (head != NULL)
        printf("%c", 'L');
}