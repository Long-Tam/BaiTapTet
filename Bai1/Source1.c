#define __STDC_WANT_LIB_EXT1__ 1
#include <stdio.h>
#include <math.h>

int main()
{
    double a;
    double b;
    double c;
    double delta;
    printf("giai phuong trinh dang ax^2+bx+c=0 \n");
    printf("nhap a=");
    scanf_s("%lf", &a);
    printf("nhap b=");
    scanf_s("%lf", &b);
    printf("nhap c=");
    scanf_s("%lf", &c);
    delta = pow(b, 2) - 4 * a * c;
    printf("\n");
    if (delta > 0)
    {
        printf("x1=%f\nx2=%f", (-b + sqrt(delta) / (2 * a)), (-b - sqrt(delta)) / (2 * a));

    }
    else if (delta == 0 || delta == -0)
    {
        printf("x=%f", -b / (2 * a));
    }
    else
    {
        printf("x1=%f+%fi", -b / (2 * a), sqrt(-delta) / (2 * a));
        printf("\nx2=%f-%fi", -b / (2 * a), sqrt(-delta) / (2 * a));
    }
    printf("\n");

    return 0;
}
