#include <math.h>
#include <stdio.h>

int main()
{
    double x = 0.0f, y = 0, z = 0;
    printf("Введите значение: ");
    scanf("%le", &x);
    if (0.01 <= x && x <= 1.39)
    {
        y = 5 * sqrt(sin(sqrt(x)));
        z = log10(cos(log(y)));
        printf("x = %le; y = %le, z = %lf\n", x, y, z);
    }
    else
        printf("Введено неверное значение!\n");
    return 0;
}
