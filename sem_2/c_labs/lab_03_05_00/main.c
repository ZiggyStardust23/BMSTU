#include <stdio.h>

#define MAX_SIZE 10
#define INCORRECT_SIZE -1
#define INCORRECT_INPUT -2
#define THERE_IS_NO_SIMPLE_NUMS -3

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

int check_simple_num(int num)
{   
    if (num > 1)
    {
        for (int i = 2; i < num; i++)
            if (num % i == 0)
                return 0;
        return 1;
    }
    return 0;
}

int matrix_to_array(int matrix[MAX_SIZE][MAX_SIZE], int simple_elements[MAX_SIZE * MAX_SIZE], int row, int column)
{
    int num_of_simple_elements = 0;
    
    for (int i = 0; i < row; i++)
        for (int j = 0; j < column; j++)
            if (check_simple_num(matrix[i][j]))
            {
                simple_elements[num_of_simple_elements] = matrix[i][j];
                num_of_simple_elements++;
            }
            
    return num_of_simple_elements;
}

void reverse_matrix(int simple_elements[MAX_SIZE * MAX_SIZE], int num_of_simple_elements)
{
    int temp;
    
    int last_simple_element_i = num_of_simple_elements - 1;
    for (int i = 0; i < num_of_simple_elements / 2; i++)
    {
        temp = simple_elements[i];
        simple_elements[i] = simple_elements[last_simple_element_i - i];
        simple_elements[last_simple_element_i - i] = temp;
    }
}

void back_to_matrix(int matrix[MAX_SIZE][MAX_SIZE], int simple_elements[MAX_SIZE * MAX_SIZE], int row, int column)
{
    int cur_simple_element_i = 0;
    for (int i = 0; i < row; i++)
        for (int j = 0; j < column; j++)
            if (check_simple_num(matrix[i][j]))
            {
                matrix[i][j] = simple_elements[cur_simple_element_i];
                cur_simple_element_i++;
            }
}

int reverse_simple_nums_in_matrix(int matrix[MAX_SIZE][MAX_SIZE], int row, int column)
{
    int simple_elements[MAX_SIZE * MAX_SIZE];

    int num_of_simple_elements = matrix_to_array(matrix, simple_elements, row, column);

    if (num_of_simple_elements == 0)
        return THERE_IS_NO_SIMPLE_NUMS;

    reverse_matrix(simple_elements, num_of_simple_elements);

    back_to_matrix(matrix, simple_elements, row, column);

    return 0;
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
    
    int no_simple_check = reverse_simple_nums_in_matrix(matrix, row, column);
    
    if (no_simple_check == THERE_IS_NO_SIMPLE_NUMS)
        return THERE_IS_NO_SIMPLE_NUMS; 

    show_matrix(matrix, row, column);

    return 0;
}
