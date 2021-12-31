#include "util.h"

int find_max_len_of_num(int **matrix, int size)
{
    int max_len = 0;
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
        {
            int cur_len = find_len_of_num(matrix[i][j]);
            if (cur_len > max_len)
                max_len = cur_len;
        }
        
    return max_len;
}

void swap(int *el_1, int *el_2)
{
    int temp = *el_1;
    *el_1 = *el_2;
    *el_2 = temp;
}

void bubble_sort(int *arr, int arr_size)
{   
    for (int i = 0; i < arr_size; i++)
        for (int j = 0; j < arr_size - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

int find_len_of_num(int num)
{
    int len = 0;

    if (num == 0)
        len = 1;

    while(num > 0)
    {
        len++;
        num /= 10;
    }

    return len;
}

int read_from_file_to_arr(FILE *f_in, int *read_array, int num_to_read)
{
    int error_code = 0;
    int cur_elem;

    for (int i = 0; i < num_to_read; i++)
        if (error_code == 0)
        {
            if (fscanf(f_in, "%d", &cur_elem) != 1)
                error_code = READ_ERROR;
            if (error_code == 0)
                read_array[i] = cur_elem;
        }   

    return error_code;   
}