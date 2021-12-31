#include <stdio.h>
#include <math.h>

int main()
{
    double a_base, b_base;
    double height;

    scanf("%lf %lf", &a_base, &b_base);
    scanf("%lf", &height);

    double dif_in_bases = (a_base - b_base) / 2;
    double side_part = sqrt(dif_in_bases * dif_in_bases + height * height);
    double perimeter = 2 * side_part + a_base + b_base;

    printf("%lf", perimeter);

    return 0;
}
