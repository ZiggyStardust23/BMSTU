#include <stdio.h>

int main()
{
    double mass, height_in_sm, height_in_m, chest_size; 
    double mass_normal, bmi;

    scanf("%lf", &height_in_sm);
    scanf("%lf", &chest_size);
    scanf("%lf", &mass);

    height_in_m = height_in_sm / 100;
    mass_normal = (height_in_sm * chest_size) / 240;
    bmi = mass / (height_in_m * height_in_m);

    printf("%lf\n", mass_normal);
    printf("%lf", bmi);

    return 0;
}
