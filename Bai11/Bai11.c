#define __STDC_WANT_LIB_EXT1__ 1
#include <stdio.h>
//#include <math.h>
//#include <stdint.h>
//#include <string.h>
//#include <stdlib.h>
struct complex {
	double re;
	double im;
};
void add(struct complex* x, struct complex* y, struct complex* ans) {
	(*ans).re = (*x).re + y->re;
	ans->im = (*x).im + y->im;
}
void subtract(struct complex* x, struct complex* y, struct complex* ans) {
	(*ans).re = (*x).re - y->re;
	ans->im = (*x).im - y->im;
}
void multiply(struct complex* x, struct complex* y, struct complex* ans) {
	(*ans).re = (*x).re * y->re - (*x).im * y->im;
	ans->im = (*x).re * y->im + (*x).im * y->re;
}

void divine(struct complex* x, struct complex* y, struct complex* ans) {
	(*ans).re = ((*x).re * y->re + (*x).im * y->im) / (y->re * y->re + (*y).im * (*y).im);
	ans->im = (-(*x).re * y->im + (*x).im * y->re) / (y->re * y->re + (*y).im * (*y).im);
}

int main() {
	struct complex x = { 0,0 }, y = { 0,0 }, res = { 0,0 };
	int state = 0;

	printf("x=a+bi:\n");
	printf("      a = ");
	scanf_s("%lf", &x.re);
	printf("      b = ");
	scanf_s("%lf", &x.im);

	printf("\ny=c+di:\n");
	printf("      c = ");
	scanf_s("%lf", &y.re);
	printf("      d = ");
	scanf_s("%lf", &y.im);

	printf("\nfor adding two complex numbers,		enter 1\n");
	printf("for subtracting two complex numbers,	enter 2\n");
	printf("for multiplying two complex numbers,	enter 3\n");
	printf("for dividing two complex numbers,	enter 4\n");

	printf("				Enter here: ");
	scanf_s("%d", &state);

	switch (state)
	{
	case 1:
		add(&x, &y, &res);
		break;
	case 2:
		subtract(&x, &y, &res);
		break;
	case 3:
		multiply(&x, &y, &res);
		break;
	case 4:
		divine(&x, &y, &res);
		break;
	default:
		break;
	}
	printf("Result: %g + %gi\n", (&res)->re, res.im);
	while (1) {
		printf("\nfor adding two complex numbers,		enter 1\n");
		printf("for subtracting two complex numbers,	enter 2\n");
		printf("for multiplying two complex numbers,	enter 3\n");
		printf("for dividing two complex numbers,	enter 4\n");
		printf("to exit,				enter 0\n");

		printf("				Enter here: ");
		scanf_s("%d", &state);
		if (state == 0) break;
		switch (state)
		{
		case 1:
			add(&x, &y, &res);
			break;
		case 2:
			subtract(&x, &y, &res);
			break;
		case 3:
			multiply(&x, &y, &res);
			break;
		case 4:
			divine(&x, &y, &res);
			break;
		default:
			break;
		}
		printf("result: %g + %gi\n", (&res)->re, res.im);
	}
	return 0;
}
