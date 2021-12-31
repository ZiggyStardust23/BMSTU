#include "../inc/check_main.h"

int tests_pow_matrix()
{

    //Pow 2
    int test_pos = 2;
    int pos_count = 0;

    int matrix_temp_1[3][3] = {{1, 2, 3},
                        {4, 5, 6},
                        {7, 8, 9}};

    int **matrix_1 = malloc(3 * sizeof(int *));
    for (int i = 0; i < 3; i++)
    {
        matrix_1[i] = malloc(3 * sizeof(int));
        for (int j = 0; j < 3; j++)
            matrix_1[i][j] = matrix_temp_1[i][j]; 
    }

    int result_matrix_1[3][3] = {{30, 36, 42},
                               {66, 81, 96},
                               {102, 126, 150}};
    
    matrix_pow(matrix_1, 2, 3);

    int same_flag = 1;
    
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if(matrix_1[i][j] != result_matrix_1[i][j])
                same_flag = 0;

    if (same_flag == 0)
        pos_count++;

    for (int i = 0; i < 3; i++)
        free(matrix_1[i]);
    free(matrix_1);

    //Pow 5
    
    int matrix_temp_2[2][2] = {{1, 2},
                        {3, 4}};

    int **matrix_2 = malloc(2 * sizeof(int *));
    for (int i = 0; i < 2; i++)
    {
        matrix_2[i] = malloc(2 * sizeof(int));
        for (int j = 0; j < 2; j++)
            matrix_2[i][j] = matrix_temp_2[i][j]; 
    }

    int result_matrix_2[2][2] = {{1069, 1558},
                                 {2337, 3406}};

    matrix_pow(matrix_2, 5, 2);

    same_flag = 1;

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            if(matrix_2[i][j] != result_matrix_2[i][j])
                same_flag = 0;

    if (same_flag == 0)
        pos_count++;
    
    for (int i = 0; i < 2; i++)
        free(matrix_2[i]);
    free(matrix_2);

    printf("===%s:", __func__);
    printf("\n -Позитивные тесты: %d of %d - %s", test_pos - pos_count, test_pos, pos_count ? "FAILED" : "SUCCESS\n");

    return pos_count;
}

int tests_matrix_multy()
{
    int test_pos = 2;
    int pos_count = 0;

    //Multy 2x2

    int matrix_a_temp_1[2][2] = {{1, 2},
                            {3, 4}};
    int matrix_b_temp_1[2][2] = {{4, 3},
                            {2, 1}};

    int **matrix_a_1 = malloc(2 * sizeof(int *));
    for (int i = 0; i < 2; i++)
    {
        matrix_a_1[i] = malloc(2 * sizeof(int));
        for (int j = 0; j < 2; j++)
            matrix_a_1[i][j] = matrix_a_temp_1[i][j]; 
    }

    int **matrix_b_1 = malloc(2 * sizeof(int *));
    for (int i = 0; i < 2; i++)
    {
        matrix_b_1[i] = malloc(2 * sizeof(int));
        for (int j = 0; j < 2; j++)
            matrix_b_1[i][j] = matrix_b_temp_1[i][j]; 
    }

    int result_matrix_1[2][2] = {{8, 5},
                                 {20, 13}};
    
    matrix_multy(matrix_a_1, matrix_b_1, 2);

    int same_flag = 1;

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            if (result_matrix_1[i][j] != matrix_a_1[i][j])
                same_flag = 0;

    if (same_flag == 0)
        pos_count++;

    for (int i = 0; i < 2; i++)
    {
        free(matrix_a_1[i]);
        free(matrix_b_1[i]);
    }
    free(matrix_a_1);
    free(matrix_b_1);

    //Multy 3x3

    int matrix_a_temp_2[3][3] = {{1, 2, 3},
                            {4, 5, 6},
                            {7, 8, 9}};
    int matrix_b_temp_2[3][3] = {{9, 8, 7},
                            {6, 5, 4},
                            {3, 2, 1}};

    int **matrix_a_2 = malloc(3 * sizeof(int *));
    for (int i = 0; i < 3; i++)
    {
        matrix_a_2[i] = malloc(3 * sizeof(int));
        for (int j = 0; j < 3; j++)
            matrix_a_2[i][j] = matrix_a_temp_2[i][j]; 
    }

    int **matrix_b_2 = malloc(3 * sizeof(int *));
    for (int i = 0; i < 3; i++)
    {
        matrix_b_2[i] = malloc(3 * sizeof(int));
        for (int j = 0; j < 3; j++)
            matrix_b_2[i][j] = matrix_b_temp_2[i][j]; 
    }

    
    int result_matrix_2[3][3] = {{30, 24, 18},
                                 {84, 69, 54},
                                 {138, 114, 90}};

    matrix_multy(matrix_a_2, matrix_b_2, 3);

    same_flag = 1;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if(matrix_a_2[i][j] != result_matrix_2[i][j])
                same_flag = 0;

    for (int i = 0; i < 3; i++)
    {
        free(matrix_a_2[i]);
        free(matrix_b_2[i]);
    }
    free(matrix_a_2);
    free(matrix_b_2);

    if (same_flag == 0)
        pos_count++;

    printf("===%s:", __func__);
    printf("\n -Позитивные тесты: %d of %d - %s", test_pos - pos_count, test_pos, pos_count ? "FAILED" : "SUCCESS\n");
    return pos_count;
}