#include <stdio.h>

#define INPUT_IS_INCORRECT -1
#define INPUT_IS_LOWER_THEN_ZERO -2
#define DIVISION_BY_ZERO -3 

int integer_division(int a, int b)
{
    int result = 0;

    while (a >= b)
    {
        a = a - b;
        result = result + 1;
    }

    return result;
}

int remains_of_division(int a, int b)
{
    int result = a - integer_division(a, b) * b;
    return result;
}

int main()
{
    int a, d;
    int q, r;

    if (scanf("%d%d", &a, &d) != 2)
    {
        return INPUT_IS_INCORRECT;
    }
    if (d == 0)
    {
        return DIVISION_BY_ZERO;
    }
    if (a <= 0 || d <= 0)
    {
        return INPUT_IS_LOWER_THEN_ZERO;
    }

    q = integer_division(a, d);
    r = remains_of_division(a, d);

    printf("%d %d", q, r);

    return 0;
}
