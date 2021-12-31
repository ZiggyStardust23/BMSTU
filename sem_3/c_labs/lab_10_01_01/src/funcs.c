#include "../inc/funcs.h"

int comparator(const void *a, const void *b)
{
    int *a_p = (int*)a;
    int *b_p = (int*)b;
    int result;
    if (*a_p < *b_p)
        result = -1;
    else if (*a_p == *b_p)
        result = 0;
    else
        result = 1; 

    return result;
}

node_t *find(node_t *head, const void *data, int (*comparator)(const void*, const void *))
{
    node_t *return_node = NULL;
    if (head != NULL && data != NULL && comparator != NULL)
    {
        node_t *cur_node = head;

        while (cur_node != NULL && return_node == NULL)
        {
            if (comparator(cur_node->data, data) == 0)
                return_node = cur_node;

            cur_node = cur_node->next;
        }
    }

    return return_node;
}

void *pop_front(node_t **head)
{
    void *temp = NULL;
    if (head != NULL && *head != NULL)
    {
        temp = (*head)->data;
        node_t *temp_node = *head;
        *head = (*head)->next;

        free(temp_node); 
    }

    return temp;
}

int copy(node_t *head, node_t **new_head)
{
    int error_code = 0;
    *new_head = NULL;

    if (head != NULL)
    {
        node_t *cur_head = head;
        node_t *save_new_head = NULL;

        *new_head = malloc(sizeof(node_t));
        if (*new_head == NULL)
            error_code = DATA_ERROR;
        else
        {
            (*new_head)->data = cur_head->data;
            (*new_head)->next = NULL;
            save_new_head = *new_head;
            cur_head = cur_head->next;

            while (cur_head != NULL && error_code == 0)
            {
                (*new_head)->next = malloc(sizeof(node_t));
                if ((*new_head)->next == NULL)
                    error_code = DATA_ERROR;
                else
                {
                    (*new_head) = (*new_head)->next;
                    (*new_head)->data = cur_head->data;
                    (*new_head)->next = NULL;

                    cur_head = cur_head->next;
                }
            }

            (*new_head)->next = NULL;
        }
        *new_head = save_new_head;
    }
    else
        error_code = DATA_ERROR;

    return error_code;
}

void sorted_insert(node_t **head, node_t *element, int(*comparator)(const void*, const void*))
{
    if (*head != NULL && element != NULL && comparator != NULL)
    {
        int found_flag = 0;

        node_t *cur_node = *head;
        node_t *previous_node = NULL;

        while (cur_node != NULL && found_flag == 0)
        {
            if (comparator(cur_node->data, element->data) > 0)
            {
                element->next = cur_node;
                found_flag = 1;

                if (previous_node == NULL)
                    *head = element;
                else
                    previous_node->next = element;
            }

            previous_node = cur_node;
            cur_node = cur_node->next;
        }

        if (found_flag == 0)
        {
            previous_node->next = element;
            element->next = NULL;
        }
    }
    else if (*head == NULL)
    {
        element->next = NULL;
        *head = element;
    }
}



node_t *sort(node_t *head, int (*comparator)(const void *, const void*))
{
    if (head != NULL && comparator != NULL)
    {
        node_t *cur_node = head;
        node_t *previous_node = NULL;

        int stop_flag = 0;
        int swap_flag = 0;

        if (head != NULL)
            while (stop_flag == 0)
            {
                swap_flag = 0;

                while (cur_node->next != NULL && swap_flag == 0)
                {
                    if (comparator(cur_node->data, (cur_node->next)->data) > 0)
                    {
                        swap_flag = 1;
                        if (previous_node != NULL)
                        {
                            previous_node->next = cur_node->next;
                        }
                        else
                        {
                            head = cur_node->next;
                        }
                        sorted_insert(&head, cur_node, comparator);
                    }
                    else
                    {
                        previous_node = cur_node;
                        cur_node = cur_node->next;
                    }
                }

                if (swap_flag == 0)
                    stop_flag = 1;
                else
                {
                    previous_node = NULL;
                    cur_node = head;
                }
            }
    }
    return head;
}

void free_list(node_t *head)
{
    node_t *cur_node = head;
    while (cur_node != NULL)
    {
        node_t *node_to_free = cur_node;
        cur_node = cur_node->next;
        free(node_to_free->data);
        free(node_to_free);
    }
}

void add_elem(node_t **head)
{
    printf("Enter int num: ");
    int cur_int = 0;
    while (scanf("%d", &cur_int) != 1)
    {
        printf("\nEnter int num: ");
    }

    node_t *new_node = malloc(sizeof(node_t));
    new_node->next = NULL;
    int *node_num = malloc(sizeof(int));
    *node_num = cur_int;
    new_node->data = node_num;
    
    if (*head == NULL)
    {
        *head = new_node;
    }
    else
    {
        node_t *cur_node = *head;
        while (cur_node->next != NULL)
            cur_node = cur_node->next;

        cur_node->next = new_node;
    }
}