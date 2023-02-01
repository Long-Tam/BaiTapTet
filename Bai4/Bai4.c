#define __STDC_WANT_LIB_EXT1__ 1
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

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
    //printf("%s",a);
    int z = strlen(a);
    //printf("length: %d",z);
    //printf("true or false: %d", a[z - 2] == ' ');
    for (int i = 0; i < z - 1; i++) {
        if (a[i] != ' ') {
            ab[ai] = a[i];
            ai++;
            if ((i == z - 2) && (a[z - 2] != ' ')) {
                char* ptr = 0;
                num_temp[count] = strtod(ab, ptr);
                //printf("\nend: %f", num_temp[count]);
                count++;

            }
            //printf("\n%c",ab[ai]);
        }
        else if ((a[i] == ' ') && (ai != 0)) {
            char* ptr = 0;
            num_temp[count] = strtod(ab, ptr);
            //printf("\n%f",num_temp[count]);
            memset(ab, 0, sizeof ab);
            ai = 0;
            count++;
        }
    }

    //finding min max value
    int max = 0, min = 0;
    printf("\nday so ban da nhap: %f", num_temp[1]);
    for (int i = 0; i < count - 1; i++) {
        if (num_temp[max] < num_temp[i + 1]) {
            max = i + 1;
        }
        if (num_temp[min] > num_temp[i + 1]) {
            min = i + 1;
        }
        printf(" %f", num_temp[i + 1]);
    }

    //display the result
    printf("\nmax: %f   \nmin:%f", num_temp[max], num_temp[min]);

    return 0;
}
