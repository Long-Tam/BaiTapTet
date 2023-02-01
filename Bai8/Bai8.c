#define __STDC_WANT_LIB_EXT1__ 1
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

int mini(double num_temp[], int count) {
    int min = 0;
    for (int i = 0; i < count - 1; i++) {
        if (num_temp[min] > num_temp[i + 1]) {
            min = i + 1;
        }
    }
    return min;
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

    //rearrange
    for (int i = count - 1; i >= 0; i--) {
        double temp = num_temp[mini(num_temp, i + 1)];
        num_temp[mini(num_temp, i + 1)] = num_temp[i];
        num_temp[i] = temp;
    }

    //display the result
    printf("descending: ");
    for (int i = 0; i < count; i++)
    {
        printf("%f ", num_temp[i]);
    }

    return 0;
}
