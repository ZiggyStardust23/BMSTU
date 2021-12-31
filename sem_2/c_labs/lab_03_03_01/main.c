#include <stdio.h>

#define MAX_SIZE 10
#define INCORRECT_SIZE -1
#define INCORRECT_INPUT -2

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

int find_max_element(int *arr, int arr_size)
{
    int max_el = arr[0];
    
    for (int i = 1; i < arr_size; i++)
        if (arr[i] > max_el)
            max_el = arr[i];
    
    return max_el;
}

void move_str_of_matrix(int matrix[MAX_SIZE][MAX_SIZE], int column, int cur_column)
{
    int array[MAX_SIZE];
    
    for (int i = 0; i < column; i++)
        array[i] = matrix[cur_column - 1][i];
        
    for (int i = 0; i < column; i++)
        matrix[cur_column - 1][i] = matrix[cur_column][i];
                              
    for (int i = 0; i < column; i++)
        matrix[cur_column][i] = array[i];   
}


void row_sort(int matrix[MAX_SIZE][MAX_SIZE], int row, int column)
{
    int str1, str2;
    
    for (int i = 0; i < row; i++)
        for (int j = row - 1; j > i; j--)
        {
            str1 = find_max_element(matrix[j], column);
            str2 = find_max_element(matrix[j - 1], column);
            
            if (str1 > str2)                  
                move_str_of_matrix(matrix, column, j);
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
    int row, column;

    if (scanf("%d%d", &row, &column) != 2)
        return INCORRECT_INPUT;
    if (row > 10 || row <= 0 || column > 10 || column <= 0)
        return INCORRECT_SIZE;

    if (read_matrix(matrix, row, column) != 0)
        return INCORRECT_INPUT;
    
    row_sort(matrix, row, column);
    show_matrix(matrix, row, column);

    return 0;
}
