#include <stdio.h>

#define MAX_ARRAY_LEN 10
#define INCORRECT_ARRAY_LEN -1
#define INCORRECT_INPUT -2
#define ARRAY_IS_EMPTY -3

int compare(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

int find_max(int *first, int *last)
{
    int *p1 = first;
    int *p2 = last - 1;
    int result = *p1 + *p2;
    int last_iter = 0;

    while (last_iter == 0)
    {   
        if ((p1 + 1) == p2 || p1 == p2) 
            last_iter = 1;
        else
        {
            p1++;
            p2--;
        }

        result = compare(result, (*p1 + *p2));
    }
    
    return result;
}

int main()
{
    int array_len;

    if (scanf("%d", &array_len) != 1)
        return INCORRECT_INPUT;
    if (array_len <= 0 || array_len > MAX_ARRAY_LEN)
        return INCORRECT_ARRAY_LEN;
    
    int array[MAX_ARRAY_LEN];

    int *start = array;
    int *end = array + array_len;

    for (int *i = start; i < end; i++)
    {
        if (scanf("%d", i) != 1)
            return INCORRECT_INPUT;
    }
    
    if (array_len > 0)
        printf("%d", find_max(array, array + array_len));
    else
        return ARRAY_IS_EMPTY;

    return 0;
}
