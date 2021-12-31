#include <stdio.h>

#define MAX_SIZE 10
#define INCORRECT_SIZE -1
#define INCORRECT_INPUT -2
#define INCORRECT_DEL_NUM -3
#define MATRIX_BECAME_EMPTY -4

int contains_this_num(int container, int content)
{
    int result_flag = 0;
    int save_num = container;
    int cur_num = 0;

    if (save_num < 0)
        save_num *= -1;

    if (container == 0 && content == 0)
        return 1;

    while (save_num != 0)
    {
        cur_num = save_num % 10;
        save_num = (save_num - cur_num) / 10;
        if (cur_num == content)
        {
            result_flag = 1;
            save_num = 0;
        }
    } 

    return result_flag;
}

void delete_column(int matrix[MAX_SIZE][MAX_SIZE], int new_num_of_columns, int row, int col)
{
    for (int n = col; n < new_num_of_columns; n++)
        for (int m = 0; m < row; m++)
            matrix[m][n] = matrix[m][n + 1];
}

int delete_columns(int matrix[MAX_SIZE][MAX_SIZE], int row, int column, int num_to_delete)
{
    int new_num_of_columns = column;
    int delete_flag;
    int i = 0;
    while (i < new_num_of_columns)
    {
        delete_flag = 0;

        for (int j = 0; j < row && delete_flag == 0; j++)
            if (contains_this_num(matrix[j][i], num_to_delete))
                delete_flag = 1;

        if (delete_flag)
        {
            --new_num_of_columns;
            delete_column(matrix, new_num_of_columns, row, i);
            i--;
        }

        i++;
    }

    return new_num_of_columns;
}

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
    int num_to_delete;

    if (scanf("%d%d", &row, &column) != 2)
        return INCORRECT_INPUT;
    if (row > 10 || row <= 0 || column > 10 || column <= 0)
        return INCORRECT_SIZE;

    if (read_matrix(matrix, row, column) != 0)
        return INCORRECT_INPUT;

    if (scanf("%d", &num_to_delete) != 1)
        return INCORRECT_INPUT;
    if (num_to_delete < 0 || num_to_delete > 9)
        return INCORRECT_DEL_NUM;

    column = delete_columns(matrix, row, column, num_to_delete);
    if (column == 0)
        return MATRIX_BECAME_EMPTY;
    show_matrix(matrix, row, column);

    return 0;
}
