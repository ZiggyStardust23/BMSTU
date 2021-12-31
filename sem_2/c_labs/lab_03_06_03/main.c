#include <stdio.h>

#define MAX_SIZE 10
#define INCORRECT_SIZE -1
#define INCORRECT_INPUT -2
#define MATRIX_IS_NOT_SQUARE -3

void show_matrix(int matrix[MAX_SIZE][MAX_SIZE], int size)
{
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
        {
            printf("%d", matrix[i][j]);

            if (j != size - 1)
                printf("%c", ' ');
            else if (i != size - 1)
                printf("%c", '\n');
        } 
}

void fill_matrix(int matrix[MAX_SIZE][MAX_SIZE], int size)
{  
    int cur_element = 1;

    for (int i = 0; i < size / 2; i++)
    {
        for (int j = i; j < size - 1 - i; j++)
        {
            matrix[j][i] = cur_element;
            cur_element++;
        }
        for (int j = i; j < size - 1 - i; j++)
        {
            matrix[size - 1 - i][j] = cur_element;
            cur_element++;
        }
        for (int j = size - 1 - i; j > i; j--)
        {
            matrix[j][size - 1 - i] = cur_element;
            cur_element++;
        }
        for (int j = size - 1 - i; j > i; j--)
        {
            matrix[i][j] = cur_element;
            cur_element++;
        }
    }

    if (size % 2 == 1)
        matrix[size / 2][size / 2] = cur_element;
}

int main()
{
    int matrix[MAX_SIZE][MAX_SIZE];
    int row, column;

    if (scanf("%d%d", &row, &column) != 2)
        return INCORRECT_INPUT;
    if (row > 10 || row <= 0 || column > 10 || column <= 0)
        return INCORRECT_SIZE;
    if (row != column)
        return MATRIX_IS_NOT_SQUARE;


    fill_matrix(matrix, row);
    show_matrix(matrix, row);

    return 0;
}