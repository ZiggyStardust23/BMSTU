#include "../inc/process.h"

int process_count_val()
{
    int error_code = 0;

    int result = 0;
    node_t *head = NULL;
    error_code = read_polynom(&head);

    if (error_code == 0 && head == NULL)
        error_code = EMPTY_POLYNOM;

    if (error_code == 0)     
        error_code = count_val(head, &result);

    if (error_code == 0)
        printf("%d", result);

    free_polynom(head);

    return error_code;
}

int process_find_ddx()
{
    int error_code = 0;

    node_t *head = NULL;
    node_t *new_head = NULL;
    error_code = read_polynom(&head);

    if (error_code == 0 && head == NULL)
        error_code = EMPTY_POLYNOM;
    
    if (error_code == 0)
        find_ddx(head, &new_head);

    if (error_code == 0 && new_head == NULL)
        error_code = EMPTY_POLYNOM;

    if (error_code == 0)
        print_polynom(new_head);

    free_polynom(head);
    free_polynom(new_head);

    return error_code;
}

int process_sum()
{
    int error_code = 0;

    node_t *head_a = NULL;
    node_t *head_b = NULL;

    error_code = read_polynom(&head_a);
    if (error_code == 0)
        error_code = read_polynom(&head_b);

    if (error_code == 0 && (head_a == NULL || head_b == NULL))
        error_code = EMPTY_POLYNOM;

    node_t *head_result = NULL;
    if (error_code == 0)
    {
        sum_polynom(head_a, head_b, &head_result);
    }

    if (error_code == 0 && head_result == NULL)
        error_code = EMPTY_POLYNOM;

    if (error_code == 0)
        print_polynom(head_result);

    free_polynom(head_a);
    free_polynom(head_b);
    free_polynom(head_result);

    return error_code;
}

int process_split_to_odd_even()
{
    int error_code = 0;

    node_t *head = NULL;
    node_t *head_odd = NULL;
    node_t *head_even = NULL;

    error_code = read_polynom(&head);

    if (error_code == 0 && head == NULL)
        error_code = EMPTY_POLYNOM;

    if (error_code == 0)
        split_to_odd_and_even(head, &head_even, &head_odd);

    if (error_code == 0)
    {
        print_polynom(head_even);
        if (head_odd != NULL)
            printf("\n");
        print_polynom(head_odd);
    }

    free_polynom(head);
    free_polynom(head_odd);
    free_polynom(head_even);

    return error_code;
}