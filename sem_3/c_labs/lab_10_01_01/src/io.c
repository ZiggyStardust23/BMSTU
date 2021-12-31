#include "../inc/io.h"

void read_from_file_to_list(FILE *f, node_t *head)
{
    int cur_num;
    int *save_num;
    node_t *cur_node = head;
    int flag_first_iter = 1;
    
    while (fscanf(f, "%d", &cur_num) == 1)
    {
        if (flag_first_iter == 1)
        {
            save_num = malloc(sizeof(int));
            *save_num = cur_num;
            cur_node->data = save_num;
            flag_first_iter = 0; 
        }
        else
        {
            cur_node->next = malloc(sizeof(node_t));
            cur_node = cur_node->next;
            cur_node->next = NULL;
            save_num = malloc(sizeof(int));
            *save_num = cur_num;
            cur_node->data = save_num;
        }
    }
}

void print_list(node_t *head)
{
    node_t *cur_node = head;
    while (cur_node != NULL)
    {
        printf("%d ", *((int*)(cur_node->data)));
        cur_node = cur_node->next;
    }
}

void write_to_file(FILE *f, node_t *head)
{
    node_t *cur_node = head;
    while (cur_node != NULL)
    {
        fprintf(f, "%d\n", *((int*)cur_node->data));
        cur_node = cur_node->next;
    }
}

void print_menu()
{
    printf("\n1 - print list\n2 - pop front\n3 - add elem\n4 - leave\nEnter code: ");
}   