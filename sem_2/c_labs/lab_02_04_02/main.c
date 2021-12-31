#include <stdio.h>

#define MAX_ARRAY_LEN 10
#define ARRAY_IS_FULL 100
#define ARRAY_IS_EMPTY -1

int fill_arr(int *arr)
{
    int current_element;
    int i = 0;
    int arr_size = 0;

    while (scanf("%d", &current_element) == 1)
    {       
        i++;
        if (arr_size <= 9)
        {
            arr[arr_size] = current_element;
            arr_size++;
        }
    }

    return i;
}

void selection_sort(int *arr, int arr_len)
{
    int min;

    for (int i = 0; i < arr_len - 1; i++)
    {
        min = i;

        for (int j = i + 1; j < arr_len; j++)
        {
            if (arr[min] > arr[j])
                min = j;
        }

        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

void print_array(int *arr, int arr_len)
{
    for (int i = 0; i < arr_len; i++)
        printf("%d ", arr[i]);
}

int main(void)
{   
    int array[MAX_ARRAY_LEN];
    
    int num_of_elements = fill_arr(array);

    if (num_of_elements == 0)
        return ARRAY_IS_EMPTY;
    
    if (num_of_elements > 10)
    {
        selection_sort(array, 10);
        print_array(array, 10);
    }
    else
    {
        selection_sort(array, num_of_elements);
        print_array(array, num_of_elements);
    }
        
    if (num_of_elements > 10)
        return ARRAY_IS_FULL;

    return 0;
}
