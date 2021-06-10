#include <stdio.h>
#include <math.h>

unsigned int res1(unsigned int x)
{
    unsigned k = 0;
    while(x)
    {
        k+= x % 10;
        x /= 10;
    }
    return k;
}

unsigned int res2(unsigned int x)
{
    if (x)
        return x % 10 + res2(x / 10);
    else
        return 0;
}
unsigned int u(unsigned int x)
{
    unsigned int k;
    while(x)
    {
        x /= 10;
        k++;
    }
    return k;
}
int main()
{
    unsigned int x = 0;;
    printf("Введите число:");
    scanf("%u", &x);
    printf("Среднее арифметическое цифр числа через цикл: %le\n", (res1(x) * 1.0f) / (u(x) * 1.0f));
    printf("Среднее арифметическое цифр числа через рекурсию: %le\n", (res2(x) * 1.0f ) / (u(x) * 1.0f));
    printf("\n");
    return 0;
}
