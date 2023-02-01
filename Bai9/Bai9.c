#define __STDC_WANT_LIB_EXT1__ 1
#include <stdio.h>
#include <math.h>

int factorial(int n) {
    int res = 1;
    for (int i = 1; i <= n; i++) {
        res *= i;
    }
    return res;
}

int main()
{
    printf("finding value of e^x through the expansion of maclaurin series to the nth term\n\n");
    int x, n;
    double res = 1;
    printf("x = ");
    scanf_s("%d", &x);
    printf("n = ");
    scanf_s("%d", &n);

    for (int i = 1; i <= n; i++) {
        res += pow(x, i) / factorial(i);
    }
    printf("\ne^%d %c %lf\n", x, 126, res);
    return 0;
}
