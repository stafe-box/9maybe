#include <stdio.h>
#include <math.h>

double res1(unsigned int x)
{
    int l = 0;
    double h = 0;
    while (x)
    {
        l++;
        h += x % 10;
        x /= 10;
    }
    return h / (l * 1.0f);
}

double res2(unsigned int x, int *p)
{
    
}

int main()
{
    unsigned int x = 0;
    int k = 0;
    printf("Введите число:");
    scanf("%u", &x);
    printf("Средне арифметическое суммы цифр числа x: %le \n", res1(x));
    printf("Средне арифметическое суммы цифр числа x: %le \n", res2(x, &k) / (1.0f * k));
    return 0;
}
