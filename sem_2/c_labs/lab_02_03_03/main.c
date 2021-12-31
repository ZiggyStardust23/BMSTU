#include <stdio.h>
#include <math.h>

#define MAX_ARRAY_LENGTH 10
#define INCORRECT_LENGTH -1
#define INCORRECT_INPUT -2

int find_reverse(int num)
{
    int save_num = num;
    int reversed_num = 0;

    while (save_num > 0)
    {
        reversed_num = reversed_num * 10 + save_num % 10;
        save_num /= 10;
    }
    return reversed_num;
}

int change_array(int *arr, int arr_len)
{   
    int new_len = arr_len;
    int reversed_element;
    for (int i = arr_len - 1; i >= 0; i--)
        if (arr[i] > 0)
        {   
            reversed_element = find_reverse(arr[i]);

            for (int j = new_len; j > i; j--)
                arr[j] = arr[j - 1];

            new_len++;
            arr[i + 1] = reversed_element;
        }

    return new_len;
}   

void show_array(int *arr, int arr_len)
{
    for (int i = 0; i < arr_len; i++)
        printf("%d ", arr[i]);
}

int main()
{
    int array_length;
    int current_element;
    
    if (scanf("%d", &array_length) != 1)
        return INCORRECT_INPUT;
    if (array_length < 1 || array_length > MAX_ARRAY_LENGTH)
        return INCORRECT_LENGTH;

    int array[MAX_ARRAY_LENGTH * 2];

    for (int i = 0; i < array_length; i++)
    {
        if (scanf("%d", &current_element) != 1)
            return INCORRECT_INPUT;
        
        array[i] = current_element;
    }     

    int n_len = change_array(array, array_length);

    show_array(array, n_len);

    return 0;
}