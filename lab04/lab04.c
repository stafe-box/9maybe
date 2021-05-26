#include <math.h>
#include <stdio.h>

int main()
{
    double xi, integral, integral2, h, y, x, e, tochost = 2.0f;
    int n = 2;
    printf("Введите необходимую точность -> ");
    scanf("%lf", &e);
    while (tochost >= e)
    {
        integral2 = integral;
        integral = 0;
        h = 2.0 / n;
        for (int i = 0; i < n; i++)
        {
            xi = 0 + i * h;
            x = xi + h / 2.0;
            if (x <= 1.0)
                y = 8 * x * x * x * cos(x);
            else
                y = log(1 + sqrt(x)) - cos(x);
            integral = integral + y;
        }
        integral = h * integral;
        n = n * 2;
        tochost = fabs(integral - integral2) / 2.0f;
    }
    printf("\nОтвет = %lf\n", integral);
 }
