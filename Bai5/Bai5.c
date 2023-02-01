#define __STDC_WANT_LIB_EXT1__ 1
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

double sum(double num_temp[], int count) {
    double s = 0;
    for (int i = 0; i < count; i++) {
        s += num_temp[i];
    }
    return s;
}


int main()
{
    //user's input
    char a[601];
    printf("vd: 5 6 4 3 2 1.6 6.1 -9.8 100000 3.14 2.17   6 5 10.5 0 8\n");
    printf("Nhap day so: ");
    fgets(a, 601, stdin);

    //convert it to numeric array
    char ab[601] = { 0 };
    int ai = 0, count = 0;
    double num_temp[301] = { 0 };
    int z = strlen(a);
    for (int i = 0; i < z - 1; i++) {
        if (a[i] != ' ') {
            ab[ai] = a[i];
            ai++;
            if ((i == z - 2) && (a[z - 2] != ' ')) {
                char* ptr = 0;
                num_temp[count] = strtod(ab, ptr);
                count++;
            }
        }
        else if ((a[i] == ' ') && (ai != 0)) {
            char* ptr = 0;
            num_temp[count] = strtod(ab, ptr);
            memset(ab, 0, sizeof ab);
            ai = 0;
            count++;
        }
    }

    //sum et avg
    double s = sum(num_temp, count), av = s / count;
    printf("\nsum of the sequence: %f", s);
    printf("\nmean of the sequence: %f\n", av);

    return 0;
}
