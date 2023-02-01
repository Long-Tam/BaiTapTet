#define __STDC_WANT_LIB_EXT1__ 1
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
int swap(double* a, double* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    return 0;
}
int maxi(double num_temp[], int count) {
    int max = 0, min = 0;
    for (int i = 0; i < count - 1; i++) {
        if (num_temp[max] < num_temp[i + 1]) {
            max = i + 1;
        }
    }
    return max;
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
    double num_temp2[301] = { 0 };
    for (int i = 0; i < 301; i++) {
        num_temp2[i] = num_temp[i];
    }
    int i = 0, step1 = 0, step2 = 0;
    while (i < count - 1) {
        if (num_temp[i] > num_temp[i + 1]) {
            swap(&num_temp[i], &num_temp[i + 1]);
            i = 0;
        }
        else i++;
        step1++;
    }


    for (int i = count - 1; i >= 0; i--) {
        swap(&num_temp2[i], &num_temp2[maxi(num_temp2, i + 1)]);
        step2++;
    }

    //display the result
    printf("\naller en haut avec bubble sort: ");
    for (int i = 0; i < count; i++)
    {
        printf("%f ", num_temp[i]);
    }
    printf("\naller en haut avec selection sort: ");
    for (int i = 0; i < count; i++)
    {
        printf("%f ", num_temp2[i]);
    }
    printf("\nnumber of loops must have if bubble sort is used: %d", step1);
    printf("\nnumber of loops must have if selection sort is used: %d\n", step2);

    return 0;
}
