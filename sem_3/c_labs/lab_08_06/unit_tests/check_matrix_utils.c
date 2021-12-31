#include "../inc/check_main.h"

int tests_make_square_matrix()
{

    //Make_square_matrix_1
    int test_pos = 2;
    int pos_count = 0;

    int matrix_1_temp[2][3] = {{1, 2, 3},
                          {4, 5, 6}};

    int **matrix_1 = malloc(2 * sizeof(int *));
    for (int i = 0; i < 2; i++)
    {
        matrix_1[i] = malloc(3 * sizeof(int));
        for (int j = 0; j < 3; j++)
            matrix_1[i][j] = matrix_1_temp[i][j];
    }

    
    int result_matrix_1[2][2] = {{2, 3},
                                 {5, 6}};
    
    int size = 0;

    matrix_1 = make_square_matrix(matrix_1, 2, 3, &size);

    int same_flag = 1;
    
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            if(matrix_1[i][j] != result_matrix_1[i][j])
                same_flag = 0;

    if (same_flag == 0)
        pos_count++;

    for (int i = 0; i < size; i++)
        free(matrix_1[i]);
    free(matrix_1);

    printf("===%s:", __func__);
    printf("\n -Позитивные тесты: %d of %d - %s", test_pos - pos_count, test_pos, pos_count ? "FAILED" : "SUCCESS\n");

    return pos_count;
}

int tests_form_matrix()
{
    int test_pos = 2;
    int pos_count = 0;

    //Form 2->3

    int matrix_a_temp_1[2][2] = {{1, 2},
                            {3, 4}};

    int **matrix_a_1 = malloc(2 * sizeof(int *));
    for (int i = 0; i < 2; i++)
    {
        matrix_a_1[i] = malloc(2 * sizeof(int));
        for (int j = 0; j < 2; j++)
            matrix_a_1[i][j] = matrix_a_temp_1[i][j];
    }

    int result_matrix_1[3][3] = {{1, 2, 1},
                                 {3, 4, 3},
                                 {1, 2, 1}};
    
    matrix_a_1 = form_matrix(matrix_a_1, 3, 2);

    int same_flag = 1;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (result_matrix_1[i][j] != matrix_a_1[i][j])
                same_flag = 0;

    if (same_flag == 0)
        pos_count++;

    for (int i = 0; i < 3; i++)
        free(matrix_a_1[i]);
    free(matrix_a_1);

    //Form 3->4

    int matrix_a_temp_2[3][3] = {{1, 2, 3},
                            {4, 5, 6},
                            {7, 8, 9}};

    int **matrix_a_2 = malloc(3 * sizeof(int *));
    for (int i = 0; i < 3; i++)
    {
        matrix_a_2[i] = malloc(3 * sizeof(int));
        for (int j = 0; j < 3; j++)
            matrix_a_2[i][j] = matrix_a_temp_2[i][j];
    }

    
    int result_matrix_2[4][4] = {{1, 2, 3, 1},
                                 {4, 5, 6, 4},
                                 {7, 8, 9, 7},
                                 {3, 4, 5, 3}};

    matrix_a_2 = form_matrix(matrix_a_2, 4, 3);

    same_flag = 1;

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if(matrix_a_2[i][j] != result_matrix_2[i][j])
                same_flag = 0;

    if (same_flag == 0)
        pos_count++;

    for (int i = 0; i < 4; i++)
        free(matrix_a_2[i]);
    free(matrix_a_2);

    printf("===%s:", __func__);
    printf("\n -Позитивные тесты: %d of %d - %s", test_pos - pos_count, test_pos, pos_count ? "FAILED" : "SUCCESS\n");
    return pos_count;
}