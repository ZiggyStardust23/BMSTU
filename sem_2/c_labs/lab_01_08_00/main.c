#include <stdio.h>

#define INCORRECT_INPUT -1
#define INPUT_IS_BELOW_ZERO -2

void print_bin(unsigned int a)
{
    int c;
    
    printf("Result: ");
    for (int i = 32; i > 0; i--)
    {
        if (a & (1 << (i - 1)))
            c = 1;
        else
            c = 0;
        printf("%d", c);
    }
}

void to_binary(unsigned int a, int n)
{
    unsigned int result = a;	
    
    result = result >> n;
    result = result | (a << (32 - n));
    
    print_bin(result);
}


int main()
{
    unsigned int a;
    int n;
    if (scanf("%u %d", &a, &n) != 2)
    {
        printf("Error: your input is incorrect.");
        return INCORRECT_INPUT;
    }
    if (n < 0)
    {
        printf("Error: n is less than zero. ");
        return INPUT_IS_BELOW_ZERO;
    }
    to_binary(a, n);
    return 0;
}
