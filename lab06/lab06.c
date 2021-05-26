#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void zapol(int k, unsigned int a[])
{
    for(int i = 0; i < k; i++)
        a[i] = rand() % 100;
}

void printmassiv(int k, unsigned int a[])
{
    for (int i = 0; i < k; i++)
        printf("%u ", a[i]);
    printf("\n");
}

void zadacha(int n, unsigned int a[])
{
    int b[n];
    int sk = 0, sl;
    for (int i = 0; i < n; i++)
    {
        sl = 0;
        if (a[i] > 1)
        {
          for(int j = 2; j < a[i]; j++)
              if (a[i] % j == 0)
                  sl++;
        }
        else
            sl++;
        if (!sl)
          b[sk++] = i;
    }
    switch(sk)
    {
        case 0:
            break;
        case 1:
            printf("%d\n", a[b[0]]);
            break;
        case 2:
            sl = a[b[0]];
            a[b[0]] = a[b[1]];
            a[b[1]] = sl;
            break;
        default:
            for (int i = 0; i < sk; i++)
                printf("%d; ", b[i]);
            printf("\n");
            break;
    }
}

int main()
{
    srand(time(NULL));
    int n = 0;
    printf("Введите количество элементов в массиве: ");
    scanf("%d", &n);
    unsigned int a[n];
    zapol(n, a);
    printmassiv(n, a);
    zadacha(n, a);
    return 0;
}
