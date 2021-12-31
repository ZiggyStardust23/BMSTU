#include "../inc/matrix_utils.h"
#include "../inc/utils.h"

int **allocate_matrix(int n, int m)
{
    int **matrix = calloc(n, sizeof(int *));

    for (int i = 0; i < n; i++)
        matrix[i] = malloc(m * sizeof(int));
    
    return matrix;
}

int create_and_input_matrix(int ***matrix, int *n, int *m)
{
    int error_code = 0;

    error_code = enter_two_int(n, m);
    if (*n <= 0 || *m <= 0)
        error_code = INTORRECT_SIZE;
    if (error_code == 0)
        *matrix = allocate_matrix(*n, *m);
    if (error_code == 0)
        error_code = input_matrix(*matrix, n, m);

    return error_code;
}

void find_size_and_make_square(int ***matrix, int n, int m, int *size)
{
    if (n != m)
    {
        *matrix = make_square_matrix(*matrix, n, m, size);
    }
    else
        *size = n;
}

void choice_matrix_and_form_it(int ***matrix_a, int ***matrix_b, int size_a, int size_b, int *size)
{
    if (size_a > size_b)
    {
        *size = size_a;
        *matrix_b = form_matrix(*matrix_b, size_a, size_b);
    }
    else if (size_b > size_a)
    {
        *size = size_b;
        *matrix_a = form_matrix(*matrix_a, size_b, size_a);
    }
    else
        *size = size_a;
}

void find_min_elems_for_columns(int column_to_delete, int *column_index, int **matrix, int n, int m)
{
    int min_elem = matrix[0][0];
    for (int s = 0; s < column_to_delete; s++)
    {
        int min_found_flag = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                if (matrix[i][j] <= min_elem || (s != 0 && min_found_flag == 0))
                {
                    int flag_not_used = 1;
                    for (int k = 0; k < s; k++)
                        if (column_index[k] == j)
                            flag_not_used = 0;
                    if (flag_not_used == 1)
                    {
                        column_index[s] = j;
                        min_elem = matrix[i][j];
                        min_found_flag = 1;
                    }
                }
        }
    }
}

void write_without_deleted_columns(int column_to_delete, int *column_index, int **matrix, int **new_matrix, int n, int m)
{
    int cur_col = 0;
    for (int i = 0; i < m; i++)
    {
        int delete_flag = 0;
        for (int k = 0; k < column_to_delete; k++)
            if (column_index[k] == i)
                delete_flag = 1;

        if (delete_flag == 0)
        {
            for (int j = 0; j < n; j++)
            {
                new_matrix[j][cur_col] = matrix[j][i];
            }
            cur_col++;
        }
    }
}

void find_min_elems_for_string(int strings_to_delete, int *string_index, int **matrix, int n, int m)
{
    int min_elem = matrix[0][0];
    for (int s = 0; s < strings_to_delete; s++)
    {
        int min_found_flag = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                if (matrix[i][j] <= min_elem || (s != 0 && min_found_flag == 0))
                {
                    int flag_not_used = 1;
                    for (int k = 0; k < s; k++)
                        if (string_index[k] == i)
                            flag_not_used = 0;
                    if (flag_not_used == 1)
                    {
                        string_index[s] = i;
                        min_elem = matrix[i][j];
                        min_found_flag = 1;
                    }
                }
        }
    }
}

void write_without_deleted_strings(int strings_to_delete, int *string_index, int **matrix, int **new_matrix, int n, int m)
{
    int cur_str = 0;
    for (int i = 0; i < n; i++)
    {
        int delete_flag = 0;
        for (int k = 0; k < strings_to_delete; k++)
            if (string_index[k] == i)
                delete_flag = 1;

        if (delete_flag == 0)
        {
            for (int j = 0; j < m; j++)
            {
                new_matrix[cur_str][j] = matrix[i][j];
            }
            cur_str++;
        }
    }
}

int input_matrix(int **matrix, int *n, int *m)
{
    int error_code = 0;

    int cur_elem;
    for (int i = 0; i < *n; i++)
        for (int j = 0; j < *m; j++)
            if (error_code == 0)
            {
                if (scanf("%d", &cur_elem) != 1)
                    error_code = READ_ERROR;
                if (error_code == 0)
                    matrix[i][j] = cur_elem;
            }

    return error_code;
}

