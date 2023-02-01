#define __STDC_WANT_LIB_EXT1__ 1
#include <stdio.h>
//#include <math.h>
//#include <stdint.h>
//#include <string.h>
#include <stdlib.h>
void add(double* ptr, int m, int n, double* ptr2, int x, int y, double* res) {
	if (m == x & n == y) {
		for (int i = 0; i < n * m; i++) {
			*(res + i) = *(ptr + i) + *(ptr2 + i);
		}
		printf("\nsum of two matrices:\n");
		for (int ii = 0; ii < x; ii++) {
			for (int i = 0; i < y; i++) {
				printf("	%g", *(res + i + ii * y));
			}
			printf("\n");
		}
	}
}
void subtract(double* ptr, int m, int n, double* ptr2, int x, int y, double* res) {
	if (m == x & n == y) {
		for (int i = 0; i < n * m; i++) {
			*(res + i) = *(ptr + i) - *(ptr2 + i);
		}
		printf("\nsubtraction of 2nd from 1st matrix:\n");
		for (int ii = 0; ii < x; ii++) {
			for (int i = 0; i < y; i++) {
				printf("	%g", *(res + i + ii * y));
			}
			printf("\n");
		}
	}
}
void multiply(double* ptr, int m, int n, double* ptr2, int x, int y, double* res) {
	if (n == x) {
		for (int ii = 0; ii < m; ii++) {
			for (int i = 0; i < y; i++) {
				*(res + i + ii * y) = 0;
				for (int iii = 0; iii < x; iii++) {
					*(res + i + ii * y) += *(ptr + iii + n * ii) * *(ptr2 + i + iii * y);
				}
			}
		}
		printf("\nmultiplication of two matrices:\n");
		for (int ii = 0; ii < m; ii++) {
			for (int i = 0; i < y; i++) {
				printf("	%g", *(res + i + ii * y));
			}
			printf("\n");
		}
	}
}
void Transpose(double* ptr, int m, int n, double* res) {

	for (int ii = 0; ii < m; ii++) {
		for (int i = 0; i < n; i++) {
			*(res + i * m + ii) = *(ptr + i + ii * n);
		}
	}

	for (int ii = 0; ii < n; ii++) {
		for (int i = 0; i < m; i++) {
			printf("	%g", *(res + i + ii * m));
		}
		printf("\n");
	}
}

int main() {
	int m, n, x, y;

	char a[301], am[21], an[21];

	printf("Enter the size of your first matrix m%cn:\n", 250);
	printf("	m = ");
	fgets(am, sizeof(am), stdin);
	m = strtoul(am, NULL, 0);//scanf doesn't work
	//scanf_s("%u", &m);

	printf("	n = ");
	fgets(an, sizeof(an), stdin);
	n = strtoul(an, NULL, 0);
	//scanf_s("%u", &n);

	double* ptr = malloc(sizeof(*ptr) * m * n);

	for (int ii = 0; ii < m; ii++) {
		printf("Enter row %d of your 1st matrix : ", ii + 1);
		fgets(a, sizeof(a), stdin);
		char* p = a;
		for (int i = 0; i < n; i++) {
			*(ptr + i + ii * n) = strtod(p, &p);
		}
	}

	printf("your first matrix:\n");
	for (int ii = 0; ii < m; ii++) {
		for (int i = 0; i < n; i++) {
			printf("	%g", *(ptr + i + ii * n));
		}
		printf("\n");
	}

	printf("\nEnter the size of your second matrix x%cy:\n", 250);

	printf("	x = ");
	fgets(am, sizeof(am), stdin);
	x = strtoul(am, NULL, 0);//scanf doesn't work
	//scanf_s("%u", &m);

	printf("	y = ");
	fgets(an, sizeof(an), stdin);
	y = strtoul(an, NULL, 0);
	//scanf_s("%u", &n);

	double* ptr2 = malloc(sizeof(*ptr2) * x * y);

	for (int ii = 0; ii < x; ii++) {
		printf("Enter row %d of your 2nd matrix : ", ii + 1);
		fgets(a, sizeof(a), stdin);
		char* p2 = a;
		for (int i = 0; i < y; i++) {
			*(ptr2 + i + ii * y) = strtod(p2, &p2);
		}
	}

	printf("your second matrix:\n");
	for (int ii = 0; ii < x; ii++) {
		for (int i = 0; i < y; i++) {
			printf("	%g", *(ptr2 + i + ii * y));
		}
		printf("\n");
	}
	double* res = malloc(sizeof(*res) * max(m, n, x, y) * max(m, n, x, y));

	add(ptr, m, n, ptr2, x, y, res);
	subtract(ptr, m, n, ptr2, x, y, res);
	multiply(ptr, m, n, ptr2, x, y, res);
	printf("\ntranspose of 1st matrix:\n");
	Transpose(ptr, m, n, res);
	printf("\ntranspose of 2nd matrix:\n");
	Transpose(ptr2, x, y, res);
	return 0;
}
