#include "math.h"
#include "stdio.h"

int main()
{
    double i = 0.0, h = 0.0, x = 0.0;
    printf("Введите шаг изменения x -> ");
    scanf("%lf", &h);
    printf("  x                                f(x)\n  -------------------------------------\n");
    long int kn = 0, n = 2/h;
    do
    {
        if ( i <= 1.0f )
            x = 8 * i * i * i * cos(i);
        else
            x = log(1 + sqrt(i)) - cos(i);
        printf("%*lf                   %*lf\n", 10, i, 10, x);
        i += h;
        kn += 1;
    } while (kn <= n);
    return 0;
}
