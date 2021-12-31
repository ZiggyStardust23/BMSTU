#include "snake.h"
#include <stdio.h>
#include <stdlib.h>

void snake_sort(int **matrix, int size)
{
	int *temp_arr = malloc(size * size * sizeof(int));

    for (int i = 0; i < size; i++)
		for(int j = 0; j < size; j++)
			temp_arr[i * size + j] = matrix[0][i * size + j];

	int c_temp = 0;
    int line = 0;
    int column = 0;
	int cur_index = 0;
    int elems_in = size * size;
    
	for (int num_of_iterations = size - 1; num_of_iterations > 0; num_of_iterations--)
	{
		
		if (c_temp % 2 == 1)
		{
            line = size - 1;
        	column = num_of_iterations;
			while(column < size)
			{
				matrix[line][column] = temp_arr[cur_index];
				column++;
				cur_index++;
                line--;
			}
		}
		else
		{
            int column = size - 1;
			int line = num_of_iterations;
			while(line < size)
			{
				matrix[line][column] = temp_arr[cur_index];
				column--;
				line++;
				cur_index++;
			}
		}
		c_temp++;
	}
    cur_index = 1;
    if (size % 2 == 1)
        c_temp++;

    for (int num_of_iterations = 0; num_of_iterations < size; num_of_iterations++)
	{
		
		if (c_temp % 2 == 1)
		{
			int line = num_of_iterations;
			int column = 0;

			while(line >= 0)
			{
				matrix[line][column] = temp_arr[elems_in - cur_index];
				column++;
				line--;
				cur_index++;
			}
		}
		else
		{
			int line = 0;
			int column = num_of_iterations;
			while(column >= 0)
			{
				matrix[line][column] = temp_arr[elems_in - cur_index];
				column--;
				line++;
				cur_index++;
			}
		}
		c_temp++;
	}
	cur_index = 1;
free(temp_arr);
}
