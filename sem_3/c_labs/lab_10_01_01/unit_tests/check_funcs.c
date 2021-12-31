#include "../inc/check_main.h"

int check_find()
{
    int test_pos = 1;
    int pos_count = 0;

    node_t *node = malloc(sizeof(node_t));
    int cur_int_1 = 1;
    int *cur_p_1 = malloc(sizeof(int));
    *cur_p_1 = cur_int_1;
    node->data = cur_p_1; 

    node_t *node_2 = malloc(sizeof(node_t));
    int cur_int_2 = 2;
    int *cur_p_2 = malloc(sizeof(int));
    *cur_p_2 = cur_int_2;
    node_2->data = cur_p_2;
    node->next = node_2;
    node_2->next = NULL;

    if (find(node, cur_p_2, comparator) != node_2)
        pos_count++;

    free(cur_p_1);
    free(cur_p_2);
    free(node);
    free(node_2);

    printf("===%s:", __func__);
    printf("\n -Позитивные тесты: %d of %d - %s", test_pos - pos_count, test_pos, pos_count ? "FAILED" : "SUCCESS\n");
    
    return pos_count;
}

int check_sort()
{
    int test_pos = 1;
    int pos_count = 0;

    node_t *node_1 = malloc(sizeof(node_t));
    int *p_1 = malloc(sizeof(int));
    *p_1 = 3;
    node_1->data = p_1;

    node_t *node_2 = malloc(sizeof(node_t));
    int *p_2 = malloc(sizeof(int));
    *p_2 = 2;
    node_2->data = p_2;

    node_1->next = node_2;

    node_t *node_3 = malloc(sizeof(node_t));
    int *p_3 = malloc(sizeof(int));
    *p_3 = 1;
    node_3->data = p_3;

    node_2->next = node_3;
    node_3->next = NULL;

    node_1 = sort(node_1, comparator);

    int checks = 0;
    if ((*(int*)(node_1->data)) == 1)
        checks++;
    if (*((int*)((node_1->next)->data)) == 2)
        checks++;
    if ((*(int*)(((node_1->next)->next)->data)) == 3)
        checks++;

    if (checks != 3)
        pos_count++;

    free(p_1);
    free(p_2);
    free(p_3);

    free((node_1->next)->next);
    free((node_1->next));
    free(node_1);

    printf("===%s:", __func__);
    printf("\n -Позитивные тесты: %d of %d - %s", test_pos - pos_count, test_pos, pos_count ? "FAILED" : "SUCCESS\n");
    
    return pos_count;
}

int check_comparator()
{
    int test_pos = 2;
    int pos_count = 0;

    int *p_1 = malloc(sizeof(int));
    int *p_2 = malloc(sizeof(int));

    *p_1 = 2;
    *p_2 = 1;

    if (comparator(p_1, p_2) <= 0)
        pos_count++;

    *p_2 = 2;

    if (comparator(p_1, p_2) != 0)
        pos_count++;

    free(p_1);
    free(p_2);

    printf("===%s:", __func__);
    printf("\n -Позитивные тесты: %d of %d - %s", test_pos - pos_count, test_pos, pos_count ? "FAILED" : "SUCCESS\n");
    
    return pos_count;
}

int check_pop_front()
{
    int test_pos = 1;
    int pos_count = 0;

    node_t *node_1 = malloc(sizeof(node_t));
    int *p_1 = malloc(sizeof(int));
    *p_1 = 3;
    node_1->data = p_1;

    node_t *node_2 = malloc(sizeof(node_t));
    int *p_2 = malloc(sizeof(int));
    *p_2 = 2;
    node_2->data = p_2;

    node_1->next = node_2;
    node_2->next = NULL;

    int *test_p = pop_front(&node_1);

    if (test_p != p_1)
        pos_count++;

    free(p_1);
    free(p_2);

    free((node_1->next));
    free(node_1); 

    printf("===%s:", __func__);
    printf("\n -Позитивные тесты: %d of %d - %s", test_pos - pos_count, test_pos, pos_count ? "FAILED" : "SUCCESS\n");
    
    return pos_count;    
}