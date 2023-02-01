#define __STDC_WANT_LIB_EXT1__ 1
#include <stdio.h>
//#include <math.h>
//#include <stdint.h>
//#include <string.h>
#include <stdlib.h>
int main() {
	char c = '\0';
	for (int i = 1; i <= 254; i++) {
		c += 1;
		printf("%d:	%c\n",i, c);
	}
}