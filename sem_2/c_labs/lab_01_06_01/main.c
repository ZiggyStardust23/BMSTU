#include <stdio.h>
#include <math.h>

#define INPUT_IS_INCORRECT -1
#define TRIANGLE_DOESNT_EXIST -2

double find_side(double x1, double y1, double x2, double y2)
{
    double side_length = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    return side_length;
}


int main()
{
    double x1, y1;
    double x2, y2;
    double x3, y3;
    double side1, side2, side3;
    double perimeter, square;
    int input_check = 0;

    input_check = scanf("%lf %lf", &x1, &y1);
    input_check = input_check + scanf("%lf %lf", &x2, &y2);
    input_check = input_check + scanf("%lf %lf", &x3, &y3);

    if (input_check != 6)
        return INPUT_IS_INCORRECT;

    side1 = find_side(x1, y1, x2, y2);
    side2 = find_side(x2, y2, x3, y3);
    side3 = find_side(x1, y1, x3, y3);

    if (side1 + side2 <= side3 || side2 + side3 <= side1 || side1 + side3 <= side2)
        return TRIANGLE_DOESNT_EXIST;

    perimeter = (side1 + side2 + side3) / 2;
    square = sqrt(perimeter * (perimeter - side1) * (perimeter - side2) * (perimeter - side3));

    printf("%lf", square);

    return 0;
}