int **delete_strings(int n, int m, int **matrix, int size)
{
    int strings_to_delete = n - m;
    int *string_index = malloc(strings_to_delete * sizeof(int));

    find_min_elems_for_string(strings_to_delete, string_index, matrix, n, m);

    int **new_matrix = malloc((size) * sizeof(int *));
    for (int i = 0; i < (size); i++)
        new_matrix[i] = malloc((size) * sizeof(int));

    write_without_deleted_strings(strings_to_delete, string_index, matrix, new_matrix, n, m);

    free(string_index);

    return new_matrix;
}

int **delete_columns(int n, int m, int **matrix, int size)
{
    int column_to_delete = m - n;
    int *column_index = malloc(column_to_delete * sizeof(int));

    find_min_elems_for_columns(column_to_delete, column_index, matrix, n, m);

    int **new_matrix = malloc((size) * sizeof(int *));
    for (int i = 0; i < (size); i++)
        new_matrix[i] = malloc((size) * sizeof(int));

    write_without_deleted_columns(column_to_delete, column_index, matrix, new_matrix, n, m);

    free(column_index);

    return new_matrix;
}

int **make_square_matrix(int **matrix, int n, int m, int *size)
{
    if (n < m)
        *size = n;
    else
        *size = m;

    int **new_matrix;

    if (n > m)
        new_matrix = delete_strings(n, m, matrix, *size);
    else
        new_matrix = delete_columns(n, m, matrix, *size);   

    for (int i = 0; i < n; i++)
        free(matrix[i]);
    free(matrix);

    return new_matrix;
}

float average_geom(float write_elem, int pow_elems)
{
    int result = (int)(floor((pow((double) abs(write_elem), (double) 1 / pow_elems))));

    return result;
}

void add_strings(int **matrix, int **new_matrix, int old_size, int new_size)
{
    int iter = new_size - old_size;
    for (int n = 0; n < iter; n++)
    {
        float write_elem = 1;
        int pow_elems = 0;
        for (int j = 0; j < old_size; j++)
        {
            write_elem = 1;
            pow_elems = 0;
            for (int i = 0; i < old_size + n; i++) 
            {
                write_elem *= new_matrix[i][j];
                pow_elems++;
            }
            new_matrix[old_size + n][j] = average_geom(write_elem, pow_elems);
        }
    }
}

void add_columns(int **matrix, int **new_matrix, int old_size, int new_size)
{
    int iter = new_size - old_size;

    for (int n = 0; n < iter; n++)
    {
        int min_elem;
        for (int i = 0; i < new_size; i++)
        {
            min_elem = new_matrix[i][0];
            for (int j = 0; j < old_size; j++) 
            {
                if (new_matrix[i][j] < min_elem)
                    min_elem = new_matrix[i][j];
            }

            new_matrix[i][old_size + n] = min_elem;
        }
    }
}

int **form_matrix(int **matrix, int new_size, int old_size)
{
    int **new_matrix = malloc(new_size * sizeof(int *));
    for (int i = 0; i < new_size; i++)
        new_matrix[i] = malloc(new_size * sizeof(int));

    copy_square_matrix(new_matrix, matrix, old_size);

    add_strings(matrix, new_matrix, old_size, new_size);

    add_columns(matrix, new_matrix, old_size, new_size);

    free_one(matrix, old_size);

    return new_matrix;
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

void free_all(int **matrix_a, int **matrix_b, int a_n, int b_n, int size_a, int size_b, int size)
{
    if (size_a != 0 || size_b != 0)
    {
        if (matrix_a != NULL)
        {
            for (int i = 0; i < size; i++)
                free(matrix_a[i]);
            free(matrix_a);
        }

        if (matrix_b != NULL)
        {
            for (int i = 0; i < size; i++)
                free(matrix_b[i]);
            free(matrix_b);
        }
    }
    else
    {
        if (matrix_a != NULL)
        {
            for (int i = 0; i < a_n; i++)
                free(matrix_a[i]);
            free(matrix_a);
        }
        if (matrix_b != NULL)
        {
            for (int i = 0; i < b_n; i++)
                free(matrix_b[i]);
            free(matrix_b);
        }
    }
}

void free_one(int **matrix, int n)
{
    for (int i = 0; i < n; i++)
        if (matrix[i] != NULL)
            free(matrix[i]);
    free(matrix);
}

void make_identity_matrix(int **matrix, int size)
{
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            matrix[i][j] = 0;
    for (int i = 0; i < size; i++)
        matrix[i][i] = 1;
}

void copy_square_matrix(int **matrix_a, int **matrix_b, int size)
{
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            matrix_a[i][j] = matrix_b[i][j];
}