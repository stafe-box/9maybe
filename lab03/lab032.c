#include "math.h"
#include "stdio.h"

int main()
{
    double i = 0.0f, h = 0.0f, x = 0.0f;
    printf("Enter the step of changing the argument -> ");
    scanf("%lf", &h);
    printf("  x                                f(x)\n  -------------------------------------\n");
    long int kn = 0, n = 2 / h;
    for (kn = 0; kn <= n; kn++)
    {
        if ( i <= 1.0f )
            x = 8 * i * i * i * cos(i);
        else
            x = log(1 + sqrt(i)) - cos(i);
        printf("%*lf                   %*lf\n", 10, i, 10, x);
        i += h;
    }
    return 0;
}
