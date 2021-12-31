#include <stdio.h>
#include <stdlib.h>

#define READ_ERROR -1

void read_and_write_to_matrix(FILE *f_in, int **matrix, int size)
{
	int cur_elem;
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
		{
				fscanf(f_in, "%d", &cur_elem);
				matrix[i][j] = cur_elem;
		}
	
}

void print_matrix(int **matrix, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			printf("%d", matrix[i][j]);
			if (j != size - 1)
				printf(" ");
		}
		if (i != size - 1)
			printf("\n");
	}
}
int main(int argc, char **argv)
{
	FILE *f_in = fopen(argv[1], "r");
	int size;
	fscanf(f_in, "%d", &size);
	int **matrix = malloc(size * sizeof(int *));
	int *data = malloc(size * size * sizeof(int));
	
	for (int i = 0; i < size; i++)
		matrix[i] = data + i * size;
	
	read_and_write_to_matrix(f_in, matrix, size); 
	fclose(f_in);

	print_matrix(matrix, size);
	/*
	snake_sort(matrix, size);
	int **ptr = calloc(n * sizeof(int *));
	int *data = calloc(n * m * sizeof(int));
	data + i * m;
	*/
	
	return 0;
}