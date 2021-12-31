#include <stdio.h>
#include <math.h>

#define INPUT_IS_INCORRECT -1
#define EPS_IS_INCORRECT -2

double sin_function(double x, double eps)
{
    double result, current_res;
    double factorial = 1;
    int minus = 1;
    double current_x = x;
    current_res = x;
    result = x;
    int fact_n = 0;

    while (fabs(current_res) > eps)
    {
        fact_n = fact_n + 2;
        factorial = factorial * fact_n * (fact_n + 1);
        minus *= -1;
        current_x *= (x * x);
        current_res = minus * current_x / factorial;
        result = result + current_res;
    }
    
    return result;
}

int main()
{
    double x, eps;
    double s, func;
    double absolut_d, conv_d;

    if (scanf("%lf %lf", &x, &eps) != 2)
        return INPUT_IS_INCORRECT;
    if (eps <= 0 || eps > 1)
        return EPS_IS_INCORRECT;
    s = sin_function(x, eps);
    func = sin(x);
    absolut_d = fabs(func - s);
    conv_d = absolut_d / fabs(func);

    printf("%lf %lf %lf %lf", s, func, absolut_d, conv_d);

    return 0;
}
