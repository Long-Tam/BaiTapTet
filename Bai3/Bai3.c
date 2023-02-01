#define __STDC_WANT_LIB_EXT1__ 1
#include <stdio.h>

int main()
{
    int bao_tien_1_mo_binh_yen;
    printf("Nhap so tien: ");
    scanf_s("%d", &bao_tien_1_mo_binh_yen);
    int a = 0, b = 0, c = 0, d = 0;
    while (bao_tien_1_mo_binh_yen > 0) {
        if (bao_tien_1_mo_binh_yen - 10 >= 0) {
            bao_tien_1_mo_binh_yen -= 10;
            a++;
        }
        else if (bao_tien_1_mo_binh_yen - 5 >= 0)
        {
            bao_tien_1_mo_binh_yen -= 5;
            b++;
        }
        else if (bao_tien_1_mo_binh_yen - 2 >= 0) {
            bao_tien_1_mo_binh_yen -= 2;
            c++;
        }
        else if (bao_tien_1_mo_binh_yen - 1 >= 0) {
            bao_tien_1_mo_binh_yen -= 1;
            d++;
        }
    }
    printf("%d$ = %d*10$ + %d*5$ + %d*2$ + %d*1$", 10 * a + 5 * b + 2 * c + d, a, b, c, d);
    printf("\nVay chung ta can tong cong %d to tien\n", a + b + c + d);
    return 0;
}
