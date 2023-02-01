#define __STDC_WANT_LIB_EXT1__ 1
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char a[601];
    int b[301] = { 0 };
    printf("text only: ");
    fgets(a, 601, stdin);
    int mots = 0;
    if (a[0] != ' ')
    {
        b[0] = 0;
        mots = mots + 1;

    }
    for (int i = 0; i < strlen(a) - 2; i++) {
        if ((a[i] == ' ') && a[i + 1] != ' ') {
            b[mots] = i + 1;
            mots = mots + 1;
        }
    }
    printf("\nChuoi ban nhap bao gom %d tu:", mots);
    for (int i = 0; i < mots; i++) {
        int ii = 0;
        printf(" %c", 34);
        while ((a[b[i] + ii] != ' ') && (a[b[i] + ii + 1] != '\0')) {
            printf("%c", a[b[i] + ii]);
            ii++;
        }
        fputs("\" ", stdout);
    }
    for (int i = 65; i <= 90; i++) {
        int x = 0, y = 0;
        for (int ii = 0; ii < strlen(a) - 1; ii++)
        {
            if (a[ii] == i) x++;
            else if (a[ii] == i + 32) y++;
        }
        if (x * y != 0) {
            printf("\nTrong chuoi co %d \"%c\" + %d \"%c\" = %d", x, i, y, i + 32, x + y);
        }
        else if (x != 0) {
            printf("\nTrong chuoi co %d \"%c\"", x, i);
        }
        else if (y != 0) {
            printf("\nTrong chuoi co %d \"%c\"", y, i + 32);
        }
    }


    return 0;
}
