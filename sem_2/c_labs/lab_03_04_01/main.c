#include <stdio.h>

#define MAX_SIZE 10
#define INCORRECT_SIZE -1
#define INCORRECT_INPUT -2
#define MATRIX_IS_NOT_SQUARE -3

void show_matrix(int matrix[MAX_SIZE][MAX_SIZE], int row, int column)
{
    for (int i = 0; i < row; i++)
        for (int j = 0; j < column; j++)
        {
            printf("%d", matrix[i][j]);

            if (j != column - 1)
                printf("%c", ' ');
            else if (i != row - 1)
                printf("%c", '\n');
        } 
}

void swap_matrix(int matrix[MAX_SIZE][MAX_SIZE], int size)
{
    int last_element_i = size - 1;

    for (int i = 0; i < size / 2; i++)
        for (int j = i; j < size - i; j++)
        {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[last_element_i - i][last_element_i - j];
            matrix[last_element_i - i][last_element_i - j] = temp;
        }
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

    for (int i = 0; i < row; i++)
        for (int j = 0; j < column; j++)
            if (scanf("%d", &matrix[i][j]) != 1)
                return INCORRECT_INPUT;
    
    swap_matrix(matrix, row);
    show_matrix(matrix, row, column);

    return 0;
}