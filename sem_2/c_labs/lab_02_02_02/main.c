#include <stdio.h>

#define MAX_ARRAY_LENGTH 10
#define INCORRECT_LENGTH -1
#define INCORRECT_INPUT -2
#define THERE_ARE_NO_MIRROR_NUMS -3

int mirror_num(int num)
{   
    if (num < 0)
        num *= -1;

    int result = 0;
    int check_num = num;
    int digits_in_num = 0;

    int last_digit = num % 10;
    int first_digit = num % 10;

    while (check_num > 0)
    {
        digits_in_num++;
        first_digit = check_num % 10;
        check_num = (check_num - check_num % 10) / 10;
    }

    if (first_digit == last_digit)
        result = 1;

    return result;
}

void show_array(int *arr, int len)
{
    for (int i = 0; i < len; i++)
        printf("%d ", arr[i]);
}

void create_mirror_array(int *child_arr, int *parent_arr, int parent_len)
{
    int j = 0;

    for (int i = 0; i < parent_len; i++)
    {
        if (mirror_num(parent_arr[i]) == 1)
        {
            child_arr[j] = parent_arr[i];
            j++;
        }
    }
}

int main()
{
    int array_length;
    int current_element;
    
    if (scanf("%d", &array_length) != 1)
        return INCORRECT_INPUT;
    if (array_length < 1 || array_length > MAX_ARRAY_LENGTH)
        return INCORRECT_LENGTH;

    int array[MAX_ARRAY_LENGTH];
    int new_array[MAX_ARRAY_LENGTH];
    int mirror_nums = 0;

    for (int i = 0; i < array_length; i++)
    {
        if (scanf("%d", &current_element) != 1)
            return INCORRECT_INPUT;
        if (mirror_num(current_element))
            mirror_nums++;

        array[i] = current_element;
    }

    if (mirror_nums == 0)
        return THERE_ARE_NO_MIRROR_NUMS;

    create_mirror_array(new_array, array, array_length);

    show_array(new_array, mirror_nums);

    return 0;
}
