#include <stdio.h>
#include <math.h>

#define INPUT_IS_INCORRECT -1

int main()
{
    double x, g;
    int n;
    n = 0;
    g = 0;
    x = 0;
    while (x >= 0)
    {
        if (scanf("%lf", &x) == 1) 
        {	
            if (x >= 0)
            {
                n++;
                g += x / n;
            }
        }
        else
        {
            return INPUT_IS_INCORRECT;
        }
    }
    g = sqrt(g);
    printf("%lf", g);
    return 0;
}
