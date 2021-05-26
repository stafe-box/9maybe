#include <stdio.h>
#include <math.h>

double res2(unsigned int x)

int main()
{
    unsigned int x = 0;
    int k = 0;
    printf("Введите число:");
    scanf("%u", &x);
    printf("Средне арифметическое суммы цифр числа x: %le \n", res1(x));
    printf("Средне арифметическое суммы цифр числа x: %le \n", res2(x, &k));
    return 0;
}
