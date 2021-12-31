#include <stdio.h>

#define MAX_SIZE 10
#define INCORRECT_SIZE -1
#define INCORRECT_INPUT -2

int check_order(int matrix[MAX_SIZE][MAX_SIZE], int cur_column, int row)
{
    int order_flag = 1;

    for (int j = 0; j < row - 1; j++)
        if (matrix[j][cur_column] <= matrix[j + 1][cur_column])
            order_flag = 0;
        
    if (row == 1)
        order_flag = 0;
        
    return order_flag;
}

void fill_k_array(int matrix[MAX_SIZE][MAX_SIZE], int *arr, int row, int column)
{
    for (int i = 0; i < column; i++)
    {
        arr[i] = check_order(matrix, i, row);
    }
}

void show_array(int *arr, int arr_len)
{
    for (int i = 0; i < arr_len; i++)
    {
        printf("%d", arr[i]);
        if (i != arr_len - 1)
            printf("%c", ' ');
    }
}

int read_matrix(int matrix[MAX_SIZE][MAX_SIZE], int row, int column)
{
    for (int i = 0; i < row; i++)
        for (int j = 0; j < column; j++)
            if (scanf("%d", &matrix[i][j]) != 1)
                return INCORRECT_INPUT;
    return 0;
}

int main()
{
    int matrix[MAX_SIZE][MAX_SIZE];
    int k_array[MAX_SIZE];
    int row, column;

    if (scanf("%d%d", &row, &column) != 2)
        return INCORRECT_INPUT;
    if (row > 10 || row <= 0 || column > 10 || column <= 0)
        return INCORRECT_SIZE;

    if (read_matrix(matrix, row, column) != 0)
        return INCORRECT_INPUT;
    
    fill_k_array(matrix, k_array, row, column);
    show_array(k_array, column);

    return 0;
}
