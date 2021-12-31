#include "../inc/check_main.h"

int check_find_arr_len()
{
    int test_pos = 2;
    int pos_count = 0;

    struct goods *arr = malloc(3 * sizeof(struct goods));
    for (int i = 0; i < 3; i++)
        arr[i].price = i * 10;

    if (find_new_arr_len(arr, 3, 20) != 2)
        pos_count++;
    
    if (find_new_arr_len(arr, 3, 0) != 0)
        pos_count++;

    free(arr);

    printf("===%s:", __func__);
    printf("\n -Позитивные тесты: %d of %d - %s", test_pos - pos_count, test_pos, pos_count ? "FAILED" : "SUCCESS\n");
    
    return pos_count;
}

int check_which_once_are_cheaper()
{
    int test_pos = 2;
    int pos_count = 0;

    struct goods *arr = malloc(3 * sizeof(struct goods));
    for (int i = 0; i < 3; i++)
        arr[i].price = i * 10;

    int new_size = find_new_arr_len(arr, 3, 11);

    struct goods *new_arr = malloc(new_size * sizeof(struct goods));

    which_ones_are_cheaper(arr, 3, new_arr, 11);

    int same_flag = 1;
    for (int i = 0; i < 2; i++)
        if (arr[i].price != new_arr[i].price)
            same_flag = 0;
    
    if (same_flag == 0)
        pos_count++;

    free(new_arr);

    new_size = find_new_arr_len(arr, 3, 1);

    new_arr = malloc(new_size * sizeof(struct goods));

    which_ones_are_cheaper(arr, 3, new_arr, 1);

    if (arr[0].price != new_arr[0].price)
        pos_count++;

    free(new_arr);
    free(arr);

    printf("===%s:", __func__);
    printf("\n -Позитивные тесты: %d of %d - %s", test_pos - pos_count, test_pos, pos_count ? "FAILED" : "SUCCESS\n");
    
    return pos_count;
}