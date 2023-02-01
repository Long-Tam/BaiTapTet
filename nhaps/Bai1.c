#define __STDC_WANT_LIB_EXT1__ 1
#include <stdio.h>
int main() {
	int num;
	printf("enter the number of lines: ");

	scanf_s("%d", &num);
	for (int i = 1; i < num + 1; i++) {
		for (int ii = 1; ii < num - i + 1; ii++)
		{
			printf(" ");
		}
		for (int ii = 1; ii < 2 * i; ii++)
		{
			printf("%c", 5);
		}
		for (int ii = 1; ii < num - i + 1; ii++)
		{
			printf(" ");
		}
		printf(" \n");
	}

	return 0;
}
