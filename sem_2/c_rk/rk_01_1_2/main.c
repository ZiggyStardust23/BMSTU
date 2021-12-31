#include <stdio.h>

#define MAX_ARR_SIZE 100
#define INCORRECT_INPUT -1
#define INCORRECT_ARRAY_SIZE -2

int remove_del_nums_from_array(int *arr, int arr_size, int del_num)
{
	int k_index = 0;
	int i = 0;
	
	while (i < arr_size)
	{
		if (arr[i] % del_num == 0)
		{
			k_index++;
			if (k_index % 2 == 0)
			{
				for (int j = i; j < arr_size - 1; j++)
				{
					arr[j] = arr[j + 1];
				}
				arr_size--;
			}
		}
		
		i++;
	}
	
	return arr_size;
}

void print_arr(int *arr, int arr_size)
{
	for (int i = 0; i < arr_size; i++)
		printf("%d ", arr[i]);
}

int main()
{
	int array[MAX_ARR_SIZE];
	int arr_size;
	int cur_element;
	int del_num;
	
	if (scanf("%d", &arr_size) != 1)
		return INCORRECT_INPUT;
	if (arr_size > MAX_ARR_SIZE || arr_size <= 0)
		return INCORRECT_ARRAY_SIZE;
	
	for (int i = 0; i < arr_size; i++)
	{
		if (scanf("%d", &cur_element) != 1)
			return INCORRECT_INPUT;
		
		array[i] = cur_element;
	}
	
	if (scanf("%d", &del_num) != 1)
		return INCORRECT_INPUT;
	
	int new_arr_size = remove_del_nums_from_array(array, arr_size, del_num);
	
	print_arr(array, new_arr_size);
	
	return 0;
}