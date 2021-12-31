#include "../inc/check_main.h"

int check_ddx()
{
    int test_pos = 1;
    int pos_count = 0;

    node_t *node_1 = malloc(sizeof(node_t));
    node_1->elem.coef = 4;
    node_1->elem.pow = 2;

    node_t *node_2 = malloc(sizeof(node_t));
    node_2->elem.coef = 12;
    node_2->elem.pow = 1;

    node_1->next = node_2;

    node_t *node_3 = malloc(sizeof(node_t));
    node_3->elem.coef = 1;
    node_3->elem.pow = 0;

    node_2->next = node_3;
    node_3->next = NULL;

    node_t *new_head = NULL;

    find_ddx(node_1, &new_head);

    if (new_head->elem.coef != 8 || new_head->elem.pow != 1)
        pos_count = 1;

    if ((new_head->next)->elem.coef != 12 || (new_head->next)->elem.pow != 0)
        pos_count = 1;

    if ((new_head->next)->next != NULL)
        pos_count = 1;

    free_polynom(node_1);
    free(new_head->next);
    free(new_head);

    printf("===%s:", __func__);
    printf("\n -Позитивные тесты: %d of %d - %s", test_pos - pos_count, test_pos, pos_count ? "FAILED" : "SUCCESS\n");
    
    return pos_count;
}