#include "array_func.h"

void fill_fibonaci(int *array, int size)
{
    int num_1, num_2;
    num_1 = 0;
    num_2 = 1;

    int i = 0;
    while (i < size)
    {
        array[i] = num_1;
        i++;

        if (i < size)
            array[i] = num_2;
        i++;

        num_1 = num_1 + num_2;
        num_2 = num_1 + num_2;
    }

}

int find_num_of_first_find_elems(int *array, int size)
{
    int *temp_array = malloc(sizeof(int) * size);
    int cur_elem_index = 0;
    for (int i = 0; i < size; i++)
    {
        int flag_is_in_array = 0;
        for (int j = 0; j < cur_elem_index; j++)
            if (array[i] == temp_array[j])
                flag_is_in_array = 1;
        if (flag_is_in_array == 0)
        {
            temp_array[cur_elem_index] = array[i];
            cur_elem_index++;
        }

        flag_is_in_array = 0;
    }

    int new_len = cur_elem_index;
    return new_len;
}

int add_first_find_elem(int *array, int size, int *new_arr, int new_size)
{
    int cur_elem_index = 0;
    for (int i = 0; i < size; i++)
    {
        int flag_is_in_array = 0;
        for (int j = 0; j < cur_elem_index; j++)
            if (array[i] == new_arr[j])
                flag_is_in_array = 1;
        if (flag_is_in_array == 0)
        {
            new_arr[cur_elem_index] = array[i];
            cur_elem_index++;
        }

        flag_is_in_array = 0;
    }

    int new_len = cur_elem_index;
    return new_len;
}
